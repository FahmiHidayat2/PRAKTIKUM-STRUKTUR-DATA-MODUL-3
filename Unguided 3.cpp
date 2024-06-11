#include <iostream>

using namespace std;

// Fungsi untuk menampilkan alfabet sebelum sorting
void tampilAlfabet(const char alfabet[], int n) {
    cout << "Alfabet sebelum pengurutan: ";
    for (int i = 0; i < n; ++i) {
        cout << alfabet[i] << " ";
    }
    cout << endl;
}

// Fungsi untuk melakukan insertion sort)
void insertionSort(char arr[], int n) {
    int i, j;
    char key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // Pindahkan elemen dari arr[0..i-1] yang lebih besar dari key
        // ke posisi satu di depan posisi mereka saat ini
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah alfabet (n): ";
    cin >> n;

    char alfabet[n];

    // Meminta pengguna untuk memasukkan alfabet sejumlah n
    for (int i = 0; i < n; ++i) {
        cout << "Alfabet ke-" << i + 1 << ": ";
        cin >> alfabet[i];
    }

    // Memanggil fungsi untuk menampilkan alfabet sebelum pengurutan
    tampilAlfabet(alfabet, n);

    // Panggil fungsi insertion sort untuk mengurutkan alfabet secara menurun
    insertionSort(alfabet, n);

    // Menampilkan hasil pengurutan menurun
    cout << "\nHasil pengurutan menurun (descending): ";
    for (int i = 0; i < n; ++i) {
        cout << alfabet[i] << " ";
    }

    return 0;
}
