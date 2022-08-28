#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
    int a, b, c, t;
    scanf("%d %d %d", &a, &b, &c);
    if(a==b&&b==c) t=10000+a*1000;
    else if(a==b||a==c) t=1000+a*100;
    else if(b==c) t=1000+b*100;
    else t=max({a, b, c})*100;
    printf("%d", t);
}