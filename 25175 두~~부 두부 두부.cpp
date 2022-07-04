#include<stdio.h>

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    k-=3;
    while(k<0) k+=n;
    printf("%d", (m+k)%n?(m+k)%n:n);
}