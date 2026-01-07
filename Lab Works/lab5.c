#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isInteger(char str[]){
    int i = 0;
    if(str[i] == '+' || str[i] == '-')
        i++;
    if(!isdigit(str[i]))
        return 0;
    for(; str[i] != '\0'; i++){
        if(!isdigit(str[i]))
            return 0;
    }
    return 1;
}

int isFloat(char str[]){
    int i = 0, dotCount = 0, digitCount = 0;
    if(str[i] == '+' || str[i] == '-'){
        i++;
    }
    for(; str[i] != '\0'; i++){
        if(str[i] == '.'){
            dotCount++;
            if(dotCount > 1)
                return 0;
        }
        else if(isdigit(str[i])){
            digitCount++;
        }
        else{
            return 0;
        }
    }
    return (dotCount == 1 && digitCount > 0);
}

int isCharacterConstant(char str[]) {
    int len = strlen(str);
    if(len == 3 && str[0] == '\'' && str[2] == '\''){
        return 1;
    }
    if(len == 4 && str[0] == '\'' && str[1] == '\\' && str[3] == '\'')
        return 1;
    return 0;
}

int isStringConstant(char str[]) {
    int len = strlen(str);
    return (len >= 2 && str[0] == '"' && str[len - 1] == '"');
}

int main() {
    char str[300];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if(isInteger(str)){
        printf("'%s' is an Integer Constant.\n", str);
    }
    else if(isFloat(str)){
        printf("'%s' is a Floating-Point Constant.\n", str);
    }
    else if(isCharacterConstant(str)){
        printf("'%s' is a Character Constant.\n", str);
    }
    else if(isStringConstant(str)){
        printf("'%s' is a String Constant.\n", str);
    }
    else{
        printf("'%s' is NOT a valid constant.\n", str);
    }
    return 0;
}