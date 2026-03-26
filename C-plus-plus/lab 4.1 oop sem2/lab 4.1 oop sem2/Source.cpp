#include <iostream>

int main() {
    setlocale(LC_ALL, "ukr");
    int n;
    std::cout << "¬ведiть розмiр масиву: ";
    std::cin >> n;

    try {
        int* dynamicArray = new int[n];
        std::cout << "ѕам'€ть успiшно видiлена дл€ масиву розмiром " << n << std::endl;
        delete[] dynamicArray;
    }
    catch (std::bad_alloc& e) {
        std::cerr << "¬иникла помилка пiд час видiленн€ пам'€тi: " << e.what() << std::endl;
    }

    return 0;
}