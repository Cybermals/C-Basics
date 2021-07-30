/*
Hello _____ Tutorial
*/

#include <stdio.h>
#include <string.h>


//Entry Point
//===========================================================================
int main(int argc, char **argv)
{
    //Get username
    printf("%s ", "Name:");

    char buf[32];
    fgets(buf, sizeof(buf), stdin);
    buf[strlen(buf) - 1] = 0; //remove newline char

    //Say hello
    printf("Hello %s!\n", buf);
    return 0;
}