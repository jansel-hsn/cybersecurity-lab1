#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int is_weak_password(const char *pass) {
    const char *weak[] = {"password", "123456", "admin", "qwerty", "letmein"};
    int weak_count = sizeof(weak) / sizeof(weak[0]);

    for (int i = 0; i < weak_count; i++) {
        if (strcmp(pass, weak[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int analyze_password(const char *pass) {
    int score = 0;
    int has_lower = 0, has_upper = 0, has_digit = 0, has_special = 0;

    for (int i = 0; pass[i] != '\0'; i++) {
        score++;

        if (islower((unsigned char)pass[i])) has_lower = 1;
        else if (isupper((unsigned char)pass[i])) has_upper = 1;
        else if (isdigit((unsigned char)pass[i])) has_digit = 1;
        else has_special = 1;
    }

    if (has_lower) score += 10;
    if (has_upper) score += 10;
    if (has_digit) score += 15;
    if (has_special) score += 20;

    if (is_weak_password(pass)) score -= 20;

    if (score < 0) score = 0;
    if (score > 100) score = 100;

    return score;
}

int main() {
    char password[256];

    printf("Enter password: ");
    scanf("%255s", password);

    int result = analyze_password(password);
    printf("Password score: %d/100\n", result);

    if (result < 40)
        printf("Weak password\n");
    else if (result < 70)
        printf("Moderate password\n");
    else
        printf("Strong password\n");

    return 0;
}