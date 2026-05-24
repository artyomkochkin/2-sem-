#include <fstream>
#include <iostream>
#include "Marsh.h"
#include "sort.h"
#include "List.h"
using namespace std;

int main() {
    Marsh gr[8];
    int n = 0;

    ifstream file("text.txt");
    if (!file.is_open()) {
        cout << "error" << endl;
        return 1;
    }

    char tempName1[20], tempName2[20];
    int tempNumber;
    while (n < 8 && file >> gr[n]){//tempName1 >> tempName2 >> tempNumber) {
        //gr[n] = Marsh(tempName1, tempName2, tempNumber);
        n++;
    }
    List lst;

    for (int i = 0; i < n; i++) {
        lst.insert_sorted(gr[i]);
    }

    cout << "\n------LIST------\n";
    lst.print();

    file.close();
    cout << "--------Before--------" << endl;
    for (int i = 0; i < 8; i++) {
        cout << gr[i] << endl;
    }
  
    insert(gr, n, Marsh::compNumber);
    //select(gr, n, Marsh::compNumber);
    //boobleSort(gr, n, Marsh::compNumber);
    //shell(gr, n, Marsh::compNumber);
    //qs(gr, 0, n-1, Marsh::compNumber);
    //qsort(gr,n,sizeof(Marsh), Marsh::compAgeQsort);
    cout << "--------After--------" << endl;
    for (int i = 0; i < 8; i++) {
        cout << gr[i] << endl;
    }
    ofstream out("marsh.bin", ios::binary);
    out.write((char*)gr, n * sizeof(Marsh));
    out.close();
  
    Marsh temp;
    ifstream fin("marsh.bin", ios::binary);
    char search[20];
    cout << "enter nane" << "\n";
    cin >> search;
    bool found = false;
    while (fin.read((char*)&temp, sizeof(Marsh))){
        if (strcmp(temp.getname1(), search) == 0){
            cout << "\nfound\n";
            cote << temp << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "\n not found\n";
    }
    fin.close();
    return 0;

}
