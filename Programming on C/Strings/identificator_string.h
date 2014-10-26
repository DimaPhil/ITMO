#ifndef IDENTIFICATORSTRING_H
#define IDENTIFICATORSTRING_H

#include "my_string.h"

class identificator_string: public my_string
{
public:
    identificator_string();
    identificator_string(char*);
    identificator_string(char);
    identificator_string(identificator_string&);

    ~identificator_string();

    int find_last(char c);

    identificator_string* operator = (char*);
    bool operator < (identificator_string&);
    char operator [](int);
protected:
    bool is_identificator(char* a);
};
#endif