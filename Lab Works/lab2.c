#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isComment(char *line){
    int i = 0;
    int len = strlen(line);
    bool inString = false;
    bool inChar = false;
    bool escapeNext = false;

    while(i < len){
        if(escapeNext){
            escapeNext = false;
            i++;
            continue;
        }

        if(line[i] == '\\'){
            escapeNext = true;
            i++;
            continue;
        }

        // handling string literals
        if(line[i] == '"' && !inChar){
            inString = !inString;
            i++;
            continue;
        }

        // handle character literals
        if(line[i] == '\'' && !inString){
            inChar = !inChar;
            i++;
            continue;
        }

        if(!inString && !inChar){
            if(i < len-1 && line[i] == '/' && line[i+1] == '/'){
                return true;
            }
        }
        i++;
    }
    return false;
}

int main(){
    char line[1000];

    printf("Enter a line of code: ");
    fgets(line, sizeof(line), stdin);

    line[strcspn(line, "\n")] = '\0';

    if(isComment(line)){
        printf("This line is a comment....\n");
    }
    else{
        printf("The line is not a comment....\n");
    }
    return 0;
}
