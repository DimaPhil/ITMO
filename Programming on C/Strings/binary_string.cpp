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
    printf("binary_string::binary_string()\n");
}

binary_string::binary_string(char *s)
{
    printf("binary_string::binary_string(char* %s)\n", s);
    if (!is_binary(s))
    {
        clear();
        return;
    }
    str = new char[33];
    len = 32;
    str[32] = 0;
    int len = strlen(s);
    int now = 31;
    for (int i = len - 1; i >= 0; i--)
        str[now--] = s[i];
    for (int i = now; i >= 0; i--)
        str[i] = '0';
}

binary_string::binary_string(binary_string &s) : my_string(s)
{
    printf("binary_string::binary_string(binary_string& %s)\n", s.c_str());
    if (!is_binary(str)) {
        clear();
    }
}

binary_string::~binary_string()
{
    printf("binary_string::~binary_string()\n");
}

void binary_string::invert()
{
    printf("binary_string::invert()\n");
    for(int i = 0;i < len; i++)
        str[i] = (str[i] == '1') ? '0' : '1';
}

int binary_string::sign()
{
    printf("binary_string::sign()\n");
    if (str[0] == '1')
        return -1;
    bool is_zero = true;
    for (int i = 0; str[i] != 0; i++)
        if (str[i] == '1')
            is_zero = false;
    return is_zero ? 0 : 1;
}

binary_string* binary_string::operator = (char *s)
{
    printf("binary_string::operator = (char* %s)\n", s);
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
    printf("binary_string::operator < (binary_string& %s)\n", b.c_str());
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