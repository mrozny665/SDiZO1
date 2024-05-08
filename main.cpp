#include<iostream>
#include"structures/table.h"
#include"structures/list.h"
#include"structures/heap.h"
#include"structures/BSTree.h"
#include"testing/tableTest.h"
#include"testing/listTest.h"
#include "testing/heapTest.h"
#include "testing/treeTest.h"

using namespace std;

void displayMenu(const string& info){
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun" << endl;
	cout << "3.Dodaj" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Utworz losowo" << endl;
	cout << "6.Wyswietl" << endl;
    if (info == "--- DRZEWO BST ---"){
        cout << "7.Algorytm DSW" << endl;
    }
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

void menu_table(){
    Table table;
	char opt;
	string fileName;
	int index, value;
    int sizes[] = {5000, 8000, 10000, 15000, 20000, 40000, 60000, 100000};

	do{
		displayMenu("--- TABLICA ---");
        cin >> opt;
		//opt = _getche();
		cout << endl;
		switch (opt){
            case '1': //wczytytwanie tablicy z pliku
                cout << " Podaj nazwe pilku:";
                cin >> fileName;
                table.loadFromFile(fileName);
                table.display();
                break;

            case '2': //usuwanie elementu z tablicy
                cout << " Podaj indeks:";
                cin >> index;
                if (table.deleteFromTable(index)) {
                    table.display();
                }
                else {
                    cout << "Bledny indeks\n";
                }
                break;

            case '3': //dodawanie elementu do tablicy
                cout << " Podaj indeks:";
                cin >> index;
                cout << " Podaj wartosc:";
                cin >> value;
                if (table.addValue(index, value)) {
                    table.display();
                }
                else {
                    cout << "Bledny indeks\n";
                }
                break;

            case '4': //znajdowanie elementu w tablicy
                cout << " Podaj wartosc:";
                cin >> value;
                if (table.isValueInTable(value))
                    cout << "Podana wartosc jest w tablicy";
                else
                    cout << "Podanej wartosci nie ma w tablicy";
                break;

            case '5':  //generowanie losowej tablicy
                cout << "Podaj liczbe elementów tablicy:";
                cin >> value;
                table.generateTable(value);
                table.display();
                break;

            case '6':  //wyświetlanie tablicy
                table.display();
                break;

            case 'q':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    table.generateTable(size);
                    cout << TableTest::addEnd(table, 100) << ", ";
                }
                break;

            case 'w':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    table.generateTable(size);
                    cout << TableTest::addStart(table, 100) << ", ";
                }
                break;

            case 'e':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    table.generateTable(size);
                    cout << TableTest::addMiddle(table, 100) << ", ";
                }
                break;

            case 'a':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    table.generateTable(size);
                    cout << TableTest::removeEnd(table, 100) << ", ";
                }
                break;

            case 's':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    table.generateTable(size);
                    cout << TableTest::removeStart(table, 100) << ", ";
                }
                break;

            case 'd':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    table.generateTable(size);
                    cout << TableTest::removeMiddle(table, 100) << ", ";
                }
                break;

            case'z':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    table.generateTable(size);
                    cout << TableTest::search(table, 100) << ", ";
                }
                break;

            case '0':
                break;

            default:
                cout << "Bledny wybor";
                break;
		}

	} while (opt != '0');
}

void menu_list(){
	List list;
	char opt;
	string fileName;
	int index, value;
    int sizes[] = {5000, 8000, 10000, 15000, 20000, 40000, 60000, 100000};

	do {
		displayMenu("--- LISTA ---");
        cin >> opt;
		//opt = _getche();
		cout << endl;
		switch (opt) {
            case '1': //wczytywanie listy z pliku
                cout << " Podaj nazwe pilku:";
                cin >> fileName;
                list.loadFromFile(fileName);
                list.display();
                break;

            case '2': //usuwanie elementu z listy
                cout << " Podaj wartosc:";
                cin >> value;
                if (list.removeElement(value)) {
                    list.display();
                }
                else {
                    cout << "Nie ma takiej wartosci";
                }
                break;

            case '3': //dodawanie elementu do listy
                cout << " Podaj index:";
                cin >> index;
                cout << " Podaj wartosc:";
                cin >> value;
                if (list.addElement(index, value)) {
                    list.display();
                }
                else {
                    cout << "Bledny index";
                }
                break;

            case '4': //znajdowanie elementu na liscie
                cout << " Podaj wartosc:";
                cin >> value;
                if (list.searchList(value)) {
                    cout << "Podana wartosc jest na liscie";
                }
                else {
                    cout << "Podanej wartosci nie ma na liscie";
                }
                break;

            case '5': //generowanie losowej listy
                cout << " Podaj liczbe elementow listy:";
                cin >> value;
                list.generateList(value);
                list.display();
                break;

            case '6': //wyswietlanie listy
                list.display();
                break;

            case '0':
                break;

            case 'q':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    list.generateList(size);
                    cout << ListTest::addEnd(list, 100) << ", ";
                }
                break;

            case 'w':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    list.generateList(size);
                    cout << ListTest::addStart(list, 100) << ", ";
                }
                break;

            case 'e':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    list.generateList(size);
                    cout << ListTest::addMiddle(list, 100) << ", ";
                }
                break;

            case 'a':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    list.generateList(size);
                    cout << ListTest::removeEnd(list, 100) << ", ";
                }
                break;

            case 's':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    list.generateList(size);
                    cout << ListTest::removeStart(list, 100) << ", ";
                }
                break;

            case 'd':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    list.generateList(size);
                    cout << ListTest::removeMiddle(list, 100) << ", ";
                }
                break;

            case'z':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    list.generateList(size);
                    cout << ListTest::search(list, 100) << ", ";
                }
                break;

            default:
                cout << "Bledny wybor";
                break;
		}
	} while (opt != '0');
}

void menu_heap(){
    Heap heap;
    char opt;
    string fileName;
    int index, value;
    int sizes[] = {5000, 8000, 10000, 15000, 20000, 40000, 60000, 100000};

    do {
        displayMenu("--- KOPIEC ---");
        cin >> opt;
        //opt = _getche();
        cout << endl;
        switch (opt) {
            case '1': //wczytywanie kopca z pliku
                cout << " Podaj nazwe pilku:";
                cin >> fileName;
                heap.loadFromFile(fileName);
                heap.display();
                break;

            case '2': //usuwanie elementu z kopca
                cout << " Podaj indeks:";
                cin >> index;
                if (heap.removeElement(index)) {
                    heap.display();
                }
                else {
                    cout << "Nieprawidłowy indeks";
                }
                break;

            case '3': //dodawanie elementu do kopca
                cout << " Podaj wartosc:";
                cin >> value;
                heap.addElement(value);
                heap.fixFromBottom(heap.getHeapSize()-1);
                heap.display();
                break;

            case '4': //znajdowanie elementu w kopcu
                cout << " Podaj wartosc:";
                cin >> value;
                if (heap.searchHeap(value)) {
                    cout << "Podana wartosc jest w kopcu";
                }
                else {
                    cout << "Podanej wartosci nie ma w kopcu";
                }
                break;

            case '5': //generowanie losowgo kopca
                cout << " Podaj liczbe elementow listy:";
                cin >> value;
                heap.generateHeap(value);
                heap.display();
                break;

            case '6': //wyswietlanie kopca
                heap.display();
                break;

            case '0':
                break;

            case 'q':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    heap.generateHeap(size);
                    cout << HeapTest::add(heap, 100) << ", ";
                }
                break;

            case 'a':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    heap.generateHeap(size);
                    cout << HeapTest::remove(heap, 100) << ", ";
                }
                break;

            case 'z':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    heap.generateHeap(size);
                    cout << HeapTest::search(heap, 100) << ", ";
                }
                break;

            default:
                cout << "Bledny wybor";
                break;
        }
    } while (opt != '0');
}

void menu_tree(){
    BSTree tree;
    char opt;
    string fileName;
    int value;
    int sizes[] = {5000, 8000, 10000, 15000, 20000, 40000, 60000, 100000};

    do {
        displayMenu("--- DRZEWO BST ---");
        cin >> opt;
        //opt = _getche();
        cout << endl;
        switch (opt) {
            case '1':
                cout << " Podaj nazwe pilku:";
                cin >> fileName;
                tree.loadFromFile(fileName);
                tree.display();
                break;

            case '2':
                cout << " Podaj wartosc:";
                cin >> value;
                tree.removeElement(value);
                tree.display();
                break;

            case '3':
                cout << " Podaj wartosc:";
                cin >> value;
                tree.addElement(value);
                tree.display();
                break;

            case '4':
                cout << " Podaj wartosc:";
                cin >> value;
                if (tree.searchTree(value)){
                    cout << "Podana wartosc jest w drzewie";
                } else {
                    cout << "Podanej wartosci nie ma w drzewie";
                }
                break;

            case '5':
                cout << " Podaj liczbe elementow:";
                cin >> value;
                tree.generateTree(value);
                tree.display();
                break;

            case '6':
                tree.display();
                break;

            case '7':
                tree.DSWalgorithm();
                tree.display();
                break;

            case 'q':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    tree.generateTree(size);
                    tree.DSWalgorithm();
                    cout << TreeTest::add(tree, 100) << ", ";
                }
                break;

            case 'a':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    tree.generateTree(size);
                    tree.DSWalgorithm();
                    cout << TreeTest::remove(tree, 100) << ", ";
                }
                break;

            case 'z':
                cout << "Czasy wykonania w mikrosekundach: ";
                for (int size : sizes) {
                    tree.generateTree(size);
                    tree.DSWalgorithm();
                    cout << TreeTest::search(tree, 100) << ", ";
                }
                break;

            default:
                break;
        }
    } while (opt != '0');
}

int main(){
    char option;
	do {
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
        cout << "3.Kopiec" << endl;
        cout << "4.Drzewo BST" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";
        cin >> option;
		//option = _getche();
		cout << endl;

        switch (option) {
		    case '1':
			    menu_table();
			    break;

		    case '2':
			    menu_list();
			    break;

            case '3':
                menu_heap();
                break;

            case '4':
                menu_tree();
                break;

            case '0':
                break;

            default:
                cout << "Bledny wybor";
                break;
		}
	} while (option != '0');
		return 0;
}