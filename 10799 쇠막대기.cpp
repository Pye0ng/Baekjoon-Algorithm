#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
stack<char> s;
int sum, pi;
char a[100001];

int main(){
	scanf("%s", a);
	for(int i=0; a[i]; i++){
		if(a[i]==')'){
			if(a[i-1]=='('){
				s.pop();
				sum+=--pi;
			}
			else{
				s.pop();
				sum++;
				pi--;
			}
		}
		else{
			s.push(a[i]);
			pi++;
		}
	}
	printf("%d", sum); 
}
