#include <processthreadsapi.h>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <TlHelp32.h>
#include <psapi.h>

int killer(int PID)  // Добавлен тип аргумента
{
    int x;
    HANDLE kill = OpenProcess(PROCESS_TERMINATE, FALSE, PID);  // Получаем дескриптор процесса по PID
    if (kill == NULL) {
        printf("Unable to open process\n");
        return 1;  // Возвращаем ошибку
    }

    DWORD fdwExit = 0;
    GetExitCodeProcess(kill, &fdwExit);
    TerminateProcess(kill, fdwExit);
    x = CloseHandle(kill);
    printf("%i\n", x);
    return 0;
}

void f_kill() {
    int pid;
    printf("Enter a PID you want to kill: ");
    scanf("%d", &pid);  // Используем %d для ввода целого числа
    killer(pid);  // Передаём PID
    return 0;
}
