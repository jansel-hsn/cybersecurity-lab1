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

void vigenere_decrypt(const char *ciphertext, const char *key, char *output) {
    int key_len = strlen(key);
    int key_index = 0;

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char c = toupper((unsigned char)ciphertext[i]);

        if (isalpha((unsigned char)c)) {
            char k_char = toupper((unsigned char)key[key_index % key_len]);
            int shift = k_char - 'A';
            output[i] = ((c - 'A' - shift + 26) % 26) + 'A';
            key_index++;
        } else {
            output[i] = ciphertext[i];
        }
    }

    output[strlen(ciphertext)] = '\0';
}

void remove_newline(char *str) {
    str[strcspn(str, "\r\n")] = '\0';
}

int main() {
    FILE *f_enc = fopen("encrypted.txt", "r");
    FILE *f_key = fopen("key.txt", "r");
    FILE *f_out;

    if (f_enc == NULL || f_key == NULL) {
        printf("Error opening input files.\n");
        return 1;
    }

    char encrypted[1024];
    char key[256];
    char decrypted[1024];

    if (fgets(encrypted, sizeof(encrypted), f_enc) == NULL) {
        printf("Error reading encrypted text.\n");
        fclose(f_enc);
        fclose(f_key);
        return 1;
    }

    if (fgets(key, sizeof(key), f_key) == NULL) {
        printf("Error reading key.\n");
        fclose(f_enc);
        fclose(f_key);
        return 1;
    }

    fclose(f_enc);
    fclose(f_key);

    remove_newline(encrypted);
    remove_newline(key);

    vigenere_decrypt(encrypted, key, decrypted);

    f_out = fopen("decrypted.txt", "w");
    if (f_out == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    fprintf(f_out, "%s", decrypted);
    fclose(f_out);

    printf("Encrypted : %s\n", encrypted);
    printf("Key       : %s\n", key);
    printf("Decrypted : %s\n", decrypted);
    printf("Result saved to decrypted.txt\n");

    return 0;
}