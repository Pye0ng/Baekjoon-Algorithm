#include<stdio.h>
#include<math.h>

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		long long int d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2), r=(r1+r2)*(r1+r2);
		if(d==0){
			if(r1==r2) printf("-1\n");
			else printf("0\n");
		}
		else{
			if(d>r) printf("0\n");
			else if(d==r) printf("1\n");
			else{
				if(d<(r1-r2)*(r1-r2)) printf("0\n");
				else if(d==(r1-r2)*(r1-r2)) printf("1\n");
				else printf("2\n");
			}
		}
	}
}
