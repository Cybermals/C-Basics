/*
Password Protected Hello
*/

#include <stdio.h>
#include <string.h>


//Entry Point
//===========================================================================
int main(int argc, char **argv)
{
    //Get username
    printf("%s ", "Name:");

    char name[32];
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = 0;

    //Get password
    printf("%s ", "Password:");

    char pswd[32];
    fgets(pswd, sizeof(pswd), stdin);
    pswd[strlen(pswd) - 1] = 0;

    //Verify credentials
    if(strcmp(name, "Dylan") == 0 && strcmp(pswd, "cheetah") == 0)
    {
        printf("Hello %s!\n", name);
    }
    else
    {
        printf("You're not allowed here %s!\n", name);
    }

    return 0;
}