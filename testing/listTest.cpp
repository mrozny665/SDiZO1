#include <iostream>
#include "listTest.h"
#include "test.h"
using namespace std;

double ListTest::addEnd(List &list, int number) {
    double time=0;
    srand((unsigned int)(size_t) time);
    for (int i = 0; i < number; i++){
        int value = rand();
        Test::StartCounter();
        list.addElement(list.getListSize(), value);
        time += Test::GetCounter();
    }
    return time/number;
}

double ListTest::addStart(List &list, int number) {
    double time=0;
    srand((unsigned int)(size_t) time);
    for (int i = 0; i < number; i++){
        int value = rand();
        Test::StartCounter();
        list.addElement(0, value);
        time += Test::GetCounter();
    }
    return time/number;
}

double ListTest::addMiddle(List &list, int number) {
    double time=0;
    srand((unsigned int)(size_t) time);
    for (int i = 0; i < number; i++){
        int index = rand() % (list.getListSize()-1) + 1;
        Test::StartCounter();
        list.addElement(index, rand());
        time += Test::GetCounter();
    }
    return time/number;
}

double ListTest::removeEnd(List &list, int number) {
    double time = 0;
    for (int i = 0; i < number; i++) {
        Test::StartCounter();
        list.removeElement2(list.getListSize()-1);
        time += Test::GetCounter();
    }
    return time/number;
}

double ListTest::removeStart(List &list, int number) {
    double time = 0;
    for (int i = 0; i < number; i++) {
        Test::StartCounter();
        list.removeElement2(0);
        time += Test::GetCounter();
    }
    return time/number;
}

double ListTest::removeMiddle(List &list, int number) {
    double time = 0;
    srand((unsigned int)(size_t) time);
    for (int i = 0; i < number; i++) {
        int index = rand() % (list.getListSize()-2) + 1;
        Test::StartCounter();
        list.removeElement2(index);
        time += Test::GetCounter();
    }
    return time/number;
}

double ListTest::search(List &list, int number) {
    double time = 0;
    srand((unsigned int) (size_t) time);
    for (int i = 0; i < number; i++) {
        int value = rand();
        Test::StartCounter();
        list.searchList(value);
        time += Test::GetCounter();
    }
    return time/number;
}