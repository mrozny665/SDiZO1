#include "heap.h"
#include<iostream>
#include<fstream>

Heap::Heap() { //konstruktor
    heapSize = 0; //ustawia wielkosc kopca na 0
}

Heap::~Heap() { //destruktor
    heapSize = 0;
}

void Heap::addElement(int value) { //dodawanie wartosci do kopca
    heapArray[heapSize] = value; //wstawienie wartosci na koniec tablicy kopca
    heapSize++; //zwiekszenie licznika elementow
} //przywracanie wlasnosci odbywa sie przy pomocy osobnej funkcji

bool Heap::removeElement(int index) { //usuwanie wartosci z kopca
    if (index < heapSize) { //sprawdzenie czy indeks jest prawidlowy
        int old = heapArray[index]; //zapisanie usuwanej wartosci
        heapArray[index] = heapArray[heapSize-1]; //przeniesienie wartosci z ostatniego liscia do miejsca usuwania
        heapSize--; //zmniejszenie licznika elementow
        if (old > heapArray[index]){ //jezeli poprzednia wartosc byla wieksza niz nowa
            fixFromTop(index); //naprawa w dol
        } else if (old < heapArray[index]){ //jezeli byla mniejsza
            fixFromBottom(index); //naprawa w gore
        }
        return true;
    }
    return false;
}

void Heap::removeRoot() { //pomocnicza: usuwanie korzenia - korzen nie moze byc mniejszy niz nowa wartosc; nie ma koniecznosci sprawdzania poprawnosci indeksu
    int old = heapArray[0];
    heapArray[0] = heapArray[heapSize-1];
    heapSize--;
    if (old > heapArray[0]){
        fixFromTop(0);
    }
}

bool Heap::searchHeap(int value) { //szukanie wartosci w kopcu
    for (int i = 0; i < heapSize; i++){ //sprawdzanie wartosci w tablicy po kolei
        if (heapArray[i] == value){ //dopoki nie zostanie znaleziona
            return true;
        }
    }
    return false;
}

void Heap::loadFromFile(std::string fileName) { //wczytywanie kopca z pliku
    heapSize = 0;
    std::ifstream file(fileName);
    std::string line;
    int newHeapSize;
    file >> newHeapSize;
    for (int i = 0; i < newHeapSize; i++) { //dodawanie kolejnych elementow
        int value;
        file >> value;
        addElement(value);
    }
    for (int i = heapSize-1; i >= 0; i--){ //na koniec przywrocenie wlasnosci algorytmem Floyda
        fixFromTop(i);
    }
}

void Heap::generateHeap(int size) { //generowanie losowego kopca
    heapSize = 0;
    srand((unsigned int)(size_t) time); //generowanie liczb pseudolosowych
    for (int i = 0; i < size; i++) { //dodawanie kolejnych elementow
        int value = rand();
        addElement(value);
    }
    for (int i = heapSize-1; i >= 0; i--){ //przywrocenie wlasnosci algorytmem Floyda
        fixFromTop(i);
    }
}

void Heap::display() { //wyswietlanie kopca w konsoli - rozwiazanie gotowe z internetu
    int level = 0;
    int limit = 1;
    int counter = 0;
    if (heapSize == 0) {
        std::cout << "Kopiec jest pusty" << std::endl;
    }
    else {
        std::cout << level << ":";
        for (int i = 0; i < heapSize; i++) {
            std::cout << " " << heapArray[i];
            counter++;
            if (counter == limit) {
                limit = limit * 2;
                counter = 0;
                level++;
                std::cout << "\n" << level << ":";
            }
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < heapSize; i++){ //wyswietlanie tablicy element po elemencie
        std::cout << heapArray[i] << ", ";
    }
}

void Heap::fixFromTop(int index) { //naprawa kopca z gory
    int leftIndex = index*2+1; //indeks lewego syna
    int rightIndex = (index*2)+2; //indeks prawego syna
    int bigger;
    if (leftIndex < heapSize){ //sprawdzenie czy indeksy istnieja w kopcu
        if (heapArray[leftIndex] > heapArray[rightIndex]){ //sprawdzenie ktory z synow jest wiekszy
            bigger = leftIndex;
        } else {
            bigger = rightIndex;
        }
        if (heapArray[bigger] > heapArray[index]){ //porowanie wiekszego z synow do obecnego wezla
            int buffer = heapArray[index];
            heapArray[index] = heapArray[bigger];
            heapArray[bigger] = buffer; //zamiana wartosci
            fixFromTop(bigger); //naprawa z gory dla kolejnego wezla
        }
    }
}

void Heap::fixFromBottom(int index) { //naprawa kopca z dolu
    int parent = (index-1)/2; //indeks rodzica
    if (heapArray[parent] < heapArray[index]){ //porownanie wezla z jego rodzicem
        int buffer = heapArray[index];
        heapArray[index] = heapArray[parent];
        heapArray[parent] = buffer; //zamiana wartosci
    }
    if (parent > 0){ //jesli rodzic nie jest korzeniem
        fixFromBottom(parent); //naprawa z dolu dla kolejnego wezla
    }
}

int Heap::getHeapSize() const { //wartosc licznika elementow
    return heapSize;
}
