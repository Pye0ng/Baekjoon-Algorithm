#include<stdio.h>
int n, cnt;void sam(int nw, int sum){if(nw>n){if(sum%3==0)cnt++;return;}sam(nw+1, sum);sam(nw+1, sum+1);sam(nw+1, sum+2);}int main(){scanf("%d", &n);sam(2, 1);sam(2, 2);printf("%d", cnt);}
