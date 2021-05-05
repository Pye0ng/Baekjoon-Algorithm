#include<iostream>
using namespace std;
char s[101][101];
int n, m, ans[101][101];

int sur(int x, int y){
	int cnt=0;
	for(int i=x-1; i<=x+1&&i<n; i++){
		for(int j=y-1; j<=y+1&&j<m; j++){
			if(i<0||j<0||(i==x&&j==y)) continue;
			else{ if(s[i][j]=='*') cnt++; }
		}
	}
	return cnt;
}

int main(){
	int i, j;
	cin>>n>>m;
	while(n+m!=0){
		for(i=0; i<n; i++) cin>>s[i];
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				if(s[i][j]=='.') ans[i][j]=sur(i, j);
				else ans[i][j]=-1;
			}
		}
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				if(ans[i][j]>=0) cout<<ans[i][j];
				else cout<<"*";
			}
			cout<<"\n";
		}
		cin>>n>>m;
	}
}

