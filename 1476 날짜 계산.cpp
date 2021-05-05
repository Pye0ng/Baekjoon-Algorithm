#include<stdio.h>
int e, s, m, ans;

int main(){
	scanf("%d %d %d", &e, &s, &m);
	if(e==15) e=0;
	if(s==28) s=0;
	if(m==19) m=0;
	ans=e+15;
	while(1){
		if(ans%15==e&&ans%28==s&&ans%19==m){
			if(ans==7980) printf("7980");
			else printf("%d", ans%7980);
			break;
		}
		ans+=15;
	}
}
