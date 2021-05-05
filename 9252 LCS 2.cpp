#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a, b, ans;
int d[1010][1010], track[1010][1010];

int main(){
	cin.tie(NULL); cout.tie(NULL);
	int i, j;
	cin>>a>>b;
	for(i=1; i<=a.length(); i++)
		for(j=1; j<=b.length(); j++){
			if(a[i-1]==b[j-1]){
				d[i][j]=d[i-1][j-1]+1;
				track[i][j]=1;
			}
			else{
				d[i][j]=max(d[i][j-1], d[i-1][j]);
				if(d[i][j]==d[i-1][j]) track[i][j]=2;
				else track[i][j]=3;
			}
		}
	cout<<d[a.length()][b.length()]<<'\n';
	int x=a.length(), y=b.length();
	while(track[x][y]!=0){
		if(track[x][y]==1){ ans+=a[x-1]; x--; y--; }
		else if(track[x][y]==2) x--;
		else if(track[x][y]==3) y--;
	}
	reverse(ans.begin(), ans.end());
	cout<<ans;
}
