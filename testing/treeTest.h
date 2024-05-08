//
// Created by mrozn on 24.04.2023.
//

#ifndef SDIZO1_TREETEST_H
#define SDIZO1_TREETEST_H


#include "../structures/BSTree.h"

class TreeTest {

public:
    static double add(BSTree &tree, int number);

    static double remove(BSTree &tree, int number);

    static double search(BSTree &tree, int number);
};


#endif //SDIZO1_TREETEST_H
