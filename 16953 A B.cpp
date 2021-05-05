#include<stdio.h>
#include<queue>
#include<math.h>
std::queue<long long int> q;
int st(int t){ return (int)floor(log10(t)); }
int t, s;

int main(){
	long long int a, b, f;
	scanf("%lld %lld", &a, &b);
	q.push(a);
	while(!q.empty()){
		s=q.size(); t++;
		for(int i=0; i<s; i++){
			f=q.front(); q.pop();
			if(f==b){ printf("%d", t); return 0; }
			if(f*2<=b) q.push(f*2);
			if(f*10<b) q.push(f*10+1);
		}
	}
	printf("-1");
}
