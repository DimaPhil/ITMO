package ru.ifmo.ctddev.filippov.implementor;

import info.kgeorgiy.java.advanced.implementor.Impler;
import info.kgeorgiy.java.advanced.implementor.ImplerException;

import java.io.*;
import java.lang.annotation.Annotation;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class Implementor implements Impler {
    private HashMap<Class<?>, String> returnValues = new HashMap<>();
    private final String TAB = "    ";
    private Class<?> mainToken;

    private void initReturnValues() {
        returnValues.put(byte.class, "0");
        returnValues.put(short.class, "0");
        returnValues.put(int.class, "0");
        returnValues.put(long.class, "0");
        returnValues.put(float.class, ".0f");
        returnValues.put(double.class, ".0d");
        returnValues.put(char.class, "0");
        returnValues.put(boolean.class, "false");
        returnValues.put(void.class, "");
    }

    private String defaultReturnValue(Class<?> returnType) {
        if (returnType.isPrimitive()) {
            if (returnValues.containsKey(returnType)) {
                return returnValues.get(returnType);
            } else {
                return "0";
            }
        } else if (returnType.isArray()) {
            return "new " + returnType.getCanonicalName().replace("[]", "[0]");
        } else return "null";
    }

    private String getDependenceType(Class token) {
        return token.isInterface() ? "implements " : "extends ";
    }


    private Predicate<Method> isAbstractPredicate = token -> Modifier.isAbstract(token.getModifiers());
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
                    method -> !Modifier.isFinal(method.getModifiers()) && !methods.contains(method)
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

    private StringBuilder getMethodParameteres(Method method) {
        StringBuilder result = new StringBuilder();
        Class[] parameteresTypes = method.getParameterTypes();
        Annotation[][] annotations = method.getParameterAnnotations();
        for (int i = 0; i < annotations.length; i++) {
            Annotation[] annotation = annotations[i];
            result.append(Arrays.stream(annotation).map(Annotation::toString).collect(Collectors.joining(",")));
            result.append(parameteresTypes[i].getCanonicalName()).append(" x").append(i);
            if (i < annotations.length - 1) {
                result.append(", ");
            }
        }
        return result;
    }

    private StringBuilder getConstructorParameteres(Constructor constructor) {
        StringBuilder result = new StringBuilder();
        Class[] parameteresTypes = constructor.getParameterTypes();
        Annotation[][] annotations = constructor.getParameterAnnotations();
        for (int i = 0; i < annotations.length; i++) {
            Annotation[] annotation = annotations[i];
            result.append(Arrays.stream(annotation).map(Annotation::toString).collect(Collectors.joining(",")));
            result.append(parameteresTypes[i].getCanonicalName()).append(" x").append(i);
            if (i < annotations.length - 1) {
                result.append(", ");
            }
        }
        return result;
    }

    private String getMainCode(Class<?> token) throws ImplerException {
        StringBuilder result = new StringBuilder();
        String className = token.getSimpleName() + "Impl";
        result.append("class ").append(className).append(" ").append(getDependenceType(token)).append(token.getCanonicalName()).append(" {\n\n");

        Constructor[] constructors = token.getDeclaredConstructors();
        boolean foundPublicConstuctor = false;
        for (Constructor constructor : constructors) {
            int modifiers = constructor.getModifiers();
            if (!Modifier.isPrivate(modifiers)) {
                foundPublicConstuctor = true;
            }
            if (Modifier.isAbstract(modifiers)) {
                modifiers ^= Modifier.ABSTRACT;
            }
            if (Modifier.isTransient(modifiers)) {
                modifiers ^= Modifier.TRANSIENT;
            }
            result.append(TAB).append(Modifier.toString(modifiers)).append(" ");
            result.append(mainToken.getSimpleName()).append("Impl").append('(');
            result.append(getConstructorParameteres(constructor));
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
        if (constructors.length != 0 && !foundPublicConstuctor) {
            throw new ImplerException("no public constructor in class");
        }

        Method[] methods = getMethods(token);
        for (Method method : methods) {
            result.append(TAB).append("@Override\n").append(TAB);
            int modifiers = method.getModifiers();
            modifiers &= ~Modifier.ABSTRACT;
            if (Modifier.isTransient(modifiers)) {
                modifiers ^= Modifier.TRANSIENT;
            }
            result.append(Modifier.toString(modifiers)).append(" ");
            result.append(method.getReturnType().getCanonicalName()).append(" ");

            result.append(method.getName()).append('(');
            result.append(getMethodParameteres(method));
            result.append(')');
            if (method.getExceptionTypes().length != 0) {
                result.append(" throws ");
            }
            result.append(Arrays.stream(method.getExceptionTypes()).map(Class::getName)
                    .collect(Collectors.joining(", "))).append(" {")
                    .append("\n").append(TAB).append(TAB);
            result.append("return ").append(defaultReturnValue(method.getReturnType()))
                    .append(";\n").append(TAB).append("}\n\n");
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

    @Override
    public void implement(Class<?> token, File root) throws ImplerException {
        if (token.getPackage() == null) {
            throw new ImplerException("Token is wrong - package is equal null");
        }
        File directoryPath = new File(root.getAbsolutePath() + File.separator + token.getPackage().getName().replace(".", File.separator) + File.separator);
        if (!directoryPath.exists()) {
            if (!directoryPath.mkdirs()) {
                throw new ImplerException("token's package doesn't exist, cannot create needed directories");
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
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws ImplerException {
        Class token = A.class;
        new Implementor().implement(token, new File("src"));
        //new Implementor().implement(A.class, new File("src"));
    }
}