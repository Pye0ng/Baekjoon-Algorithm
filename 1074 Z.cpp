#include<stdio.h>
#include<math.h>
int n, r, c, x, y, t, s, ans;

int main(){
	scanf("%d %d %d", &n, &r, &c);
	x=y=1<<(n-1);
	while(n--){
		t=(int)pow(2.0, n)/2; s=(int)pow(4.0, n);
		if(r<x&&c<y){ x-=t; y-=t; }
		else if(r<x&&c>=y){ x-=t; y+=t; ans+=s; }
		else if(r>=x&&c<y){ x+=t; y-=t; ans+=2*s; }
		else{ x+=t; y+=t; ans+=3*s; }
	}
	printf("%d", ans);
}
