#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void normalize_text(const char *input, char *output) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha((unsigned char)input[i])) {
            output[j++] = toupper((unsigned char)input[i]);
        }
    }
    output[j] = '\0';
}

void find_repeated_trigrams(const char *text) {
    int len = strlen(text);

    printf("--- KASISKI HELPER REPORT ---\n");

    for (int i = 0; i < len - 2; i++) {
        char trigram[4];
        strncpy(trigram, &text[i], 3);
        trigram[3] = '\0';

        for (int j = i + 3; j < len - 2; j++) {
            if (strncmp(trigram, &text[j], 3) == 0) {
                printf("Found \"%s\": Pos %d & Pos %d -> Distance: %d\n",
                       trigram, i, j, j - i);
            }
        }
    }
}

int main() {
    const char *ciphertext =
        "LXFOPVEFRNHRLXFOPVEFRNHRABCXYZLXF";

    char normalized[2048];
    normalize_text(ciphertext, normalized);

    find_repeated_trigrams(normalized);

    return 0;
}