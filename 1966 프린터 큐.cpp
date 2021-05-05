#include<iostream>
#include<queue>
using namespace std;
queue<pair<int, int> > q;
priority_queue<int> p;

int main(){
	int a, n, m, k, i, j;
	cin>>a;
	for(j=1; j<=a; j++){
		int cnt=0;
		cin>>n>>m;
		for(i=0; i<n; i++){
			cin>>k;
			q.push(make_pair(i, k));
			p.push(k);
		}
		while(!p.empty()||!q.empty()){
			int x=q.front().first; int y=q.front().second;	
			q.pop(); 
			if(y==p.top()){
				p.pop();
				cnt++;
				if(x==m){
					cout<<cnt<<"\n";
					break;
				}
			}
			else q.push(make_pair(x, y));
		}
		while(!p.empty()||!q.empty()){
			p.pop();
			q.pop();
		}
	}
}
