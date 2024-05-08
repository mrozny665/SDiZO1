#include"table.h"
#include<iostream>
#include<fstream>
#include<cstdlib>

Table::Table(){ //konstruktor
	Table::tablePointer = nullptr; //ustawienie wskaznika na pocz. tablicy na NULL
	Table::tableSize = 0; //ustawienie rozmiaru tablicy na 0
}

int Table::getTableSize() const {
    return tableSize;
}

Table::~Table(){ //destruktor
	clearTable(); //wywolanie funkcji czyszczacej tablice
}

void Table::loadFromFile(const std::string& FileName){ //wczytywanie tablicy z pliku
	clearTable();
	std::ifstream file(FileName);
	std::string line;
	int newTableSize;
	file >> newTableSize; //ladowanie pierwszej liczby z pliku jako liczby elementow
	for (int i = 0; i < newTableSize; i++) { 
		int number;
		file >> number;
		addValue(i, number); //dodawanie wartosci do tablicy o wartosci z pliku i indeksie i
	}
	}

bool Table::isValueInTable(int val){ //szukanie wartosci w tablicy
	for (int i = 0; i < tableSize; i++) { //przeszkiwanie tablicy po kolei
		if (tablePointer[i] == val) return true; //jezeli znaleziono wartosc - zwraca true
	}
	return false; // jezeli nie znaleziono - zwraca false
}

bool Table::addValue(int index, int value){ //dodawanie wartosci do tablicy
	if (index <= tableSize) { //sprawdzenie czy wpisany indeks jest wartoscia prawidlowa
		int* newTablePointer = new int[tableSize + 1]; //alokowanie nowej tablicy, wiekszej o 1 od poprzedniej
		int i = 0;
		for (; i < index; i++) { //przepisywanie starej tablicy do nowej az do napotkania pozadanego miejsca
			newTablePointer[i] = tablePointer[i];
		}

		newTablePointer[i] = value; //zapisanie nowej wartosci w odpowiednim miejscu

		for (; i < tableSize; i++) { //przepisywanie kolejnych wartosci ze starej tablicy do nowej z indeksem o 1 wiekszym
			newTablePointer[i + 1] = tablePointer[i];
		}

		delete tablePointer; //zwolnienie starej tablicy
		tablePointer = newTablePointer; //zapisanie nowego wskaznika
		tableSize++; //zwiekszenie rozmiaru tablicy
		return true;
	}
	else return false;
}

bool Table::deleteFromTable(int index){ //usuwanie danych z tablicy
    if (index == tableSize-1){
        int* newTablePointer = new int[tableSize-1];
        for (int i = 0; i < tableSize-1; i++){
            newTablePointer[i] = tablePointer[i];
        }
        delete tablePointer;
        tablePointer = newTablePointer;
        tableSize--;
        return true;
    } else if (index == 0){
        int* newTablePointer = new int[tableSize-1];
        for (int i = 0; i < tableSize-1; i++) {
            newTablePointer[i] = tablePointer[i+1];
        }
        delete tablePointer;
        tablePointer = newTablePointer;
        tableSize--;
        return true;
    } else if (index < tableSize) { //sprawdzenie poprawnosci indeksu
        int* newTablePointer = new int[tableSize - 1]; //alokacja tablicy mniejszej o 1 liczbe
        for (int i = 0; i < index; i++) { //przepisywanie wartosci ze starej tablicy do nowej do napotkania wybranego miejsca
            newTablePointer[i] = tablePointer[i];
        }
        for (int i = index; i < tableSize-1; i++) { //przepisywanie kolejnych wartosci z pominieciem wybranej
            newTablePointer[i] = tablePointer[i + 1];
        }
        delete tablePointer; //zwolnienie starej tablicy
        tablePointer = newTablePointer; //zapisanie nowego wskaznika
        tableSize--; //zmniejszenie rozmiaru tablicy
        return true;
        }
    else return false;
}

void Table::display(){ //wyswietlenie tablicy
	for (int i = 0; i < tableSize; i++){
		std::cout<<tablePointer[i]<<" ";
	}
}

void Table::generateTable(int size) { //tworzenie losowej tablicy
	clearTable();
	srand((unsigned)(size_t)time); //generowanie liczb pseudolosowych
	for (int i = 0; i < size; i++) {
		int value = rand();
		addValue(i, value); //dodawanie liczb na kolejnych pozycjach
	}
}

void Table::clearTable() { //usuwanie istniejacej tablicy
	if (tablePointer != nullptr) { //jezeli tablica nie jest pusta
		delete tablePointer; //zwalnianie tablicy
		tablePointer = nullptr;
		tableSize = 0;
	}
}