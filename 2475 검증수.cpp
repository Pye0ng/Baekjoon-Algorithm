#include<stdio.h>
int c[6];
int sq(int n){ return n*n; }

int main(){
    int i, sum=0;
    for(i=0; i<5; i++) scanf("%d", &c[i]);
    for(i=0; i<5; i++) sum+=sq(c[i]);
    printf("%d", sum%10);
}
