#include<stdio.h>
#include<queue>
#include<memory.h>
using namespace std;

queue<int> q;
int d;
bool visited[100500];

int main(){
	int a, b, i;
	memset(visited, 0, sizeof(visited));
	scanf("%d %d", &a, &b);
	if(a>=b){
		printf("%d", a-b);
		return 0;
	}
	q.push(a);
	visited[a]=1;
	
	while(!q.empty()){
		int size=q.size();
		for(i=0; i<size; i++){
			int v=q.front();
			q.pop();
			if(v==b){
				printf("%d", d);
				queue<int> zero;
				q=zero;
				break;
			}
			if(v-1>=0&&!visited[v-1]){
				q.push(v-1);
				visited[v-1]=1;
			}
			if(v+1<=100500&&!visited[v+1]){
				q.push(v+1);
				visited[v+1]=1;
			}
			if(v*2<=100500&&!visited[v*2]){
				q.push(v*2);
				visited[v*2]=1;
			}
		}
		d++;
	}
}
