// 자물쇠와 열쇠
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // copy 함수

using namespace std;

int keySize;
int lockSize;
int boardSize;

vector<vector<int>> rotation(vector<vector<int>> key) {   // 시계방향 90도 회전 구현
    vector<vector<int> > tmp(keySize, vector<int>(keySize));           // 회전한 값을 arr에 넣기 위한 임시 2차원 배열

    // copy(&key[0][0], &key[0][0] + keySize * keySize, &tmp[0][0]);

    for(int i=0; i<keySize; i++) {
        for(int j=0; j<keySize; j++) {
            tmp[i][j] = key[keySize - j - 1][i];
        }
    }
}

// 지금 키가 있는 자리가 자물쇠와 풀리도록 일치하는지 확인하는 함수
bool check(int x, int y, vector<vector<int>> key, vector<vector<int>> board) {
    for(int i=x; i<x+keySize; i++) {
        for(int j=y; j<y+keySize; j++) {
            if(i>=keySize-1 && i<=boardSize-keySize && j>=keySize-1 && j<=boardSize-keySize) {
                if (key[i-x][i-y] + board[i][j] != 1) {
                    return false;   // 튀어나온데 또 튀어나오거나 비었는데 채우지 못했거나
                }
            }
            
        }
    }
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    keySize = key.size();
    lockSize = lock.size();
    boardSize = lockSize + (keySize-1) * 2;

    vector<vector<int> > board(boardSize, vector<int> (boardSize));
    
    // 큰 보드에 자물쇠 (lock) 옮기기
    for(int i=keySize-1; i<=boardSize-keySize; i++) {
        for(int j=keySize-1; j<=boardSize-keySize; j++) {
            board[i][j] = lock[i-keySize+1][j-keySize+1];
        }
    }

    // 다 돌아보기
    for(int i=0; i<4; i++) {
        for(int j=0; j<=(boardSize - keySize); j++) {
            for(int k=0; k<=(boardSize - keySize); k++) {
                if(check(j, k, key, board)) { answer = true; return answer; }
            }
        }

        key = rotation(key);
    }
    
    return answer;
}
