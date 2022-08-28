#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
    int a, b, c, t;
    scanf("%d %d %d", &a, &b, &c);
    t=min({a, b, c});
    if(a+b+c>99) printf("OK");
    else printf("%s", t==a?"Soongsil":t==b?"Korea":"Hanyang");
}