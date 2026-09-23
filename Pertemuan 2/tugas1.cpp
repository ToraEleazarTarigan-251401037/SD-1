//Buatlah program meneglola single linked list non circular yg menyimpan data nilai mhs.
// bisa nambah node di awal,akhir, dan bisa di delete. lalu tampilkan semua
#include <iostream>
using namespace std;

//Struktur Node untuk Single Linked List
struct Node {
    int data;
    Node* next;
};

// Pointer global untuk menunjuk awal (head) dari list
Node* head = NULL;

//Fungsi Tambah Node di Awal
void tambahAwal(int nilai) {
    Node* nodeBaru = new Node();
    nodeBaru->data = nilai;
    nodeBaru->next = head;
    head = nodeBaru;
    cout << "Berhasil menambahkan " << nilai << " di awal.\n";
}

//Fungsi Tambah Node di Akhir
void tambahAkhir(int nilai) {
    Node* nodeBaru = new Node();
    nodeBaru->data = nilai;
    nodeBaru->next = NULL;

    if (head == NULL) {
        head = nodeBaru;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }
    cout << "Berhasil menambahkan " << nilai << " di akhir.\n";
}
//Fungsi Tambah Node setelah nilai tertentu
void tambahSetelah(int nilaiCari, int nilaiBaru) {
    if (head == NULL) {
        cout << "Linked List kosong, tidak ada nilai " << nilaiCari << "!\n";
        return;
    }

    // Cari node yang berisi nilaiCari
    Node* temp = head;
    while (temp != NULL && temp->data != nilaiCari) {
        temp = temp->next;
    }

    // Jika tidak ditemukan
    if (temp == NULL) {
        cout << "Nilai " << nilaiCari << " tidak ditemukan dalam list!\n";
        return;
    }

    // Sisipkan node baru setelah temp
    Node* nodeBaru = new Node();
    nodeBaru->data = nilaiBaru;
    nodeBaru->next = temp->next;  // node baru menunjuk ke node setelah temp
    temp->next = nodeBaru;        // temp menunjuk ke node baru

    cout << "Berhasil menambahkan " << nilaiBaru << " setelah " << nilaiCari << ".\n";
}

// Fungsi untuk menghapus node berdasarkan nilai
void hapusNilai(int nilai) {
    // Kondisi 1: List kosong
    if (head == NULL) {
        cout << "Linked List kosong, tidak ada data yang bisa dihapus!\n";
        return;
    }

    Node* temp = head;

    // Kondisi 2: Node yang akan dihapus adalah node pertama (head)
    if (temp->data == nilai) {
        head = head->next; // Geser head ke node selanjutnya
        delete temp;       // Hapus node dari memori
        cout << "Nilai " << nilai << " berhasil dihapus dari list.\n";
        return;
    }

    // Kondisi 3: Mencari node di tengah atau akhir
    Node* prev = NULL;
    while (temp != NULL && temp->data != nilai) {
        prev = temp;
        temp = temp->next;
    }

    // Jika nilai tidak ditemukan sampai ujung list
    if (temp == NULL) {
        cout << "Nilai " << nilai << " tidak ditemukan dalam list!\n";
        return;
    }

    // Hubungkan node sebelum ke node sesudah
    prev->next = temp->next;
    delete temp; // Hapus node dari memori
    cout << "Nilai " << nilai << " berhasil dihapus dari list.\n";
}

// 4. Fungsi Tampilkan Linked List
void tampilkanList() {
    if (head == NULL) {
        cout << "Linked List kosong!\n";
        return;
    }

    Node* temp = head;
    cout << "Isi Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// 5. Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "\n=============MENU SINGLE LINKED LIST===============\n";
    cout << "1. Tambah di awal\n";
    cout << "2. Tambah di akhir\n";
    cout << "3. Tambah setelah nilai tertentu\n";
    cout << "4. Hapus berdasarkan nilai\n";
    cout << "5. Tampilkan Linked List\n";
    cout << "0. Keluar\n";
    cout << "===================================================\n";
    cout << "Pilihan : ";
}


int main() {
    int pilih;
    int nilai,nilaiCari;

    do {
        tampilkanMenu();
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahAwal(nilai);
                tampilkanList();
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahAkhir(nilai);
                tampilkanList();
                break;
            case 3:
                cout << "Tambah setelah nilai: ";
                cin >> nilaiCari;
                cout << "Masukkan nilai baru: ";
                cin >> nilai;
                tambahSetelah(nilaiCari, nilai);
                tampilkanList();
                break;

            case 4:
                cout<<"Masukkan nilai : ";
                cin>>nilai;
                hapusNilai(nilai);
                tampilkanList();
                break;
            case 5:
                tampilkanList();
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 0);

    return 0;
}