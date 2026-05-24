#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Marsh {
public:
    char name1[20] = "";
    char name2[20] = "";
    int number = 0;

    Marsh() {}

    Marsh(const char* n, const char* a, int p) {
        strncpy_s(name1, n, 19);
        strncpy_s(name2, a, 19);
        number = p;
    }

    Marsh(const Marsh& m) {
        strncpy_s(name1, m.name1, 19);
        strncpy_s(name2, m.name2, 19);
        number = m.number;
    }

    Marsh& operator=(const Marsh& m) {
        if (this != &m) {
            strncpy_s(name1, m.name1, 19);
            strncpy_s(name2, m.name2, 19);
            number = m.number;
        }
        return *this;
    }

    bool operator<(const Marsh& m) {
        return strcmp(name1, m.name1) < 0;
    }
    bool operator>(const Marsh& m) {
        return strcmp(name1, m.name1) > 0;
    }

    friend ostream& operator<<(ostream& os, const Marsh& m) {
        return os << m.name1 << " " << m.name2 << " " << m.number;
    }

    friend istream& operator>>(istream& os, const Marsh& m) {
        return os >> m.name1 >> m.name2 >> m.number;
    }

    static bool compName1(const Marsh& m1, const Marsh& m2) {
        return strcmp(m1.name1, m2.name1) < 0;
    }
    static bool compName2(const Marsh& m1, const Marsh& m2) {
        return strcmp(m1.name2, m2.name2) < 0;
    }
    static bool compNumber(Marsh& m1, Marsh& m2) {
        return m1.number < m2.number;
    }
    static int compNumberQsort(const void* a, const void* b) {
        Marsh* m1 = (Marsh*)a;
        Marsh* m2 = (Marsh*)b;
        return m1->number - m2->number;
    }
    char* getname1();
};
