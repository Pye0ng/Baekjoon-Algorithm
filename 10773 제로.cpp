#include<stdio.h>
int st[100001];

int main(){
	int k, p, c=0, i;
	scanf("%d", &k);
	for(i=0; i<k; i++){
		scanf("%d", &p);
		if(p==0){
			c--;
			st[c]=0;
		}
		else{
			st[c]=p;
			c++;
		}
	}
	p=0;
	for(i=0; st[i]!='\0'; i++) p+=st[i];
	printf("%d", p);
}
