#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[10][10] = {
    "int", "float", "if", "else", "while",
    "for", "return", "char", "double", "void"
};

int isKeyword(char *word){
    for(int i=0; i<10; i++){
        if(strcmp(keywords[i], word) == 0){
            return 1;
        }
    }
    return 0;
}

int main(){
    char ch, buffer[50];
    int i=0;

    FILE *fp = fopen("input.c", "r");

    if(fp == NULL){
        printf("Error opening file\n");
        return 0;
    }

    printf("TOKENS FOUND\n");

    while((ch = fgetc(fp)) != EOF){
        // Preprocessor Symbol
        if(ch == '#'){
            printf("# -> Special symbol\n");

            fscanf(fp, "%s", buffer);
            printf("%s -> Preprocessor Directive\n", buffer);

            fgetc(fp);
            printf("< -> Special symbol\n");

            fscanf(fp, "%[^>]", buffer);
            printf("%s -> Header File\n", buffer);

            fgetc(fp);
            printf("> -> Special symbol\n");
        }
        // Identifier or keyword
        // if(isalnum(ch)){
        //     buffer[i++] = ch;
        // }
        else if(isalpha(ch)){
            buffer[i++] = ch;
            while(isalnum(ch = fgetc(fp))){
                buffer[i++] = ch;
            }

            buffer[i] = '\0';

            if(isKeyword(buffer)){
                printf("%s -> Keyword\n", buffer);
            }
            else{
                printf("%s -> Identifier\n", buffer);
            }

            i = 0;
            ungetc(ch, fp);
        }
        // End of token
        // else if((ch == ' ' || ch == '\n' || ch == '\t') && i !=0){
        //     buffer[i] = '\0';
        //     if(isKeyword(buffer)){
        //         printf("%s -> Keyword\n", buffer);
        //     }
        //     else if(isdigit(buffer[0])){
        //         printf("%s -> Number\n", buffer);
        //     }
        //     else{
        //         printf("%s -> Identifier\n", buffer);
        //     }
        //     i = 0;
        //     ungetc(ch, fp);
        // }

        else if(isdigit(ch)){
            buffer[i++] = ch;
            while(isdigit(ch = fgetc(fp))){
                buffer[i++] = ch;
            }

            buffer[i] = '\0';
            printf("%s -> Number\n", buffer);

            i = 0;
            ungetc(ch, fp);
        }

        else if(ch == '+' || ch == '-' ||  ch == '*' || ch == '/' || ch == '<' || ch == '>'){
            printf("%c -> Operator\n", ch);
        }

        else if(ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}'){
            printf("%c -> Special Symbol\n", ch);
        }
    }
    fclose(fp);
    return 0;
}