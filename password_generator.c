#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int PASSWORD_SIZE = 16;
char* CHARACTERS = "abcdefhijklmnopqrstuvwxyzABCDEFHIJKLMNOPQRSTUVWXYZ123456789&%$#@!+-=";

int main() {
    srand(time(NULL));
    int characters_length = strlen(CHARACTERS); 

    char* password = malloc(sizeof(char) * (PASSWORD_SIZE + 1));

    for (int i = 0; i < PASSWORD_SIZE; i++) {
        password[i] = CHARACTERS[(int)(characters_length * ((float)rand() / (float)RAND_MAX))];
    }

    printf("Password: %s\n", password);

    free(password);

    return 0;
}
