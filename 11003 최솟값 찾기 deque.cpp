#include<stdio.h>
#include<deque>
using namespace std;
deque<int> q;
int d[5000100];

int main(){
	int n, l, t, i;
	scanf("%d %d", &n, &l);
	for(i=1; i<=n; i++){
		scanf("%d", &d[i]);
		while(!q.empty()&&d[q.back()]>=d[i]) q.pop_back();
		q.push_back(i);
		if(q.front()<=i-l) q.pop_front();
		printf("%d ", d[q.front()]);
	}
}
