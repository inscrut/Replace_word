#include "windows.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>

#define SIZE_MAS 256 //Ограничение SIZE_MAS символов

using namespace std;

char input_str[SIZE_MAS] = {'\0'};
char word[SIZE_MAS] = {'\0'}; //Искомая лексемма
char repl[SIZE_MAS] = {'\0'}; //Замена

char reslt[SIZE_MAS] = {'\0'}; //результат

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Enter string: ";

    gets(input_str); //Чтение строки

    cout << "Entered: ";
    printf("%s", input_str);
    cout << endl;

    cout << "Enter search word: ";
    gets(word);
    cout << "Entered: ";
    printf("%s", word);
    cout << endl;

    cout << "Enter replace word: ";
    gets(repl);
    cout << "Entered: ";
    printf("%s", repl);
    cout << endl;

    //проверка, есть ли вообще такое слово в строке?
    if(strstr(input_str, word) == NULL){
        cout << "Not found word!" << endl << endl;
        cout << "Output: ";
        strncpy(reslt, input_str, SIZE_MAS); //SIZE_MAS - длина массива, чтобы не вылезти за пределы
        printf("%s", input_str);
        getche(); //Пауза, Enter для выхода
        return 0;
    }

    //разбиваем строку на лексеммы:
    char *p; //указатель
    p = strtok(input_str, " ");

    if(p == NULL){ //что-то пошло не так :(
        //
        cout << "p is NULL :(";
        getche(); //Пауза, Enter для выхода
        return 1;
    }

    //смотрим первое слово
    if (strcmp(p, word) == 0){ //совпадает?
        strncat(reslt, repl, SIZE_MAS);
        strcat(reslt, " ");
    }
    else{
        strncat(reslt, p, SIZE_MAS);
        strcat(reslt, " ");
    }

    while(p){ //пока не null
        p = strtok('\0', " ");

        //смотрим слово
        if(p){
            if (strcmp(p, word) == 0){ //совпадает?
                strncat(reslt, repl, SIZE_MAS);
                strcat(reslt, " ");
            }
            else{
                strncat(reslt, p, SIZE_MAS);
                strcat(reslt, " ");
            }
        }
    }

    cout << endl << "Result: ";
    printf("%s", reslt);
    cout << endl;

    getche(); //Пауза, Enter для выхода

    return 0;
}
