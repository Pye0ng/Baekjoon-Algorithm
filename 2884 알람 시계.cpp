#include<stdio.h>

int main(){
	int i, h, m;
	scanf("%d %d", &h, &m);
	for(i=45; i>=1; i--){
		m--; 
		if(m==-1){
			m=59;
			h--;
			if(h==-1) h=23;
		}
	}
	printf("%d %d", h, m);
}
