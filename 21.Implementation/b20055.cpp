#include <iostream>
#include <deque>
using namespace std;

// 컨베이어 벨트 위의 로봇

int N, K;
deque<bool> dq; // 로봇
deque<int> dq2; // 내구도
int cnt=0, ans=1;

void Rotation() {
    dq.push_front(dq.back());
    dq.pop_back();
    dq[N-1] = false;    // 비우는 자리

    dq2.push_front(dq2.back());
    dq2.pop_back();

    
}

void Move() {
    for(int i=N-1; i>=0; i--) {
        // 해당 자리에 로봇이 있고 다음 자리에 로봇이 없고 내구도가 1 이상일 때
        if (dq[i] == true && dq[i + 1] == false && dq2[i + 1] > 0)
        {
            dq[i+1] = true;
            dq[i] = false;
            dq2[i+1]--;
        }
        // N-1 자리에 오면 무조건 내려야 함
        dq[N-1] = false;
    }
}

void Put() {
    // 내구도가 1 이상이며 해당 자리가 비었을 때
    if(dq2[0]>0 && dq[0]==false) {
        dq[0] = true;
        dq2[0]--;
    }
}

int main() {
    ios::sync_with_stdio(0);

    cin >> N >> K;

    int n;
    for(int i=0; i<2*N; i++) {
        cin >> n;
        dq2.push_back(n);
    }
    dq.assign(N, false);

    while(1) {
        Rotation();
        Move();
        Put();

        cnt=0;
        for(int i=0; i<2*N; i++) {
            if(dq2[i] == 0) { cnt++; }
        }
        if(cnt >= K) { 
            cout << ans << '\n';
            return 0;
        }
        ans++;
    }


    return 0;
}