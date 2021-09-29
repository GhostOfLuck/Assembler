#include "pch.h"
#include <iostream>
//вычислить сумму всех чисел фибоначчи, не превосходящих заданного числа N
using namespace std;

int check(int n)
{
	if (n == 0) {
		cout << "Сумма чисел Фибоначчи равна 0." << endl;
		return 1;
	}
	return 0;
}


int main()
{
	setlocale(LC_ALL, ".1251");
	int n;
	cout << "Введите N: " << endl;
	cin >> n;
	if(check(n))
		return 1;
	int res = 2;
	_asm {
		mov ecx, 0
		mov eax, 1
		mov ebx, 1
	cirkle:
		mov ecx, eax
		add ecx, ebx
		mov ebx, eax
		mov eax, ecx
		add res, ecx
		cmp ecx, n
		jle cirkle
		sub res, ecx
	}
	cout <<"Сумма чисел Фибоначи до N (включительно): "<< res << endl;
	return 0;
}
