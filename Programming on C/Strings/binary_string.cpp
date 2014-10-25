#include "binary_string.h"
#include "main.h"

bool binary_string::is_binary(char* str)
{
    for (int i = 0; str[i] != 0; i++)
        if (str[i] != '0' && str[i] != '1') 
            return false;
    return true;
}

int binary_string::to_int()
{
    int number = 0;
    bool sign = str[0] == '1';
    if (sign)
        invert();
    int power = 1;
    for (int i = 31; i > 0; i--)
        number += (str[i] - '0') * power, power *= 2;
    if (sign)
        number = -(number + 1), invert();
    return number;
}

binary_string::binary_string()
{
    printf("binary_string::binary_string()");
}

binary_string::binary_string(char *s) : my_string(s)
{
    printf("binary_string::binary_string(char* %s)", s);
    if (!is_binary(str)) 
        clear();
}

binary_string::binary_string(binary_string &s) : my_string(s)
{
    printf("binary_string::binary_string(binary_string& %s)", s.c_str());
    if (!is_binary(str)) {
        clear();
    }
}

binary_string::~binary_string()
{
    printf("binary_string::~binary_string()");
}

void binary_string::invert()
{
    printf("binary_string::invert()");
    for(int i = 0;i < len; i++)
        str[i] = (str[i] == '1') ? '0' : '1';
}

binary_string* binary_string::operator = (char *s)
{
    printf("binary_string::operator = (char* %s)", s);
    if(is_binary(s)) {
        delete str;
        str = new char[len + 1];
        for (int i = 0; i <= len; i++)
            str[i] = s[i];
        return this;
    } else {
        clear();
    }
    return this;
}

bool binary_string::operator < (binary_string &b)
{
    printf("binary_string::operator < (binary_string& %s)", b.c_str());
    int this_value = this->to_int();
    int b_value = b.to_int();
    return this_value < b_value;
}

binary_string* binary_string::operator - (binary_string &b)
{
    printf("binary_string::operator - (binary_string& %s)\n", b.c_str());
    int this_value = this->to_int();
    int b_value = b.to_int();

    int x = this_value - b_value;
    
    str = new char[33];
    bool sign = x >= 0;
    x = abs(x);
    int i = 1;
    while (x > 0) {
        int digit = x % 2;
        str[i++] = char(digit + '0');
        x /= 2;
    }
    str[32] = 0;
    std::reverse(str + 1, str + 32);
    if (!sign) {
        binary_string::invert();
        int i = 31;
        while (i > 0 && str[i] == '1')
            str[i] = '0', i--;
        str[i] = '1';
    }
    return this;
}