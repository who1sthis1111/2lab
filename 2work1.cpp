#include <iostream>
using namespace std;



int main() {
    setlocale(LC_ALL, "ru-RU.UTF-8");
    int size = 0;
    int numcheck = 0;
    
    cout << "Прога выполняет сортировку массива пузырьком, а также бинарный поиск" << endl;
    cout << "Введите размер массива(число): ";
    cin >> size;
    if (cin.fail() or size <= 0) {
        cout << "Ошибка: нужно ввести целое число или же массив нулевого размера!" << endl;
        return 1;
    }
    
    int mass[size];
    for(int i = 0; i < size; i++){
        numcheck += 1;
        cout << "Введите значение для значения(" << numcheck << "): " << endl;
        cin >> mass[i];
        if (cin.fail()) {
            cout << "Ошибка: нужно ввести целое число!" << endl;
        return 1;
        }
    }
    cout << "Какие значения в массиве были введены и отсортированны автоматически(для проверки): " << endl;
    for(int k = 0; k < size ; k++){
        for(int i = 0; i < size-1; i++){
            if (mass[i] > mass[i+1]){
                swap(mass[i], mass[i+1]);
            }
        }
        
    }
    for(int i = 0; i < size; i++){
        cout << mass[i] << endl;
    }
    
    // 2 lab 2 work
    int numsearch;
    int left = 0;
    int right =  size - 1;
    int foundnum = -1;
    int mid;
    cout << "Хотите ли вы найти какое нибудь число в вашем массиве? (напишите число которое вы хотите найти): ";
    cin >> numsearch;
    if (cin.fail()) {
        cout << "Ошибка: нужно ввести целое число!" << endl;
    return 1;
    }
    
    while (left <= right){
        mid = (left+right)/2;
        if (numsearch == mass[mid]){
            foundnum = mid;
            break;
        }
        else if (mass[mid] < numsearch){
            left = mid + 1;
        }
        else if (mass[mid] > numsearch){
            right = mid - 1;
        }

    }
    if (foundnum == -1){
        cout << endl << "Этого числа нету в массиве: попробуйте снова";
    }
    else {
        cout << endl <<  "Число: " << numsearch << " НАйдено под индексом: " << foundnum;
    }
    
    

    return 0;
}