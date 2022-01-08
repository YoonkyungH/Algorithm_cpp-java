// 조합 코드

/**
 * https://visualgo.net/en/recursion에서 함수 돌려보기
 * 
 * parameter:  s = 1, n = 5, m=3, top=0
 * fun: 
 * /
// if (top == m) return s-1; /* base case */
// /* recursive caseS */
// for (var i = s; i <= n; i++)
// {
//     top++;
//     f(i + 1, n, m, top);
//     top--;
// }
// return s - 1;

#include <bits/stdc++.h>

#define MAXN 10

using namespace std;

int N, M;
int Top;
int D[MAXN];

void printD()
{
    for(int i=0; i<M; i++) printf("%d ", D[i]);
    printf("\n");
}

void backtracking(int start)
{
    if(Top == M)
    {
        printD();
        return;
    }

    for(int i=start; i<=N; i++)
    {
        D[Top++] = i;
        backtracking(i+1);
        Top--;
    }
}

int main()
{
    printf("combination\n");
    N = 5;
    M = 3;
    Top = 0;
    backtracking(1);

    return 0;
}