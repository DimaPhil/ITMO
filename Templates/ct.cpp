#include <bits/stdc++.h>
#include <io.h>
#include <direct.h>
#include <windows.h>

const int MAX_PATH_SIZE = 1000;
const int MAX_TEMPLATE_NAME_SIZE = 100;
const int specialTypesLength = 4;
const int languagesLength = 3;

bool _delete_directories = false;
std::string specialTypes[] = {"no_files", "multitest", "multitest_no_files", "tc"};
std::string languages[] = {"cpp", "java", "py"};

bool isSpecialType(const std::string &type) {
    int len = specialTypesLength;
    return find(specialTypes, 
                specialTypes + len,
                type
                ) != specialTypes + len;
}

bool isLanguage(const std::string &language) {
    int len = languagesLength;
    return find(languages, 
                languages + len, 
                language) != languages + len;
}

bool fileExists(const char *fileName) {
    return access(fileName, 0) != -1;
}

void createDirectory(const char *directoryName) {
    if (fileExists(directoryName)) {
        if (_delete_directories) {
            //delete directory
        } else {
            fprintf(stderr, "Cannot create problem %s: directory with this name is already exists. Try to use -del\n", directoryName);
        }
        return;
    }
    if (_mkdir(directoryName)) {
        fprintf(stderr, "Some problems has occured while creating directory with problem %s\n", directoryName);
        return;
    }
}

void createProblem(const char *problemName, const std::string &templateType, const std::string &language) {
    createDirectory(problemName);

    std::string templatePath = "C:\\Users\\DimaPhil\\Documents\\Programming\\_DimaPhil\\ITMO\\Templates\\";
    std::string templateName = (language == "java" ? "Main" : "main") + \
                               (templateType.size() ? "_" + templateType : "") + \
                               "." + language;
    templatePath += templateName;
    if (!fileExists(templatePath.c_str())) {
        fprintf(stderr, "Path to template file is wrong - just change it");
        rmdir(problemName);
        return;
    }

    TCHAR buffer[MAX_PATH_SIZE]; 
    GetCurrentDirectory(sizeof(buffer), buffer);
    std::string needPath = (std::string)buffer + \
                           "\\" + (std::string)problemName + \
                           "\\" + (language == "java" ? "Main" : "main") + \
                           (templateType.size() ? "_" + templateType : "") + \
                           "." + language;
    
    CopyFile(templatePath.c_str(), 
             needPath.c_str(),
             false
             );
}

int main(int argc, char* args[]) {
    if (argc > 1 && !strcmp(args[1], "create")) {
        if (argc == 2) {
            fprintf(stderr, "Enter what you want to create");
        } else if (!strcmp(args[2], "problem")) {
            if (argc == 3) {
                fprintf(stderr, "You need to enter name(s) of problem(s)\n");
                return 0;                               
            }

            std::vector <std::string> keys;
            for (int idx = 3; idx < argc; idx++)
                if (args[idx][0] == '-')
                    keys.push_back(((std::string)args[idx]).erase(0, 1));
            
            std::string specialType = "";
            std::string language = "cpp";
            for (size_t it = 0; it < keys.size(); ++it) {
                if (keys[it] == "del")
                    _delete_directories = true;
                else if (isSpecialType(keys[it]))
                    specialType = keys[it];
                else if (isLanguage(keys[it]))
                    language = keys[it];
                else {
                    fprintf(stderr, "Unknown key %s - can't parse expression\n", keys[it].c_str());
                    return 0;
                }
            }

            int startProblemIdx = 3 + keys.size();
            for (int idx = startProblemIdx; idx < argc; ++idx)
                createProblem(args[idx], specialType, language);
        } else if (!strcmp(args[2], "directory")) {
            if (argc == 3) {
                fprintf(stderr, "You need to enter name(s) of directory(ies)\n");
                return 0;
            }

            //Maybe, need change this code to std::vector <std::string> keys, like the code from above?
            int startDirectoryIdx = 3;
            if (!strcmp(args[startDirectoryIdx], "-d")) {
                ++startDirectoryIdx;
                _delete_directories = true;
            }

            for (int idx = startDirectoryIdx; idx < argc; ++idx)
                createDirectory(args[idx]);
        } else {
            fprintf(stderr, "Unknown word %s, can't create\n", args[2]); 
        }
    }
    return 0;
}
                                        