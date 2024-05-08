#ifndef SDIZO1_LISTTEST_H
#define SDIZO1_LISTTEST_H


#include "../structures/list.h"

class ListTest {

public:
    static double addEnd(List &list, int number);
    static double addStart(List &list, int number);
    static double addMiddle(List &list, int number);

    static double removeEnd(List &list, int number);
    static double removeStart(List &list, int number);
    static double removeMiddle(List &list, int number);

    static double search(List &list, int number);

};


#endif //SDIZO1_LISTTEST_H
