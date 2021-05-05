#include<stdio.h>
int mu[9];

int main(){
	int to=0, bo=0, i;
	for(i=0; i<8; i++) scanf("%d", &mu[i]);
	for(i=0; i<7; i++){
		if(mu[i]>mu[i+1]) to++;
		else if(mu[i]<mu[i+1]) bo++;
	}
	if(to==7) printf("descending");
	else if(bo==7) printf("ascending");
	else printf("mixed");
} 
