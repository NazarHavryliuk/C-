#include <iostream>
#include <vector>

using namespace std;

int Foo(int a, int b) {
    if (a < 0 || b < 0) {
        throw exception("Введенi вiд'ємнi числа!");// видавання помилки
    }
    if (a == 0 || b == 0) {
        throw exception("Введенi нульовi числа!");// видавання помилки
    }
    while (b) //цикл для пошуку найбільшого спільного дільника
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    setlocale(LC_ALL, "ukr");
    int n;
    cout << "Введiть кiлькiсть чисел: ";
    cin >> n;

    vector<int> numbers(n);//створення вектора для зберігання чисел
    cout << "Введiть " << n << " чисел: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    try 
    {
        int nod = numbers[0];
        for (int i = 1; i < n; i++) //цикл для обробки кожного елемента
        {
            nod = Foo(nod, numbers[i]);
        }
        cout << "Найбiльший спiльний дiльник: " << nod << endl;
    }
    catch (const exception & e) //відловлює помилки
    {
        cout << "Помилка: " << e.what() << endl;
    }

    return 0;
}
