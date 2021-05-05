#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;
stack<int> s;
vector<char> pr;

int main(){
	int n, i, j=1;
	scanf("%d", &n);
	int ar[n+1]; 
	for(i=1; i<=n; i++) scanf("%d", &ar[i]); 
	for(i=1; i<=n; i++){
		s.push(i);
		pr.push_back('+');
		while(!s.empty()&&s.top()==ar[j]){
			s.pop();
			pr.push_back('-');
			j++;
		}	
	}
	if(!s.empty()) printf("NO\n");
	else for(i=0; i<pr.size(); i++)	printf("%c\n", pr[i]); 
} 
