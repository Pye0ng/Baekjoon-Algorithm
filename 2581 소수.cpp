#include<stdio.h>
#include<math.h>
int sum, min; 

int main(){
    int m, n, r, i, j;
    scanf("%d %d", &m, &n);
    for(i=n;i>=m;i--){
		r=1;
		if(i==1) break;
		for(j=2;j<=sqrt(i);j++) if(i%j==0){ r=0; break; }
    	if(r){ sum+=i; min=i; }
    }
    if(min!=0) printf("%d\n%d",sum,min);
    else printf("-1");
}
