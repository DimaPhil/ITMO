#include "my_string.h"
#include "main.h"

char* my_string::c_str(void)  //������� �� my_string char*
{
    return str;
}

int my_string::length(void) //������ ����� ������
{
  return len;
}

my_string::my_string() //������ �����������, �������� ������
{
    len = 0;
    str = new char[1];
    str[0] = 0;
    print_console("my_string::my_string()");
}

my_string::my_string(char *s) //����������� �� char* - ������� ����� ������ � �������� � ��� ���������� s
{
    len = strlen(s);
    str = new char[len + 1];
    for (int i = 0; i <= len; i++)
        str[i] = s[i];
    printf("my_string::my_string(char* %s)\n", s);
    //print_console("my_string::my_string(char *s)");
}
                 
my_string::my_string(char c) //����������� �� ������� - ������� ������ �� 2 ��������, �������� � ��� "c\0"
{
    len = 1;
    str = new char[2];
    str[0] = c;
    str[1] = 0;
    printf("my_string::my_string(char %c)\n", c);
    //print_console("my_string::my_string(char c)");
}

my_string& my_string::operator = (my_string &s)
{
    std::swap(str, s.str);
    printf("my_string::operator = (string %s)\n", str);
    //print_console("my_string::operator = (my_string &s)");
    return *this;
}

my_string::my_string(my_string &s) //����������� �� ������ my_string
{
    char *tmp = s.c_str();
    int len = strlen(tmp);
    str = new char[len + 1];
    for (int i = 0; i <= len; i++)
        str[i] = tmp[i];
    printf("my_string::my_string(%s)\n", s.c_str());
    //print_console("my_string::my_string(my_string &s)");
}

my_string::~my_string() //����������
{
    delete str;
    print_console("my_string::~my_string()");
}

void my_string::clear() //�������� ������
{
    delete str;
    len = 0;
    str = new char[1];
    str[0] = 0;
    print_console("my_string::clear()");
}