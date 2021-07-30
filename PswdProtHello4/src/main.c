/*
Password Protected Hello 4
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Forward Declarations
//===========================================================================
void Fini(void);
bool LoadUsers(void);
void FreeUsers(void);


//Structures
//===========================================================================
typedef struct
{
    char name[32];
    char pswd[32];
} User;


//Constants
//===========================================================================
User *users = NULL;
int userCnt;


//Functions
//===========================================================================
bool Init(void)
{
    //Load user data
    printf("%s", "Loading user data...");

    if(!LoadUsers())
    {
        printf("%s\n", "failed");
        fprintf(stderr,
            "%s\n",
            "Fatal Error: Failed to load user data.");
        return false;
    }

    printf("%s\n", "ok");

    //Register with atexit
    atexit(Fini);
    return true;
}


void Fini(void)
{
    //Free user data
    FreeUsers();
}


bool LoadUsers(void)
{
    //Open users config file
    FILE *usrCfg = fopen("./data/users.cfg", "r");

    if(usrCfg == NULL)
    {
        return false;
    }

    //Find users section
    char line[64] = "";

    while(strncmp(line, "[Users]", 7) != 0)
    {
        //Get next line
        fgets(line, sizeof(line), usrCfg);

        //Fail if no users section
        if(feof(usrCfg))
        {
            return false;
        }
    }

    //Parse user count
    if(fscanf(usrCfg, "count = %i ", &userCnt) < 1)
    {
        fprintf(stderr, 
            "%s\n",
            "Fatal Error: User config file is corrupt.");
        return false;
    }

    //Allocate users array
    users = (User*)malloc(sizeof(User) * userCnt);

    if(users == NULL)
    {
        fprintf(stderr,
            "%s\n",
            "Fatal Error: Out of memory.");
        return false;
    }

    //Load user data
    int i = 0;

    while(i < userCnt)
    {
        //Get next line
        fgets(line, sizeof(line), usrCfg);

        //User entry?
        if(strncmp(line, "[User]", 6) == 0)
        {
            //Load user data
            if(fscanf(usrCfg, "name = %31s pswd = %31s ", 
                users[i].name, users[i].pswd) < 2)
            {
                free(users);
                fclose(usrCfg);
                fprintf(stderr,
                    "%s\n",
                    "Fatal Error: Failed to parse user data.");
                return false;
            }

            i++;
        }
        //Corrupt garbage
        else
        {
            free(users);
            fclose(usrCfg);
            fprintf(stderr,
                "%s\n",
                "Fatal Error: User config file is corrupt.");
            return false;
        }
    }

    //Close users config file
    fclose(usrCfg);
    return true;
}


void FreeUsers(void)
{
    free(users);
}


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
    for(int i = 0; i < userCnt; i++)
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
    //Initialize
    if(!Init())
    {
        return 1;
    }

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