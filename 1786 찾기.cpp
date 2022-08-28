#include<iostream>
#include<vector>
using namespace std;
char a[1000100], b[1000100];
int n, m, i, j, p[1000100];
vector<int> ans;

int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin.getline(a, 1000100);
    cin.getline(b, 1000100);
    while(a[n]!='\0'){ if(a[n]==' ') a[n]='.'; n++; }
    while(b[m]!='\0'){ if(b[m]==' ') b[m]='.'; m++; }
    for(i=1; i<n; i++){
        while(j>0&&b[i]!=b[j]) j=p[j-1];
        if(b[i]==b[j]) p[i]=++j;
    }
    for(i=0; i<n; i++){
        while(j>0&&a[i]!=b[j]) j=p[j-1];
        if(a[i]==b[j]){
            if(j==m-1){ ans.push_back(i-m+2); j=p[j]; }
            else j++; 
        }
    }
    printf("%d\n", ans.size());
    for(auto i:ans) printf("%d ", i);
}