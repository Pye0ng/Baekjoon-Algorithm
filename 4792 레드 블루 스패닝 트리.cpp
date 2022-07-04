#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct tup{ int s, e, c; };
int pn[1010], px[1010];
vector<tup> mn, mx;

bool cmp(tup a, tup b){ return a.c<b.c; }

int findn(int t){ return pn[t]<0?t:pn[t]=findn(pn[t]); }

void uniten(int x, int y){
	x=findn(x); y=findn(y);
	if(x!=y){
		if(pn[x]>pn[y]) swap(x, y);
		pn[x]+=pn[y]; pn[y]=x;
	}
}

int findx(int t){ return px[t]<0?t:px[t]=findx(px[t]); }

void unitex(int x, int y){
	x=findx(x); y=findx(y);
	if(x!=y){
		if(px[x]>px[y]) swap(x, y);
		px[x]+=px[y]; px[y]=x;
	}
}

int main(){
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, k, a, b, mnblue, mxblue, i;
	char rb;
	cin>>n>>m>>k;
	while(n){
		mnblue=mxblue=0;
		for(i=1; i<=n; i++){ pn[i]=-1; px[i]=-1; }
		for(i=0; i<m; i++){
			cin>>rb>>a>>b;
			tup mnt, mxt;
			mnt.s=mxt.s=a; 
			mnt.e=mxt.e=b;
			mnt.c=rb=='B';
			mxt.c=rb=='R';
			mn.push_back(mnt);
			mx.push_back(mxt);
		}
		sort(mn.begin(), mn.end(), cmp);
		sort(mx.begin(), mx.end(), cmp);
		for(i=0; i<m; i++){
			a=mn[i].s; b=mn[i].e;
			if(findn(a)!=findn(b)){
				uniten(a, b);
				mnblue+=mn[i].c;
			}
			a=mx[i].s; b=mx[i].e;
			if(findx(a)!=findx(b)){
				unitex(a, b);
				mxblue+=mx[i].c;
			}
		}
		cout<<((k<=n-1-mxblue)&&(k>=mnblue))<<"\n";
		mn.clear();
		mx.clear();
		cin>>n>>m>>k;
	}
}
