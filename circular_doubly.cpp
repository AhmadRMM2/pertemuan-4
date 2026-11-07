
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *berikut;
};

int main() {
    Node *A = new Node;
    Node *B = new Node;
    Node *C = new Node;

    A->data = 10;
    B->data = 20;
    C->data = 30;

    // Hubungan ke depan
    A->berikut = B;
    B->berikut = C;
    C->berikut = A;

    // Hubungan ke belakang
    A->prev = C;
    B->prev = A;
    C->prev = B;

    Node *temp = A;

    cout << "Dari depan: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->berikut;
    } while (temp != A);

    cout << "(kembali ke awal)" << endl;

    temp = C;

    cout << "Dari belakang: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->prev;
    } while (temp != C);

    cout << "(kembali ke akhir)" << endl;

    // Putuskan hubungan melingkar
    A->prev = NULL;
    C->berikut = NULL;

    delete A;
    delete B;
    delete C;

    return 0;
}



