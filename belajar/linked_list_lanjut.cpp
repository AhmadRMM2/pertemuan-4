#include <iostream>
using namespace std;

// =====================================================
// A. CIRCULAR LINKED LIST
// =====================================================
class NodeC {
public:
    int data;
    NodeC *berikut;
};

NodeC *buatNodeC(int x) {
    NodeC *B = new NodeC;
    B->data = x;
    B->berikut = B;              // awalnya menunjuk dirinya sendiri
    return B;
}

NodeC *cariAkhirC(NodeC *A) {
    NodeC *akhir = A;
    while (akhir->berikut != A) akhir = akhir->berikut;
    return akhir;
}

void tambahDepanC(NodeC *&A, int x) {
    NodeC *B = buatNodeC(x);
    if (A == 0) { A = B; return; }
    NodeC *akhir = cariAkhirC(A);
    B->berikut = A;              // B menunjuk elemen pertama lama
    akhir->berikut = B;          // elemen terakhir menunjuk B
    A = B;                       // B jadi elemen pertama
}

void tambahBelakangC(NodeC *&A, int x) {
    NodeC *B = buatNodeC(x);
    if (A == 0) { A = B; return; }
    NodeC *akhir = cariAkhirC(A);
    B->berikut = A;              // B menutup lingkaran
    akhir->berikut = B;
}

// sisip x setelah node yang berisi nilai "cari"
bool tambahSetelahC(NodeC *A, int cari, int x) {
    if (A == 0) return false;
    NodeC *P = A;
    do {
        if (P->data == cari) {
            NodeC *B = buatNodeC(x);
            B->berikut = P->berikut;   // 1. B menunjuk node setelah P
            P->berikut = B;            // 2. P menunjuk B
            return true;
        }
        P = P->berikut;
    } while (P != A);
    return false;
}

void hapusDepanC(NodeC *&A) {
    if (A == 0) return;
    if (A->berikut == A) {       // hanya 1 elemen
        delete A;
        A = 0;
        return;
    }
    NodeC *akhir = cariAkhirC(A);
    NodeC *hapus = A;
    A = A->berikut;
    akhir->berikut = A;
    delete hapus;
}

void hapusBelakangC(NodeC *&A) {
    if (A == 0) return;
    if (A->berikut == A) {
        delete A;
        A = 0;
        return;
    }
    NodeC *P = A;
    while (P->berikut->berikut != A) P = P->berikut;   // elemen sebelum terakhir
    NodeC *hapus = P->berikut;
    P->berikut = A;
    delete hapus;
}

// hapus node yang berisi nilai tertentu (di mana saja)
bool hapusNilaiC(NodeC *&A, int nilai) {
    if (A == 0) return false;
    if (A->data == nilai) { hapusDepanC(A); return true; }
    NodeC *P = A;
    while (P->berikut != A && P->berikut->data != nilai) P = P->berikut;
    if (P->berikut == A) return false;                 // tidak ketemu
    NodeC *hapus = P->berikut;
    P->berikut = hapus->berikut;
    delete hapus;
    return true;
}

void cetakC(NodeC *A) {
    if (A == 0) { cout << "(kosong)\n"; return; }
    NodeC *P = A;
    do {
        cout << P->data << " -> ";
        P = P->berikut;
    } while (P != A);
    cout << "(kembali ke " << A->data << ")\n";
}

// =====================================================
// B. DOUBLY LINKED LIST
// =====================================================
class NodeD {
public:
    int data;
    NodeD *berikut;
    NodeD *sebelum;
};

NodeD *buatNodeD(int x) {
    NodeD *B = new NodeD;
    B->data = x;
    B->berikut = 0;
    B->sebelum = 0;
    return B;
}

void tambahDepanD(NodeD *&A, int x) {
    NodeD *B = buatNodeD(x);
    if (A != 0) {
        B->berikut = A;          // 1. B maju ke A
        A->sebelum = B;          // 2. A mundur ke B
    }
    A = B;                       // 3. A pindah ke B
}

void tambahBelakangD(NodeD *&A, int x) {
    NodeD *B = buatNodeD(x);
    if (A == 0) { A = B; return; }
    NodeD *akhir = A;
    while (akhir->berikut != 0) akhir = akhir->berikut;
    akhir->berikut = B;
    B->sebelum = akhir;
}

bool tambahSetelahD(NodeD *A, int cari, int x) {
    NodeD *P = A;
    while (P != 0 && P->data != cari) P = P->berikut;
    if (P == 0) return false;
    NodeD *B = buatNodeD(x);
    B->berikut = P->berikut;     // 1. B maju ke node setelah P
    B->sebelum = P;              // 2. B mundur ke P
    if (P->berikut != 0)
        P->berikut->sebelum = B; // 3. node setelah P mundur ke B (sebelum langkah 4!)
    P->berikut = B;              // 4. P maju ke B
    return true;
}

void hapusDepanD(NodeD *&A) {
    if (A == 0) return;
    NodeD *hapus = A;
    A = A->berikut;
    if (A != 0) A->sebelum = 0;  // cek dulu, kalau tadi 1 elemen A sudah null
    delete hapus;
}

void hapusBelakangD(NodeD *&A) {
    if (A == 0) return;
    NodeD *akhir = A;
    while (akhir->berikut != 0) akhir = akhir->berikut;
    if (akhir->sebelum != 0) akhir->sebelum->berikut = 0;
    else A = 0;                  // hanya 1 elemen
    delete akhir;
}

bool hapusNilaiD(NodeD *&A, int nilai) {
    NodeD *hapus = A;
    while (hapus != 0 && hapus->data != nilai) hapus = hapus->berikut;
    if (hapus == 0) return false;
    if (hapus->sebelum != 0) hapus->sebelum->berikut = hapus->berikut;
    else A = hapus->berikut;     // yang dihapus elemen pertama
    if (hapus->berikut != 0) hapus->berikut->sebelum = hapus->sebelum;
    delete hapus;
    return true;
}

void cetakD(NodeD *A) {
    if (A == 0) { cout << "(kosong)\n"; return; }
    NodeD *P = A, *akhir = A;
    cout << "Maju  : ";
    while (P != 0) {
        cout << P->data << " ";
        akhir = P;
        P = P->berikut;
    }
    cout << "\nMundur: ";
    for (P = akhir; P != 0; P = P->sebelum) cout << P->data << " ";
    cout << "\n";
}

// =====================================================
int main() {
    cout << "=== CIRCULAR LINKED LIST ===\n";
    NodeC *A = 0;
    tambahBelakangC(A, 1);
    tambahBelakangC(A, 2);
    tambahBelakangC(A, 3);
    cout << "Awal             : "; cetakC(A);
    tambahDepanC(A, 9);
    cout << "Tambah depan 9   : "; cetakC(A);
    tambahSetelahC(A, 2, 7);
    cout << "Sisip 7 setelah 2: "; cetakC(A);
    tambahBelakangC(A, 5);
    cout << "Tambah belakang 5: "; cetakC(A);
    hapusDepanC(A);
    cout << "Hapus depan      : "; cetakC(A);
    hapusNilaiC(A, 7);
    cout << "Hapus nilai 7    : "; cetakC(A);
    hapusBelakangC(A);
    cout << "Hapus belakang   : "; cetakC(A);

    cout << "\n=== DOUBLY LINKED LIST ===\n";
    NodeD *D = 0;
    tambahBelakangD(D, 1);
    tambahBelakangD(D, 2);
    tambahBelakangD(D, 3);
    cout << "Awal\n"; cetakD(D);
    tambahDepanD(D, 9);
    cout << "Tambah depan 9\n"; cetakD(D);
    tambahSetelahD(D, 2, 7);
    cout << "Sisip 7 setelah 2\n"; cetakD(D);
    tambahBelakangD(D, 5);
    cout << "Tambah belakang 5\n"; cetakD(D);
    hapusDepanD(D);
    cout << "Hapus depan\n"; cetakD(D);
    hapusNilaiD(D, 7);
    cout << "Hapus nilai 7\n"; cetakD(D);
    hapusBelakangD(D);
    cout << "Hapus belakang\n"; cetakD(D);

    system("pause");
    return 0;
}
