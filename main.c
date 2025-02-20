#include <stdio.h>
#include "process_list.c"

int main(void)
{
    //variables
    char cmd[10];

    show_menu();

    void show_menu() {
        printf("Enter 'List' to get the list of processes\n");
        printf("Enter 'Kill' to kill process\n");
        printf("Enter 'Pause' to pause process\n");
        printf("Enter 'Unpause' to unpause process\n");
        printf("Enter 'Find' to find process by it's name'\n");
        printf("Enter 'Help' to show this info again\n");
        printf("Enter 'Exit' to close this program\n);
    }

    //enter command request
    void cmd_switcher() {

        scanf("%s", &cmd);

        switch (cmd){
            case "List":
                f_list();
                break;

            case "Kill":
                f_kill();
                break;

            case "Pause":
                f_pause();
                break;

            case "Unpause":
                f_unpause();
                break;

            case "Find":
                f_find();
                break;

            case "Help":
                show_menu();
                break;

            case "Exit":
                f_exit;
                break;

            default:
                printf("Unknown input, try again\n");
                printf("Enter 'Help' to get the list of commands\n");
                cmd_switcher();
                break;
        }

    }

    return 0;
}
