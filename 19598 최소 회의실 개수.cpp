#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
priority_queue<int, vector<int>, greater<int> > q;
vector<pii> v;

int main(){
	int n, s, e, m=1, i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d %d", &s, &e);
		v.push_back(pii(s, e));
	}
	sort(v.begin(), v.end());
	q.push(v[0].y);
	for(i=1; i<n; i++){
		while(!q.empty()&&q.top()<=v[i].x) q.pop();
		q.push(v[i].y);
		m=max(m, (int)q.size());
	}
	printf("%d", m);
}
