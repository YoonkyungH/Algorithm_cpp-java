// 숫자 카드
// algorithm의 find 함수는 시간복잡도가 O(N)으로 시간초과
// 이분탐색 사용
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> card(N);
    for(int i=0; i<N; i++) {
        cin >> card[i];
    }

    sort(card.begin(), card.end());

    cin >> M;
    for(int i=0; i<M; i++) {
        int num;
        cin >> num;

        if(binary_search(card.begin(), card.end(), num)) {
            cout << "1 ";
        } else {
            cout << "0 ";
        }

    }
    cout << '\n';

    return 0;
}