#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    (void)argc;
    (void)argv;
    char **var;
    for (var = envp; *var != NULL; ++var)
        printf("%s\n", *var);
    return 0;
}