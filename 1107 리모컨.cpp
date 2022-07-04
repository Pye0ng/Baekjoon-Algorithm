#include<stdio.h>
#include<algorithm>
using namespace std;
int br[12];

bool no(int t){
	if(!t) return br[0];
	while(t){
		if(br[t%10]) return 1;
		t/=10;
	}
	return 0;
}

int main(){
	int n, t, s, p, i;
	scanf("%d %d", &n, &t);
	while(t--){
		scanf("%d", &s);
		br[s]=1;
	}
	s=1e7;
	for(i=1000000; i>=0; i--){
		if(i!=100&&no(i)) continue;
		p=(i==100?0:i); t=0;
		while(p){ p/=10; t++; }
		if(!i) t=1;
		s=min(s, abs(n-i)+t);
	}
	printf("%d", s);
}
