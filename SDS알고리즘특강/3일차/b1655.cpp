// 가운데를 말해요

// priority_queue
// priority_queue라는 것을 떠올리기가 힘든 문제

#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> minPq;
priority_queue<int> maxPq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0; i<N; i++) {
        int n;
        cin >> n;

        if(minPq.size() < maxPq.size()) { minPq.push(-n); }
        else { maxPq.push(n); }

        if(!maxPq.empty() && !minPq.empty()) {
            // maxPq중 가장 큰 값이 minPq중 가장 작은 값보다 크면 안되니까
            if(maxPq.top() > -minPq.top()) {    // minPq와 교환
                int maxTmp = maxPq.top();
                int minTmp = -minPq.top();

                minPq.pop();
                maxPq.pop();
                minPq.push(-maxTmp);
                maxPq.push(minTmp);
            }
        }

        cout << maxPq.top() << '\n';
        
    }


    return 0;
}