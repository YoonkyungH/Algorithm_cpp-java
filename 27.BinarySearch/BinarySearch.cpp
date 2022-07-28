// 이분탐색 뼈대코드
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tmp 10000

vector<int> v;
int N;  // 총 원소 수
int target;

/**
 * 반복문 활용
 */
bool binary_search1(int target) {
    int left = 0, right = N - 1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(target == v[mid]) return true;

        if(target < v[mid]) right = mid - 1;
        else if(target > v[mid]) left = mid + 1;
    }

    return false;   // 끝까지 못 찾았음 = 없음
}

/**
 * 재귀 활용
 */
bool binary_search2(int left, int right, int target) {
    if(left > right) return false;

    int mid = (left + right) / 2;

    if(v[mid] == target) return true;

    if(v[mid] > target) return binary_search2(left, mid-1, target);
    else return binary_search2(mid+1, right, target);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    v.resize(N);

    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    cin >> target;

    cout << binary_search1(target) << '\n';
    cout << binary_search2(0, N-1, target) << '\n';

    /**
     * C++ STL binary_search() 함수 활용
     */
    bool binary_search3 = binary_search(v.begin(), v.end(), target);
    cout << binary_search3 << '\n';

    return 0;
}