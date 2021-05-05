#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v[60];
bool d[60];
int n, root, cnt;

bool check(int k){
	for(int i=0; i<v[k].size(); i++)
		if(!d[v[k][i]]) return 0;
	return 1;
}

void find(int k){
	d[k]=1;
	for(int i=0; i<v[k].size(); i++)
		if(!d[v[k][i]]) find(v[k][i]);
}

int main(){
	int k, i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &k);
		if(k==-1) root=i;
		else v[k].push_back(i);
	}
	scanf("%d", &k);
	if(k==root){
		printf("0");
		return 0;
	}
	find(k);
	for(i=0; i<n; i++)
		if(!d[i]&&check(i)) cnt++;
	printf("%d", cnt);
} 
