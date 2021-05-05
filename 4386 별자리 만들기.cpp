#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int parent[110];
float ans, p[110], q[110];
bool ch;

typedef struct kruskal{ int a, b; double val; }ks;
vector<ks> v;

bool cmp(ks x, ks y){ return x.val<y.val; }

int find(int t){
	if(t==parent[t]) return t;
	else return parent[t]=find(parent[t]);
}

void unity(int x, int y){
	ch=false;
	x=find(x); y=find(y);
	if(x==y) return; //cycle
	parent[x]=y;
	ch=true;
}

int main(){
	int n, i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%f %f", &p[i], &q[i]);
		parent[i]=i;
	}
	for(i=1; i<n; i++)
		for(j=i+1; j<=n; j++){
			ks t; t.a=i; t.b=j;
			t.val=sqrt((p[i]-p[j])*(p[i]-p[j])+(q[i]-q[j])*(q[i]-q[j]));
			v.push_back(t);
		}
	sort(v.begin(), v.end(), cmp);
	for(i=0; i<v.size(); i++){
		unity(v[i].a, v[i].b);
		if(ch) ans+=v[i].val;
	}
	printf("%.2f", ans);
}
