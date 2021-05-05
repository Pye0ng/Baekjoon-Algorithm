#include<stdio.h> 
int n, m, w, b;
char a[101][101];
bool visit[100][100];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int dfs(int x, int y, char c) {
    int an=1;
    visit[x][y] = true;
    for (int i=0; i<4; i++) {
        int ax=x+dx[i];
		int ay=y+dy[i];
        if (ax<0||ax>=n||ay<0||ay>=m) continue;
        if (!visit[ax][ay]&&a[ax][ay]==c) an+=dfs(ax, ay, c);
    }
    return an;
}

int main() {
    scanf("%d %d", &m, &n);
    for (int i=0; i<n; i++) scanf("%s", a[i]);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!visit[i][j]) {
                int k=dfs(i, j, a[i][j]);
                if (a[i][j]=='W') w+=k*k;
                else b+=k*k;
            }
        }
    }
    printf("%d %d\n", w, b);
    return 0;
}

