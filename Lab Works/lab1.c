#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[32][10] ={
    "auto","break","case","char","const","continue","default","do",
    "double","else","enum","extern","float","for","goto","if","int",
    "long","register","return","short","signed","sizeof","static",
    "struct","switch","typedef","union","unsigned","void","volatile","while"
};

int isKeyword(char *str){
    for(int i = 0; i < 32; i++){
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isValidIdentifier(char *str){
    if(!(isalpha(str[0]) || str[0] == '_'))
        return 0;
        
    for(int i = 1; str[i] != '\0'; i++){
        if(!(isalnum(str[i]) || str[i] == '_')){
            return 0;
        }
            
    }

    if(isKeyword(str))
        return 0;

    return 1;
}

int main() {
    char identifier[50];

    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if(isValidIdentifier(identifier))
        printf("'%s' is a VALID identifier.\n", identifier);
    else
        printf("'%s' is an INVALID identifier.\n", identifier);

    return 0;
}
