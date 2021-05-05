#include<stdio.h>
#include<set>
using namespace std;
set<int> s;

int main(){
	int n, k, i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &k);
		s.insert(k);
	}
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &k);
		printf("%d\n", s.find(k)!=s.end());
	}
}
