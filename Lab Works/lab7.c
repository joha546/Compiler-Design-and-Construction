#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n;
char production[10][10];
char first[10][10];
int firstCount[10];

void addToFirst(int index, char ch){
    for(int i=0; i<firstCount[index]; i++){
        if(first[index][i] == ch){
            return;
        }
    }

    first[index][firstCount[index]++] = ch;
}

void findFirst(int index){
    char rhs[10];
    strcpy(rhs, production[index]+2);

    if(!isupper(rhs[0])){
        addToFirst(index, rhs[0]);
        return;
    }

    int ntIndex = rhs[0] - 'A';
    findFirst(ntIndex);
}

int main(){
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions {For example: E=TR:}\n");
    for(int i=0; i<n; i++){
        scanf("%s", production[i]);
        firstCount[i] = 0;
    }

    for(int i=0; i<n; i++){
        findFirst(i);
    }

    printf("\nFirst sets: \n");
    for(int i=0; i<n; i++){
        printf("First(%c) = { ", production[i][0]);
        for(int j=0; j<firstCount[i]; j++){
            printf("%c", first[i][j]);
        }
        printf("}\n");
    }

    return 0;
}