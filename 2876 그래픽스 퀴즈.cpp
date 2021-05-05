#include<stdio.h>
int n, m, t, a[1000010], b[1000010], da[1000010], db[1000010];

int main(){
	int i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d %d", &a[i], &b[i]);
	if(n==1){ printf("1 %d", a[1]<b[1]?a[1]:b[1]); return 0; }
	da[1]=db[1]=1; 
	for(i=2; i<=n; i++){
		da[i]=db[i]=1;
		if(a[i]==a[i-1]) da[i]=da[i-1]+1;
		if(a[i]==b[i-1]&&db[i-1]+1>da[i]) da[i]=db[i-1]+1;
		if(b[i]==a[i-1]) db[i]=da[i-1]+1;
		if(b[i]==b[i-1]&&db[i-1]+1>db[i]) db[i]=db[i-1]+1;
		if((da[i]>db[i]?da[i]:db[i])>m){
			m=da[i]>db[i]?da[i]:db[i];
			if(da[i]>db[i]) t=a[i];
			else if(da[i]==db[i]) t=a[i]>b[i]?b[i]:a[i];
			else t=b[i];
		} 	
	}
	printf("%d %d", m, t);
}
