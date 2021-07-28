#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    deque<int> dq;
    for(int i=N; i>0; i--) {
        dq.push_front(i);
    }

    int j=1;
    while(1) {
        if(dq.size()==1) { break; }
        if(j % 2 == 1) {
            dq.pop_front();
            j++;
        } else if(j % 2 != 1) {
            int tmp = dq.front();
            dq.pop_front();
            dq.push_back(tmp);
            j++;
        }
    }

    cout << dq.front() << '\n';

    return 0;
}