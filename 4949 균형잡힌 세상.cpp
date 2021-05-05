#include<iostream>
#include<stack>
#include<cstring> 
using namespace std;

int main(){
	char c[101];
	while(true){
		int ch=0;
		stack<char> s;
		cin.getline(c, 101);
		if(!strcmp(c, ".")) break;
		
		for(int i=0; i<strlen(c); i++){
			if(c[i]=='('||c[i]=='[') s.push(c[i]);
			else if(c[i]==')'){
				if(!s.empty()&&s.top()=='(') s.pop();
				else{
					ch=1;
					break;	
				}
			}
			else if(c[i]==']'){
				if(!s.empty()&&s.top()=='[') s.pop();
				else{
					ch=1;
					break;
				}
			}
			
		}
		
		if(ch!=0||!s.empty()) cout<<"no\n";
		else cout<<"yes\n";
	}
	return 0;
}
