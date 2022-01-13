// 가장 긴 증가하는 부분 수열 5
// DP + 이분탐색
// pro sw 검정시험에서 DP 문제가 나온다면 이정도에서 조금 더 어렵게 출제될듯

/**
 * 벡터를 갱신해주면서 덮어씌움
 * 예를 들어 10 20 15 ... 가 있다면
 * 먼저 10을 벡터에 넣고 10에 1
 * 그 다음 20을 벡터에 넣고 20에 2
 * 그 다음 15를 넣으려는데 20보다 작으니까 20자리에 15를 넣고 15에 2 저장
 * 
 * 이렇게 모두 실행한 다음 역추적을 시작
 * 거꾸로 봤을 때 10에 1 20에 2 15에 2 이렇게 저장해두었던 것들을 보고
 * 맨 뒤에서부터 원소가 만약 5개면 5부터 뒤에서부터 찾아가면서 4인 원소, 3인 원소.. 
 * 모두 찾으면 답을 찾을 수 있다.
 */

// 강사님 코드 참고

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, num;
int arr[1000001];
int idx[1000001];
vector<int> v;
vector<int> vReverse;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    v.push_back(arr[0]);
    idx[0] = 1;
    for(int i=1; i<N; i++) {
        if(arr[i] > v[v.size()-1]) {
            v.push_back(arr[i]);
            idx[i] = v.size();
        } else {
            int l = 0;
            int r = v.size()-1;

            while(l < r) {  // 이분탐색
                int mid = (l + r) / 2;

                if(v[mid] >= arr[i]) r = mid;
                else l = mid + 1;
            } 

            v[l] = arr[i];
            idx[i] = l + 1;
        }
    }

    cout << v.size() << '\n';

    vReverse.clear();   // 초기화
    int k = v.size();   // 현재 배열의 크기

    for(int i=N-1; i>=0; i--) {  // 역추적
        if(k == 0) break;
        if(k == idx[i]) {
            vReverse.push_back(arr[i]);
            k--;
        }
    }

    while(!vReverse.empty()) {
        cout << vReverse[vReverse.size()-1] << ' ';
        vReverse.pop_back();
    }   cout << '\n';

    return 0;
}