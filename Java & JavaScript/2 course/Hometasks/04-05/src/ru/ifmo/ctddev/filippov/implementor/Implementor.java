package ru.ifmo.ctddev.filippov.implementor;

import info.kgeorgiy.java.advanced.implementor.JarImpler;
import info.kgeorgiy.java.advanced.implementor.ImplerException;

import javax.tools.JavaCompiler;
import javax.tools.ToolProvider;
import java.io.*;
import java.lang.annotation.Annotation;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.jar.Attributes;
import java.util.jar.JarEntry;
import java.util.jar.JarOutputStream;
import java.util.jar.Manifest;
import java.util.stream.Collectors;

/**
 * This class shows implementation of {@link info.kgeorgiy.java.advanced.implementor.JarImpler}
 * interface
 * <p>
 * It can generate implementation (<tt>java</tt> file) for interfaces and classes that can be
 * implemented/extended
 * Class implements all methods that should be overridden, their default return value
 * gets out according to javadoc primitive types
 * (see <a href="http://docs.oracle.com/javase/tutorial/java/nutsandbolts/datatypes.html">Primitive Data Types</a>).
 * Implemented class name is equal to class name that we must implement plus "Impl" suffix
 * <p>
 * It can also generate <tt>jar</tt> archive with that certain class.
 * <p>
 * If something went wrong while creating <tt>java</tt> or <tt>jar</tt> files
 * and it is impossible to generate such file, than
 * {@link info.kgeorgiy.java.advanced.implementor.ImplerException} is thrown with error message
 *
 * @author  Dmitry Philippov
 * @see     info.kgeorgiy.java.advanced.implementor.Impler
 * @see     info.kgeorgiy.java.advanced.implementor.JarImpler
 * @see     info.kgeorgiy.java.advanced.implementor.ImplerException
 */
public class Implementor implements JarImpler {
    /**
     * map of return values of basic classes
     */
    private HashMap<Class<?>, String> returnValues = new HashMap<>();
    /**
     * indentation string
     */
    private final String TAB = "    ";
    /**
     * global variable means token that we need to implement
     */
    private Class<?> mainToken;

    /**
     * Creates an entry of {@link Implementor} class.
     */
    public Implementor() {
    }

    /**
     * Inits return values of classes according to javadoc primitive types
     * (see <a href="http://docs.oracle.com/javase/tutorial/java/nutsandbolts/datatypes.html">Primitive Data Types</a>)
     */
    private void initReturnValues() {
        returnValues.put(byte.class, "0");
        returnValues.put(short.class, "0");
        returnValues.put(int.class, "0");
        returnValues.put(long.class, "0L");
        returnValues.put(float.class, "0.0f");
        returnValues.put(double.class, "0.0d");
        returnValues.put(char.class, "0");
        returnValues.put(boolean.class, "false");
        returnValues.put(void.class, "");
        returnValues.put(String.class, "null");
    }

    /**
     *
     * @param returnType class, means the return type
     * @return String, means the return value of type taken from returnValues. if class is not in
     * returnValues, null returns
     */
    private String defaultReturnValue(Class<?> returnType) {
        if (returnType.isPrimitive()) {
            if (returnValues.containsKey(returnType)) {
                return returnValues.get(returnType);
            } else {
                return "0";
            }
        } else {
            return "null";
        }
    }

    /**
     * method that returns dependence type
     *
     * @param token class we need to implement
     * @return dependence type - "implements" if token is interface and "extends" otherwise
     */
    private String getDependenceType(Class token) {
        return token.isInterface() ? "implements " : "extends ";
    }


    /**
     * predicate that returns if token is abstract or static
     */
    private Predicate<Method> isAbstractPredicate = token -> (Modifier.isAbstract(token.getModifiers()) || Modifier.isStatic(token.getModifiers()));

    /**
     * function that returns highest method in dependence tree equal to first parameter
     */
    private static Function<Method, Method> getSuperClassMethod = method -> {
        try {
            Class<?> superClass = method.getDeclaringClass().getSuperclass();
            if (superClass == null) {
                return method;
            }
            Method baseMethod = (superClass.getDeclaredMethod(method.getName()));
            if (baseMethod.equals(method)) {
                return method;
            }
            return Implementor.getSuperClassMethod.apply(baseMethod);
        } catch (NoSuchMethodException e) {
            return method;
        }
    };

    /**
     * Comparator that compares methods -- first by names, then by parameters count, than by parameters types
     */
    private Comparator<Method> methodComparator = (m1, m2) -> {
        int namesEqual = m1.getName().compareTo(m2.getName());
        if (namesEqual != 0) {
            return namesEqual;
        }
        if (m1.getParameterCount() != m2.getParameterCount()) {
            return m1.getParameterCount() - m2.getParameterCount();
        }
        Class[] pt1 = m1.getParameterTypes();
        Class[] pt2 = m2.getParameterTypes();
        for (int i = 0; i < pt1.length; i++) {
            if (!pt1[i].getName().equals(pt2[i].getName())) {
                return pt1[i].getName().compareTo(pt2[i].getName());
            }
        }
        return 0;
    };

    /**
     * Method that tests and unique given methods
     *
     * @param methods list of methods to be unique
     * @param predicate predicate, that tests methods
     * @param comparator comparator, that compares methods
     * @return {@link java.util.TreeSet} that contains only tested and unique methods
     *
     */
    private TreeSet<Method> getMethodsList(Method[] methods, Predicate<Method> predicate, Comparator<Method> comparator) {
        TreeSet<Method> result = new TreeSet<>(comparator);
        for (Method method : methods) {
            if (!predicate.test(method)) {
                continue;
            }
            if (!result.contains(method)) {
                result.add(method);
            }
        }
        return result;
    }

    /**
     * Finds all methods that we need to override in given class and all superclasses.
     *
     * @param token class for which we need to find method
     * @return array of methods that we need to override in given class and all superclasses
     * @see #getMethodsList
     */
    private Method[] getMethods(Class token) {
        TreeSet<Method> methods = getMethodsList(token.getDeclaredMethods(), isAbstractPredicate, methodComparator);
        TreeSet<Method> overridedMethods = getMethodsList(token.getMethods(), isAbstractPredicate.negate(), methodComparator);

        ArrayDeque<Class> classesQueue = new ArrayDeque<>();
        classesQueue.push(token);
        while (!classesQueue.isEmpty()) {
            Class currentClass = classesQueue.pop();
            if (currentClass.getInterfaces().length > 0) {
                Arrays.stream(currentClass.getInterfaces()).forEach(classesQueue::addLast);
            }
            Arrays.stream(currentClass.getDeclaredMethods()).filter(isAbstractPredicate).map(getSuperClassMethod).filter(
                    method -> !Modifier.isFinal(method.getModifiers()) && !overridedMethods.contains(method) && !methods.contains(method)
            ).forEach(methods::add);
            Arrays.stream(currentClass.getDeclaredMethods()).filter(isAbstractPredicate.negate()).map(getSuperClassMethod).filter(
                    method -> !overridedMethods.contains(method) && !methods.contains(method)
            ).forEach(overridedMethods::add);

            if (currentClass.getSuperclass() != null) {
                classesQueue.addLast(currentClass.getSuperclass());
            }
        }
        Method[] answer = new Method[methods.size()];
        methods.toArray(answer);
        return answer;
    }

    /**
     * Method that returns parameters of given method with their random names
     *
     * @param method method of some class
     * @return {@link java.lang.StringBuilder} that contains method parameters with names
     */
    private StringBuilder getMethodParameters(Method method) {
        StringBuilder result = new StringBuilder();
        Class[] parametersTypes = method.getParameterTypes();
        Annotation[][] annotations = method.getParameterAnnotations();
        for (int i = 0; i < annotations.length; i++) {
            Annotation[] annotation = annotations[i];
            result.append(Arrays.stream(annotation).map(Annotation::toString).collect(Collectors.joining(",")));
            result.append(parametersTypes[i].getCanonicalName()).append(" x").append(i);
            if (i < annotations.length - 1) {
                result.append(", ");
            }
        }
        return result;
    }

    /**
     * Method that returns parameters of given constructor with their random names
     *
     * @param constructor constructor of some class
     * @return {@link java.lang.StringBuilder} that contains constructor parameters with names
     */
    private StringBuilder getConstructorParameters(Constructor constructor) {
        StringBuilder result = new StringBuilder();
        Class[] parametersTypes = constructor.getParameterTypes();
        Annotation[][] annotations = constructor.getParameterAnnotations();
        for (int i = 0; i < annotations.length; i++) {
            Annotation[] annotation = annotations[i];
            result.append(Arrays.stream(annotation).map(Annotation::toString).collect(Collectors.joining(",")));
            result.append(parametersTypes[i].getCanonicalName()).append(" x").append(i);
            if (i < annotations.length - 1) {
                result.append(", ");
            }
        }
        return result;
    }

    /**
     * Writes main code of implemented class
     *
     * @param token given class
     * @return String means main code of class
     * @throws ImplerException throws {@link ImplerException} if an error occurred and it is impossible to write main code
     * @see info.kgeorgiy.java.advanced.implementor.ImplerException
     * @see #getConstructorParameters
     * @see #getMethods
     * @see #getMethodParameters
     */
    private String getMainCode(Class<?> token) throws ImplerException {
        StringBuilder result = new StringBuilder();
        String className = token.getSimpleName() + "Impl";
        result.append("class ").append(className).append(" ").append(getDependenceType(token)).append(token.getName()).append(" {\n\n");

        Constructor[] constructors = token.getDeclaredConstructors();
        boolean foundPublicConstructor = false;
        for (Constructor constructor : constructors) {
            int modifiers = constructor.getModifiers();
            if (!Modifier.isPrivate(modifiers)) {
                foundPublicConstructor = true;
            }
            modifiers &= ~Modifier.ABSTRACT;
            modifiers &= ~Modifier.TRANSIENT;
            result.append(TAB).append(Modifier.toString(modifiers)).append(" ");
            result.append(mainToken.getSimpleName()).append("Impl").append('(');
            result.append(getConstructorParameters(constructor));
            result.append(')');
            if (constructor.getExceptionTypes().length != 0) {
                result.append(" throws ");
            }
            result.append(Arrays.stream(constructor.getExceptionTypes()).map(Class::getName)
                    .collect(Collectors.joining(", "))).append(" {")
                    .append("\n");
            if (token.getSuperclass() != null) {
                result.append(TAB).append(TAB).append("super(");
                for (int i = 0; i < constructor.getParameterCount(); i++) {
                    result.append("x" + i);
                    if (i < constructor.getParameterCount() - 1) {
                        result.append(", ");
                    }
                }
                result.append(");\n").append(TAB).append("}\n\n");
            } else {
                result.append(TAB).append("}\n\n");
            }
        }
        if (constructors.length != 0 && !foundPublicConstructor) {
            throw new ImplerException("no public constructor in class");
        }

        Method[] methods = getMethods(token);
        for (Method method : methods) {
            int modifiers = method.getModifiers();
            modifiers &= ~Modifier.ABSTRACT;
            modifiers &= ~Modifier.TRANSIENT;
            if (!Modifier.isStatic(modifiers)) {
                result.append(TAB).append("@Override\n");
            }
            result.append(TAB);
            result.append(Modifier.toString(modifiers)).append(" ");
            result.append(method.getReturnType().getCanonicalName()).append(" ");

            result.append(method.getName()).append('(');
            result.append(getMethodParameters(method));
            result.append(')');
            if (method.getExceptionTypes().length != 0) {
                result.append(" throws ");
            }
            result.append(Arrays.stream(method.getExceptionTypes()).map(Class::getName)
                    .collect(Collectors.joining(", ")));
            if (!Modifier.isNative(method.getModifiers())) {
                result.append(" {").append("\n").append(TAB).append(TAB);
                result.append("return ").append(defaultReturnValue(method.getReturnType())).
                        append(";\n").append(TAB).append("}\n\n");
            } else {
                result.append(";\n\n");
            }
        }

        for (Class inner : token.getClasses()) {
            if (!Modifier.isAbstract(inner.getModifiers())) {
                continue;
            }
            result.append("\n\n").append(TAB);
            result.append(getMainCode(inner));
        }
        result.append("\n}\n");

        return result.toString();
    }

    /**
     *  This method creates <tt>java</tt> file in directory {@code root} and writes implementation of class, given in {@code token}.
     *  Throws {@link info.kgeorgiy.java.advanced.implementor.ImplerException} if an error occurred while creating implemention
     *
     * @param token class to create implementation for
     * @param root root directory, where we need to save implementation of class
     * @throws ImplerException if something went wrong, ImplerException throws
     * @see info.kgeorgiy.java.advanced.implementor.ImplerException
     */
    @Override
    public void implement(Class<?> token, File root) throws ImplerException {
        if (token == null) {
            throw new ImplerException("Token is null");
        }
        if (root == null) {
            throw new ImplerException("root is null");
        }
        if (token.getPackage() == null) {
            throw new ImplerException("Token is wrong - package is equal null");
        }
        File directoryPath = new File(root.getAbsolutePath() + File.separator + token.getPackage().getName().replace(".", File.separator) + File.separator);
        if (!directoryPath.exists()) {
            if (!directoryPath.mkdirs()) {
                throw new ImplerException("token's package doesn't exists, cannot create needed directories");
            }
        }
        if (Modifier.isFinal(token.getModifiers())) {
            throw new ImplerException("token is final");
        }
        mainToken = token;
        String fileName = directoryPath.toString() + File.separator + token.getSimpleName() + "Impl.java";
        try (Writer writer = new OutputStreamWriter(new FileOutputStream(fileName), StandardCharsets.UTF_8)) {
            writer.write("package " + token.getPackage().getName() + ";\n\n");
            initReturnValues();
            writer.write(getMainCode(token));
        } catch (IOException e) {
            System.out.println("An error occurred while writing to source file: " + e.toString());
            return;
        }
    }

    /**
     * Method that returns file, containing implemented class name
     *
     * @param root root directory
     * @param clazz class
     * @return file containing implemented class name with absolute path
     */
    private File getFile(final File root, final Class<?> clazz) {
        final String path = clazz.getCanonicalName().replace(".", File.separator) + "Impl.java";
        return new File(root, path).getAbsoluteFile();
    }

    /**
     *  Compile java files
     *
     * @param root root directory
     * @param classes classes we need to compile
     * @throws ImplerException if compilation failed, throws ImplerException
     */
    private void compile(final File root, final List<Class<?>> classes) throws ImplerException {
        final List<String> files = new ArrayList<>();
        for (final Class<?> token : classes) {
            files.add(getFile(root, token).getPath());
        }
        compileFiles(root, files);
    }

    /**
     * Compile java files
     *
     * @param root root directory
     * @param files list of files we need to compile
     * @throws ImplerException if compilation failed, throws ImplerException
     * @see info.kgeorgiy.java.advanced.implementor.ImplerException
     * @see javax.tools.ToolProvider
     */
    private void compileFiles(final File root, final List<String> files) throws ImplerException {
        final JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        if (compiler == null) {
            throw new ImplerException("Could not find java compiler, include tools.jar to classpath");
        }
        final List<String> args = new ArrayList<>();
        args.addAll(files);
        args.add("-cp");
        args.add(root.getPath() + File.pathSeparator + System.getProperty("java.class.path"));
        final int exitCode = compiler.run(null, null, null, args.toArray(new String[args.size()]));
        if (exitCode != 0) {
            throw new ImplerException("exit code doesn't equal 0");
        }
    }

    /**
     * This method creates <tt>jar</tt> file with name {@code jarFile} in root directory. <tt>.jar</tt> file is obtained by compiling imlementation
     * of {@code token} class by calling {@link #implement} function (so, implemented
     * <tt>java</tt> class also creates).
     * Throws {@link info.kgeorgiy.java.advanced.implementor.ImplerException} if something went wrong and <tt>jar</tt> file cannot be created
     *
     * @param token class to create jar file for
     * @param jarFile target <tt>jar</tt> file.
     * @throws ImplerException if something went wrong, {@link ImplerException} throws
     * @see info.kgeorgiy.java.advanced.implementor.ImplerException
     * @see #implement
     * @see #compile
     */
    @Override
    public void implementJar(Class<?> token, File jarFile) throws ImplerException {
        if (token == null) {
            throw new ImplerException("token is null");
        }
        if (jarFile == null) {
            throw new ImplerException("jarFile is null");
        }
        File root = new File("src");
        if (!root.exists() && !root.mkdirs()) {
            throw new ImplerException(String.format("directory %s doesn't exist and we can't create this directory", root.toString()));
        }
        implement(token, root);
        compile(root, Arrays.asList((new Class<?>[]{token})));

        String implementTokenName = token.getSimpleName() + "Impl";
        String implementTokenPackagePath = token.getPackage().getName().replace(".", File.separator) + File.separator;
        Manifest manifest = new Manifest();
        manifest.getMainAttributes().put(Attributes.Name.MANIFEST_VERSION, "1.0");
        manifest.getMainAttributes().put(Attributes.Name.MAIN_CLASS, implementTokenName);
        try (JarOutputStream outputStream = new JarOutputStream(new FileOutputStream(jarFile.getAbsoluteFile()), manifest)) {
            String absoluteClassPath = implementTokenPackagePath + implementTokenName + ".class";
            try (FileInputStream inputStream = new FileInputStream(root.getAbsolutePath() + File.separator + absoluteClassPath)) {
                outputStream.putNextEntry(new JarEntry(absoluteClassPath));
                byte[] buffer = new byte[4096];
                int size;
                while (true) {
                    size = inputStream.read(buffer);
                    if (size <= 0) {
                        break;
                    }
                    outputStream.write(buffer, 0, size);
                }
                outputStream.closeEntry();
            }
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }

    /**
     *  Creates jar archive and implementation of token class. Saves jar to args[1] (path to jar file)
     *
     * @param args arguments: args[0] - class name, args[1] - path to jar file
     */
    public static void main(String[] args) {
        if (args == null || args.length != 2 || args[0] == null || args[1] == null) {
            System.out.println("Usage: java <class name> <jarFile>");
            return;
        }
        try {
            Class token = Class.forName(args[0]);
            File jarFile = new File(args[1]);
            if (!jarFile.isFile()) {
                System.out.println(String.format("File %s doesn't exist, can't write to it", jarFile.toString()));
            }
            new Implementor().implementJar(token, jarFile);
        } catch (ImplerException | ClassNotFoundException e) {
            System.out.println(e.toString());
        }
    }
}