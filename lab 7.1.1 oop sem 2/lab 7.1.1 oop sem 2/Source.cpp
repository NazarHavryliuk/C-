#include <windows.h>
#include <iostream>
#include<thread>
using namespace std;
int main() {
    STARTUPINFO si;//�� ��������� ������ ���������� ��� ������ ��������.
    PROCESS_INFORMATION pi;//�� ��������� ������ ���������� ��� ��������� ������.
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // ������������ ������� ������� ��� ������������
    if (!CreateProcess(
        TEXT("C:\\Windows\\System32\\calc.exe"), // ���� �� ������������
        NULL, // ��������� �����
        NULL, // �������� ������� �������
        NULL, // �������� ������� ������
        FALSE, // ������������ ������������ �����������
        HIGH_PRIORITY_CLASS, // ������� �������
        NULL, // ���� ����������
        NULL, // �������� �� �������� �������
        &si, // �������� �� STARTUPINFO
        &pi  // �������� �� PROCESS_INFORMATION
    ))
    {
        std::cerr << "CreateProcess failed (" << GetLastError() << ").\n";
        return 1;
    }

    std::cout << "Calculator started with high priority.\n";

    //Sleep(4000);
    if (!TerminateProcess(pi.hProcess, 0))
    {
        std::cout << "ghghfgeag";
    }
    // ��������� ����������� ������� �� ������
    
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}