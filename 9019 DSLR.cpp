#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
vector<string> ans;
int v[10100];

int D(int n){ return (n*2)%10000; }
int S(int n){ return (n+9999)%10000; }
int L(int n){ return (n%1000)*10+n/1000; }
int R(int n){ return (n%10)*1000+n/10; }

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string o="";
	int a, b, t, i; 
	cin>>t;
	while(t--){
		cin>>a>>b;
		queue<pair<int, string> > q;
		q.push({a, o}); 
		while(!q.empty()){
			pair<int, string> p=q.front(); q.pop();
			if(p.first==b){ ans.push_back(p.second); break; }
			if(v[D(p.first)]==0){ v[D(p.first)]=1; q.push({D(p.first), p.second+"D"}); }
			if(v[S(p.first)]==0){ v[S(p.first)]=1; q.push({S(p.first), p.second+"S"}); }
			if(v[L(p.first)]==0){ v[L(p.first)]=1; q.push({L(p.first), p.second+"L"}); }
			if(v[R(p.first)]==0){ v[R(p.first)]=1; q.push({R(p.first), p.second+"R"}); }
		}
		for(i=0; i<10000; i++) v[i]=0;
	}
	for(i=0; i<ans.size(); i++) cout<<ans[i]<<"\n";
}
