#include<stdio.h>
char c[1000100];
long long n, k, sum;

int main(){
    int i;
    scanf("%s", c);
    for(i=0; c[i]!='\0'; i++){
        if(c[i]=='1'){ sum+=i+1; k++; }
        n++;
    }
    k=n-k;
    printf("%s", (n*(n+1)/2-k*(k+1)/2-sum)%3?"Alice":"Bob");
}