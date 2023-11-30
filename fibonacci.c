#include <stdio.h>
#include <inttypes.h>

int main(void) {
    printf("Enter a number:");
    
    int maxFibo;
    scanf("%d", &maxFibo);

    printf("\n");

    long a = 0;
    long b = 1;
    long c;

    for (int i = 0; i < maxFibo; i++) {
        c = a + b;
        a = b;
        b = c;
        printf("%li\n", c);
    }

    return 0;
}
