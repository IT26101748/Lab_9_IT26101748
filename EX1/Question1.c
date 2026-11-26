#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{    
    char name[50] = "";
    int hasLastName = 0;
    int newWord = 1;

    printf("Input Name: ");
    fgets(name, sizeof(name), stdin);

    int len = strlen(name);
    while (len > 0 && (name[len - 1] == '\n' || name[len - 1] == ' '))
    {
        name[len - 1] = '\0';
        len--;
    }

    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == ' ') {
            newWord = 1;
        } else {
            if (newWord) {
                name[i] = toupper(name[i]);
                if (i > 0) {
                    hasLastName = 1;
                }
                newWord = 0;
            } else {
                name[i] = tolower(name[i]);
            }
        }
    }
    
    if (!hasLastName && len > 0)
    {
        strcat(name, " N/A");
    }

    printf("Output: %s\n", name);

    return 0;
}

