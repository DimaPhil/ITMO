package ru.ifmo.ctddev.filippov.antlr;

import java.util.ArrayList;

/**
 * Created by dmitry on 11.05.16.
 */
public class IOWriter {
    public static String getMapping(String functionName, ArrayList<String> args) {
        if (functionName.equals("write") || functionName.equals("writeln")) {
            String code = "std::cout << " + String.join(" << ", args);
            if (functionName.equals("writeln")) {
                if (args.isEmpty()) {
                    code += "std::endl";
                } else {
                    code += " << std::endl";
                }
            }
            return code;
        } else if (functionName.equals("read") || functionName.equals("readln")) {
            return "std::cin >> " + String.join(" >> ", args);
        } else {
            return functionName + "(" + String.join("", args) + ")";
        }
    }
}
