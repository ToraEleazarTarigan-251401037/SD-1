#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Masukkan Jumlah Elemen Array: ";
    cin>>n;

    int* arr = new int[n]; // Dynamic array allocation

    cout << "Masukkan " << n << " angka :\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input elements into the dynamic array
    }

    cout << "Isi Array : ";
    for (int i=n-1;i >= 0; i--){
        cout << arr[i] <<" "; // Output elements of the dynamic array
    }

    delete[] arr; // Free the allocated memory
    return 0;
}
