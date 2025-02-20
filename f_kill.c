#include <processthreadsapi.h>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <TlHelp32.h>
#include <psapi.h>

int getPIDbyProcName(const char * procname) {
    int pid = 0;
    DWORD Procs[1024], bytesReturned, NumOfProcesses;
    TCHAR szProcessName[MAX_PATH];

    // Get the list of process identifiers.
    if ( !EnumProcesses(Procs, sizeof(Procs), &bytesReturned) )
        return 0;

    // Calculate how many process identifiers were returned.
    NumOfProcesses = bytesReturned / sizeof(DWORD);

    for (int i = 0; i < NumOfProcesses; i++ ) {
        if (Procs[i] != 0) {
            // Get a handle to the process.
            HANDLE hProc = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, Procs[i]);
            // and find the one we're looking for
            if (hProc != NULL) {
                HMODULE hModule;
                if (EnumProcessModules(hProc, &hModule, sizeof(hModule), &bytesReturned)) {
                    GetModuleBaseName(hProc, hModule, (LPSTR) szProcessName, sizeof(szProcessName)/sizeof(TCHAR));
                    if (lstrcmpiA(procname, szProcessName) == 0) {
                        pid = Procs[i];
                        break;
                    }
                }
            }
            CloseHandle(hProc);
        }
    }
    return pid;
}

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

int main(void) {
    int pid;
    printf("Enter a PID you want to kill: ");
    scanf("%d", &pid);  // Используем %d для ввода целого числа
    killer(pid);  // Передаём PID
    return 0;
}
