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

bool was_number_of_elements_called = false;
int elements_number = 0;
my_string *strings;
char **types;

bool was_testing_called = false;
bool was_operand_called = false;
int testing_type = 0;
int testing_id = 0;

void wait_for_enter()
{
    print_console("Press Enter to exit");
    getchar();
    getchar();
}

void processItem(int chosenItem)
{
    assert(chosenItem != 0 && chosenItem != 3); //not Initialization and not Testing
    system("CLS");
    if (chosenItem == 8) //Exit
        exit(0);
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
        types = new char*[elements_number];

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
        types[index] = type;

        print_console("Enter value of string");
        char value[50];
        scanf("%s", value);
        if (!strcmp(type, "string"))
        {
            my_string tt(value);
            strings[index] = tt;
        }
        if (!strcmp(type, "identificator"))
        {
            identificator_string tt(value);
            strings[index] = tt;
        }
        if (!strcmp(type, "binary"))
        {
            binary_string tt(value);
            strings[index] = tt;
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
                print_console("String. Method length(). Enter string:");
                char str[50];
                scanf("%s", str);
                my_string s(str);
                printf("length = %d\n", s.length());
            }
            if (testing_id == 2)
            {
                print_console("String. Operator []. Enter string:");
                char str[50];
                scanf("%s", str);
                my_string s(str);
                print_console("Enter index of string:");
                int index;
                scanf("%d", &index);
                printf("%c\n", s[index]);
            }
            wait_for_enter();
        }
        if (testing_type == 1)
        {
            if (testing_id == 1)
            {
                print_console("Identificator string. Method length(). Enter string:");
                char str[50];
                scanf("%s", str);
                identificator_string s(str);
                printf("length = %d\n", s.length());
            }
            if (testing_id == 2)
            {
                print_console("Identificator string. Operator []. Enter string:");
                char str[50];
                scanf("%s", str);
                identificator_string s(str);
                print_console("Enter index of string:");
                int index;
                scanf("%d", &index);
                printf("%c\n", s[index]);
            }
            if (testing_id == 3)
            {
                print_console("Indentificator string. Method \"find last position of symbol\". Enter string:");
                char str[50];
                scanf("%s", str);
                identificator_string s(str);
                print_console("Enter symbol:");
                char c;
                scanf("%c", &c);
                printf("%d\n", s.find_last(c));
            }
            if (testing_id == 4)
            {
                print_console("Indentificator string. Operator =. Enter string:");
                char str[50];
                scanf("%s", str);
                identificator_string s(str);
                print_console("Enter index of your initialized strings:");
                int id;
                scanf("%d", &id);
                if (0 >= id || id > elements_number)
                {
                    print_console("Wrong id");
                    wait_for_enter();
                    return;
                }
                //types[id] = ;
                strings[id - 1] = s;
            }
            if (testing_id == 5)
            {
                print_console("Indentificator string. Operator <. Enter string:");
                char str[50];
                scanf("%s", str);
                identificator_string s(str);
                print_console("Enter another string:");
                scanf("%s", str);
                identificator_string t(str);
                printf("Is %s less than %s? %s\n", s.c_str(), t.c_str(), s < t ? "Yes" : "No");
            }
            wait_for_enter();
        }
        if (testing_type == 2)
        {
            if (testing_id == 1)
            {
                print_console("Binary string. Method sign(). Enter string:");
                char str[50];
                scanf("%s", str);
                binary_string s(str);
                printf("sign = %d\n", s.sign());
            }
            if (testing_id == 2)
            {
                print_console("Binary string. Operator []. Enter string:");
                char str[50];
                scanf("%s", str);
                binary_string s(str);
                print_console("Enter index of string:");
                int index;
                scanf("%d", &index);
                printf("%c\n", s[index]);
            }
            if (testing_id == 3)
            {
                print_console("Binary string. Operator <. Enter string:");
                char str[50];
                scanf("%s", str);
                binary_string s(str);
                print_console("Enter another string:");
                scanf("%s", str);
                binary_string t(str);
                printf("Is %s less than %s? %s\n", s.c_str(), t.c_str(), s < t ? "Yes" : "No");
            }
            if (testing_id == 4)
            {
                print_console("Binary string. Operator -. Enter string:");
                char str[50];
                scanf("%s", str);
                binary_string s(str);
                print_console("Enter another string:");
                scanf("%s", str);
                binary_string t(str);
                printf("%s - %s is equal to %s\n", s.c_str(), t.c_str(), (s - t)->c_str());
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
    if (was_number_of_elements_called)
    {
        for (int i = 0; i < elements_number; i++)
        {
            printf("%d. ", i + 1);
            if (was_operand_called)
                print_console(strings[i].c_str(), Green);
            else
                print_console(strings[i].c_str(), White);
        }
    }
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
