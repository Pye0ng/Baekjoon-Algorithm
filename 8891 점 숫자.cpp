#include<stdio.h>
#include<utility>
using namespace std;

int T(int n){ return (n*(n+1))/2; }

int main(){
	int t, a, b, i;
	scanf("%d", &t);
	while(t--){
		pair<int, int> aa, bb, p;
		scanf("%d %d", &a, &b);
		for(i=0; i<=200; i++){
			if(T(i)<a&&a<=T(i+1)){ aa.first=a-T(i); aa.second=i+2-aa.first; }
			if(T(i)<b&&b<=T(i+1)){ bb.first=b-T(i); bb.second=i+2-bb.first; }
		}
		p.first=aa.first+bb.first; p.second=aa.second+bb.second;
		printf("%d\n", T(p.first+p.second-2)+p.first);
	}
}
