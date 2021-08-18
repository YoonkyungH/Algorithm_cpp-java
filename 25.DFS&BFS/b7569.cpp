#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;

int d[100][100][100];
bool chk[100][100][100];

int main()
{
    int m, n, h;
    scanf("%d %d %d", &m, &n, &h);
    int dx[] = {1, -1, 0, 0, 0, 0};
    int dy[] = {0, 0, 1, -1, 0, 0};
    int dz[] = {0, 0, 0, 0, 1, -1};
    queue<tuple<int, int, int>> q;
    bool is_right;
    for (int z = 0; z < h; z++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &d[i][j][z]);
                // 0이 입력됐는지 확인
                if (d[i][j][z] == 0)
                    is_right = true;
                if (d[i][j][z] == 1)
                {
                    q.push(make_tuple(i, j, z));
                    chk[i][j][z] = true;
                }
            }
        }
    }
    // 0의 입력이 없으면
    if (!is_right)
    {
        printf("0");
        return 0;
    }
    while (!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();
        for (int k = 0; k < 6; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nz = z + dz[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && nz >= 0 && nz < h)
            {
                if (d[nx][ny][nz] == 0 && !chk[nx][ny][nz])
                {
                    q.push(make_tuple(nx, ny, nz));
                    chk[nx][ny][nz] = true;
                    d[nx][ny][nz] = d[x][y][z] + 1;
                }
            }
        }
    }
    int ans = 0;
    for (int z = 0; z < h; z++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (d[i][j][z] == 0)
                { // 익지 않은 토마토가 있을 경우
                    printf("-1");
                    return 0;
                }
                if (ans < d[i][j][z])
                    ans = d[i][j][z];
            }
        }
    }
    printf("%d", ans - 1);
    return 0;
}

