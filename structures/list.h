#ifndef LIST_H
#define LIST_H

#include<string>

class List {

	struct ListElement { //struktura odpowiadajaca elementowi listy
		int data; //zawartosc elementu
		ListElement *prev, *next; //wskaznik na poprzedni i nastepny element
	};
	ListElement *headPointer; //wskaznik na pierwszy element
	ListElement *tailPointer; //wskaznik na ostatni element
	int listSize; //obecna wielkosc listy

public:
	List(); //konstruktor
	~List(); //destruktor

	void loadFromFile(std::string fileName); //funkcja ladujaca liste z pliku
	bool addElement(int index, int value); //funkcja dodajaca element do listy
	bool removeElement(int value); //funkcja usuwajaca element z listy
    void removeElement2(int index);
	bool searchList(int value); //funkcja szukajaca wartosci na liscie
	void generateList(int number); //funkcja tworzaca losowa liste
	void display(); //funkcja wyswietlajaca liste
	void clearList();

    int getListSize() const;
    //funkcja usuwajaca istnejaca liste
};
#endif /* LIST_H */