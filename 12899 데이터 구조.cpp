#include<stdio.h>
#include<vector>
using namespace std;
vector<int> s(8000100, 0);
int d[2000100], n=2000000;

void upd(int c, int a, int b, int i, int t){
	if(i<a||i>b) return;
	s[c]+=t;
	if(a!=b){
		int m=a+b>>1;
		upd(c<<1, a, m, i, t);
		upd(c<<1|1, m+1, b, i, t);
	}
}

int find(int c, int a, int b, int t){
	if(a==b) return a;
	int m=a+b>>1;
	if(t<=s[c<<1]) return find(c<<1, a, m, t);
	else return find(c<<1|1, m+1, b, t-s[c<<1]);
}

int main(){
	int N, a, b, i;
	scanf("%d", &N);
	while(N--){
		scanf("%d %d", &a, &b);
		if(a&1) upd(1, 1, n, b, 1);
		else{
			b=find(1, 1, n, b);
			printf("%d\n", b);
			upd(1, 1, n, b, -1);
		}
	}
}
