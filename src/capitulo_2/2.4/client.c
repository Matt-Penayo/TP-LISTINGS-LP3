#include <stdio.h>
#include <stdlib.h>

int main (){
    char* server_name = getenv ("SERVER_NAME");
    if (server_name == NULL){
        server_name = "fpuna.edu.py";
    }
    printf ("Accesing server %s\n", server_name);

    return 0;
}