// 킹

#include <iostream>
#include <string>

using namespace std;

// int map[8][8];
char kX, dX;
int kY, dY;

bool inMap(char X, int Y) {  // 알파벳, 숫자
    if(65 <= X && X <= 72 && 1 <= Y && Y <= 8) {
        return true;
    } else {
        return false;
    }
    // 그 방향으로 움직였을 때 범위에서 벗어나는지 검사
}

bool isDoll(char kX, int kY) {  // 돌과 겹치는지
    if(kX == dX && kY == dY) {
        return true;
    } else {
        return false;
    }
}

void R() {  // 한 칸 오른쪽으로
    if(inMap(kX+1, kY)) {   // 범위에서 벗어나지 않는다면
        if(isDoll(kX+1, kY) && inMap(dX+1, dY)) {   // 돌과 겹쳐 돌을 옮겼을 때 범위에서 벗어나지 않는다면
            dX += 1;
        } else if(isDoll(kX+1, kY) && !inMap(dX+1, dY)) {   // 돌과 겹치는데 범위에서 벗어난다면
            return;
        }
        kX += 1;
    }

    
}

void L() {  // 한 칸 왼쪽으로
    if(inMap(kX-1, kY)) {
        if(isDoll(kX-1, kY) && inMap(dX-1, dY)) {
            dX -= 1;
        }  else if(isDoll(kX-1, kY) && !inMap(dX-1, dY)) {
            return;
        }
        kX -= 1;
    }

    
}

void B() {  // 한 칸 아래로
    if(inMap(kX, kY-1)) {
        if(isDoll(kX, kY-1) && inMap(dX, dY-1)) {
            dY -= 1;
        }  else if(isDoll(kX, kY-1) && !inMap(dX, dY-1)) {
            return;
        }
        kY -= 1;
    }

    
}

void T() {  // 힌 칸 위로
    if(inMap(kX, kY+1)) {
        if(isDoll(kX, kY+1) && inMap(dX, dY+1)) {
            dY += 1;
        }  else if(isDoll(kX, kY+1) && !inMap(dX, dY+1)) {
            return;
        }
        kY += 1;
    }

    
}

void RT() {
    if(inMap(kX+1, kY+1)) {
        if(isDoll(kX+1, kY+1) && inMap(dX+1, dY+1)){
            dX += 1; dY += 1;
        }  else if(isDoll(kX+1, kY+1) && !inMap(dX+1, dY+1)) {
            return;
        }
        kX += 1; kY += 1;
    }
}

void LT() {
    if(inMap(kX-1, kY+1)) {
        if(isDoll(kX-1, kY+1) && inMap(dX-1, dY+1)){
            dX -= 1; dY += 1;
        }  else if(isDoll(kX-1, kY+1) && !inMap(dX-1, dY+1)) {
            return;
        }
        kX -= 1; kY += 1;
    }
}

void RB() {
    if(inMap(kX+1, kY-1)) {
        if(isDoll(kX+1, kY-1) && inMap(dX+1, dY-1)){
            dX += 1; dY -= 1;
        }  else if(isDoll(kX+1, kY-1) && !inMap(dX+1, dY-1)) {
            return;
        }
        kX += 1; kY -= 1;
    }
}

void LB() {
    if(inMap(kX-1, kY-1)) {
        if(isDoll(kX-1, kY-1) && inMap(dX-1, dY-1)){
            dX -= 1; dY -= 1;
        }  else if(isDoll(kX-1, kY-1) && !inMap(dX-1, dY-1)) {
            return;
        }
        kX -= 1; kY -= 1;
    }
}

int main() {
    ios::sync_with_stdio(0);

    string K, D;
    int c;
    cin >> K >> D >> c;

    kX = K[0]; kY = K[1]-48;
    dX = D[0]; dY = D[1]-48;

    // cout << kX << ' ' << kY << ' ' << dX << ' ' << dY << '\n';

    for(int i=0; i<c; i++) {
        string way;
        cin >> way;

        if(way == "B") { B(); }
        else if(way == "T") { T(); }
        else if(way == "L") { L(); }
        else if(way == "R") { R(); }
        else if(way == "RT") { RT(); }
        else if(way == "LT") { LT(); }
        else if(way == "RB") { RB(); }
        else if(way == "LB") { LB(); }
    }

    K = kX; K += to_string(kY);
    D = dX; D += to_string(dY);

    cout << K << '\n' << D << '\n';

    return 0;
}