#include<iostream>
using namespace std;
float d[5][5];
float ans[5][12];

int main(){
	int t, m, i, j, k;
	cin>>t>>m;
	while(m--){
		char a, b; float c;
		cin>>a>>b>>c;
		d[a-'A'][b-'A']=c;
	}
	ans[0][0]=ans[1][0]=ans[2][0]=ans[3][0]=0.25;
	for(i=1; i<=t; i++)
		for(j=0; j<4; j++)
			for(k=0; k<4; k++)
				ans[k][i]+=ans[j][i-1]*d[j][k];
	cout<<fixed;
	cout.precision(2);
	for(i=0; i<4; i++) cout<<100*ans[i][t]<<"\n";
}
