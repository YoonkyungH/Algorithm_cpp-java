// 순열 코드

#include <bits/stdc++.h>

#define MAXN 10

using namespace std;

int N, M;
int Top;
bool Visit[MAXN];
int D[MAXN];

void printD()
{
    for(int i=0; i<M; i++) printf("%d ", D[i]);
    printf("\n");
}

void backtracking()
{
    if(Top == M)
    {
        printD();
        return;
    }

    for(int i=1; i<=N; i++)
    {
        if(!Visit[i])
        {
            Visit[i] = true;
            D[Top++] = i;
            backtracking();
            Top--;
            Visit[i] = false;
        }
    }
}

int main()
{
    printf("permutation\n");
    N = 5;
    M = 3;
    Top = 0;
    backtracking();
    printf("\n");

    return 0;
}