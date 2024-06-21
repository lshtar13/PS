#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    int a=2, b=2, mat[3][3] = {0};
    mat[2][2] = 10;
    mat[--a][--b] = mat[a][b] + 1;
    printf("%d", mat[a][b]);
    return 0;
}