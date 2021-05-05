#include<stdio.h>
#include<vector>
int N, k, d[100010];
std::vector<int> v;

int sg(int n, int a, int b){
	if(a==b) return v[n]=d[a];
	int m=(a+b)/2;
	return v[n]=sg(2*n, a, m)+sg(2*n+1, m+1, b);
}

int sm(int n, int a, int b, int p, int q){
	if(a>q||b<p) return 0;
	if(b<=q&&a>=p) return v[n];
	int m=(a+b)/2;
	return sm(2*n, a, m, p, q)+sm(2*n+1, m+1, b, p, q);
}

void ud(int n, int a, int b, int index, int df){
	if(index<a||index>b) return;
	v[n]+=df;	
	if(a!=b){
		int m=(a+b)/2;
		ud(2*n, a, m, index, df);
		ud(2*n+1, m+1, b, index, df);
	}
}

int main(){
	int a, b, c, i;
	v.resize(400100);
	scanf("%d", &N);
	for(i=1; i<=N; i++){
		scanf("%d", &d[i]);
		d[i]%=2;
	}
	sg(1, 1, N);
	scanf("%d", &k);
	for(i=1; i<=k; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(a==1){
			ud(1, 1, N, b, c%2-d[b]);
			d[b]=c%2;
		}
		else if(a==2) printf("%d\n", c-b+1-sm(1, 1, N, b, c));
		else printf("%d\n", sm(1, 1, N, b, c));
	}
}
