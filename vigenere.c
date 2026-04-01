#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void vigenere_encrypt(const char *plaintext, const char *key, char *output) {
    int key_len = strlen(key);
    int key_index = 0;

    for (int i = 0; plaintext[i] != '\0'; i++) {
        char p = toupper((unsigned char)plaintext[i]);

        if (isalpha((unsigned char)p)) {
            char k_char = toupper((unsigned char)key[key_index % key_len]);
            int shift = k_char - 'A';

            output[i] = ((p - 'A' + shift) % 26) + 'A';
            key_index++;
        } else {
            output[i] = plaintext[i];
        }
    }

    output[strlen(plaintext)] = '\0';
}

int main() {
    const char *plaintext = "ATTACK AT DAWN";
    const char *key = "LEMON";
    char output[256];

    vigenere_encrypt(plaintext, key, output);

    printf("Plaintext : %s\n", plaintext);
    printf("Key       : %s\n", key);
    printf("Encrypted : %s\n", output);

    return 0;
}