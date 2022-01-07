#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
queue<pair<pair<int, int>, int> > q;
vector<int> v;
int visit[210][210][210];

int main(){
	int A, B, C, a, b, c, i;
	scanf("%d %d %d", &A, &B, &C);
	q.push({{0, 0}, C});
	while(!q.empty()){
		a=q.front().first.first;
		b=q.front().first.second;
		c=q.front().second;
		q.pop();
		if(visit[a][b][c]) continue;
		visit[a][b][c]=1;
		if(a==0) v.push_back(c);
		if(a+b>A) q.push({{A, a+b-A}, c});
		else q.push({{a+b, 0}, c}); 
		if(a+b>B) q.push({{a+b-B, B}, c});
		else q.push({{0, a+b}, c}); 
		if(b+c>B) q.push({{a, B}, b+c-B});
		else q.push({{a, b+c}, 0}); 
		if(b+c>C) q.push({{a, b+c-C}, C});
		else q.push({{a, 0}, b+c}); 
		if(a+c>A) q.push({{A, b}, a+c-A});
		else q.push({{a+c, b}, 0}); 
		if(a+c>C) q.push({{a+c-C, b}, C});
		else q.push({{0, b}, a+c}); 
	}
	sort(v.begin(), v.end());
	for(i=0; i<v.size(); i++) printf("%d ", v[i]);
}
