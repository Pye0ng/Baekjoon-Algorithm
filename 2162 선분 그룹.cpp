#include<stdio.h>
#include<utility>
#include<algorithm>
using namespace std;
int n, cnt, mx, parent[3010];
pair<int, int> p[3010];
pair<int, int> q[3010];

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c){
    int t=(b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first);
    if(t>0) return 1;
    else if(t<0) return -1;
    else return 0;
}

bool cross(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d){
	int ab=ccw(a, b, c)*ccw(a, b, d);
    int cd=ccw(c, d, a)*ccw(c, d, b);
    if(ab==0&&cd==0){
    	if(a>b) swap(a, b);
    	if(c>d) swap(c, d);
    	return c<=b&&a<=d;
	}
	return ab<=0&&cd<=0;
}

int find(int t){
    if(parent[t]<0) return t;
    else{
        parent[t]=find(parent[t]);
        return parent[t];
    }
}

void unity(int x, int y){
    x=find(x); y=find(y);
    if(x==y) return;
    if(parent[x]<parent[y]){
        parent[x]+=parent[y];
        parent[y]=x;
    }
    else{
        parent[y]+=parent[x];
        parent[x]=y;
    }
}

int main(){
    int i, j;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        parent[i]=-1;
        scanf("%d %d %d %d", &p[i].first, &p[i].second, &q[i].first, &q[i].second);
    }
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            if(cross(p[i], q[i], p[j], q[j])) unity(i, j);			
    for(i=0; i<n; i++)
    	if(parent[i]<0){
    		cnt++;
    		if(parent[i]<mx) mx=parent[i];
		} 
	printf("%d\n%d", cnt, -mx);
}
