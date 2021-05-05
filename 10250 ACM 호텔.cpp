#include<stdio.h>
void p(int n){ printf("%d\n", n);}

int main(){
	int t, h, w, n, i;
	scanf("%d", &t);
	for(i=0; i<t; i++){
		scanf("%d %d %d", &h, &w, &n);
		if(n%h==0){
			p(h*100+n/h);	
		}
		else{
			if(h==1) p((n%h)*100+n/h);
			else p((n%h)*100+n/h+1);	
		}
	}
} 
