#include <iostream>

using namespace std;

// Fungsi untuk melakukan Selection Sort
void selectionSort(float arr[], int n) {
    int i, j, maks;

    // Loop untuk setiap elemen kecuali elemen terakhir
    for (i = 0; i < n - 1; i++) {
        maks = i; // Menginisialisasi indeks maksimum

        // Loop untuk mencari nilai maksimum dari elemen yang belum diurutkan
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[maks]) {
                maks = j;
            }
        }

        // Menukar elemen terbesar dengan elemen pertama yang belum diurutkan
        float temp = arr[i];
        arr[i] = arr[maks];
        arr[maks] = temp;
    }
}

int main() {
    // IPS dari masing-masing mahasiswa
    float ips[] = {3.8, 2.9, 3.3, 4.0, 2.4};
    int n = sizeof(ips) / sizeof(ips[0]);

    // Mengurutkan IPS mahasiswa menggunakan Selection Sort
    selectionSort(ips, n);

    // Menampilkan IPS mahasiswa yang telah diurutkan
    cout << "IPS mahasiswa setelah diurutkan dari yang terbesar hingga terkecil:" << endl;
    for (int i = 0; i < n; i++) {
        cout << ips[i] << " ";
    }
    cout << endl;
    
    cout << "" << endl;
    cout << "" << endl;
    cout << "By: Fahmi Hidayat (2311110063)" << endl;

    return 0;
}
