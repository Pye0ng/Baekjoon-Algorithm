#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct info{
	int ag;
	int jo;
	string nm;
};

bool check(info a, info b){
	if(a.ag<b.ag) return 1;
	else if(a.ag==b.ag) return a.jo<b.jo;
	else return 0;
}

int main(){
	cin.sync_with_stdio(false);
	int n, i;
	cin>>n;
	vector<info> v;
	v.resize(n);
	for(i=0; i<n; i++){
		cin>>v[i].ag>>v[i].nm;
		v[i].jo=i;
	}
	sort(v.begin(), v.end(), check);
	for(i=0; i<n; i++) cout<<v[i].ag<<" "<<v[i].nm<<"\n";
}
