#ifndef TABLE_H
#define TABLE_H

#include<string>

class Table
{
	int *tablePointer; //wskaznik na poczatek tablicy
	int tableSize; //ilosc elementów w tablicy
public:
	
	Table(); //konstruktor - wywolywany automatycznie przy tworzeniu obieku
	~Table(); //destrukor - wywolywany automatycznie przy usuwaniu obiektu

	void loadFromFile(const std::string& FileName); //funkcja ladujaca tabele z pliku
	bool isValueInTable(int val); //funkcja szukajaca wartosci w tabeli
	bool addValue(int index, int value); //funkcja dodajaca wartosc do tabeli
	bool deleteFromTable(int index); //funkcja usuwajaca wartosc z tabeli
	void display(); //funkcja wyswietlajaca tabele
	void generateTable(int size); //funkcja tworzaca losowa tabele
	void clearTable();

    int getTableSize() const;
    //funkcja usuwajaca istniejaca tablice

};

#endif /* TABLE_H */