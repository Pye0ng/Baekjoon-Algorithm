#include<stdio.h>
int n, ans, d[10010];
int min(int a, int b){ return a<b?a:b; }

int main(){
	int a, b, i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &d[i]);
	for(i=0; i<n; i++){
		if(d[i+1]>d[i+2]){
			a=min(d[i], d[i+1]-d[i+2]);
			ans+=a*5; d[i]-=a; d[i+1]-=a;
			b=min(d[i], min(d[i+1], d[i+2]));
			ans+=b*7; d[i]-=b; d[i+1]-=b; d[i+2]-=b;
		}
		else{
			b=min(d[i], d[i+1]);
			ans+=b*7; d[i]-=b; d[i+1]-=b; d[i+2]-=b;
			a=min(d[i], d[i+1]);
			ans+=a*5; d[i]-=a; d[i+1]-=a; d[i+2]-=a;
		}
		ans+=d[i]*3;
	}
	printf("%d", ans);
}
