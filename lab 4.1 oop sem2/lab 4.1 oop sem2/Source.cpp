#include <iostream>

int main() {
    setlocale(LC_ALL, "ukr");
    int n;
    std::cout << "����i�� ����i� ������: ";
    std::cin >> n;

    try {
        int* dynamicArray = new int[n];
        std::cout << "���'��� ���i��� ���i���� ��� ������ ����i��� " << n << std::endl;
        delete[] dynamicArray;
    }
    catch (std::bad_alloc& e) {
        std::cerr << "������� ������� �i� ��� ���i����� ���'��i: " << e.what() << std::endl;
    }

    return 0;
}