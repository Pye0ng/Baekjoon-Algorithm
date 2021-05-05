#include<stdio.h>
#include<algorithm>
int cnt, d[100001], a[100001];

int gcd(int a, int b){
	int n;
	if(a>=b){ while(a%b!=0){ n=a%b; a=b; b=n; } return b; }
	else{ while(b%a!=0){ n=b%a; b=a; a=n; } return a; }
}

int main(){
	int n, t, i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &d[i]);
	std::sort(d, d+n);
	for(i=1; i<n; i++) a[i]=d[i]-d[i-1];
	t=gcd(a[1], a[2]);
	for(i=3; i<n; i++) t=gcd(t, a[i]);
	for(i=1; i<n; i++){
		int s=(a[i]/t);
		cnt+=s;
	}
	printf("%d", cnt-n+1);
}
