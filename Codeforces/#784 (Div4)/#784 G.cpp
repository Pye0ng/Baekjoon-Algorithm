#include<stdio.h>
#include<vector>
#define x first
#define y second
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int main(){
	int n, m, t, a, i, j;
	int d[52][52], r[52][52];
	char c[52][52];
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(i=0; i<n; i++) scanf("%s", c[i]);
		for(i=0; i<n; i++)
			for(j=0; j<m; j++){ d[i][j]=(i==0?c[i][j]=='*':0); r[i][j]=0; }
		for(j=0; j<m; j++)
			for(i=1; i<n; i++){
				if(c[i][j]=='.') d[i][j]=d[i-1][j];
				if(c[i][j]=='*') d[i][j]=d[i-1][j]+1;
				if(c[i][j]=='o'){
					r[i][j]=d[i-1][j];
					d[i][j]=0;
				}
			}
		for(j=0; j<m; j++){
			a=d[n-1][j];
			for(i=n-1; i>=0; i--){
				if(a>0){ a--; c[i][j]='*'; }
				else if(r[i][j]>0||c[i][j]=='o'){ a=r[i][j]; c[i][j]='o'; }
				else c[i][j]='.';
			}
		}
		for(i=0; i<n; i++){
			for(j=0; j<m; j++) printf("%c", c[i][j]);
			printf("\n");
		}
	}
}
