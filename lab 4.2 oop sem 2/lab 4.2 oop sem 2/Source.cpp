#include <iostream>
#include <vector>

using namespace std;

int Foo(int a, int b) {
    if (a < 0 || b < 0) {
        throw exception("������i �i�'���i �����!");// ��������� �������
    }
    if (a == 0 || b == 0) {
        throw exception("������i ������i �����!");// ��������� �������
    }
    while (b) //���� ��� ������ ���������� �������� �������
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    setlocale(LC_ALL, "ukr");
    int n;
    cout << "����i�� �i���i��� �����: ";
    cin >> n;

    vector<int> numbers(n);//��������� ������� ��� ��������� �����
    cout << "����i�� " << n << " �����: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    try 
    {
        int nod = numbers[0];
        for (int i = 1; i < n; i++) //���� ��� ������� ������� ��������
        {
            nod = Foo(nod, numbers[i]);
        }
        cout << "����i����� ��i����� �i�����: " << nod << endl;
    }
    catch (const exception & e) //�������� �������
    {
        cout << "�������: " << e.what() << endl;
    }

    return 0;
}
