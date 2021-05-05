#include<stdio.h>
#include<iostream>
using namespace std;

string Wh[8]={
    { "WBWBWBWB" },
    { "BWBWBWBW" },
    { "WBWBWBWB" },
    { "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" }
};

string Bl[8]={
	{ "BWBWBWBW" },
    { "WBWBWBWB" },
    { "BWBWBWBW" },
    { "WBWBWBWB" },
    { "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" }
};

int minF(int a, int b){ return a<b? a:b;}

int BlCom(string a[], int x, int y){
	int sum=0;
	for(int i=x; i<=x+7; i++)
		for(int j=y; j<=y+7; j++)
			if(a[i][j]!=Bl[i-x][j-y]) sum++;
	return sum;
}

int WhCom(string a[], int x, int y){
	int sum=0;
	for(int i=x; i<=x+7; i++)
		for(int j=y; j<=y+7; j++)
			if(a[i][j]!=Wh[i-x][j-y]) sum++;
	return sum;
}

int main(){
	int n, m, i, j, min=64;
	cin>>n>>m;
	string a[n];
	for(i=0; i<n; i++) cin>>a[i];
	for(i=0; i<n-7; i++)
		for(j=0; j<m-7; j++)
			min=minF(BlCom(a, i, j), minF(min, WhCom(a, i, j)));
	cout<<min<<"\n";
}
