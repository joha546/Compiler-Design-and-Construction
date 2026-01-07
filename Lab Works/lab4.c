#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_KEYWORDS 50
#define MAX_KEYWORD_LENGTH 20

int readKeywords(char keywords[][MAX_KEYWORD_LENGTH], const char* filename){
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening keywords file.\n");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%s", keywords[count]) == 1 && count < MAX_KEYWORDS) {
        count++;
    }
    printf("%d", count);
    fclose(file);
    return count;
}

int isKeyword(char str[], char keywords[][MAX_KEYWORD_LENGTH], int keywordCount){
    for(int i=0; i<keywordCount; i++){
        if(strcmp(str, keywords[i]) == 0){
            return 1;
        }
    }
    return 0;
}

int main(){
    char str[MAX_KEYWORD_LENGTH];
    char keywords[MAX_KEYWORDS][MAX_KEYWORD_LENGTH];
    char keywordFilename[40];
    int keywordCount;

    scanf("%s", keywordFilename);

    keywordCount = readKeywords(keywords, keywordFilename);
    if(keywordCount == 0){
        printf("No keywords loaded. Exiting.\n");
        return 1;
    }

    while(getchar() != '\n');

    scanf("%s", str);

    if(isKeyword(str, keywords, keywordCount)){
        printf("\"%s\" is a keyword.\n", str);
    }
    else{
        printf("\"%s\" is not a keyword.\n", str);
    }
    return 0;
}