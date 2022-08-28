#include<iostream>
#include<string>
using namespace std;
string s;
int a, b;

int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>s>>a>>b;
    while(a){
        cout<<s<<" "<<(a>17||b>79?"Senior":"Junior")<<"\n";
        cin>>s>>a>>b;
    }
}