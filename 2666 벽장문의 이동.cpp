#include<stdio.h>
#include<queue>
using namespace std;
struct p{ int a, b, c; };
queue<p> q;

int abs(int t){ return t>0?t:-t; }

int main(){
	int n, m, mx=10000, s, a, b, k, i, j; p t;
	scanf("%d %d %d %d", &n, &a, &b, &m);
	if(a<b){ t.a=a; t.b=b; }
	else{ t.a=b; t.b=a; }
	t.c=0; q.push(t);
	for(i=0; i<m; i++){
		scanf("%d", &k);
		s=q.size();
		for(j=0; j<s; j++){
			t=q.front();
			p t1, t2;
			if(k<=t.a){
				t1.a=k; t1.b=t.b; t1.c=t.c+t.a-k;
				t2.a=k; t2.b=t.a+1; t2.c=t.c+t.b-k-1;
			}
			else if(t.a<k&&k<t.b){
				t1.a=k; t1.b=t.b; t1.c=t.c+k-t.a;
				t2.a=t.a; t2.b=k; t2.c=t.c+t.b-k;
			}
			else if(k>=t.b){
				t1.a=t.b-1; t1.b=k; t1.c=t.c+k-t.a-1;
				t2.a=t.a; t2.b=k; t2.c=t.c+k-t.b;
			}
			q.push(t1); q.push(t2);
			q.pop();
		}
	}	
	while(!q.empty()){
		if(q.front().c<mx) mx=q.front().c;
		q.pop();
	}
	printf("%d", mx);
}
