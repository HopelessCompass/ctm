#include <stdio.h>

int main(void) {
    char process_name[20];
    printf("Enter a process name to look for\n");
    scanf("%10s", process_name);

    int pid = getPIDbyProcName(process_name);
    printf("Process %s%d)\n", pid > 0 ? "found at PID: (" : "NOT FOUND (", pid);
    return 0;
}
