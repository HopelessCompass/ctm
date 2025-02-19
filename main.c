#include <stdio.h>

int main(void)
{
    //variables
    char cmd[10]

    //welcome screen
    printf("Console Task Manager\n");
    printf("Enter 'List' to get a list of tasks\n");
    printf("Enter 'Kill' to enter killing process menu\n");
    printf("Enter 'Pause' to enter pause process menu\n");
    printf("Enter 'Unpause' to enter unpause process menu\n");

    //enter command request
    scanf("%s", &cmd);
    return 0;
}
