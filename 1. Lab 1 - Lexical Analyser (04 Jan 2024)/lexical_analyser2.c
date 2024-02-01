#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void lexicalAnalyzer(FILE *file) {
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            // Ignore spaces
            continue;
        } else if (isalpha(ch)) {
            // Tokenize words
            printf("Word: ");
            while (isalnum(ch)) {
                printf("%c", ch);
                ch = fgetc(file);
            }
            printf("\n");
            ungetc(ch, file); // Put back non-alphanumeric character
        } else {
            // Tokenize other characters
            printf("Character: %c\n", ch);
        }
    }
}

int main() {
    FILE *file;
    char filename[50];

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    lexicalAnalyzer(file);

    fclose(file);

    return 0;
}


