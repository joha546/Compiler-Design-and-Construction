#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFFER_SIZE 4096
#define MAX_FILENAME_LENGTH 255

char buffer[BUFFER_SIZE];

void clearInputBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void getUserInput(const char *prompt){
    printf("%s", prompt);
    clearInputBuffer();
    
    if(fgets(buffer, BUFFER_SIZE, stdin) != NULL){
        size_t len = strlen(buffer);
        if(len > 0 && buffer[len - 1] == '\n'){
            buffer[len - 1] = '\0';
        }
    }
}

FILE *openFile(const char *filename, const char *mode){
    FILE *file = fopen(filename, mode);
    if(file == NULL){
        perror("Error opening file");
    }
    return file;
}

void writeToFile(const char *filename){
    FILE *file = openFile(filename, "w");
    if(file == NULL){
        return;
    }

    getUserInput("Enter text to write into the file:\n");
    
    fprintf(file, "%s\n", buffer);
    fclose(file);
    printf("Data written successfully.\n");
}

void appendToFile(const char *filename){
    FILE *file = openFile(filename, "a");
    if(file == NULL){
        return;
    }

    getUserInput("Enter text to append to the file:\n");
    
    fprintf(file, "%s\n", buffer);
    fclose(file);
    printf("Data appended successfully.\n");
}

void readAndCount(const char *filename){
    FILE *file = openFile(filename, "r");
    if(file == NULL){
        return;
    }

    int lineCount = 0, wordCount = 0, charCount = 0;
    bool inWord = false;

    printf("\n--- File Content ---\n");

    while(fgets(buffer, BUFFER_SIZE, file) != NULL){
        printf("%s", buffer);
        lineCount++;
        
        size_t len = strlen(buffer);
        // Not to count new line character
        if(len > 0 && buffer[len - 1] == '\n'){
            charCount += len - 1;
        }
        else{
            charCount += len;
        }

        for(size_t i = 0; i < len; i++){
            if(isspace((unsigned char)buffer[i])){
                inWord = false;
            } 
            else if(!inWord){
                inWord = true;
                wordCount++;
            }
        }
    }

    fclose(file);

    printf("\n--- File Statistics ---\n");
    printf("Lines: %d\n", lineCount);
    printf("Words: %d\n", wordCount);
    printf("Characters: %d\n", charCount);
}

int main() {
    char filename[MAX_FILENAME_LENGTH + 1];
    int choice;

    printf("Enter file name: ");
    if(scanf("%255s", filename) != 1){
        printf("Error reading filename.\n");
        return 1;
    }

    while(1){
        printf("\n--- File Operations Menu ---\n");
        printf("1. Write to file\n");
        printf("2. Append to file\n");
        printf("3. Read & Count file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if(scanf("%d", &choice) != 1){
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch(choice){
            case 1:
                writeToFile(filename);
                break;
            case 2:
                appendToFile(filename);
                break;
            case 3:
                readAndCount(filename);
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}