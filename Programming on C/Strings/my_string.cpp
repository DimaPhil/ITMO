#include "my_string.h"
#include <string.h>
#include "main.h"

char* my_string::c_str(void)  //сделать из my_string char*
{
  return begin;
}

int my_string::length(void) //узнать длину строки
{
  return len;
}

my_string::my_string() //пустой конструктор, создание строки
{
    len = 0;
    begin = new char[1];
    begin[0] = 0;
    print_console("my_string::my_string()");
}

my_string::my_string(char *s) //конструктор от char* - создаем новую строку и копируем в нее содержимое s
{
    len = strlen(s);
    begin = new char[len + 1];
    strcpy(begin, s);
    begin[len] = 0;
    printf("%s\n", begin);
    print_console("my_string::my_string(char *s)");
}

my_string::my_string(char c) //конструктор от символа - создали строку из 2 символос, записали в нее "c\0"
{
    len = 1;
    begin = new char[2];
    begin[0] = c;
    begin[1] = 0;
    print_console("my_string::my_string(char c)");
}

my_string::my_string(my_string &s) //конструктор от другой my_string
{
    char *tmp = s.c_str();
    *this = my_string(tmp);
    print_console("my_string::my_string(my_string &from)");
}

my_string::~my_string() //деструктор
{
    delete begin;
    print_console("my_string::~my_string()");
}

void my_string::clear() //очищение строки
{
    delete begin;
    len = 0;
    begin = new char[1];
    begin[0] = 0;
    print_console("my_string::clear()");
}