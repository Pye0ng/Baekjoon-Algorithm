#include<stdio.h>
#include<set>
using namespace std;

int main(){
	char c;
	int t, k, i;
	long long int n;
	scanf("%d", &t);
	while(t--){
		multiset<long long int> s;
		scanf("%d", &k);
		for(i=0; i<k; i++){
			scanf("\n%c %lld", &c, &n);
			if(c=='I') s.insert(n);
			else if(c=='D'&&!s.empty()){
				if(n==1) s.erase(--s.end());
				else s.erase(s.begin());
			}
		}
		if(s.empty()) printf("EMPTY\n");
		else printf("%lld %lld\n", *(--s.end()), *s.begin());
	}
}
