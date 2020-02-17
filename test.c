//test
#include <stdio.h>
 
int n, min; // 맵의 크기와 최소값을 나타내는 변수
int map[10][10]; // 맵을 나타내는 2차원 배열
 
void DFS(int x, int y, int l)
{
    // 도착 지점에 도착했을 경우
    if (x == n - 1 && y == n - 1)
    {
        // 현재 최소값이 l보다 크면, l이 작은 것이므로 l를 최소값으로 지정
        if (min > l) min = l;
        return;
    }
    map[x][y] = 0; // 방문했음을 표시하기 위해 0을 대입
 
    // 왼쪽 이동할 수 있다면 이동!
    if (x > 0 && map[x - 1][y] != 0) DFS(x - 1, y, l + 1);
    // 오른쪽 이동할 수 있다면 이동!
    if (x < n - 1 && map[x + 1][y] != 0) DFS(x + 1, y, l + 1);
    // 아래로 이동할 수 있다면 이동!
    if (y > 0 && map[x][y - 1] != 0) DFS(x, y - 1, l + 1);
    // 위로 이동할 수 있다면 이동!
    if (y < n - 1 && map[x][y + 1] != 0) DFS(x, y + 1, l + 1);
 
    map[x][y] = 1; // 지나간 자리를 원상태로 되돌리기 위해 1을 대입
}
 
int main()
{
    int i, j;
 
    scanf_s("%d", &n);
    min = n * n; // 모든 경로를 돌아다녀도 n * n이니, 이를 최소값으로 지정해둔다
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf_s("%d", &map[i][j]);
    DFS(0, 0, 1); // DFS 시작!
 
    printf("최단 거리: %d\n", min);
 
    return 0;
}
