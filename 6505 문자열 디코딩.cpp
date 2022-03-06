#include<iostream>
using namespace std;
int d[90], p[90], s[35][90];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, k, i, j;
	cin>>n>>m;
	while(n!=0&&m!=0){
		char c[100];
		for(i=1; i<=n; i++){
			cin>>d[i];
			s[0][i]=d[i];
		}
		cin.ignore();
		cin.getline(c, 90, '\n');
		for(i=1; i<30; i++)
			for(j=1; j<=n; j++)
				s[i][j]=s[i-1][s[i-1][j]];
		for(i=1; i<=n; i++){
			k=i;
			for(j=29; j>=0; j--)
				if(m&(1<<j)) k=s[j][k];
			p[k]=i;
		}
		for(i=1; i<=n; i++)
			cout.put(c[p[i]-1]);
		cout.put('\n');
		cin>>n>>m;
	}
}
