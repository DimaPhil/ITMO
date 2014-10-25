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
    printf("my_string::my_string()");
    len = 0;
    str = new char[1];
    str[0] = 0;
}

my_string::my_string(char *s) //����������� �� char* - ������� ����� ������ � �������� � ��� ���������� s
{
    printf("my_string::my_string(char* %s)\n", s);
    len = strlen(s);
    str = new char[len + 1];
    for (int i = 0; i <= len; i++)
        str[i] = s[i];
}
                 
my_string::my_string(char c) //����������� �� ������� - ������� ������ �� 2 ��������, �������� � ��� "c\0"
{
    printf("my_string::my_string(char %c)\n", c);
    len = 1;
    str = new char[2];
    str[0] = c;
    str[1] = 0;
}

my_string& my_string::operator = (my_string &s)
{
    printf("my_string::operator = (string %s)\n", str);
    std::swap(str, s.str);
    return *this;
}

my_string::my_string(my_string &s) //����������� �� ������ my_string
{
    printf("my_string::my_string(%s)\n", s.c_str());
    char *tmp = s.c_str();
    int len = strlen(tmp);
    str = new char[len + 1];
    for (int i = 0; i <= len; i++)
        str[i] = tmp[i];
}

my_string::~my_string() //����������
{
    printf("my_string::~my_string()");
    delete str;
}

void my_string::clear() //�������� ������
{
    printf("my_string::clear()");
    delete str;
    len = 0;
    str = new char[1];
    str[0] = 0;
}