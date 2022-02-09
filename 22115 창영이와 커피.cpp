#include<stdio.h>
#define min(x, y) x<y?x:y
int t, c[110], d[100100];

int main(){
	int n, k, i, j;
	scanf("%d %d", &n, &k);
	for(i=1; i<=k; i++) d[i]=101;
	for(i=1; i<=n; i++){
		scanf("%d", &c[i]);
		d[c[i]]=1;
	}
	for(i=1; i<=n; i++)
		for(j=k; j>0; j--)
			if(j>=c[i]&&d[j-c[i]]!=101) d[j]=min(d[j], d[j-c[i]]+1);
	if(d[k]==101) printf("-1");
	else printf("%d", d[k]); 
}
