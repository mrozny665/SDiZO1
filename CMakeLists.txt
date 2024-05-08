cmake_minimum_required(VERSION 3.24)
project(SDiZO1)

set(CMAKE_CXX_STANDARD 17)

add_executable(SDiZO1 main.cpp structures/table.cpp structures/table.h structures/list.cpp structures/list.h structures/heap.cpp structures/heap.h structures/BSTree.cpp structures/BSTree.h testing/tableTest.cpp testing/tableTest.h testing/test.cpp testing/test.h testing/listTest.cpp testing/listTest.h testing/heapTest.cpp testing/heapTest.h testing/treeTest.cpp testing/treeTest.h)
