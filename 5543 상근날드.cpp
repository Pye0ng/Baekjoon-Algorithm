#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    printf("%d", min({a, b, c})+min(d, e)-50);
}