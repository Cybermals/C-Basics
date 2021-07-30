/*
Password Protected Hello 3
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>


//Structures
//===========================================================================
typedef struct
{
    char *name;
    char *pswd;
} User;


//Constants
//===========================================================================
const User users[] = {
    {"Dylan", "cheetah"},
    {"Fiona", "fox"},
    {"Daniel", "lion"},
    {"Leila", "lioness"},
    {"Serena", "squirrel"}
};


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
    for(int i = 0; i < sizeof(users) / sizeof(User); i++)
    {
        //Found username?
        if(strcmp(name, users[i].name) == 0)
        {
            return (strcmp(pswd, users[i].pswd) == 0);
        }
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