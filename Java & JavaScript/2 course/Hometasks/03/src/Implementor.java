import info.kgeorgiy.java.advanced.implementor.Impler;
import info.kgeorgiy.java.advanced.implementor.ImplerException;

import java.io.*;
import java.lang.annotation.Annotation;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class Implementor implements Impler {
    private HashMap<Class<?>, String> returnValues = new HashMap<Class<?>, String>();
    private final String TAB = "    ";

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
            //System.out.println(e.toString());
            return method;
        }
    };

    private Method[] getMethods(Class token) {
        ArrayList<Method> methods = Arrays.stream(token.getDeclaredMethods()).filter(isAbstractPredicate)
                .collect(ArrayList::new, ArrayList::add, ArrayList::addAll);
        ArrayList<Method> overridedMethods = Arrays.stream(token.getMethods()).filter(isAbstractPredicate.negate())
                .collect(ArrayList::new, ArrayList::add, ArrayList::addAll);

        ArrayDeque<Class> classesQueue = new ArrayDeque<Class>();
        classesQueue.push(token);
        while (!classesQueue.isEmpty()) {
            Class currentClass = classesQueue.pop();
            if (currentClass.getSuperclass() != null) {
                classesQueue.addFirst(currentClass.getSuperclass());
            }
            if (currentClass.getInterfaces().length > 0) {
                Arrays.stream(currentClass.getInterfaces()).forEach(classesQueue::addLast);
            }
            Arrays.stream(currentClass.getMethods()).filter(isAbstractPredicate).map(getSuperClassMethod).filter(
                    method -> !Modifier.isFinal(method.getModifiers()) && !overridedMethods.contains(method) && !methods.contains(method)
            ).forEach(methods::add);
            Arrays.stream(currentClass.getMethods()).filter(isAbstractPredicate.negate()).map(getSuperClassMethod).forEach(overridedMethods::add);
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

    private String getMainCode(Class<?> token) {
        StringBuilder result = new StringBuilder();
        String className = token.getSimpleName() + "Impl";
        result.append("class ").append(className).append(" ").append(getDependenceType(token)).append(token.getName()).append(" {\n\n");

        Method[] methods = getMethods(token);
        for (Method method : methods) {
            result.append(TAB).append("@Override\n").append(TAB);
            for (Annotation annotation : token.getDeclaredAnnotations()) {
                result.append(annotation.toString()).append("\n").append(TAB);
            }
            result.append(Modifier.toString(method.getModifiers())).append(" ");
            result.append(method.getReturnType().getCanonicalName()).append(" ");

            //writing parameteres
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
            if (!Modifier.isAbstract(inner.getModifiers())) continue;
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
        File directoryPath = new File(root.getAbsolutePath() + '/' + token.getPackage().getName().replace('.', '/') + '/');
        if (!directoryPath.exists()) {
            //trying to create directories
            if (!directoryPath.mkdirs()) {
                throw new ImplerException("token's package doesn't exists, cannot create needed directories");
            }
        }
        String fileName = directoryPath.toString() + "/" + token.getSimpleName() + "Impl.java";
        try (Writer writer = new OutputStreamWriter(new FileOutputStream(fileName), StandardCharsets.UTF_8)) {
            writer.write("package " + token.getPackage().getName() + ";\n\n");
            initReturnValues();
            writer.write(getMainCode(token));
        } catch (IOException e) {
            System.out.println("An error occured while writing to source file: " + e.toString());
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws ImplerException {
        /*if (args == null || args.length != 1 || args[0] == null) {
            System.out.println("Usage: java <class name>");
            return;
        }*/
        Class token = java.util.ArrayList.class;
        new Implementor().implement(token, new File(""));
    }
}