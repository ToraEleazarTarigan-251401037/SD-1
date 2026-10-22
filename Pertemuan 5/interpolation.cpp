
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;

    cout << "Masukkan jumlah data: ";
    cin >> N;

    if (N <= 0) {
        cout << "Jumlah data harus lebih dari 0!" << endl;
        return 0;
    }

    int data[N];

    cout << "Masukkan " << N << " data (acak):\n";
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }

    // Urutkan data secara ascending
    sort(data, data + N);

    cout << "\nData setelah diurutkan: ";
    for (int i = 0; i < N; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    int cari;
    cout << "\nMasukkan data yang ingin dicari: ";
    cin >> cari;

    int low = 0;
    int high = N - 1;
    int flag = 0;
    int posisi = -1;

    // Proses Interpolation Search
    while (low <= high &&
           cari >= data[low] &&
           cari <= data[high]) {

        // Menghindari pembagian dengan nol
        if (data[low] == data[high]) {
            if (data[low] == cari) {
                posisi = low;
                flag = 1;
            }
            break;
        }

        // Rumus Interpolation Search
        posisi = low + (int)(
            (double)(cari - data[low]) * (high - low) /
            (data[high] - data[low])
        );

        cout << "Iterasi: low = " << low
             << ", high = " << high
             << ", posisi = " << posisi << endl;

        if (data[posisi] == cari) {
            flag = 1;
            break;
        }
        else if (data[posisi] < cari) {
            low = posisi + 1;
        }
        else {
            high = posisi - 1;
        }
    }

    cout << "\nHasil: ";
    if (flag == 1) {
        cout << "Data " << cari
             << " ditemukan pada indeks ke-"
             << posisi << endl;
    }
    else {
        cout << "Data " << cari
             << " tidak ditemukan dalam array." << endl;
    }

    return 0;
}
