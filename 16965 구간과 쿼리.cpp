#include<stdio.h>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
vector<pair<int, int> > v;
int n, a, b, c;
bool ch, visited[110];

bool check(int s, int k){
	if((v[k].first<v[s].first&&v[s].first<v[k].second)||(v[k].first<v[s].second&&v[s].second<v[k].second)) return 1;
	else return 0;
}

void find(int s, int k){
	visited[s]=1;
	if(check(s, k)){
		ch=1;
		return;
	}
	for(int i=1; i<=n; i++)
		if(check(s, i)&&!visited[i]) find(i, k);
}

int main(){
	int i;
	scanf("%d", &n);
	v.push_back({1, 1});
	for(i=1; i<=n; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(a==1) v.push_back({b, c});
		else{
			find(b, c);
			printf("%d\n", ch);
			ch=0;
			memset(visited, 0, sizeof(visited));
		}
	}
}
