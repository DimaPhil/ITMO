#include <windows.h>
#include <stdlib.h>
#include <string>
#include <assert.h>

#include "main.h"
#include "my_string.h"

using namespace std;
 
const int MAX_ITEMS_LENGTH = 10;
const int MAX_NUMBER_OF_STRINGS = 6;

const int itemsLength = 8; //количество item-ов
const string items[] = {"     1. Initialization",                //0
                        "         1.1. Number of elements",      //1
                        "         1.2. Initial value",           //2
                        "     2. Testing",                       //3
                        "         2.1. String",                  //4
                        "         2.2. Identificator string",    //5
                        "         2.3. Binary number",           //6
                        "     3. Exit"                           //7
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
int elements_number;
my_string *strings;
char **types;

void wait_for_enter()
{
    getchar();
    getchar();
}

void processItem(int chosenItem)
{
    assert(chosenItem != 0 && chosenItem != 3); //not Initialization and not Testing
    system("CLS");
    if (chosenItem == 7) //Exit
        exit(0);
    if (chosenItem == 1) //Number of elements
    {
        if (was_number_of_elements_called) 
        {
            print_console("You can't choose this menu item anymore");
            wait_for_enter();
            return;
        }
        print_console("Please enter the number of elements - it should be from 1 to 6");
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

        print_console("Enter the number of element");
        int index;
        scanf("%d", &index);
        if (0 > index || index >= elements_number)
        {
            print_console("Out of bounds");
            wait_for_enter();
            return;
        }

        print_console("Enter the type of string - string, identificator or binary");
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
        my_string tt(value);
        strings[index] = tt;
        wait_for_enter();
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
