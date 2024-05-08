#ifndef SDIZO1_BSTREE_H
#define SDIZO1_BSTREE_H

#include<string>


class BSTree {
    struct TreeElement { //struktura odpowiadajaca elementowi drzewa
        TreeElement *left, *right, *parent; //wskazniki na lewego i prawego syna oraz na rodzica
        int value; //zawartosc elementu
    };

    TreeElement *root; //wskaznik na korzen drzewa
    int elementCount; //liczba elementow drzewa


public:
    BSTree(); //konstruktor
    ~BSTree(); //destruktor

    void addElement(int value); //funkcja dodajaca element do drzewa
    void removeElement(int value); //funkcja usuwajaca element z drzewa
    bool searchTree(int value); //funkcja szukajaca wartosci w drzewie
    void display(); //funkcja wyswietlajaca drzewo
    void loadFromFile(std::string fileName); //funkcja generujaca drzewo z pliku
    void generateTree(int size); //funkcja generujaca losowe drzewo
    void DSWalgorithm(); //funkcja implementujaca algorytm rownowazenia DSW
    TreeElement *getRoot() const; //funkcja zwracajaca wskaznik na korzen

private:
    void inorder(TreeElement *thisElement); //funkcja wyswietlajaca wartosci w kolejnosci inorder
    void printTree(TreeElement *thisElement, int space); //funkcja wyswietlajaca drzewo w postaci graficznej
    TreeElement *successor(TreeElement *thisElement); //funkcja wyznaczajaca nastepce wezla
    void rotateLeft(TreeElement *thisElement); //funkcja rotujaca w lewo
    void rotateRight(TreeElement *thisElement); //funkcja rotujaca w prawo

    void printBT(const TreeElement *node);

    void printBT(const std::string &prefix, const TreeElement *node, bool isLeft);

    void printBT(std::string sp, std::string sn, TreeElement *v);
};


#endif //SDIZO1_BSTREE_H
