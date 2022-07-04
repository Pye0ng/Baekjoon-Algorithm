#include<stdio.h>
long long int n, m;

int main(){
    scanf("%lld %lld", &n, &m);
    printf("%s", (n-1)%(m+1)?"Can win":"Can't win");
}