#include <iostream>
using namespace std;
struct NodeSingly {
    int data;
    NodeSingly* next;
};
void inputdata(){
}
void tampilkanSingly(NodeSingly* head) {
    NodeSingly* bantu = head;
	
	cout << "Node Singly: ";
    while (bantu != NULL) {
        cout << bantu->data << " -> ";
        bantu = bantu->next;
    }
    cout << "NULL" << endl;
}
void singlyLinkedList(int data[], int jumlah) {
 	NodeSingly* head = NULL;
 	NodeSingly* tail = NULL;
 	
 	for(int i = 0; i < jumlah; i++){
 		NodeSingly* baru = new NodeSingly;
 		baru -> data = data[i];
 		baru -> next = NULL;
 		
 		if (head == NULL){
 			head = baru;
 			tail = baru;
		 } else {
		 	tail -> next = baru;
		 	tail = baru;
		 }
	 }
	 
	 tampilkanSingly(head);
}
struct NodeCircular {
    int data;
    NodeCircular* next;
};
void tampilkanCircular(NodeCircular* head) {
    if (head == NULL) {
        return;
    }
    NodeCircular* bantu = head;
    do {
        cout << bantu->data << " -> ";
        bantu = bantu->next;
    } while (bantu != head);
    cout << "(kembali ke awal)" << endl;
}
void circularLinkedList() {
    NodeCircular* A = new NodeCircular;
    NodeCircular* B = new NodeCircular;
    NodeCircular* C = new NodeCircular;
    A->data = 10;
    B->data = 20;
    C->data = 30;
    A->next = B;
    B->next = C;
    C->next = A;
    cout << "2. CIRCULAR LINKED LIST" << endl;
    cout << "Sebelum ditambah: ";
    tampilkanCircular(A);
    NodeCircular* baru = new NodeCircular;
    baru->data = 40;
    baru->next = A;
    C->next = baru;
    cout << "Sesudah ditambah: ";
    tampilkanCircular(A);
    cout << endl;
}
struct NodeDoubly {
    int data;
    NodeDoubly* prev;
    NodeDoubly* next;
};
void tampilkanDoubly(NodeDoubly* head) {
    NodeDoubly* bantu = head;
    cout << "NULL <-> ";
    while (bantu != NULL) {
        cout << bantu->data << " <-> ";
        bantu = bantu->next;
    }
    cout << "NULL" << endl;
}
void doublyLinkedList() {
    NodeDoubly* A = new NodeDoubly;
    NodeDoubly* B = new NodeDoubly;
    NodeDoubly* C = new NodeDoubly;
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
    NodeDoubly* baru = new NodeDoubly;
    baru->data = 25;
    baru->prev = B;
    baru->next = C;
    B->next = baru;
    C->prev = baru;
    cout << "Sesudah ditambah: ";
    tampilkanDoubly(A);
    cout << endl;
}
struct NodeCircularDoubly {
    int data;
    NodeCircularDoubly* prev;
    NodeCircularDoubly* next;
};
void tampilkanCircularDoubly(
    NodeCircularDoubly* head
) {
    if (head == NULL) {
        return;
    }
    NodeCircularDoubly* bantu = head;
    do {
        cout << bantu->data << " <-> ";
        bantu = bantu->next;
    } while (bantu != head);
    cout << "(kembali ke awal)" << endl;
}
void circularDoublyLinkedList() {
    NodeCircularDoubly* A = new NodeCircularDoubly;
    NodeCircularDoubly* B = new NodeCircularDoubly;
    NodeCircularDoubly* C = new NodeCircularDoubly;
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
    NodeCircularDoubly* baru = new NodeCircularDoubly;
    baru->data = 40;
    baru->prev = C;
    baru->next = A;
    C->next = baru;
    A->prev = baru;
    cout << "Sesudah ditambah: ";
    tampilkanCircularDoubly(A);
    cout << endl;
}
int main() {
	cout << "==============================================================\n";
	cout << " 						PROGRAM NODE\n";
	cout << "==============================================================\n";
	int jumlah;
	cout << "Masukkan jumlah data: ";
	cin >> jumlah;
	int data[100];	
	for(int i=0 ; i < jumlah; i++){
		cout << "Masukkan data ke-" << i+1 << ": ";
		cin >> data[i];
	}
	do{
		int pilihan;
		cout << "\n\nPilih Opsi Node \n";
		cout << "1. Singy Linked List\n";
		cout << "2. Circular Linked List\n";
		cout << "3. Doubly Linked List\n";
		cout << "4. Circular Doubly Linked List\n";
		cout << "5. Tampilkan Semua Variasi\n";
		cout << "6. Keluar\n";
		
		cout << "Masukkan pilihan : ";
		cin >> pilihan;

        switch (pilihan)
        {
        case constant expressionz:
            /* code */
            break;
        
        default:
            break;
        }
	}
    singlyLinkedList(data, jumlah);
    circularLinkedList(data, jumlah);
    doublyLinkedList(data, jumlah);
    circularDoublyLinkedList(data, jumlah);
    return 0;
}
