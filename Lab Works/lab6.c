#include <stdio.h>

int main(){
    char str[200];
    int count = 0, i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == ' ')
            count++;
    }

    printf("Number of blank spaces: %d\n", count);

    return 0;
}
