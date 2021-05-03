#include<iostream>
#include<conio.h>
#include <stdlib.h> 
#include <string.h> 
#include <thread>
#include <time.h>
#include <windows.h>
using namespace std;

void gotoxy(int x1, int y1)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x1;
	dwPos.Y = y1;
	SetConsoleCursorPosition(hcon, dwPos);
}

struct Nodo {
	int valor;
	Nodo* siguiente;
};

void Add(Nodo*&, int);
void Remove(Nodo*&);
void cajero();
void cajero1();
void cajero2();
void cajero3();

Nodo* fin = NULL;

int main() {
	Sleep(300);
	thread caje(cajero);
	Sleep(300);
	thread caje1(cajero1);
	Sleep(300);
	thread caje2(cajero2);
	Sleep(300);
	thread caje3(cajero3);
	Sleep(300);
	caje3.join();
	Sleep(300);
	caje2.join();
	Sleep(300);
	caje1.join();
	Sleep(300);
	caje.join();
	Sleep(300);

	system("pause");
}

void cajero() {
	Nodo* inicio = NULL;

	int valor = 0, contar = 0;
	int suma1 = 0;
	char s;

	for (int i = 6; i <= 16; i++) {

		contar += 1;
		srand(time(NULL));
		valor = 1 + rand() % (90);
		gotoxy(1, i); cout << valor << endl;
		suma1 = suma1 + valor;

		Add(inicio, valor);
		Sleep(700);

		gotoxy(1, 1); cout << "cajero1(total: " << suma1 << ")" << endl;
		gotoxy(1, 2); cout << "inicio: " << inicio->valor << endl;
		gotoxy(1, 3); cout << "fin: " << fin->valor << endl;
	}

	/*
	Remove(inicio);
	if (inicio == NULL) {
		gotoxy(1, 30);	cout << "La Cola esta vacia" << endl;

	}
	else {
		gotoxy(1, 31); cout << "--------------- inicio: " << inicio->valor << endl;
		gotoxy(1, 32); cout << "--------------- fin: " << fin->valor << endl;
	}
	*/

	system("PAUSE");
}

void cajero1() {
	Nodo* inicio = NULL;

	int valor = 0, contar = 0;
	int suma2 = 0;
	char s;

	for (int i = 6; i <= 16; i++) {
		contar += 1;
		srand(time(NULL));
		valor = 1 + rand() % (90);
		gotoxy(30, i); cout << valor << endl;
		suma2 = suma2 + valor;

		Add(inicio, valor);
		Sleep(700);
		gotoxy(30, 1); cout << "cajero2(total: " << suma2 << ")" << endl;
		gotoxy(30, 2); cout << "inicio: " << inicio->valor << endl;
		gotoxy(30, 3); cout << "fin: " << fin->valor << endl;
	}

	/*Remove(inicio);
	if (inicio == NULL) {
		gotoxy(30, 30); cout << "La Cola esta vacia" << endl;

	}
	else {
		gotoxy(30, 31); cout << "--------------- inicio: " << inicio->valor << endl;
		gotoxy(30, 32); cout << "--------------- fin: " << fin->valor << endl;
	}
	*/

	system("PAUSE");
}

void cajero2() {
	Nodo* inicio = NULL;

	int valor = 0, contar = 0;
	int suma3 = 0;
	char s;

	for (int i = 6; i <= 16; i++) {
		contar += 1;
		srand(time(NULL));
		valor = 1 + rand() % (90);
		gotoxy(60, i); cout << valor << endl;
		suma3 = suma3 + valor;

		Add(inicio, valor);
		Sleep(700);
		gotoxy(60, 1); cout << "cajero3(total: " << suma3 << ")" << endl;
		gotoxy(60, 2); cout << "inicio: " << inicio->valor << endl;
		gotoxy(60, 3); cout << "fin: " << fin->valor << endl;
	}

	/*Remove(inicio);
	if (inicio == NULL) {
		gotoxy(30, 30); cout << "La Cola esta vacia" << endl;

	}
	else {
		gotoxy(30, 31); cout << "--------------- inicio: " << inicio->valor << endl;
		gotoxy(30, 32); cout << "--------------- fin: " << fin->valor << endl;
	}
	*/

	system("PAUSE");
}

void cajero3() {
	Nodo* inicio = NULL;

	int valor = 0, contar = 0;
	int suma4 = 0;
	char s;

	for (int i = 6; i <= 16; i++) {
		contar += 1;
		srand(time(NULL));
		valor = 1 + rand() % (90);
		gotoxy(90, i); cout << valor << endl;
		suma4 = suma4 + valor;

		Add(inicio, valor);
		Sleep(700);
		gotoxy(90, 1); cout << "cajero4(total: " << suma4 << ")" << endl;
		gotoxy(90, 2); cout << "inicio: " << inicio->valor << endl;
		gotoxy(90, 3); cout << "fin: " << fin->valor << endl;
	}

	gotoxy(1, 20); cout << "Fin" << endl;

	/*Remove(inicio);
	if (inicio == NULL) {
		gotoxy(30, 30); cout << "La Cola esta vacia" << endl;

	}
	else {
		gotoxy(30, 31); cout << "--------------- inicio: " << inicio->valor << endl;
		gotoxy(30, 32); cout << "--------------- fin: " << fin->valor << endl;
	}
	*/

	system("PAUSE");
}

void Add(Nodo*& inicio, int v) {
	Nodo* add = new Nodo();
	add->valor = v;
	add->siguiente = NULL;
	if (inicio == NULL) {
		inicio = add;
	}
	else {
		fin->siguiente = add;
	}
	fin = add;
}
void Remove(Nodo*& inicio) {
	int v;
	Nodo* fin = NULL;
	v = inicio->valor;
	Nodo* cola = inicio;

	if (inicio == fin) {
		inicio = NULL;
		fin = NULL;
	}
	else {
		inicio = inicio->siguiente;
	}
	delete cola;
}
