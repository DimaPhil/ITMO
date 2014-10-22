#include "binary_string.h"
#include "main.h"

bool binary_string::is_binary(char* str)
{
    int i = 0;
    while (str[i] != 0) 
    {
        if (str[i] != '0' && str[i] != '1') 
            return false;
        i++;
    }
    return true;
}

int binary_string::to_int()
{
    int number = 0;
    for (int i = 0; begin[i] != '0'; i++)
        number = number * 2 + (begin[i] - '0');
    return number;
}

binary_string::binary_string()
{
    print_console("binary_string::binary_string()");
}

binary_string::binary_string(char *s) : my_string(s)
{
    print_console("binary_string::binary_string(char*)");
    if(!is_binary(begin)) 
        clear();
}

binary_string::binary_string(binary_string &s) : my_string(s)
{
    print_console("binary_string::binary_string(binary_string&)");
    if(!is_binary(begin)) {
        clear();
    }
}

binary_string::~binary_string()
{
    print_console("binary_string::~binary_string()");
}

void binary_string::invert()
{
    print_console("binary_string::invert()");
    for(int i = 0;i < len; i++)
        begin[i] = (begin[i] == '1') ? '0' : '1';
}

binary_string* binary_string::operator = (char *s)
{
    print_console("binary_string::operator = (char*)");
    if(is_binary(s)) {
        delete begin;
        begin = new char[len + 1];
        strcpy(begin, s);
        begin[len] = 0;
        return this;
    } else {
        clear();
    }
    return this;
}

bool binary_string::operator < (binary_string &b)
{
    print_console("binary_string::operator <");
    int this_value = this->to_int();
    int b_value = b.to_int();
    return this_value < b_value;
}

binary_string* binary_string::operator - (binary_string &b)
{
    print_console("binary_string::operator -");
}