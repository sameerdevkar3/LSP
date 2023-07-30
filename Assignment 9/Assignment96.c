#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main()
{
    char **env = environ;

    for(;*env != NULL;env++)
    {
        printf("%s\n",*env);
    }

    return 0;
}