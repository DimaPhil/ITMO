#ifndef MYSTRING_H
#define MYSTRING_H

#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <algorithm>

class my_string
{
protected:
    char *str;
    int len;
public:
    //конструкторы
    my_string();
    my_string(char*);
    my_string(char);
    my_string(my_string& str);

    //деструктор
    ~my_string();

    char* c_str();
    void clear();
    int length();

    my_string& operator = (my_string &s);
};
#endif