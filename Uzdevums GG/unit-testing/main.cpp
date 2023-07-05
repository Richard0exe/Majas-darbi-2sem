#include <iostream>
#include "../program1/header.h"
#include <cassert>
/// G_linked_list.cpp
/*********************************************************
G9. Uzrakstīt funkciju, kas pārbauda, vai sarakstā ir
vismaz divi elementi ar vienādām vērtībām.
********************************************************/
/// Autors: Ričards Bubišs, rb22033
/// Veidota: 21.05.2023
using namespace std;
///Empty
void test1() {
    elem *first = NULL;
    try{ (twoMatches(first));
    }
        catch (int e){
            if (e==5) cout<<"Passed"<<endl;
        };

}
///2 equal elements
void test2() {
    elem *first = NULL, *last;
    append(first, last, 2);
    append(first, last, 4);
    append(first, last, 6);
    append(first, last, 2);
    if (!twoMatches(first))
        throw "Test 2 failed: Expected true, got false";
}
///More than 2 equal elements
void test3() {
    elem *first = NULL, *last;
    append(first, last, 1);
    append(first, last, 2);
    append(first, last, 3);
    append(first, last, 2);
    append(first, last, 4);
    append(first, last, 3);
    append(first, last, 1);
    if (!twoMatches(first))
        throw "Test 3 failed: Expected true, got false";
}

void test4() {
    elem *first = nullptr, *last;
    append(first, last, 2);
    append(first, last, 4);
    append(first, last, 6);
    if (twoMatches(first))
        throw "Test 4 failed: Expected false, got true";
}


void runTests() {
    try {
        test1();
        cout << "Test 1 passed!" << endl;

        test2();
        cout << "Test 2 passed!" << endl;

        test3();
        cout << "Test 3 passed!" << endl;

        test4();
        cout << "Test 4 passed!" << endl;

        cout << "All tests passed!" << endl;
    } catch (const char* errorMessage) {
        cout << "Test failed: " << errorMessage << endl;
    }
}

int main() {
    runTests();
    return 0;
}
