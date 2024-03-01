#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

void file_copyer(string* arr, int size, string in_file);
void file_printer(string* arr, int size, string out_file);
void processing(string* arr, int& size);
int elem_deleter(string* arr, int size, int number);
int max_searching(string* arr, int size);
bool is_digit(char letter);

int main() {
    setlocale(LC_ALL, "Rus");
    string in_file = "F1.txt";
    string out_file = "F2.txt";
    int size = 5;
    string* arr = new string[size];
    file_copyer(arr, size, in_file);
    processing(arr, size);
    file_printer(arr, size, out_file);
    cout << "Номер слова с наибольшим колличеством цифр: " << max_searching(arr, size);
}

void file_copyer(string* arr, const int size, const string in_file) {
    ifstream input;
    input.open(in_file);
    for (int i = 0; i < size; i++) {
        getline(input, arr[i]);
    }
    input.close();
}

void file_printer(string* arr, const int size, const string out_file) {
    ofstream output;
    output.open(out_file);
    for (int i = 0; i < size; i++)
        output << arr[i] << endl;
    output.close();
}

int elem_deleter(string* arr, int size, int number) {
    for (int i = number; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return --size;
}

void processing(string* arr, int& size) {
    for (int i = 0; i < size; i++) {
        int count = 0;
        string str = arr[i];
        for (int j = 0; j < arr[i].size(); j++) {
            if (str[j] == ' ') {
                count++;
            }
        }
        if (count == 0) {
            size = elem_deleter(arr, size, i);
        }
    }
}

bool is_digit(const char letter) {
    for (int i = 0; i < 10; i++) {
        if (i + '0' == letter) {
            return true;
        }
    }
    return false;
}

int max_searching(string* arr, const int size) {
    int max_count = 0;
    int number = 1;
    int search_number = -1;
    for (int i = 0; i < size; i++) {
        int count = 0;
        string str = arr[i];
        for (int j = 0; j < arr[i].size(); j++) {
            if (str[j] != ' ') {
                count = count + is_digit(str[j]);
            }
            else {
                number++;
                count = 0;
            }
            if (count >= max_count) {
                max_count = count;
                search_number = number;
            }
        }
        number++;
    }
    return search_number;
}
