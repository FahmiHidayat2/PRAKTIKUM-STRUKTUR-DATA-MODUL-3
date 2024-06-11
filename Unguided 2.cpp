#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk melakukan Bubble Sort
void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Menukar elemen jika elemen saat ini lebih besar dari elemen berikutnya
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Array berisi nama-nama warga Pak RT
    string namaWarga[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
    int n = sizeof(namaWarga) / sizeof(namaWarga[0]);

    // Mengurutkan nama-nama warga menggunakan Bubble Sort
    bubbleSort(namaWarga, n);

    // Menampilkan nama-nama warga yang telah diurutkan
    cout << "Nama-nama warga Pak RT setelah diurutkan sesuai alfabet:" << endl;
    for (int i = 0; i < n; i++) {
        cout << namaWarga[i] << endl;
    }
    
    cout << "" << endl;
    cout << "" << endl;
    cout << "By: Fahmi Hidayat (2311110063)" << endl;

    return 0;
}
