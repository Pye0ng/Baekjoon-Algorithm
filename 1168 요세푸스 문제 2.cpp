#include<stdio.h>
#include<vector>
using namespace std;
vector<int> s;

int seg(int c, int a, int b){
	if(a==b) return s[c]=1;
	int m=(a+b)>>1;
	return s[c]=seg(c<<1, a, m)+seg(c<<1|1, m+1, b);
}

int find(int c, int a, int b, int t){
	if(a==b) return a;
	int m=(a+b)>>1;
	if(t<=s[c<<1]) return find(c<<1, a, m, t);
	else return find(c<<1|1, m+1, b, t-s[c<<1]);
}

void upd(int c, int a, int b, int i){
	if(i<a||i>b) return;
	s[c]--;
	if(a!=b){
		int m=(a+b)>>1;
		upd(c<<1, a, m, i);
		upd(c<<1|1, m+1, b, i);
	}
}

int main(){
	int n, k, t, o=1, p, i;
	scanf("%d %d", &n, &k);
	s.resize(n*4); seg(1, 1, n);
	printf("<");
	for(i=0; i<n; i++){
		p=n-i; o+=k-1;
		if(o%p==0) o=p;
		else o%=p;
		t=find(1, 1, n, o);
		upd(1, 1, n, t);
		printf("%d", t);
		if(i<n-1) printf(", ");
	}
	printf(">");
}
