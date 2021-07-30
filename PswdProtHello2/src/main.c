/*
Password Protected Hello 2
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>


//Functions
//===========================================================================
void Prompt(char *msg, char *buf, int bufSize)
{
    //Display prompt
    printf("%s ", msg);

    //Get input
    fgets(buf, bufSize, stdin);
    buf[strlen(buf) - 1] = 0;
}


bool IsValid(char *name, char *pswd)
{
    //Verify password
    if(strcmp(name, "Dylan") == 0)
    {
        return (strcmp(pswd, "cheetah") == 0);
    }

    return false;
}


//Entry Point
//===========================================================================
int main(int argc, char **argv)
{
    //Get credentials
    char name[32];
    char pswd[32];
    Prompt("Name:", name, sizeof(name));
    Prompt("Pswd:", pswd, sizeof(pswd));

    //Verify credentials
    if(IsValid(name, pswd))
    {
        printf("Hello %s!\n", name);
    }
    else
    {
        printf("You're not allowed here %s!\n", name);
    }
    
    return 0;
}