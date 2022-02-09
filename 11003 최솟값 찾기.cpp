#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p> > s;
int d[5000100];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, l, i;
	cin>>n>>l;
	for(i=1; i<=n; i++) cin>>d[i];
	for(i=1; i<=n; i++){
		s.push({d[i], i});
		while(s.top().second<=i-l) s.pop();
		cout<<s.top().first<<" ";
	}
}
