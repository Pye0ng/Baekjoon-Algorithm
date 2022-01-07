#include<stdio.h>
#include<queue>
using namespace std;
queue<int> q;
int dp[110], s[110], c[110];

int main(){
	int a, b, t, p, i, k;
	scanf("%d %d", &a, &b);
	for(i=0; i<a; i++){ scanf("%d %d", &p, &t); s[p]=t; }
	for(i=0; i<b; i++){ scanf("%d %d", &p, &t); c[p]=t; }
	q.push(1);
	while(!q.empty()){
		t=q.size();
		for(k=0; k<t; k++){
			p=q.front(); q.pop();
			for(i=p+1; i<=p+6&&i<=100; i++){
				if(dp[i]>0) continue;
				if(s[i]>0&&dp[s[i]]==0){ dp[s[i]]=dp[p]+1; q.push(s[i]); }
				else if(c[i]>0&&dp[c[i]]==0){ dp[c[i]]=dp[p]+1; q.push(c[i]); }
				else if(c[i]==0&&s[i]==0){ 
					if(i==100){
						printf("%d", dp[p]+1);
						return 0;
					}
					dp[i]=dp[p]+1;
					q.push(i); 
				}
			}
		}
	}
}	
