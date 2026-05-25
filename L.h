List lst;

for (int i = 0; i < n; i++) {
    lst.insert_sorted(gr[i]);
}

cout << "\n------LIST------\n";
lst.print();

cout << "\nPUSH FRONT\n";
lst.push_front(Marsh("Paris", "Berlin", 1));
lst.print();

cout << "\nPUSH BACK\n";
lst.push_back(Marsh("Rome", "Madrid", 9999));
lst.print();

cout << "\nREMOVE Moscow\n";
lst.remove("Moscow");
lst.print();

Node* f = lst.find("Sochi");

if (f)
    cout << "\nFOUND: " << f->data << endl;
else
    cout << "\nNOT FOUND\n";
