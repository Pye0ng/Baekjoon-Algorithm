#include<stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a+b+c!=180) printf("Error");
    else{
        if(a==60&&b==60) printf("Equilateral");
        else if(a==b||b==c||c==a) printf("Isosceles");
        else printf("Scalene");
    }
}