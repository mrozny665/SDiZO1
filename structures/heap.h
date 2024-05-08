#ifndef SDIZO1_HEAP_H
#define SDIZO1_HEAP_H

#include<string>


class Heap {

    int heapArray[200000]{}; //tablica przechowujaca elementy kopca - wartosc przyjeta jest nadmiarowa
    int heapSize; //obecna liczba elementow kopca

public:
    Heap(); //konstruktor
    ~Heap(); //destruktor

    void addElement(int value); //funkcja dodajaca element do kopca
    bool removeElement(int index); //funkcja usuwajaca element z kopca
    bool searchHeap(int value); // funkcja szukajaca wartosci w kopcu
    void loadFromFile(std::string fileName); //funkcja generujaca kopiec z pliku txt
    void generateHeap(int size); //funkcja generujaca losowy kopiec
    void display(); //funkcja wyswietlajaca kopiec
    void fixFromTop(int index); //funkcja przywracajaca wlasnosc kopca od gory
    void fixFromBottom(int index); //funkcja przywracajaca wlasnosc kopca od dolu
    int getHeapSize() const; //funkcja zwracajaca liczbe elementow kopca

    void removeRoot(); //funkcja usuwajaca korzen kopca
};


#endif //SDIZO1_HEAP_H
