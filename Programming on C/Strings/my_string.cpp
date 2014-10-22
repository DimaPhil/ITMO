#include "my_string.h"
#include <string.h>
#include "main.h"

char* my_string::c_str(void)  //������� �� my_string char*
{
  return begin;
}

int my_string::length(void) //������ ����� ������
{
  return len;
}

my_string::my_string() //������ �����������, �������� ������
{
    len = 0;
    begin = new char[1];
    begin[0] = 0;
    print_console("my_string::my_string()");
}

my_string::my_string(char *s) //����������� �� char* - ������� ����� ������ � �������� � ��� ���������� s
{
    len = strlen(s);
    begin = new char[len + 1];
    strcpy(begin, s);
    begin[len] = 0;
    printf("%s\n", begin);
    print_console("my_string::my_string(char *s)");
}

my_string::my_string(char c) //����������� �� ������� - ������� ������ �� 2 ��������, �������� � ��� "c\0"
{
    len = 1;
    begin = new char[2];
    begin[0] = c;
    begin[1] = 0;
    print_console("my_string::my_string(char c)");
}

my_string::my_string(my_string &s) //����������� �� ������ my_string
{
    char *tmp = s.c_str();
    *this = my_string(tmp);
    print_console("my_string::my_string(my_string &from)");
}

my_string::~my_string() //����������
{
    delete begin;
    print_console("my_string::~my_string()");
}

void my_string::clear() //�������� ������
{
    delete begin;
    len = 0;
    begin = new char[1];
    begin[0] = 0;
    print_console("my_string::clear()");
}