#ifndef SDIZO1_HEAPTEST_H
#define SDIZO1_HEAPTEST_H


#include "../structures/heap.h"

class HeapTest {

public:
    static double add(Heap &heap, int number);

    static double remove(Heap &heap, int number);

    static double search(Heap &heap, int number);
};


#endif //SDIZO1_HEAPTEST_H
