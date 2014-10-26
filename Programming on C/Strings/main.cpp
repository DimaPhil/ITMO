#include <windows.h>
#include <stdlib.h>
#include <string>
#include <assert.h>

#include "main.h"
#include "my_string.h"
#include "identificator_string.h"
#include "binary_string.h"

using namespace std;
 
const int MAX_ITEMS_LENGTH = 10;
const int MAX_NUMBER_OF_STRINGS = 6;

const int itemsLength = 9; //количество item-ов
const string items[] = {"     1. Initialization",                //0
                        "         1.1. Number of elements",      //1
                        "         1.2. Initial value",           //2
                        "     2. Testing",                       //3
                        "         2.1. String",                  //4
                        "         2.2. Identificator string",    //5
                        "         2.3. Binary number",           //6
                        "         2.4. Operand",                 //7
                        "     3. Exit"                           //8
                        }; //названия item-ов меню
int chosenIndex; //индекс выбранного item-а

HANDLE hStdin, hStdout; // для дескрипторов стандартного ввода и вывода
bool bRead = true; // для цикла обработки событий

void print_console(const char *s, ConsoleColor color) 
{
    SetConsoleTextAttribute(hStdout, (WORD)((Black << 4) | color));
    printf("%s\n", s);
    SetConsoleTextAttribute(hStdout, (WORD)((Black << 4) | White));
}

void print_console_no_enter(const char *s, ConsoleColor color) 
{
    SetConsoleTextAttribute(hStdout, (WORD)((Black << 4) | color));
    printf("%s", s);
    SetConsoleTextAttribute(hStdout, (WORD)((Black << 4) | White));
}

const char* TYPES[] = {"String", "Identificator", "Binary string"};

bool was_number_of_elements_called = false;
int elements_number = 0;
my_string *strings;
int *types;

bool was_testing_called = false;
bool *changed;
bool *initialized;
int testing_type = 0;
int testing_id = 0;

void wait_for_enter()
{
    print_console("Press Enter to exit");
    getchar();
    getchar();
}

void printStrings()
{
    if (was_number_of_elements_called)
    {
        for (int i = 0; i < elements_number; i++)
        {
            printf("%d. ", i + 1);
            if (!initialized[i]) {
                puts("");
                continue;
            }
            if (changed[i])
            {
                print_console_no_enter("Type: ", Green);
                print_console_no_enter(TYPES[types[i]], Green);
                print_console_no_enter(". String: ", Green);
                print_console(strings[i].c_str(), Green);
            }
            else
            {
                print_console_no_enter("Type: ", White);
                print_console_no_enter(TYPES[types[i]], White);
                print_console_no_enter(". String: ", White);
                print_console(strings[i].c_str(), White);
            }
        }
    }
    puts("\n");
}

int get_type(char *s) 
{
    identificator_string str(s);
    if (str.length() != 0)
        return 1;
    binary_string str2(s);
    if (str2.length() != 0)
        return 2;
    return 0;
}

void processItem(int chosenItem)
{
    assert(chosenItem != 0 && chosenItem != 3); //not Initialization and not Testing
    system("CLS");
    if (chosenItem == 8) //Exit
        exit(0);
    printStrings();
    if (chosenItem == 1) //Number of elements
    {
        if (was_number_of_elements_called) 
        {
            print_console("You can't choose this menu item anymore");
            wait_for_enter();
            return;
        }
        print_console("Please enter the number of elements - it should be from 1 to 6:");
        scanf("%d", &elements_number);
        if (0 >= elements_number || elements_number > 6)
        {
            print_console("Wrong number of elements");
            wait_for_enter();
            return;
        }

        strings = new my_string[elements_number];
        types = new int[elements_number];
        changed = new bool[elements_number];
        initialized = new bool[elements_number];
        for (int i = 0; i < elements_number; i++)
            changed[i] = initialized[i] = false;

        was_number_of_elements_called = true;
        wait_for_enter();
    }
    if (chosenItem == 2) //Initial value
    {
        if (!was_number_of_elements_called)
        {
            print_console("Number of elements wasn't set");
            wait_for_enter();
            return;
        }

        print_console("Enter the number of element:");
        int index;
        scanf("%d", &index);
        if (0 >= index || index > elements_number)
        {
            print_console("Out of bounds");
            wait_for_enter();
            return;
        }
        --index;

        print_console("Enter the type of string - string, identificator or binary:");
        char type[20];
        scanf("%s", type);
        if (strcmp(type, "string") && strcmp(type, "identificator") && strcmp(type, "binary"))
        {
            print_console("Wrong type of string");
            wait_for_enter();
            return;
        }

        print_console("Enter value of string");
        char value[50];
        scanf("%s", value);
        initialized[index] = true;
        if (!strcmp(type, "string"))
        {
            my_string tt(value);
            strings[index] = tt;
            types[index] = 0;
        }
        if (!strcmp(type, "identificator"))
        {
            identificator_string tt(value);
            strings[index] = tt;
            types[index] = 1;
        }
        if (!strcmp(type, "binary"))
        {
            binary_string tt(value);
            strings[index] = tt;
            types[index] = 2;
        }
        wait_for_enter();
    }
    if (chosenItem == 4) //Simple string
    {
        print_console("Enter one number - number of method:");
        print_console("1. length()");
        print_console("2. operator []");
        int id;
        scanf("%d", &id);
        if (id < 1 || id > 2)
        {
            print_console("Wrong id");
            wait_for_enter();
            return;
        }
        testing_type = 0;
        testing_id = id;
        was_testing_called = true;
    }
    if (chosenItem == 5) //Identificator
    {
        print_console("Enter one number - number of method:");
        print_console("1. length()");
        print_console("2. operator []");
        print_console("3. find position of last symbol");
        print_console("4. operator =");
        print_console("5. operator <");
        int id;
        scanf("%d", &id);
        if (id < 1 || id > 5)
        {
            print_console("Wrong id");
            wait_for_enter();
            return;
        }
        testing_type = 1;
        testing_id = id;
        was_testing_called = true;
    }
    if (chosenItem == 6) //Binary string
    {
        print_console("Enter one number - number of method:");
        print_console("1. sign()");
        print_console("2. operator []");
        print_console("3. operator <");
        print_console("4. operator -");
        int id;
        scanf("%d", &id);
        if (id < 1 || id > 4)
        {
            print_console("Wrong id");
            wait_for_enter();
            return;
        }
        testing_type = 2;
        testing_id = id;
        was_testing_called = true;
    }
    if (chosenItem == 7) //Operand
    {
        if (!was_testing_called) 
        {
            print_console("You didn't choose type of string");
            wait_for_enter();
            return;
        }
        if (testing_type == 0)
        {
            if (testing_id == 1)
            {
                print_console("String. Method length(). Enter id of string:");
                int id;
                scanf("%d", &id);
                --id;
                if (0 > id || id >= elements_number)
                {
                    print_console("Wrong id - out of bounds");
                    wait_for_enter();
                    return;
                }
                if (types[id] != testing_type)
                {
                    print_console("Wrong type of string was chosen");
                    wait_for_enter();
                    return;
                }
                printf("length = %d\n", strings[id].length());
            }
            if (testing_id == 2)
            {
                print_console("String. Operator []. Enter id of string:");
                int id;
                scanf("%d", &id);
                --id;
                if (0 > id || id >= elements_number)
                {
                    print_console("Wrong id - out of bounds");
                    wait_for_enter();
                    return;
                }
                if (types[id] != testing_type)
                {
                    print_console("Wrong type of string was chosen");
                    wait_for_enter();
                    return;
                }
                print_console("Enter index of string:");
                int index;
                scanf("%d", &index);
                printf("%c\n", strings[id][index]);
            }
            wait_for_enter();
        }
        if (testing_type == 1)
        {
            if (testing_id == 1)
            {
                print_console("Identificator string. Method length(). Enter id of string:");
                int id;
                scanf("%d", &id);
                --id;
                if (0 > id || id >= elements_number)
                {
                    print_console("Wrong id - out of bounds");
                    wait_for_enter();
                    return;
                }
                if (types[id] != testing_type)
                {
                    print_console("Wrong type of string was chosen");
                    wait_for_enter();
                    return;
                }
                printf("length = %d\n", strings[id].length());
            }
            if (testing_id == 2)
            {
                print_console("Identificator string. Operator []. Enter id of string:");
                int id;
                scanf("%d", &id);
                --id;
                if (0 > id || id >= elements_number)
                {
                    print_console("Wrong id - out of bounds");
                    wait_for_enter();
                    return;
                }
                if (types[id] != testing_type)
                {
                    print_console("Wrong type of string was chosen");
                    wait_for_enter();
                    return;
                }
                print_console("Enter index of string:");
                int index;
                scanf("%d", &index);
                printf("%s\n", strings[id].c_str());
                printf("%c\n", strings[id][index]);
            }
            if (testing_id == 3)
            {
                print_console("Identificator string. Method \"find last position of symbol\". Enter id of string:");
                int id;
                scanf("%d", &id);
                --id;
                if (0 > id || id >= elements_number)
                {
                    print_console("Wrong id - out of bounds");
                    wait_for_enter();
                    return;
                }
                if (types[id] != testing_type)
                {
                    print_console("Wrong type of string was chosen");
                    wait_for_enter();
                    return;
                }
                print_console("Enter symbol:");
                char c;
                while (scanf("%c", &c) >= 1)
                {
                    if (c != 13 && c != 10 && c != 32)
                        break;
                }
                printf("Last symbol %c is at position %d\n", c, identificator_string(strings[id].c_str()).find_last(c));
            }
            if (testing_id == 4)
            {
                print_console("Identificator string. Operator =. Enter id of string:");
                int id;
                scanf("%d", &id);
                --id;
                if (0 > id || id >= elements_number)
                {
                    print_console("Wrong id - out of bounds");
                    wait_for_enter();
                    return;
                }
                if (types[id] != testing_type)
                {
                    print_console("Wrong type of string was chosen");
                    wait_for_enter();
                    return;
                }
                print_console("Enter string:");
                char str[50];
                scanf("%s", str);
                if (get_type(str) != types[id])
                {
                    print_console("String has wrong type");
                    wait_for_enter();
                    return;
                }
                my_string A(str);
                strings[id] = A;
                changed[id] = true;
            }
            if (testing_id == 5)
            {
                print_console("Identificator string. Operator <. Enter id of string:");
                int id;
                scanf("%d", &id);
                --id;
                if (0 > id || id >= elements_number)
                {
                    print_console("Wrong id - out of bounds");
                    wait_for_enter();
                    return;
                }
                if (types[id] != testing_type)
                {
                    print_console("Wrong type of string was chosen");
                    wait_for_enter();
                    return;
                }
                print_console("Enter string:");
                char str[50];
                scanf("%s", str);
                if (get_type(str) != types[id])
                {
                    print_console("String has wrong type");
                    wait_for_enter();
                    return;
                }
                identificator_string A(strings[id].c_str());
                identificator_string B(str);
                printf("Is %s less than %s? %s\n", strings[id].c_str(), str, A < B ? "Yes" : "No");
            }
            wait_for_enter();
        }
        if (testing_type == 2)
        {
            if (testing_id == 1)
            {
                print_console("Binary string. Method sign(). Enter id of string:");
                int id;
                scanf("%d", &id);
                --id;
                if (0 > id || id >= elements_number)
                {
                    print_console("Wrong id - out of bounds");
                    wait_for_enter();
                    return;
                }
                if (types[id] != testing_type)
                {
                    print_console("Wrong type of string was chosen");
                    wait_for_enter();
                    return;
                }
                printf("sign = %d\n", binary_string(strings[id].c_str()).sign());
            }
            if (testing_id == 2)
            {
                print_console("Binary string. Operator []. Enter id of string:");
                int id;
                scanf("%d", &id);
                --id;
                if (0 > id || id >= elements_number)
                {
                    print_console("Wrong id - out of bounds");
                    wait_for_enter();
                    return;
                }
                if (types[id] != testing_type)
                {
                    print_console("Wrong type of string was chosen");
                    wait_for_enter();
                    return;
                }
                print_console("Enter index of string:");
                int index;
                scanf("%d", &index);
                printf("%c\n", strings[id][index]);
            }
            if (testing_id == 3)
            {
                print_console("Binary string. Operator <. Enter id of string:");
                int id;
                scanf("%d", &id);
                --id;
                if (0 > id || id >= elements_number)
                {
                    print_console("Wrong id - out of bounds");
                    wait_for_enter();
                    return;
                }
                if (types[id] != testing_type)
                {
                    print_console("Wrong type of string was chosen");
                    wait_for_enter();
                    return;
                }
                print_console("Enter string:");
                char str[50];
                scanf("%s", str);
                binary_string A(strings[id].c_str());
                binary_string B(str);
                printf("Is %s less than %s? %s\n", A.c_str(), B.c_str(), A < B ? "Yes" : "No");
            }
            if (testing_id == 4)
            {
                print_console("Binary string. Operator -. Enter id of string:");
                int id;
                scanf("%d", &id);
                --id;
                if (0 > id || id >= elements_number)
                {
                    print_console("Wrong id - out of bounds");
                    wait_for_enter();
                    return;
                }
                if (types[id] != testing_type)
                {
                    print_console("Wrong type of string was chosen");
                    wait_for_enter();
                    return;
                }
                print_console("Enter string:");
                char str[50];
                scanf("%s", str);
                binary_string A(strings[id].c_str());
                binary_string B(str);
                binary_string *result = A - B;
                printf("%s - %s is equal to %s\n", A.c_str(), B.c_str(), result->c_str());
                strings[id] = *result;
                changed[id] = true;
            }
            wait_for_enter();
        }
    }
}

bool enterPressed = false;

// функция обработки сообщений от клавиатуры
void KeyEventProcess(KEY_EVENT_RECORD kir, bool &enterPressed) 
{
  //Если нажали стрелку вверх, переходим на предыдущий item меню
  if (kir.wVirtualKeyCode == VK_UP) 
  {
      if (--chosenIndex < 0)
          chosenIndex = itemsLength - 1;
      if (chosenIndex == 0)
          chosenIndex = itemsLength - 1;
      if (chosenIndex == 3)
          chosenIndex = 2;
  }

  //Если нажали стрелку вниз, переходим на следующий item меню
  if (kir.wVirtualKeyCode == VK_DOWN) 
  {
      if (++chosenIndex == itemsLength)
          chosenIndex = 1;
      if (chosenIndex == 3)
          chosenIndex = 4;
  }

  //нажали Enter
  if (kir.wVirtualKeyCode == VK_RETURN) 
  {
      enterPressed = true;
      processItem(chosenIndex);
  }
}

void init() 
{
    chosenIndex = 1;
}

void printMenu() 
{
    //очищаем консоль
    system("CLS");
 
    puts("\n\n");
    //перебираем item-ы меню
    for (int i = 0; i < itemsLength; i++) 
    {
        if (i == chosenIndex) 
        {
            //выбранный item - пишем его красным цветом
            print_console(items[i].c_str(), Red);
        } else 
        {
            print_console(items[i].c_str(), White);
        }
    }
    puts("");
    printStrings();
}
 
int main() 
{
    // получить дескрипторы стандартного ввода и вывода
    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    if (hStdin == INVALID_HANDLE_VALUE)  //не получилось создать дескриптор на чтение
    { 
        printf("Get standard input handle failed\n");
        return GetLastError();
    }

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdout == INVALID_HANDLE_VALUE) //не получилось создать дескриптор на вывод
    { 
        printf("Get standard output handle failed\n");
        return GetLastError();
    }

    INPUT_RECORD ir; // входная запись
    DWORD cNumRead;  // количество прочитанных записей

    //инициализируем меню
    init();
    do 
    {
        printMenu();
        // ждем событие ввода
        WaitForSingleObject(hStdin, INFINITE);
     
        // читаем запись ввода
        if (!ReadConsoleInput(
              hStdin,     // дескриптор ввода
              &ir,        // буфер для записи
              1,          // читаем одну запись
              &cNumRead)) // количество прочитанных записей
        {  //не получилось считать из консоли
            printf("Read console input failed\n");
            break;
        }
     
        // вызываем соответствующий обработчик
        switch (ir.EventType) 
        {
            case KEY_EVENT: // событие ввода с клавиатуры
                if (ir.Event.KeyEvent.bKeyDown)
                    KeyEventProcess(ir.Event.KeyEvent, enterPressed);
                break;
              
            default: // неизвестное событие
                printf("Unknown event type\n");
                break;
        }
    } while (bRead);
    return 0;
}
