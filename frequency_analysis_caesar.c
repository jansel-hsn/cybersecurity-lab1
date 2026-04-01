#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void print_histogram(const char *text) {
    int counts[26] = {0};
    int total_letters = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            int index = toupper((unsigned char)text[i]) - 'A';
            counts[index]++;
            total_letters++;
        }
    }

    printf("\n--- FREQUENCY HISTOGRAM ---\n");
    printf("Total letters: %d\n\n", total_letters);

    for (int i = 0; i < 26; i++) {
        if (counts[i] > 0) {
            printf("%c (%3d): ", 'A' + i, counts[i]);
            for (int j = 0; j < counts[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
}

int main() {
    const char *text =
        "This is a simple English text used for frequency analysis. "
        "The letter E should appear very often in this sentence.";

    print_histogram(text);

    return 0;
}