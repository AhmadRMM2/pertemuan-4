#include <iostream>
using namespace std;

// ==================================================
// 1. SINGLY LINKED LIST
// ==================================================

struct NodeSingly
{
    int data;
    NodeSingly *next;
};

void tampilkanSingly(NodeSingly *head)
{
    NodeSingly *bantu = head;
// fguaiosdfjioasdjfjasdfjoasdjfoajsdfujasduiofasdiofuioasdf
    while (bantu != NULL)
    {
        cout << bantu->data << " -> ";
        bantu = bantu->next;
    }

    cout << "NULL" << endl;
}

void singlyLinkedList()
{
    NodeSingly *A = new NodeSingly;
    NodeSingly *B = new NodeSingly;
    NodeSingly *C = new NodeSingly;

    A->data = 10;
    B->data = 20;
    C->data = 30;

    A->next = B;
    B->next = C;
    C->next = NULL;

    cout << "1. SINGLY LINKED LIST" << endl;
    cout << "Sebelum ditambah: ";
    tampilkanSingly(A);

    // Menambahkan node 25 setelah node 20
    NodeSingly *baru = new NodeSingly;
    baru->data = 25;

    baru->next = B->next;
    B->next = baru;

    cout << "Sesudah ditambah: ";
    tampilkanSingly(A);
    cout << endl;
}

// ==================================================
// 2. CIRCULAR LINKED LIST
// ==================================================

struct NodeCircular
{
    int data;
    NodeCircular *next;
};

void tampilkanCircular(NodeCircular *head)
{
    if (head == NULL)
    {
        return;
    }

    NodeCircular *bantu = head;

    do
    {
        cout << bantu->data << " -> ";
        bantu = bantu->next;
    } while (bantu != head);

    cout << "(kembali ke awal)" << endl;
}

void circularLinkedList()
{
    NodeCircular *A = new NodeCircular;
    NodeCircular *B = new NodeCircular;
    NodeCircular *C = new NodeCircular;

    A->data = 10;
    B->data = 20;
    C->data = 30;

    A->next = B;
    B->next = C;
    C->next = A;

    cout << "2. CIRCULAR LINKED LIST" << endl;
    cout << "Sebelum ditambah: ";
    tampilkanCircular(A);

    // Menambahkan node 40 di akhir
    NodeCircular *baru = new NodeCircular;
    baru->data = 40;

    baru->next = A;
    C->next = baru;

    cout << "Sesudah ditambah: ";
    tampilkanCircular(A);
    cout << endl;
}

// ==================================================
// 3. DOUBLY LINKED LIST
// ==================================================

struct NodeDoubly
{
    int data;
    NodeDoubly *prev;
    NodeDoubly *next;
};

void tampilkanDoubly(NodeDoubly *head)
{
    NodeDoubly *bantu = head;

    cout << "NULL <-> ";

    while (bantu != NULL)
    {
        cout << bantu->data << " <-> ";
        bantu = bantu->next;
    }

    cout << "NULL" << endl;
}

void doublyLinkedList()
{
    NodeDoubly *A = new NodeDoubly;
    NodeDoubly *B = new NodeDoubly;
    NodeDoubly *C = new NodeDoubly;

    A->data = 10;
    A->prev = NULL;
    A->next = B;

    B->data = 20;
    B->prev = A;
    B->next = C;

    C->data = 30;
    C->prev = B;
    C->next = NULL;

    cout << "3. DOUBLY LINKED LIST" << endl;
    cout << "Sebelum ditambah: ";
    tampilkanDoubly(A);

    // Menambahkan node 25 di antara 20 dan 30
    NodeDoubly *baru = new NodeDoubly;
    baru->data = 25;

    baru->prev = B;
    baru->next = C;

    B->next = baru;
    C->prev = baru;

    cout << "Sesudah ditambah: ";
    tampilkanDoubly(A);
    cout << endl;
}

// ==================================================
// 4. CIRCULAR DOUBLY LINKED LIST
// ==================================================

struct NodeCircularDoubly
{
    int data;
    NodeCircularDoubly *prev;
    NodeCircularDoubly *next;
};

void tampilkanCircularDoubly(
    NodeCircularDoubly *head)
{
    if (head == NULL)
    {
        return;
    }

    NodeCircularDoubly *bantu = head;
    // apalaah dia fjklasdflkasdfjasdjfjasdfjklasdfjklasdkl;fjasdkl;jflasdfasd
    do
    {
        cout << bantu->data << " <-> ";
        bantu = bantu->next;
    } while (bantu != head);

    cout << "(kembali ke awal)" << endl;
}

void circularDoublyLinkedList()
{
    NodeCircularDoubly *A = new NodeCircularDoubly;
    NodeCircularDoubly *B = new NodeCircularDoubly;
    NodeCircularDoubly *C = new NodeCircularDoubly;

    A->data = 10;
    A->prev = C;
    A->next = B;

    B->data = 20;
    B->prev = A;
    B->next = C;

    C->data = 30;
    C->prev = B;
    C->next = A;

    cout << "4. CIRCULAR DOUBLY LINKED LIST" << endl;
    cout << "Sebelum ditambah: ";
    tampilkanCircularDoubly(A);

    // Menambahkan node 40 setelah node 30
    NodeCircularDoubly *baru = new NodeCircularDoubly;
    baru->data = 40;

    baru->prev = C;
    baru->next = A;

    C->next = baru;
    A->prev = baru;

    cout << "Sesudah ditambah: ";
    tampilkanCircularDoubly(A);
    cout << endl;
}

// ==================================================
// MAIN PROGRAM
// Semua variasi langsung dijalankan
// ==================================================

int main()
{
    singlyLinkedList();
    circularLinkedList();
    doublyLinkedList();
    circularDoublyLinkedList();

    system("pause");
    return 0;
}
