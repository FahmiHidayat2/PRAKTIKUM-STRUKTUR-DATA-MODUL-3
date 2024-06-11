# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Fahmi Hidayat</p>

## Dasar Teori

Algoritma sorting adalah serangkaian langkah atau prosedur yang digunakan untuk mengurutkan elemen-elemen dalam suatu struktur data, seperti array atau daftar, sesuai dengan kriteria tertentu. Tujuan utama dari algoritma sorting adalah untuk menyusun elemen-elemen data dalam urutan yang teratur [1]. baik itu dari yang terkecil ke yang terbesar (ascending), maupun sebaliknya dari yang terbesar ke yang terkecil (descending). Algoritma sorting sangat penting dalam pengembangan perangkat lunak karena sering digunakan dalam berbagai aplikasi, termasuk basis data, pencarian data, dan analisis data.

### 1. Bubble Sort
Bubble Sort adalah algoritma sorting sederhana yang berulang kali menukar elemen yang berdekatan jika mereka berada dalam urutan yang salah.
```c++
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
```
### 2. Insertion Sort
Insertion Sort adalah algoritma yang membangun array hasil secara bertahap dengan menambahkan satu elemen pada satu waktu ke posisi yang sesuai.
```c++
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}
```
### 3. Quick Sort
Quick Sort adalah algoritma divide-and-conquer yang paling umum digunakan karena efisiensinya.
```c++
#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
```
### . 4. Kompleksitas Algoritma
Kompleksitas suatu algoritma merupakan ukuran seberapa banyak komputasi yang dibutuhkan algoritma tersebut untuk mendapatkan hasil yang diinginkan [4]. Algoritma Bubble Sort, Selection Sort, dan Insertion Sort adalah tiga algoritma pengurutan sederhana yang mudah diimplementasikan. Ketiganya memiliki kompleksitas waktu rata-rata O(n^2), di mana n adalah jumlah elemen dalam array yang akan diurutkan. Namun, di antara ketiganya, Insertion Sort sering kali dianggap lebih efisien daripada Bubble Sort dan Selection Sort [5]. Bubble Sort dan Selection Sort sering melakukan banyak pertukaran atau pergeseran elemen dalam array, bahkan jika array sudah hampir terurut. Hal ini mengakibatkan kinerja yang lebih lambat karena setiap pertukaran membutuhkan waktu tambahan. Insertion Sort, di sisi lain, hanya memindahkan elemen yang diperlukan ke posisi yang benar dalam bagian terurut dari array, yang sering kali lebih efisien daripada pertukaran elemen yang dilakukan oleh Bubble Sort dan Selection Sort. Meskipun Insertion Sort dianggap lebih efisien dalam banyak kasus daripada Bubble Sort dan Selection Sort, pilihan algoritma pengurutan yang tepat tergantung pada kebutuhan spesifik aplikasi dan karakteristik data yang akan diurutkan. Setiap algoritma memiliki kelebihan dan kelemahan masing-masing, dan penting untuk mempertimbangkan konteks penggunaannya secara cermat.

Masing-masing algoritma di atas memiliki kelebihan dan kekurangan. Pilihan algoritma tergantung pada kebutuhan spesifik seperti ukuran data, kebutuhan performa, dan kesederhanaan implementasi. Algoritma seperti std::sort dari pustaka standar C++ sering kali lebih efisien dan optimal karena telah diimplementasikan dan dioptimalkan oleh para ahli.
## Guided 

### 1.Bubble Sort Ascending

```C++
// Guided 1
// bubble sorting
#include <iostream>

using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }//end of for loop
    }//end of while loop
}//end of bubble_sort

void print_array(double a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {

    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99.99};

    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```
Program di atas adalah implementasi algoritma bubble sort dalam bahasa C++. Algoritma ini digunakan untuk mengurutkan array bilangan pecahan secara berurutan dari yang terkecil hingga yang terbesar. Dalam implementasi ini, algoritma Bubble Sort digunakan untuk mengurutkan array a. Proses pengurutan dimulai dari awal array dengan membandingkan setiap pasangan elemen adjacent dan menukarnya jika diperlukan. Proses ini diulang hingga tidak ada lagi pertukaran yang dilakukan dalam satu iterasi.

### 2. Insertion Sort Descending
```c++
// Guided 2

// insertion sorting

# include <iostream>

using namespace std;

void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;

    for (i = 1; i < length; i++) {
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }// end of while loop
    }// end of for loop
}

void print_array(char a[], int length) {

    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}
int main() {

    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
}

```
Program di atas adalah implementasi algoritma insertion sort dalam bahasa C++. Algoritma ini digunakan untuk mengurutkan array secara berurutan dari yang terbesar hingga yang terkecil. Dalam implementasi ini, algoritma insertion sort digunakan untuk mengurutkan array a. Proses pengurutan dimulai dari elemen kedua dalam array, dan setiap elemen dibandingkan dengan elemen-elemen sebelumnya. Jika elemen saat ini lebih besar dari elemen sebelumnya, maka elemen tersebut akan "disisipkan" ke posisi yang sesuai di antara elemen-elemen sebelumnya. Proses ini diulang hingga semua elemen telah diproses, sehingga array akan terurut secara berurutan dari yang terbesar hingga yang terkecil.
## Unguided 

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort!

```C++
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
```
Inisialisasi Array IPS:

Array ips[] dideklarasikan untuk menyimpan nilai-nilai IPS mahasiswa.
Nilai-nilai ini adalah: {3.8, 2.9, 3.3, 4.0, 2.4}.
Fungsi selectionSort:

Fungsi selectionSort dipanggil untuk mengurutkan nilai-nilai dalam array ips[].
Panjang array ips[] adalah 5, sehingga panjang ini (n) disampaikan sebagai argumen ke dalam fungsi selectionSort.
Algoritma Selection Sort:

Algoritma Selection Sort dilakukan dalam fungsi selectionSort.
Iterasi dimulai dari elemen pertama (i = 0) hingga elemen sebelum elemen terakhir (i < n - 1).
Pada setiap iterasi, nilai maksimum diidentifikasi dalam sisa array yang belum diurutkan.
Nilai maksimum tersebut kemudian ditukar dengan elemen pertama yang belum diurutkan.
Proses ini diulang hingga seluruh array terurut.

#### Output:
<img width="517" alt="image" src="https://github.com/FahmiHidayat2/PRAKTIKUM-STRUKTUR-DATA-MODUL-3/assets/161399477/321822ae-4877-4ce9-bfdd-7fde0984acbd">

### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan nama-nama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!
```c++
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
```
Penjelasan:

Array namaWarga[]:

Array namaWarga[] menyimpan nama-nama warga Pak RT dalam bentuk string.
Nilai-nilai yang disimpan dalam array tersebut adalah: {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"}.
Nama-nama warga tersebut tidak terurut secara alfabet.
Fungsi bubbleSort:

Fungsi ini merupakan implementasi algoritma Bubble Sort.
Menerima array string arr[] sebagai input, yang merupakan array yang akan diurutkan, dan int n yang menyatakan panjang array tersebut.
Dalam fungsi ini, terdapat dua loop bersarang:
Loop pertama (for (int i = 0; i < n - 1; i++)) berjalan sebanyak (n - 1) kali, menunjukkan jumlah iterasi yang diperlukan untuk mengurutkan seluruh array.
Loop kedua (for (int j = 0; j < n - i - 1; j++)) digunakan untuk membandingkan setiap pasangan elemen adjacent dan melakukan pertukaran jika diperlukan.
Proses pertukaran dilakukan jika nilai elemen pada indeks j lebih besar dari nilai elemen pada indeks j + 1.
Fungsi dalam main:

Array namaWarga[] dideklarasikan dan diinisialisasi dengan nama-nama warga Pak RT yang belum terurut.
Panjang array namaWarga[] dihitung menggunakan ekspresi sizeof(namaWarga) / sizeof(namaWarga[0]) dan disimpan dalam variabel n.
Fungsi bubbleSort dipanggil untuk mengurutkan array namaWarga[].
#### Output :
<img width="437" alt="image" src="https://github.com/FahmiHidayat2/PRAKTIKUM-STRUKTUR-DATA-MODUL-3/assets/161399477/1a348cb7-c057-427f-bc96-9deaf95edc8f">

### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!
```c++
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
```
Penjelasan:

Fungsi tampilAlfabet:

Fungsi ini digunakan untuk menampilkan alfabet sebelum dilakukan pengurutan.
Menerima dua parameter, yaitu array const char alfabet[] yang berisi alfabet-alfabet yang akan ditampilkan dan integer n yang merupakan panjang array tersebut.
Melalui loop, setiap elemen alfabet akan ditampilkan ke layar.
Fungsi insertionSort:

Fungsi ini digunakan untuk melakukan pengurutan array menggunakan algoritma insertion sort secara menurun.
Menerima dua parameter, yaitu array char arr[] yang akan diurutkan dan integer n yang merupakan panjang array tersebut.
Algoritma insertion sort digunakan di dalam fungsi ini. Pada algoritma ini, elemen-elemen array akan disusun satu per satu dengan cara - membandingkan dengan elemen sebelumnya, dan jika ditemukan elemen yang lebih besar, maka akan dipindahkan ke posisi yang sesuai.
Fungsi dalam main:

Meminta pengguna untuk memasukkan jumlah alfabet yang akan dimasukkan (n).
Array alfabet[] dideklarasikan dengan panjang n.
Menggunakan loop untuk meminta pengguna memasukkan alfabet sejumlah n.
Memanggil fungsi tampilAlfabet untuk menampilkan alfabet sebelum pengurutan.
Memanggil fungsi insertionSort untuk mengurutkan alfabet secara menurun.
Output:
#### Output :
<img width="404" alt="image" src="https://github.com/FahmiHidayat2/PRAKTIKUM-STRUKTUR-DATA-MODUL-3/assets/161399477/8e43284d-9d2c-4b02-a8f1-ee8b8b3e8f3e">





## Kesimpulan
## Kesimpulan

Pada praktikum kali ini, kami mempelajari dan mengimplementasikan beberapa algoritma sorting dasar seperti Bubble Sort, Insertion Sort, dan Selection Sort. Masing-masing algoritma memiliki kelebihan dan kekurangan tergantung pada kebutuhan dan karakteristik data yang akan diurutkan. Bubble Sort sederhana namun kurang efisien untuk dataset besar karena kompleksitas waktu rata-rata O(n^2). Insertion Sort lebih efisien dalam beberapa kasus terutama ketika array hampir terurut, meskipun tetap memiliki kompleksitas O(n^2). Selection Sort juga memiliki kompleksitas O(n^2) dan umumnya lebih lambat karena sering melakukan banyak pertukaran elemen. Algoritma seperti Quick Sort lebih efisien untuk dataset yang lebih besar karena menggunakan pendekatan divide-and-conquer. Praktikum ini menegaskan pentingnya memilih algoritma yang tepat sesuai dengan konteks aplikasi dan data yang dihadapi. Selain itu, kami belajar bahwa algoritma yang dioptimalkan oleh para ahli, seperti `std::sort` dari pustaka standar C++, sering kali menawarkan performa yang lebih baik.
## Referensi
[1] T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, "Introduction to Algorithms," 3rd ed. The MIT Press, 2009.
