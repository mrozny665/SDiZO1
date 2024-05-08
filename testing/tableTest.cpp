#include "tableTest.h"
#include "test.h"
using namespace std;

double TableTest::addEnd(Table &table, int number){
    double time=0;
    srand((unsigned int)(size_t) time);
    for (int i = 0; i < number; i++){
        int value = rand();
        Test::StartCounter();
        table.addValue(table.getTableSize(), value);
        time += Test::GetCounter();
    }
    return time/number;
}

double TableTest::addStart(Table &table, int number){
    double time=0;
    srand((unsigned int)(size_t) time);
    for (int i = 0; i < number; i++){
        int value = rand();
        Test::StartCounter();
        table.addValue(0, value);
        time += Test::GetCounter();
    }
    return time/number;
}

double TableTest::addMiddle(Table &table, int number){
    double time=0;
    srand((unsigned int)(size_t) time);
    for (int i = 0; i < number; i++){
        int index = rand() % (table.getTableSize()-1) + 1;
        int value = rand();
        Test::StartCounter();
        table.addValue(index, value);
        time += Test::GetCounter();
    }
    return time/number;
}

double TableTest::removeEnd(Table &table, int number) {
    double time = 0;
    for (int i = 0; i < number; i++) {
        Test::StartCounter();
        table.deleteFromTable(table.getTableSize()-1);
        time += Test::GetCounter();
    }
    return time/number;
}

double TableTest::removeStart(Table &table, int number) {
    double time = 0;
    for (int i = 0; i < number; i++) {
        Test::StartCounter();
        table.deleteFromTable(0);
        time += Test::GetCounter();
    }
    return time/number;
}

double TableTest::removeMiddle(Table &table, int number) {
    double time = 0;
    srand((unsigned int)(size_t) time);
    for (int i = 0; i < number; i++) {
        int index = rand() % (table.getTableSize()-2) + 1;
        Test::StartCounter();
        table.deleteFromTable(index);
        time += Test::GetCounter();
    }
    return time/number;
}

double TableTest::search(Table &table, int number) {
    double time = 0;
    srand((unsigned int)(size_t) time);
    for (int i = 0; i < number; i++) {
        int value = rand();
        Test::StartCounter();
        table.isValueInTable(value);
        time += Test::GetCounter();
    }
    return time/number;
}
