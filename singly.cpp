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

    // Mengisi data
    A->data = 10;
    A->berikut = B;

    B->data = 20;
    B->berikut = C;

    C->data = 30;
    C->berikut = NULL;

    // Menampilkan linked list
    Node *temp = A;

    cout << "Singly Linked List: ";
    while (temp != NULL) {
        cout << temp->data;

        if (temp->berikut != NULL)
            cout << " -> ";

        temp = temp->berikut;
    }

    cout << endl;

    // Menghapus node
    delete A;
    delete B;
    delete C;

	return 0;
}


