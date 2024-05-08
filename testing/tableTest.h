#ifndef SDIZO1_TABLETEST_H
#define SDIZO1_TABLETEST_H


#include "../structures/table.h"

class TableTest {

public:
    static double addEnd(Table &table, int number);

    static double addStart(Table &table, int number);

    static double addMiddle(Table &table, int number);

    static double removeEnd(Table &table, int number);

    static double removeStart(Table &table, int number);

    static double removeMiddle(Table &table, int number);

    static double search(Table &table, int number);
};


#endif //SDIZO1_TABLETEST_H
