#include<stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        char c[5];
        scanf("%s", c);
        printf("%s\n", (c[0]=='Y'||c[0]=='y')&&(c[1]=='E'||c[1]=='e')&&(c[2]=='S'||c[2]=='s')?"YES":"NO");
    }
}