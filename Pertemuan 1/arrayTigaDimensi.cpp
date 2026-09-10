#include <iostream>
using namespace std;
int main () {
    int array [3][3][4];
    int angka = 2;

    for(int i= 0; i<3 ; i++){ //untuk baris
        for(int j = 0; j < 3 ; j++){ // untuk kolom
            for(int k = 0; k < 4; k++){ // untuk kedalaman
                array[i][j][k] = angka ; // untuk mendeklarasikan array 3 dimensi
                angka += 2;
            }
        }
    }
    // menampilkan isi array 3 dimensi
    for(int i= 0; i<3 ; i++){ //untuk baris
        cout << "Lapis ke-"<< i + 1 << endl;

        for(int j = 0; j < 3 ; j++){ // untuk kolom
            for(int k = 0; k < 4; k++){ // untuk kedalaman
                cout << array[i][j][k] << " \t "; //untuk menampilkan isi array 3 dimensi
                }
                cout<<endl; //untuk membuat baris baru

                    }
                  cout<<endl; //untuk membuat baris baru
    }
    return 0;
}