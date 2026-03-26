#include <windows.h>
#include <iostream>
#include<thread>
using namespace std;
int main() {
    STARTUPINFO si;//Ця структура містить інформацію про запуск програми.
    PROCESS_INFORMATION pi;//Ця структура містить інформацію про створений процес.
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Встановлюємо високий пріорітет для калькулятора
    if (!CreateProcess(
        TEXT("C:\\Windows\\System32\\calc.exe"), // Шлях до калькулятора
        NULL, // Командний рядок
        NULL, // Атрибути захисту процесу
        NULL, // Атрибути захисту потоку
        FALSE, // Налаштування успадкування дескрипторів
        HIGH_PRIORITY_CLASS, // Високий пріорітет
        NULL, // Блок середовища
        NULL, // Вказівник на поточний каталог
        &si, // Указівник на STARTUPINFO
        &pi  // Указівник на PROCESS_INFORMATION
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
    // Закриваємо дескриптори процесу та потоку
    
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}