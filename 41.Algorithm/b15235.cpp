// Olympiad Pizza


#include <iostream>
#include <vector>

using namespace std;

int N, sum, c;
vector<int> v;
int arr[1000];
int cnt[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    v.resize(N);

    for(int i=0; i<N; i++) {
        cin >> v[i];
        // cin >> arr[i];
        sum += v[i];
    }

    int i=0;
    c = 0;


    while(sum--) {
        if(i == N) i = 0;
        v[i]--;
        if (v[i] <= -1) {
            i++; sum++;
            continue;
        }

        c++;

        if(v[i] == 0) {
            cnt[i] = c;
        }
        
        i++;

    }

    for(i=0; i<N; i++) {
        cout << cnt[i] << ' ';
    } cout << '\n';

    return 0;
}