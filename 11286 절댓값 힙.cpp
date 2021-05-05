#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
int n, k;

int abs(int a){ return a>0?a:-a; }

void heap_pop(){
	if(q.size()){
		printf("%d\n", q.top().first*q.top().second);
		q.pop();	
	}
	else printf("0\n");
}

int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &k);
		if(k==0) heap_pop();
		else q.push({abs(k), k/abs(k)});
	}
}
