#include <iostream>
using namespace std;
struct NodeSingly
{
    int data;
    NodeSingly *next;
};
void tampilkanSingly(NodeSingly *head)
{
    NodeSingly *bantu = head;
    while (bantu != NULL)
    {
        cout << bantu->data << " -> ";
        bantu = bantu->next;
    }
    cout << "NULL" << endl;
}
void singlyLinkedList(int data[], int jumlah)
{
    NodeSingly *head = NULL;
    NodeSingly *tail = NULL;

    for (int i = 0; i < jumlah; i++)
    {
        NodeSingly *baru = new NodeSingly;
        baru->data = data[i];
        baru->next = NULL;

        if (head == NULL)
        {
            head = baru;
            tail = baru;
        }
        else
        {
            tail->next = baru;
            tail = baru;
        }
    }

    tampilkanSingly(head);
}

struct NodeCircular
{
    int data;
    NodeCircular *next;
};
void tampilkanCircular(NodeCircular *head, int data[])
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
    cout << "(kembali ke " << data[0] << ")" << endl;
}
void circularLinkedList(int data[], int jumlah)
{
    NodeCircular *head = NULL;
    NodeCircular *tail = NULL;

    for (int i = 0; i < jumlah; i++)
    {
        NodeCircular *baru = new NodeCircular;
        baru->data = data[i];
        baru->next = NULL;

        if (head == NULL)
        {
            head = baru;
            tail = baru;
        }
        else
        {
            tail->next = baru;
            tail = baru;
        }
    }
    if (tail != NULL)
    {
        tail->next = head;
    }
    tampilkanCircular(head, data);
}
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
void doublyLinkedList(int data[], int jumlah)
{
    NodeDoubly *head = NULL;
    NodeDoubly *tail = NULL;

    for (int i = 0; i < jumlah; i++)
    {
        NodeDoubly *baru = new NodeDoubly;
        baru->data = data[i];
        baru->next = NULL;
        baru->prev = NULL;

        if (head == NULL)
        {
            head = baru;
            tail = baru;
        }
        else
        {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }
    tampilkanDoubly(head);
}
struct NodeCircularDoubly
{
    int data;
    NodeCircularDoubly *prev;
    NodeCircularDoubly *next;
};
void tampilkanCircularDoubly(
    NodeCircularDoubly *head, int data[])
{
    if (head == NULL)
    {
        return;
    }
    NodeCircularDoubly *bantu = head;
    do
    {
        cout << bantu->data << " <-> ";
        bantu = bantu->next;
    } while (bantu != head);
    cout << "(kembali ke " << data[0] << ")" << endl;
}
void circularDoublyLinkedList(int data[], int jumlah)
{
    NodeCircularDoubly *head = NULL;
    NodeCircularDoubly *tail = NULL;

    for (int i = 0; i < jumlah; i++)
    {
        NodeCircularDoubly *baru = new NodeCircularDoubly;
        baru->data = data[i];
        baru->next = NULL;
        baru->prev = NULL;

        if (head == NULL)
        {
            head = baru;
            tail = baru;
        }
        else
        {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }
    if (tail != NULL)
    {
        tail->next = head;
        head->prev = tail;
    }
    tampilkanCircularDoubly(head, data);
}
int main()
{
    cout << "==============================================================\n";
    cout << "                       PROGRAM NODE                           \n";
    cout << "==============================================================\n";
    int jumlah;
    cout << "Masukkan jumlah data: ";
    cin >> jumlah;
    int data[100];
    for (int i = 0; i < jumlah; i++)
    {
        cout << "Masukkan data ke-" << i + 1 << ": ";
        cin >> data[i];
    }
    int pilihan;
    do
    {
        cout << "\n\nPilih Opsi Node \n";
        cout << "1. Singly Linked List\n";
        cout << "2. Circular Linked List\n";
        cout << "3. Doubly Linked List\n";
        cout << "4. Circular Doubly Linked List\n";
        cout << "5. Tampilkan Semua Variasi\n";
        cout << "6. Keluar\n";

        cout << "Masukkan pilihan : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            singlyLinkedList(data, jumlah);
            break;
        case 2:
            circularLinkedList(data, jumlah);
            break;
        case 3:
            doublyLinkedList(data, jumlah);
            break;
        case 4:
            circularDoublyLinkedList(data, jumlah);
            break;
        case 5:
            cout << "ini adalah variasi Singly Linked list\n";
            singlyLinkedList(data, jumlah);
            cout << "\n ini adalah variasi circular linked list\n";
            circularLinkedList(data, jumlah);
            cout << "\n ini adalah variasi doubly linked list\n";
            doublyLinkedList(data, jumlah);
            cout << "\n ini adalah variasi circular doubly linked list\n";
            circularDoublyLinkedList(data, jumlah);
            break;
        case 6:
            cout << "anda telah keluar dari program\n";
            break;

        default:
            cout << "Input yang anda masukkan salah";
            break;
        }
    } while (pilihan != 6);
    system("pause");
    return 0;
}