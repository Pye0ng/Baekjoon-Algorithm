#include<stdio.h>
int i, d[28];
char c[110];

int main(){
    scanf("%s", c);
    for(i=0; c[i]!='\0'; i++) d[c[i]-'a']++;
    for(i=0; i<26; i++) printf("%d ", d[i]);
}