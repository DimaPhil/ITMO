#ifndef BINARYSTRING_H
#define BINARYSTRING_H
#include "my_string.h"

class binary_string : public my_string
{
    //�������� ��������� �������
    bool is_binary(char*);
    int to_int();
public:
    //������������ - ������, �� ��������� �� char, �� ������ ������
    binary_string();
    binary_string(char*);
    binary_string(binary_string&);
    
    //����������
    ~binary_string();
    
    //�������� ��������� �������
    void invert();
    bool operator < (binary_string&);
    
    //��������������� ���������� ��� �������� ������
    binary_string* operator = (char*);
    binary_string* operator - (binary_string&);
};
#endif