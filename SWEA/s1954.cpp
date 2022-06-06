// 달팽이 숫자
#include <iostream>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t; 
    for(int i=1; i<=t; i++) {
        int arr[10][10] = {0, };
        int n;
        cin >> n;

        arr[0][0] = 1;
        int number = 2;
        int k=0, j=0, dir=0;

        while(n*n >= number) {
            int y = j + dy[dir];
            int x = k + dx[dir];

            if(x<0 || y<0 || y>=n || x>=n || arr[y][x]>0) { // 영역을 벗어날 때
                dir += 1;
                if(dir == 4) {
                    dir = 0;
                }
                continue;
            }
            arr[y][x] = number++;
            j = y; k = x;
        }

        cout << "#" << i << "\n";
        for(int q=0; q<n; q++) {
            for(int z=0; z<n; z++) {
                cout << arr[q][z] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}