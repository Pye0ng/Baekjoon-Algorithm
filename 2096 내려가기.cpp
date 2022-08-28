#include<stdio.h>
#include<algorithm>
using namespace std;
int d[100100][4], p1[4], p2[4], q1[4], q2[4];

int main(){
    int n, i, j;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
        for(j=0; j<3; j++){
            scanf("%d", &d[i][j]);
            if(i==1) p1[j]=q1[j]=d[1][j];
        }
    for(i=2; i<=n; i++){
        p2[0]=min(p1[0], p1[1])+d[i][0];
        p2[1]=min({p1[0], p1[1], p1[2]})+d[i][1];
        p2[2]=min(p1[1], p1[2])+d[i][2];
        q2[0]=max(q1[0], q1[1])+d[i][0];
        q2[1]=max({q1[0], q1[1], q1[2]})+d[i][1];
        q2[2]=max(q1[1], q1[2])+d[i][2];
        for(j=0; j<3; j++){
            p1[j]=p2[j];
            q1[j]=q2[j];
        }
    }
    printf("%d %d", max({q1[0], q1[1], q1[2]}), min({p1[0], p1[1], p1[2]}));
}