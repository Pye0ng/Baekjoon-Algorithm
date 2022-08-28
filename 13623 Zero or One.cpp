#include<stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a+b+c==0||a+b+c==3) printf("*");
    else printf("%c", a==b?'C':b==c?'A':'B');
}