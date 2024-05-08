#include "treeTest.h"
#include "test.h"

double TreeTest::add(BSTree &tree, int number) {
    double time = 0;
    srand ((unsigned int)(size_t) time);
    for (int i = 0; i < number; i++){
        int value = rand();
        Test::StartCounter();
        tree.addElement(value);
        tree.DSWalgorithm();
        time+=Test::GetCounter();
    }
    return time/number;
}

double TreeTest::remove(BSTree &tree, int number) {
    double time = 0;
    for (int i = 0; i < number; i++){
        int value = tree.getRoot()->value;
        Test::StartCounter();
        tree.removeElement(value);
        tree.DSWalgorithm();
        time+=Test::GetCounter();
    }
    return time/number;
}

double TreeTest::search(BSTree &tree, int number) {
    double time = 0;
    srand ((unsigned int)(size_t) time);
    for (int i = 0; i < number; i++){
        int value = rand();
        Test::StartCounter();
        tree.searchTree(value);
        time+=Test::GetCounter();
    }
    return time/number;
}
