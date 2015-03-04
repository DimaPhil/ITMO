import info.kgeorgiy.java.advanced.implementor.Impler;
import info.kgeorgiy.java.advanced.implementor.ImplerException;

import java.io.*;
import java.lang.reflect.Method;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;

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

    private Method[] getMethods(Class token) {

    }

    private void writeMainCode(Writer writer, Class<?> token) throws ImplerException {
        try {
            StringBuilder result = new StringBuilder();
            String className = token.getSimpleName() + "Impl";
            result.append("class ").append(className).append(" ").append(getDependenceType(token)).append(token.getName()).append(" {");

            Method[] methods = getMethods(token);

            for (Method method : methods) {

            }

            writer.write(result.toString());
        } catch (IOException e) {
            System.out.println(e.toString());
            e.printStackTrace();
        }
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
        String fileName = directoryPath.toString() + token.getSimpleName() + "Impl.java";
        try (Writer writer = new OutputStreamWriter(new FileOutputStream(fileName), StandardCharsets.UTF_8)) {
            writer.write("package " + token.getPackage().getName() + ";\n\n");
            writeMainCode(writer, token);
        } catch (IOException e) {
            System.out.println("An error occured while writing to source file: " + e.toString());
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws ImplerException {
        if (args == null || args.length != 1 || args[0] == null) {
            System.out.println("Usage: java <class name>");
            return;
        }
        Class token = java.util.ArrayList.class;
        new Implementor().implement(token, new File("."));
    }
}