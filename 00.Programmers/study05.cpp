// 자물쇠와 열쇠

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 90도 시계방향 회전 

// 회전한 키를 백터 형태로 반환

vector<vector<int>> rotation (vector<vector<int>> key, int keySize) {
    vector<vector<int>> newKey(keySize, vector<int>(keySize));
    // keySize 개의 원소에 각 원소는 vector<int> keysize만큼 초기화

    for(int i=0; i<keySize; i++) {
        for(int j=0; j<keySize; j++) {
            newKey[i][j] = key[keySize - j - 1][i];
        }
    }

    return newKey; 
}

bool check(int x, int y, int boardSize, int keySize, vector<vector<int>> key, vector<vector<int>> board) {
    for(int i=x; i<x+keySize; i++) {
        for(int j=y; j<y+keySize; j++) {
            
            board[i][j] += key[i-x][j-y];
        }
    }
    
    for(int i=keySize-1; i<=boardSize-keySize; i++) {
        for(int j=keySize-1; j<=boardSize-keySize; j++) {
            if(board[i][j] != 1) { return false; }
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    int keySize = key.size();
    int lockSize = lock.size();
    int boardSize = lockSize + (keySize-1) * 2;

    // 키를 자물쇠에 딱 맞춰서 비교해야 하는 것이 아니기 때문에 훨씬 큰 보드를 벡터로 구현
    // 보드 사이즈는 lockSize + (keySize-1)*2
    // 자물쇠에 하나라도 걸쳐야 하기 때문에 -1을 해주고 위아래를 생각하면 *2 해주는 것이 맞음
    vector<vector<int> > board(boardSize, vector<int> (boardSize));

    // 보드에 정 가운데 자물쇠 옮기기
    for(int i=keySize-1; i<=boardSize-keySize; i++) {
        for(int j=keySize-1; j<=boardSize-keySize; j++) {
            board[i][j] = lock[i-keySize+1][j-keySize+1];
        }
    }

    // 탐색
    // 방향을 확인하는 코드가 제일 바깥 for문이어야 함
    for(int r=0; r<4; r++) {    // 네 방향 돌려서 확인 (ratation)
    
        for(int i=0; i<=boardSize-keySize; i++) {   // 보드를 옮겨다니면서
            for(int j=0; j<=boardSize-keySize; j++) {
                if(check(i, j, boardSize, keySize, key, board)) {
                    answer = true; return answer;
                }

            }
        }

        key = rotation(key, keySize);
    }



    return answer;
}