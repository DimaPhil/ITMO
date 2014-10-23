#include "identificator_string.h"
#include "main.h"

bool identificator_string::is_identificator(char* s)
{
    int len = strlen(s);
    if (len == 0)
    {
        print_console("empty string is wrong name for identificator");
        return false;
    }

    if (len == 1 && s[0] == '_')
    {
        print_console("_ is wrong name for identificator");
        return false;
    }

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(s[i]) && !isdigit(s[i]) && s[i] != '_')
        {
            print_console("wrong name for identificator");
            return false;
        }
    }

    return true;
}

identificator_string::identificator_string() : my_string()
{
    print_console("identificator_string::identificator_string()");
}

identificator_string::identificator_string(char c): my_string(c)
{
    printf("identificator_string::identificator_string(char %c)", c);
    if (!is_identificator(str))
        clear();
}

identificator_string::identificator_string(char *s) : my_string(s)
{
    printf("identificator_string::identificator_string(char* %s)", s);
    if (!is_identificator(s))
        clear();
}

identificator_string::identificator_string(identificator_string &s) : my_string(s)
{
    if (!is_identificator(str))
        clear();
}

identificator_string::~identificator_string()
{
    print_console("identificator_string::~identificator_string()");
}

identificator_string* identificator_string::operator = (char *s)
{
    printf("identificator_string::operator = (char* %s)", s);
    delete str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    str[len] = 0;
    if (!is_identificator(str))
    {
        print_console("source is not identificator");
        clear();
    }
    return this;
}

char identificator_string::operator [] (int i)
{
    printf("identificator_string::operator [] (%d)", i);
    if (i < 0 || i >= (int)strlen(str)) 
    {
        print_console("Out of bounds");
        return 0;
    }
    return str[i];
}

bool identificator_string::operator < (identificator_string &id)
{
    printf("identificator_string::operator < (identificator_string* %s)", id.c_str());
    int this_length = len;
    int id_length = id.len;
    for (int i = 0; i < std::min(len, id.len); i++) 
    {
        if (str[i] < id.str[i])
            return true;
        if (str[i] > id.str[i])
            return false;
    }
    if (this_length < id_length)
        return true;
    if (this_length > id_length)
        return false;
    return false;
}