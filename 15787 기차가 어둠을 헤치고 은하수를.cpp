#include<iostream>
#include<math.h>
#include<set>
using namespace std;
set<int> s;
int n, m, d[100010][25];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int a, b, c, i;
	cin>>n>>m;
	while(m--){
		cin>>a;
		if(a==1){
			cin>>b>>c;
			if(d[b][c]==0){
				d[b][c]=1;
				d[b][0]+=pow(2.0, c); 
			}
		}
		else if(a==2){
			cin>>b>>c;
			if(d[b][c]){
				d[b][c]=0;
				d[b][0]-=pow(2.0, c);
			}
		}
		else if(a==3){
			cin>>b;
			int p[22]={};
			if(d[b][20]) d[b][0]-=pow(2.0, 20);
			for(i=1; i<=20; i++)
				if(d[b][i]){
					d[b][i]=0;
					p[i+1]=1;
				}
			for(i=1; i<=20; i++) d[b][i]=p[i];
			d[b][0]*=2;
		}
		else{
			cin>>b;
			int p[22]={};
			if(d[b][1]) d[b][0]-=2;
			for(i=1; i<=20; i++)
				if(d[b][i]){
					d[b][i]=0;
					p[i-1]=1;
				}
			for(i=1; i<=20; i++) d[b][i]=p[i];
			d[b][0]/=2;
		}
	}
	for(i=1; i<=n; i++) s.insert(d[i][0]);
	cout<<s.size();
}
