#include<iostream>
#include<algorithm>
using namespace std; 
char c[52][52];
int n, m;

int ch(){
	int i, j, t=1;
	for(i=0; i<n; i++){
		int cnt=1;
		for(j=1; j<n; j++){
			if(c[i][j]==c[i][j-1]) cnt++;
			else cnt=1;
			t=max(t, cnt);
		}
	}
	for(i=0; i<n; i++){
		int cnt=1;
		for(j=1; j<n; j++){
			if(c[j-1][i]==c[j][i]) cnt++;
			else cnt=1;
			t=max(t, cnt);
		}
	}
	return t;
} 

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	char t;
	int i, j;
	cin>>n;
	for(i=0; i<n; i++) cin>>c[i]; 
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(j<n-1){
				t=c[i][j]; c[i][j]=c[i][j+1]; c[i][j+1]=t;
				m=max(m, ch());
				t=c[i][j]; c[i][j]=c[i][j+1]; c[i][j+1]=t;
			}
			if(i<n-1){
				t=c[i][j]; c[i][j]=c[i+1][j]; c[i+1][j]=t;
				m=max(m, ch());
				t=c[i][j]; c[i][j]=c[i+1][j]; c[i+1][j]=t;
			}
		}
	}
	cout<<m;
}
