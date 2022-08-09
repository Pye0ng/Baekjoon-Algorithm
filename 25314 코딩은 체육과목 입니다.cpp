#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    while(n){
        n-=4;
        printf("long ");
    }
    printf("int");
}