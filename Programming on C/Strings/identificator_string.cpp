#include "identificator_string.h"
#include "main.h"

bool identificator_string::is_identificator(char* s)
{
    int len = strlen(s);
    if (len == 0)
    {
        printf("Empty string is wrong name for identificator\n");
        return false;
    }

    if (!isalpha(s[0]))
    {
        printf("Wrong first symbol\n");
        return false;
    }

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(s[i]) && !isdigit(s[i]) && s[i] != '_')
        {
            printf("Wrong name for identificator\n");
            return false;
        }
    }

    return true;
}

identificator_string::identificator_string() : my_string()
{
    printf("identificator_string::identificator_string()\n");
}

identificator_string::identificator_string(char c): my_string(c)
{
    printf("identificator_string::identificator_string(char %c)\n", c);
    if (!is_identificator(str))
        clear();
}

identificator_string::identificator_string(char *s) : my_string(s)
{
    printf("identificator_string::identificator_string(char* %s)\n", s);
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
    printf("identificator_string::~identificator_string()\n");
}

int identificator_string::find_last(char c) 
{
    printf("my_string::find_last(my_string %s, char %c)\n", str, c);
    int ans = -1;
    for (int i = 0; str[i] != 0; i++)
        if (str[i] == c)
            ans = i;
    return ans;
}

identificator_string* identificator_string::operator = (char *s)
{
    printf("identificator_string::operator = (char* %s)\n", s);
    delete str;
    len = strlen(s);
    str = new char[len + 1];
    for (int i = 0; i <= len; i++)
        str[i] = s[i];
    if (!is_identificator(str))
    {
        printf("source is not identificator\n");
        clear();
    }
    return this;
}

char identificator_string::operator [] (int i)
{
    printf("identificator_string::operator [] (%d)\n", i);
    if (i < 0 || i >= (int)strlen(str)) 
    {
        printf("Out of bounds");
        return 0;
    }
    return str[i];
}

bool identificator_string::operator < (identificator_string &id)
{
    printf("identificator_string::operator < (identificator_string* %s)\n", id.c_str());
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