// 인덱스 트리
// 동빈나님의 블로그 참고 (https://blog.naver.com/PostView.naver?blogId=ndb796&logNo=221312822103&redirect=Dlog&widgetTypeCall=true&directAccess=false)

#include <iostream>

using namespace std;

int tree[6];    // 

int sum(int i) {
    int result = 0;

    while(i > 0) {
        result += tree[i];
        i -= (i & -i);
    }

    return result;
}

void update(int i, int dif) {
    while(i <= 6) { // 6이라고 가정
        tree[i] += dif;
        i += (i & -i);
    }
}

int getSection(int start, int end) {
    return sum(end) - sum(start - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);



    return 0;
}