#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
vector<pair<int, int> > in;
pair<int, int> track[100010]; 
vector<int> v;
int n, k, d[100010], ans[100010];

int lowerbound(int t){
	int s=0, e=k;
	while(e>s){
		int m=(s+e)/2;
		if(d[m]<t) s=m+1;
		else e=m;
	}
	return e;
}

int find(int t){
	int s=0, e=n-1;
	while(e>s){
		int m=(s+e)/2;
		if(v[m]==t) return m;
		else if(v[m]>t) e=m-1;
		else s=m+1;
	}
}

int main(){
	int t, i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		in.push_back({b, a});
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	sort(in.begin(), in.end());
	d[0]=in[0].second; track[0]={0, in[0].second};
	for(i=1; i<n; i++){
		t=in[i].second;
		if(t>d[k]){
			d[++k]=t;
			track[i]={k, t};
		}
		else{
			d[lowerbound(t)]=t;
			track[i]={lowerbound(t), t};
		}
	}
	printf("%d\n", n-k-1);
	for(i=n-1; i>=0; i--)
		if(track[i].first==k){
			ans[find(track[i].second)]=1;
			k--;
		}
	for(i=0; i<n; i++)
		if(!ans[i]) printf("%d ", v[i]);
}

