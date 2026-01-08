#include<stdio.h>
#include<string.h>

int main(){
    char srcCode[100];
    // bool inString;
    printf("Enter source code: ");
    fgets(srcCode, sizeof(srcCode), stdin);

    for(int i=0; i<sizeof(srcCode); i++){
        if(srcCode[i] == ' ' || srcCode[i] == '\t'){
            printf("\n");
        }
        else if(srcCode[i] == '(' || srcCode[i] == ')' || srcCode[i] == '{' || srcCode[i] == '}' || srcCode[i] == ',' || srcCode[i] == ';'){
            printf("\n%c", srcCode[i]);
        }
        else{
            if(srcCode[i] == '/' && srcCode[i+1] == '/'){
                printf("This line is a comment skip it");
                return 0;
            }
            printf("%c", srcCode[i]);
        }
    }
    return 0;
}
