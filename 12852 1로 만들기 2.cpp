#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
queue<int> q;
vector<int> v;
int n, m, cnt, ans[1000100];
bool visited[1000100];

void bfs(){
	int i;
	while(!q.empty()){
		int s=q.size();
		for(i=1; i<=s; i++){
			m=q.front();
			q.pop();
			if(m==1){
				while(!q.empty()) q.pop();
				return;
			}
			else{
				if(m%3==0&&!visited[m/3]){
					ans[m/3]=m;
					visited[m/3]=1;
					q.push(m/3);
				}
				if(m%2==0&&!visited[m/2]){
					ans[m/2]=m;
					visited[m/2]=1;
					q.push(m/2);
				}
				if(m-1>0&&!visited[m-1]){
					ans[m-1]=m;
					visited[m-1]=1;
					q.push(m-1);
				}
			}
		}
		cnt++;
	} 
}

int main(){
	int i;
	scanf("%d", &n);
	if(n==1){
		printf("0\n1");
		return 0;
	}
	q.push(n);
	visited[n]=1;
	bfs();
	printf("%d\n", cnt);
	v.push_back(m=1);
	do{
		m=ans[m];
		v.push_back(m);
	}while(m!=n);
	for(i=v.size()-1; i>=0; i--) printf("%d ", v[i]);
}
