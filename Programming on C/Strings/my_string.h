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
    char *begin;
    int len;
public:
    //конструкторы
    my_string();
    my_string(char*);
    my_string(char);
    my_string(my_string& str);

    //декструктор
    ~my_string();

    char* c_str();
    void clear();
    int length();
};
#endif