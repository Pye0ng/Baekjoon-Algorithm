#include<stdio.h>
#include<algorithm>
using namespace std;
char a[110], b[110], c[110];
int la, lb, ans, ch;

int main(){
    int i, j;
    scanf("%s", a);
    scanf("%s", b);
    for(i=0; a[i]!='\0'; i++) la++;
    for(i=0; b[i]!='\0'; i++) lb++;
    a[la]=b[lb]='0';
    for(i=0; i<=la; i++){
        ch=1;
        for(j=0; j<lb; j++) ch&=(b[j]-'0')+(i+j<=la?a[i+j]-'0':0)<=3;
        if(ch){
            ans=max(la, i+lb);
            break;
        }
    }
    for(i=0; i<=lb; i++){
        ch=1;
        for(j=0; j<la; j++) ch&=(a[j]-'0')+(i+j<=lb?b[i+j]-'0':0)<=3;
        if(ch){
            ans=min(ans, max(lb, i+la));
            break;
        }
    }
    printf("%d", ans);
}