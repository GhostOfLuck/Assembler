#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
//#include <clocale>
using namespace std;


int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	char n[255];
	char a[] = { '.', ',' , ';', '!', '?', ':', '"', '-' };
	cout << "Введите, пожалуйста, строку: ";
	cin.getline(n, 255);
	int counter = strlen(n);
	if (counter == 0)
	{
		cout << "Вы ввели пустую строку!";
		return 0;
	}
	int leng;
	char res;
	_asm
	{
		cld
		lea edi, n
		lea ebx, a
		xor esi, esi
		xor ah, ah
		mov res, 0
		mov ecx, counter
		m1 :
			mov al, [ebx][esi]
			repne scasb
			jne m2
			inc ah
			jmp m1
		m2 :
			cmp esi, 7
			je m3
			mov ecx, counter
			lea edi, n
			inc esi
			jmp m1
		m3 :
			mov res, ah
	}
	cout << (int)res << endl;
	cout << endl;
	system("pause");
	return 0;
}