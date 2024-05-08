#include "heapTest.h"
#include "test.h"

double HeapTest::add(Heap &heap, int number) {
    double time = 0;
    srand ((unsigned int)(size_t) time);
    for (int i = 0; i < number; i++){
        int value = rand();
        Test::StartCounter();
        heap.addElement(value);
        heap.fixFromBottom(heap.getHeapSize()-1);
        time += Test::GetCounter();
    }
    return time/number;
}

double HeapTest::remove(Heap &heap, int number) {
    double time = 0;
    for (int i = 0; i < number; i++){
        Test::StartCounter();
        heap.removeRoot();
        time += Test::GetCounter();
    }
    return time/number;
}

double HeapTest::search(Heap &heap, int number) {
    double time = 0;
    srand ((unsigned int)(size_t) time);
    for (int i = 0; i < number; i++){
        int value = rand();
        Test::StartCounter();
        heap.searchHeap(value);
        time += Test::GetCounter();
    }
    return time/number;
}
