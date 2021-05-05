#include<stdio.h>
#include<string.h>
char s[101][81];
int sc[101];

int main(){
    int n, i, st=0;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%s", s[i]);
    for(i=0; i<n; i++){
        for(int j=0; j<strlen(s[i]); j++){
            if(s[i][j]=='O') st++;
            else st=0;
            sc[i]+=st;
        }
        st=0; 
    }
    for(i=0; i<n; i++) printf("%d\n", sc[i]);
}
