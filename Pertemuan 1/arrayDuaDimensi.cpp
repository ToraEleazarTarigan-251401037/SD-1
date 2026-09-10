#include <iostream>
using namespace std;
int main() {
    int nilai[3][4]={ //deklarasi tabel nilai dengan array 2 dimensi
        {80,75,90,85},
        {70,60,88,77},
        {95,85,92,89}
    };

    for(int i = 0; i<3;i++ ){ //untuk baris
        cout<< "Mahasiswa "<< i + 1 << " : "; 
        
        for(int j = 0; j<4;j++){ // untuk kolom
            cout << nilai[i][j]<< " "; //untuk menampilkan isi array 2 dimensi
        }
        cout << endl; //untuk membuat baris baru
    }
    return 0;

}