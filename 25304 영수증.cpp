#include<stdio.h>

int main(){
    int x=0, c, t, a, b;
    scanf("%d %d", &c, &t);
    while(t--){
        scanf("%d %d", &a, &b);
        x+=a*b;
    }
    printf("%s", x==c?"Yes":"No");
}