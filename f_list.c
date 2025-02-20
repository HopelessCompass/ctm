#include <stdio.h>

int main(void) {
 int pid = getPIDbyProcName("notepad.exe");
 printf("Notepad %s%d)\n", pid > 0 ? "found at PID: (" : "NOT FOUND (", pid);
 return 0;
}
