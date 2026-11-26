#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char catalog[3][50] = {"Camera", "Camp Stove", "Candle"};
    char search[50];
    int firstMatch = 1;

    printf("Input: ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = '\0';

    for (int i = 0; search[i] != '\0'; i++) {
        search[i] = tolower(search[i]);
    }

    printf("Output: Products found: ");
    for (int i = 0; i < 3; i++) {
        char temp[50];
        strcpy(temp, catalog[i]);
        for (int j = 0; temp[j] != '\0'; j++) {
            temp[j] = tolower(temp[j]);
        }

        if (strstr(temp, search) != NULL) {
            if (!firstMatch) {
                printf(", ");
            }
            printf("%s", catalog[i]);
            firstMatch = 0;
        }
    }
    printf("\n");

    return 0;
}

