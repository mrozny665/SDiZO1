#include "BSTree.h"
#include<iostream>
#include<fstream>
#include<cmath>

BSTree::BSTree() { //konstruktor
    elementCount = 0; //reset licznika elementow
    root = nullptr; //usuniecie korzenia
}

BSTree::~BSTree() { //destruktor
    elementCount = 0;
    root = nullptr;
}

void BSTree::addElement(int value) { //dodawanie elementow
    if (root == nullptr){ //jezeli drzewo jest puste
        auto *newElement = new TreeElement;
        newElement->left = nullptr;
        newElement->right = nullptr;
        newElement->parent = nullptr;
        newElement->value = value; //utworzenie nowego elementu z rodzicem i synami -> NULL
        root = newElement; //zapisanie nowego elementu jako korzen
    } else {
        TreeElement *thisElement;
        TreeElement *nextElement = root;
        do {
            thisElement = nextElement;
            if (thisElement->value <= value) { //znajdowanie drogi do odpowiedniego liscia
                nextElement = thisElement->right;
            } else {
                nextElement = thisElement->left;
            }
        } while (nextElement != nullptr); //przejscie po kolejnych elementach do dotarcia do liscie
        auto *newElement = new TreeElement;
        newElement->left = nullptr;
        newElement->right = nullptr;
        newElement->parent = thisElement; //utworzenie nowego elementu bez synow, ale z rodzicem
        newElement->value = value;
        if (thisElement->value <= value) { //zapisanie nowego elementu jako syna obecnego
            thisElement->right = newElement;
        } else {
            thisElement->left = newElement;
        }
    }
    elementCount++; //zwiekszenie licznika elementow
}

void BSTree::removeElement(int value) { //usuwanie elementu
    TreeElement *thisElement; //1 czesc - wyszukiwanie elementu w drzewie
    TreeElement *nextElement = root;
    bool found = false;
    do {
        thisElement = nextElement;
        if (thisElement->value == value) {
            found = true;
            break;
        } else if (thisElement->value < value){
            nextElement = thisElement->right;
        } else {
            nextElement = thisElement->left;
        }
    } while (nextElement != nullptr); //przeszukiwanie drzewa do dotarcia do szukanej liczby lub do liscia
    if (found){ //jezeli znaleziono wartosc
        if (thisElement->right == nullptr){ //jezeli nie ma prawego poddrzewa
            if (thisElement->left == nullptr){ //jezeli nie ma zadnego poddrzewa
                if (thisElement->parent->left == thisElement) //usuniecie wskaznika z rodzica
                thisElement->parent->left = nullptr;
                else thisElement->parent->right = nullptr;
                delete thisElement; //usuniecie elementu
            } else { //jezeli jest lewe poddrzewo
                TreeElement *deleteElement = thisElement->left; //wstawienie lewego syna w miejsce usuwanego elementu
                thisElement->left = deleteElement->left;
                thisElement->right = deleteElement->right;
                thisElement->value = deleteElement->value;
                delete deleteElement;
            }
        } else if (thisElement->left == nullptr){ //jezeli nie ma lewego poddrzewa (jest prawe, sprawdzone juz wczesniej)
            TreeElement *deleteElement = thisElement->right; //wstawienie prawego syna w miejsce usuwanego elementu
            thisElement->left = deleteElement->left;
            thisElement->right = deleteElement->right;
            thisElement->value = deleteElement->value;
            delete deleteElement;
        } else { //jezeli sa oba poddrzewa
            TreeElement *suc = successor(thisElement); //znalezienie nastepnika
            thisElement->value = suc->value; //przypisanie wartosci nastepnika do usuwanego elementu
            if (suc->right != nullptr){ //zachowanie ewentualnego prawego syna nastepnika
                suc->parent->left = suc->right;
                suc->right->parent = suc->parent;
            } else {
                suc->parent->left = nullptr;
            }
            delete suc; //usuniecie nastepnika (przeniesiony juz do elementu, ktory wczesniej mial usuwana wartosc)
        }
    }
    elementCount--; //zmniejszenie licznika elementow
}

bool BSTree::searchTree(int value) { //szukanie wartosci w drzewie
    if (root == nullptr) //jezeli drzewo jest puste, to nie ma w nim wartosci
        return false;
    else {
        TreeElement *thisElement;
        TreeElement *nextElement = root;
        do {
            thisElement = nextElement;
            if ((*thisElement).value < value) { //przejscie do kolejnego elementu odpowiednio w lewo lub w prawo
                nextElement = (*thisElement).right;
            } else if ((*thisElement).value > value) {
                nextElement = (*thisElement).left;
            } else { //jesli wartosc sie zgadza, zwrocenie prawdy
                return true;
            }
        } while (nextElement != nullptr);
    }
    return false;
}

void BSTree::display() { //wyswietlanie drzewa w konsoli
    //printTree(root, 0); //wywolanie funkcji prezenujacej graficznie drzewo
    printBT(root);
    if (root == nullptr){ //jesli drzewo jest puste
        std::cout << "Drzewo jest puste";
    } else { //jesli nie jest puste
        inorder(root); //wyswietlenie elementow w kolejnosci inorder
        std::cout << std::endl;
    }
}

void BSTree::loadFromFile(std::string fileName) { //wczytanie drzewa z pliku
    root = nullptr; //czyszczenie drzewa
    elementCount = 0;
    std::ifstream file(fileName);
    int treeSize;
    file >> treeSize; //ladowanie pierwszej liczby z pliku jako liczby elementow
    for (int i = 0; i < treeSize; i++) {
        int value;
        file >> value;
        addElement(value); //zapisywanie kolejnych elementow z pliku jako kolejne elementy listy
    }
}

void BSTree::generateTree(int size) { //generowanie losowego drzewa
    root = nullptr; //czyszczenie drzewa
    elementCount = 0;
    srand((unsigned int)(size_t) time); //generowanie liczb pseudolosowych
    for (int i = 0; i < size; i++) { //dla kolejnych wartosci licznika i az do 'number'
        int value = rand();
        addElement(value); //wywolanie funkcji tworzacej nowy element
    }
}

void BSTree::DSWalgorithm() { //rownowazenie drzewa algorytmem DSW
    TreeElement *thisElement = root; //rozpoczecie od korzenia
    do{
        while (thisElement->left != nullptr){//dopoki jest lewy syn
            rotateRight(thisElement->left); //rotacje w prawo
            thisElement = thisElement->parent;
        }
        thisElement = thisElement->right;
    } while (thisElement != nullptr); //dopoki nie dotrzemy do liscia
    int n = elementCount;
    int m = (int) pow(2,floor(log2(n+1))) - 1; //wyliczanie wartosci m potrzebnej do kolejnego kroku
    thisElement = root->right;
    for (int i = 0; i < n-m; i++){//rotacje co drugiego wezla w lewo
        rotateLeft(thisElement);
        thisElement = thisElement->right->right;
    }
    while (m > 1){ //kolejne rotacje co drugiego wezla w lewo
        thisElement = root->right;
        m = floor(m/2);
        for (int i = 0; i < m; i++){
            rotateLeft(thisElement);
            thisElement = thisElement->right->right;
        }
    }
}

void BSTree::inorder(TreeElement *thisElement){ //wyswietlanie elementow w kolejnosci inorder
    if (thisElement->left != nullptr){ //jesli jest lewy syn
        inorder(thisElement->left); //inorder dla lewego syna
    }
    std::cout << thisElement->value << " "; //wypisanie wartosci obecnego wezla
    if (thisElement->right != nullptr){ //jesli jest prawy syn
        inorder(thisElement->right); //inorder dla prawego syna
    }
}

void BSTree::printTree(TreeElement *thisElement, int space){ //graficzne przedstawienie drzewa - gotowe rozwiazanie znalezione w internecie
    if (thisElement == nullptr)
        return;
    space += 2;
    printTree(thisElement->right, space);
    for (int i = 2; i < space; i++)
        std::cout<<"\t";
    std::cout << thisElement->value << "\n";
    printTree(thisElement->left, space);
}

BSTree::TreeElement *BSTree::successor(TreeElement *thisElement){ //znajdowanie nastepnika
    if (thisElement->right != nullptr){ //jezeli jest prawy syn
        thisElement = thisElement->right;
        while (thisElement->left != nullptr){ //szukanie najmniejszego liscia
            thisElement = thisElement->left;
        }
        return thisElement;
    } else { //jezeli nie ma prawego syna
        TreeElement *x = thisElement->parent; //szukanie nastepnika sposrod przodkow wezla
        while (x != nullptr && thisElement == x->right) {
            thisElement = x;
            x = x->parent;
        }
        return x;
    }
}

void BSTree::rotateRight(BSTree::TreeElement *thisElement) { //rotacje w prawo
    TreeElement *parent = thisElement->parent;
    if (parent->parent != nullptr) {
        if (parent->parent->left == parent) { //wezel ktory do tej pory byl synem zapisujemy jako syna rodzica dotychczasowego rodzica
            parent->parent->left = thisElement;
        } else {
            parent->parent->right = thisElement;
        }
    } else { //lub jako korzen
        root = thisElement;
    }
    parent->left = thisElement->right; //odpowiednie przypisania
    if (thisElement->right != nullptr)
        thisElement->right->parent = parent;
    thisElement->parent = parent->parent;
    parent->parent = thisElement;
    thisElement->right = parent;
}

void BSTree::rotateLeft(BSTree::TreeElement *thisElement) { //rotacja w lewo - algorytm analogiczny do rotacji w prawo
    TreeElement *parent = thisElement->parent;
    if (parent->parent != nullptr) {
        if (parent->parent->left == parent) {
            parent->parent->left = thisElement;
        } else {
            parent->parent->right = thisElement;
        }
    } else {
        root = thisElement;
    }
    parent->right = thisElement->left;
    if (thisElement->left != nullptr)
        thisElement->left->parent = parent;
    thisElement->parent = parent->parent;
    parent->parent = thisElement;
    thisElement->left = parent;
}

BSTree::TreeElement *BSTree::getRoot() const { //wskaznik na korzen
    return root;
}

void BSTree::printBT(const std::string& prefix, const TreeElement* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "'--" );

        // print the value of the node
        std::cout << node->value << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

void BSTree::printBT(const TreeElement* node)
{
    printBT("", node, false);
}