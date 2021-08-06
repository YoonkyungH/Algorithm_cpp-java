#include <iostream>
#include <algorithm>
using namespace std;

// 주유소

int N;

int price[100000] = {0, };
int d[99999] = {0, };
int total_d = 0;
int min_price = 1000000001; // 최소 기름 값
int min_p_idx = 0;          // 최소 기름 값의 인덱스

int ans = 0;

void TotalOil(int start, int end, int min_price) {
    // start부터 end까지 거리를 다 더한다음 min_price(시작지점 price)로 기름값을 계산(ans에 저장)
    total_d = 0;
    for(int i=start; i<=end; i++) {
        total_d += d[i];
    }
    ans += total_d * min_price;
}

int tmp;
void Oil(int start, int n) {
    min_price = 1000000001;

    // 더 구할 수 없는 상황일 때 마지막으로 TotalOil 함수를 호출하고 함수 탈출
    if(n <= 0) { TotalOil(0, tmp-1, price[0]); return; }

    // start 지점에서부터 n까지 돌면서 최소값을 찾음
    // 최솟값과 최솟값의 인덱스를 저장시켜둠
    for(int i=start; i<=n; i++) {
        if (min_price > price[i]) {
            min_p_idx = i;
            min_price = price[i];
        }
    }

    tmp = min_p_idx;
    // 방금 구한 최소값의 인덱스부터 for문을 돌았던 끝까지 그 최솟값으로 기름값을 계산하기 위해 TotalOil 함수 호출
    TotalOil(min_p_idx, n, min_price);
    // 최솟값 인덱스 전 도시들의 기름값을 또 구해야하므로 0부터 다시 구한 도시 전까지 돌기 위해 Oil 함수 호출
    Oil(0, min_p_idx-1);
}



int main() {
    ios::sync_with_stdio(0);

    cin >> N;

    // 도시 사이 거리
    for(int i=0; i<N-1; i++) {
        cin >> d[i];
    }

    // 기름값
    for(int i=0; i<N-1; i++) {
        cin >> price[i];
        
    }

    // 어차피 마지막 도시의 기름값은 의미가 없으므로 처음부터 (맨 마지막-1)번째 도시를 인자로 넣어 호출
    Oil(0, N-2);

    cout << ans << '\n';

    return 0;
}