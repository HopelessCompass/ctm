#include <stdio.h>

#include "f_find.c"
#include "f_kill.c"
#include "f_list.c"
#include "f_scan.c"

char cmd[20];

void show_menu() {
	printf("Enter 'List' to get the list of processes\n");
	printf("Enter 'Kill' to kill process\n");
	printf("Enter 'Pause' to pause process\n");
	printf("Enter 'Unpause' to unpause process\n");
	printf("Enter 'Find' to find process by it's name'\n");
	printf("Enter 'Help' to show this info again\n");
	printf("Enter 'Exit' to close this program\n");
}
void cmd_switcher() {
    while (1) {
        scanf("%s", cmd);

        if (strcmp(cmd, "List") == 0) {
            f_list();
        }
        else if (strcmp(cmd, "Kill") == 0) {
            f_kill();
        }
        else if (strcmp(cmd, "Pause") == 0) {
            f_pause();
        }
        else if (strcmp(cmd, "Unpause") == 0) {
            f_unpause();
        }
        else if (strcmp(cmd, "Find") == 0) {
            f_find();
        }
        else if (strcmp(cmd, "Help") == 0) {
            show_menu();
        }
        else if (strcmp(cmd, "Exit") == 0) {
            f_exit();
            break;
        }
        else {
            printf("Unknown input, try again\n");
            printf("Enter 'Help' to get the list of commands\n");
        }
    }
}

int main(void) {
	show_menu();
	return 0;
}
