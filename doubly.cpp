
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *berikut;
};

void tampilkan(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data;

        if (temp->berikut != NULL)
            cout << " <-> ";

        temp = temp->berikut;
    }

    cout << endl;
}

int main() {
    // Membuat node awal
    Node *A = new Node;
    Node *B = new Node;
    Node *C = new Node;

    A->data = 10;
    A->prev = NULL;
    A->berikut = B;

    B->data = 20;
    B->prev = A;
    B->berikut = C;

    C->data = 30;
    C->prev = B;
    C->berikut = NULL;

    cout << "Sebelum penambahan:" << endl;
    tampilkan(A);

    // Membuat node baru berisi 25
    Node *baru = new Node;
    baru->data = 25;

    // Menghubungkan node 25
    baru->prev = B;
    baru->berikut = C;

    B->berikut = baru;
    C->prev = baru;

    cout << "Setelah penambahan:" << endl;
    tampilkan(A);

    // Menampilkan dari belakang
    cout << "Dari belakang: ";
    Node *temp = C;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;

    // Menghapus semua node
    delete A;
    delete B;
    delete baru;
    delete C;

    return 0;
}



