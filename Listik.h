friend ostream& operator<<(ostream& os, const List& lst);



ostream& operator<<(ostream& os, const List& lst) {

    Node* p = lst.head;

    while (p != nullptr) {
        os << p->data << endl;
        p = p->next;
    }

    return os;
}


cout << lst;
