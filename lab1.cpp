#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void A_creator(fstream &arr); //создание "неизвестного" массива 
void A_puncher(fstream &arr); //обработка массива
void A_sorter(int *A, int N); //сортировка от большего к меньшему
void A_output(int *A, int N); //вывод
void A_input(int *A, int N, fstream& arr); //ввод массива из файла

void A2_creator(int *A, int N); //создание массива cо случайными элементами в промежуьке от а до b
void A2_puncher(int* A, int N); //работа со вторым массивом

int main() {

    fstream clear;
	clear.open("C:/Users/Legion/Desktop/lab1_arrays_prog/lab1/lab1/array.txt", ios::out);
	clear.close();
    fstream clear2;
    clear2.open("C:/Users/Legion/Desktop/lab1_arrays_prog/lab1/lab1/array2.txt", ios::out);
    clear2.close();

    int number;
    cout << "Enter the number, 0 to close - " << endl;
    cin >> number;
    while(number) {
        if(number == 1) {
            fstream arr;
            arr.open("C:/Users/Legion/Desktop/lab1_arrays_prog/lab1/lab1/array.txt");
            A_creator(arr);
            A_puncher(arr);
            arr.close();
        }
        if(number == 2) {
            int N = rand() % 1000 + 100;
            int *A = new int[N];
            A2_creator(A, N);
            A2_puncher(A, N);
        }
        cout << "Enter the number, 0 to close - " << endl;
        cin >> number;
    }
    return 0;
}

void A_creator(fstream& arr) {
    int N = rand() % 1000 + 100;
    for (int i = 0; i <= N; i++)
        arr << rand() % N << endl;
}

void A_puncher(fstream& arr) {

    fstream clear;
    clear.open("C:/Users/Legion/Desktop/lab1_arrays_prog/lab1/lab1/final_array.txt", ios::out);
    clear.close();

    fstream f_arr;
    f_arr.open("C:/Users/Legion/Desktop/lab1_arrays_prog/lab1/lab1/final_array.txt");

    int k, max_num = 0, LINE;
    cout << "Enter K - "; cin >> k;
	arr.seekg(0);
	while (arr >> LINE) { //в одном цикле считываем подходящие по условию элементы и считаем их количество для создания финального массива
		if (LINE > k) {
            f_arr << LINE << endl;
            max_num++;
		}
    }
    int *A = new int(max_num);
    A_input(A, max_num, f_arr);
    f_arr.close();
    A_sorter(A, max_num);
    A_output(A, max_num);
}

void A_sorter(int *A, int N) {
	for (int i = 1; i <= N; i++) {
		for (int j = i - 1; j > 0; j--) if (A[j] < A[j - 1]) { //поменять знак в условии на меньше/больше для сортировки по убыванию/возрастанию соответственно
			A[j] = A[j] + A[j - 1];
			A[j - 1] = A[j] - A[j - 1];
			A[j] = A[j] - A[j - 1];
		}
	}
}

void A_output(int *A, int N) {
    for (int i = 0; i < N; i++){
        printf("element - %i\t|\tindex - %i\n", A[i], i);
    }
}

void A_input(int *A, int N, fstream& arr) {
    arr.seekg(0);
    for(int i = 0; i < N; i++)
        arr >> A[i];
}

void A2_creator(int *A, int N) { 
    int a, b;
    cout << "Enter a - ";
    cin >> a;
    cout << "Enter b - ";
    cin >> b;
    for (int i = 0; i <= N; i++)
        A[i] = rand() % b + a;
}

void A2_puncher(int *A, int N) {
    fstream arr2;
    arr2.open("C:/Users/Legion/Desktop/lab1_arrays_prog/lab1/lab1/array2.txt");
    int k, numplus = 0;
    cout << "Enter k to add - " << endl; cin >> k;
    for(int i = 0; i < N; i++) { 
        if(A[i] < 0) {
            arr2 << k << endl;
            numplus++;
        }
        arr2 << A[i] << endl;
        numplus++;
    }
	
    arr2.seekg(0);
    int *B = new int[N + numplus];
    A_input(B, N + numplus, arr2);
    arr2.close();
    A_output(B, N);
}
