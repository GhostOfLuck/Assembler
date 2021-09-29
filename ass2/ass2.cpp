//Минимальный эелемент первого массива, которого нет во втором
//
#include "pch.h"
#include <iostream>
int num = 100;

using namespace std;

void my_sort(int*& arr, int n);
void compare(int*& ar1, int*&ar2, int n, int m);

void my_out(int a) {
	cout << endl << "Минимальный элемент первого массива, которого нет во втором: " << endl;
	cout << a << endl;
	return;
}
void oshibka()
{
	cout << endl << "Такого элемента не существует!" << endl;
	return;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	int *mas1 = new int[num];
	int *mas2 = new int[num];

	int n, m;
	cout << "Введите количество элементов в массивах:(для первого и для второго) " << endl;
	cin >> n >> m;
	cout << "Введите первый массив: " << endl;
	for (int i = 0; i < n; i++)
		cin >> mas1[i];

	cout << "Введите второй массив: " << endl;
	for (int i = 0; i < m; i++)
		cin >> mas2[i];

	my_sort(mas1, n);
	my_sort(mas2, m);

	cout << endl << "Отсортированный первый массив: " << endl;
	for (int i = 0; i < n; ++i)
		cout << mas1[i] << '\t';

	cout << endl << "Отсортированный второй массив: " << endl;
	for (int i = 0; i < m; ++i)
		cout << mas2[i] << '\t';


	compare(mas1, mas2, n, m);
	return 0;
}

void my_sort(int*& arr, int n) {
	int ar = (int)arr;
	int * mas = arr;
	_asm {
		mov ecx, n
		dec ecx
		mov eax, ar
		cykle :
		mov edx, [eax][4 * ecx]
			cmp edx, [eax][4 * ecx - 4]
			jge cont
			mov ebx, [eax][ecx * 4]
			mov edx, [eax][ecx * 4 - 4]
			mov[eax][ecx * 4], edx
			mov[eax][ecx * 4 - 4], ebx
			mov ecx, n
			cont :
		loop cykle
	}
}

void compare(int*& ar1, int*&ar2, int n, int m) {
	int arr1 = (int)ar1;
	int arr2 = (int)ar2;
	_asm {
		mov eax, arr1
		xor edi, edi
		cykle1 :
		mov ecx, m
			cmp edi, n
			je net
			inc edi
			mov edx, [eax]
			add eax, 4
			mov ebx, arr2
			cykle2 :
		cmp edx, [ebx]
			je cykle1
			cmp ecx, 0
			je end_prog
			endc :
		add ebx, 4
			cmp ecx, 0
			je cykle1
			dec ecx
			jmp cykle2
			end_prog :
		push edx
			call my_out
			pop edx
			jmp konec
			net :
		call oshibka
			konec :
	}
}