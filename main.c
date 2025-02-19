#include <stdio.h>

int main(void)
{
    //variables
    char cmd[10];

    //welcome screen
    printf("Console Task Manager\n");
    printf("Enter 'List' to get a list of tasks\n");
    printf("Enter 'Kill' to enter killing process menu\n");
    printf("Enter 'Pause' to enter pause process menu\n");
    printf("Enter 'Unpause' to enter unpause process menu\n");

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

            default:
                printf("Unknown input, try again\n")
                cmd_switcher();
        }

    }

    return 0;
}
