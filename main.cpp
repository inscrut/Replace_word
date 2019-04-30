#include "windows.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>

#define SIZE_MAS 256 //����������� SIZE_MAS ��������

using namespace std;

char input_str[SIZE_MAS] = {'\0'};
char word[SIZE_MAS] = {'\0'}; //������� ��������
char repl[SIZE_MAS] = {'\0'}; //������

char reslt[SIZE_MAS] = {'\0'}; //���������

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Enter string: ";

    gets(input_str); //������ ������

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

    //��������, ���� �� ������ ����� ����� � ������?
    if(strstr(input_str, word) == NULL){
        cout << "Not found word!" << endl << endl;
        cout << "Output: ";
        strncpy(reslt, input_str, SIZE_MAS); //SIZE_MAS - ����� �������, ����� �� ������� �� �������
        printf("%s", input_str);
        getche(); //�����, Enter ��� ������
        return 0;
    }

    //��������� ������ �� ��������:
    char *p; //���������
    p = strtok(input_str, " ");

    if(p == NULL){ //���-�� ����� �� ��� :(
        //
        cout << "p is NULL :(";
        getche(); //�����, Enter ��� ������
        return 1;
    }

    //������� ������ �����
    if (strcmp(p, word) == 0){ //���������?
        strncat(reslt, repl, SIZE_MAS);
        strcat(reslt, " ");
    }
    else{
        strncat(reslt, p, SIZE_MAS);
        strcat(reslt, " ");
    }

    while(p){ //���� �� null
        p = strtok('\0', " ");

        //������� �����
        if(p){
            if (strcmp(p, word) == 0){ //���������?
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

    getche(); //�����, Enter ��� ������

    return 0;
}
