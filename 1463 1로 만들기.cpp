#include<stdio.h>
#include<queue>
using namespace std;
int cnt;
bool visited[1000001];
queue<int> q;

void bfs(int s){
	q.push(s);
	visited[s]=1;
	while(!q.empty()){
		int k=q.size();
		for(int i=0; i<k; i++){
			int p=q.front();
			if(p==1) return;
			q.pop();
			if(p%3==0&&!visited[p/3]){
				q.push(p/3);
				visited[p/3]=1;
			}
			if(p%2==0&&!visited[p/2]){
				q.push(p/2);
				visited[p/2]=1;
			}
			if(p>=2&&!visited[p-1]){
				q.push(p-1);
				visited[p-1]=1;
			}
		}
		cnt++;
	}
}

int main(){
	int x;
	scanf("%d", &x);
	bfs(x);
	printf("%d", cnt);
}
