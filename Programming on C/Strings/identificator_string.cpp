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
    print_console("identificator_string::identificator_string(char c)");
    if (!is_identificator(begin))
        clear();
}

identificator_string::identificator_string(char *s) : my_string(s)
{
    print_console("identificator_string::identificator_string(char *s)");
    if (!is_identificator(s))
        clear();
}

identificator_string::identificator_string(identificator_string &s) : my_string(s)
{
    if (!is_identificator(begin))
        clear();
}

identificator_string::~identificator_string()
{
    print_console("identificator_string::~identificator_string()");
}

identificator_string* identificator_string::operator = (char *s)
{
    print_console("identificator_string::operator = (char *s)");
    delete begin;
    len = strlen(s);
    begin = new char[len + 1];
    strcpy(begin, s);
    begin[len] = 0;
    if (!is_identificator(begin))
    {
        print_console("source is not identificator");
        clear();
    }
    return this;
}

char identificator_string::operator [] (int i)
{
    print_console("identificator_string::operator [] (int i)");
    if (i < 0 || i >= (int)strlen(begin)) 
    {
        print_console("Out of bounds");
        return 0;
    }
    return begin[i];
}

bool identificator_string::operator < (identificator_string &id)
{
    print_console("identificator_string::operator < (identificator_string *id)");
    int this_length = len;
    int id_length = id.len;
    for (int i = 0; i < std::min(len, id.len); i++) 
    {
        if (begin[i] < id.begin[i])
            return true;
        if (begin[i] > id.begin[i])
            return false;
    }
    if (this_length < id_length)
        return true;
    if (this_length > id_length)
        return false;
    return false;
}