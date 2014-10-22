#ifndef BINARYSTRING_H
#define BINARYSTRING_H
#include "my_string.h"

class binary_string : public my_string
{
    //описание приватных функций
    bool is_binary(char*);
    int to_int();
public:
    //конструкторы - пустой, от указателя на char, от другой строки
    binary_string();
    binary_string(char*);
    binary_string(binary_string&);
    
    //деструктор
    ~binary_string();
    
    //описание публичных функций
    void invert();
    bool operator < (binary_string&);
    
    //переопределение операторов для бинарной строки
    binary_string* operator = (char*);
    binary_string* operator - (binary_string&);
};
#endif