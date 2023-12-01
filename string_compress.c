#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// Problem modified from https://leetcode.com/problems/string-compression/

char* stringify_uint(unsigned int x) {
    char* out = malloc(((int)log10f(x)) + 1);
    sprintf(out, "%u", x);
    return out;
}

char* compress_string(char* string, size_t length) {
    char* output = malloc(length * 2);
    char last_char = string[0];
    int last_char_count = 1;
    int output_idx = 0;

    for (size_t i = 1; i <= length; i++) {
        if (last_char != string[i]) {
            // Fill output with stringified count if there would be any advantage
            if (last_char_count > 1) {
                char* strfd_count = stringify_uint(last_char_count);
                for (size_t j = 0; j < strlen(strfd_count); j++) {
                    output[output_idx] = strfd_count[j];
                    output_idx++;
                }
                free(strfd_count);
            }

            output[output_idx] = last_char;
            output_idx++;
            last_char = string[i];
            last_char_count = 0;
        }
        
        last_char_count++;
    }

    return output;
}

int main(void) {
    char input[256];
    fgets(input, 256, stdin);

    char* compressed = compress_string(input, strlen(input));
    printf("%s\n", compressed);
    free(compressed);
}
