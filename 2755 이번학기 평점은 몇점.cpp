#include<stdio.h>
#include<string.h>
char im[101];
char sc[3];
int cl[101];

float re(char c[3]){
	if(!strcmp(c, "A+")) return 4.3; else if(!strcmp(c, "A0")) return 4.0; else if(!strcmp(c, "A-")) return 3.7;
	else if(!strcmp(c, "B+")) return 3.3; else if(!strcmp(c, "B0")) return 3.0; else if(!strcmp(c, "B-")) return 2.7;
	else if(!strcmp(c, "C+")) return 2.3; else if(!strcmp(c, "C0")) return 2.0;else if(!strcmp(c, "C-")) return 1.7;
	else if(!strcmp(c, "D+")) return 1.3; else if(!strcmp(c, "D0")) return 1.0; else if(!strcmp(c, "D-")) return 0.7;
	else if(!strcmp(c, "F")) return 0.0;
}

int main(){
	int n, cls=0;
	float score=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%s %d %s", im, &cl[i], sc);
		cls+=cl[i];
		score+=re(sc)*cl[i];
	}
	printf("%.02f", score/cls);
}
