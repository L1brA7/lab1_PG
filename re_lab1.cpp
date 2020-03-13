#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//создание неизвестного массива в файле
void array_creator();
//создание нужного нам массива
void array_puncher();
//сортировка
void array_sorter(int *A, int N);
//вывод массива
void array_output(int *A, int N);
//создание первого массива для второго задания
void task_2();


int main() {
    int number;
    cout << "Enter the number, 0 to close - " << endl;
    cin >> number;
    while (number) {
        if (number == 1) {
            array_creator();
            array_puncher();
        }
        if (number == 2) {
			task_2();
        }
        cout << "Enter the number, 0 to close - " << endl;
        cin >> number;
    }
    return 0;
}

void task_2() {
	//первая часть задания
	int a, b, N, k, temp;
	cout << "ENTER INITTIAL ARRAY SIZE - "; cin >> N;
	cout << "b must be bigger than a" << endl;
	cout << "ENTER a - "; cin >> a;
	cout << "ENTER b - "; cin >> b;
	while (a > b) {
		cout << "b must be bigger than a" << endl;
		cout << "ENTER a - "; cin >> a;
		cout << "ENTER b - "; cin >> b;
	}
	cout << "ENTER k to add - "; cin >> k;
	int* ARRAY = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) ARRAY[i] = (rand() % (b + abs(a))) + a;
	array_output(ARRAY, N);
	cout << endl;
	//вторая часть задания
	int newN = N;
	for (int i = 0; i < N; i++) {
		if (ARRAY[i] < 0) {
			i++;
			newN++;
			ARRAY = (int*)realloc(ARRAY, newN * sizeof(int));
            for (int j = newN - 1; j > i; j--) {
				temp = ARRAY[j - 1];
				ARRAY[j - 1] = ARRAY[j];
				ARRAY[j] = temp;
            }
			ARRAY[i] = k;
        }
	}
	array_output(ARRAY, newN);
    free(ARRAY);
}

void array_creator() {
    ofstream array;
    array.open("given_array.txt", ios::out);
    for (int i = 0; i < rand() % 1000; i++) {
        array << rand() % 1000 << endl;
    }
    array.close();
}

void array_puncher() {
    ifstream array;
    array.open("given_array.txt");
    int *ARRAY = (int*)malloc(0 * sizeof(int));
    int LINE, k, i = 0;
	cout << "ENTER K - "; cin >> k;
    while(array >> LINE) {
        if (LINE > k) {
            i++;
            ARRAY = (int*)realloc(ARRAY, i * sizeof(int));
			ARRAY[i - 1] = LINE;
        }
    }
	array_sorter(ARRAY, i);
    array_output(ARRAY, i);
	free(ARRAY);
	array.close();
}

void array_sorter(int *array, int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = i - 1; j > 0; j--) {
            if (array[j] < array[j - 1]) { //поменять знак в условии на меньше/больше для сортировки по убыванию/возрастанию соответственно
                array[j] = array[j] + array[j - 1];
                array[j - 1] = array[j] - array[j - 1];
                array[j] = array[j] - array[j - 1];
            }
        }
    }
}

void array_output(int *array, int N) {
    for (int i = 0; i < N; i++) {
        printf("element - %i\t|\tindex - %i\n", array[i], i);
    }
}