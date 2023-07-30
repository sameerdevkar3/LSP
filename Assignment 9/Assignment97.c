#include <stdio.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

int main()
{
    char **env = environ;

    for(;*env != NULL;env++)
    {
        if(!memcmp("HOME",*env,4) || !memcmp("USERNAME",*env,8))
            printf("%s\n",*env);
    }

    return 0;
}