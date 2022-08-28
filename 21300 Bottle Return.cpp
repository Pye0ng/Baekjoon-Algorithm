#include<stdio.h>
int t, s, i;

int main(){
    for(i=0; i<6; i++){
        scanf("%d", &t);
        s+=t;
    }
    printf("%d", s*5);
}