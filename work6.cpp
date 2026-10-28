#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL,"ru_RU.UTF-8");
    string text;
    cout << "Это программа из любого текста - показывает количество: букв, цифр, пробелов, остальные символы. (поддерживает только английский язык)" << endl;
    cout << "Напишите любое сообщение: ";
    getline(cin, text);

    if (cin.fail()) {
        cout << "Ошибка: не удалось прочитать строку!" << endl;
        return 1;
    }

    if (text.empty()) {
        cout << "Ошибка: строка пустая - нечего считать!" << endl;
        return 1;
    }

    int letters = 0, digits = 0, spaces = 0, punct = 0;

    for (int i = 0; i < (int)text.length(); ++i) {
        char c = text[i];

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            letters++;
        }
        else if (c >= '0' && c <= '9') {
            digits++;
        }
        else if (c == ' ') {
            spaces++;
        }
        else if (c == (','||'.'||'+'||'-'||'?'||'!'||';'||':'||'"') ) {
            punct++;
        }
    }

    cout << "Букв: " << letters << endl;
    cout << "Цифр: " << digits << endl;
    cout << "Пробелов: " << spaces << endl;
    cout << "Знаков препинания: " << punct << endl;

    return 0;
}