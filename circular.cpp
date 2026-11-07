
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *berikut;
};

int main() {
    // Membuat node
    Node *A = new Node;
    Node *B = new Node;
    Node *C = new Node;

    // Mengisi data dan menghubungkan node
    A->data = 10;
    A->berikut = B;

    B->data = 20;
    B->berikut = C;

    C->data = 30;
    C->berikut = A;

    // Menampilkan circular linked list
    Node *temp = A;

    cout << "Circular Linked List: ";

    do {
        cout << temp->data << " -> ";
        temp = temp->berikut;
    } while (temp != A);

    cout << "(kembali ke awal)" << endl;

    // Memutus hubungan melingkar
    C->berikut = NULL;

    // Menghapus node
    delete A;
    delete B;
    delete C;

    return 0;
}
