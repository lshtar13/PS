#include <bits/stdc++.h>

using namespace std;
char board[50][50];

int check(int x, int y, char start)
{
    char copy[8][8];
    for (int i = 0; i < 8; ++i)
        for (int l = 0; l < 8; ++l)
            copy[i][l] = board[x + i][y + l];

    int result = 0;
    for (int i = 0; i < 8; ++i)
        if (copy[i][i] != start)
            copy[i][i] = start, result += 1;

    for (int i = 1; i < 8; ++i)
        for (int l = 0; l < i; ++l)
            if (copy[i][l] == copy[i - 1][l])
            {
                // cout << endl
                //      << start << " " << i << " " << l;
                result += 1, copy[i][l] = copy[i - 1][l] == 'W' ? 'B' : 'W';
            }

    for (int i = 1; i < 8; ++i)
        for (int l = 0; l < i; ++l)
            if (copy[l][i] == copy[l][i - 1])
            {
                // cout << endl
                //      << start << " " << l << " " << i;
                result += 1, copy[l][i] = copy[l][i - 1] == 'W' ? 'B' : 'W';
            }

    // for (int i = 0; i < 8; ++i)
    // {
    //     for (int l = 0; l < 8; ++l)
    //         cout << copy[i][l];
    //     cout << endl;
    // }
    return result;
}

int main(void)
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int l = 0; l < m; ++l)
            cin >> board[i][l];

    int minimum = 0x7fffffff;
    for (int i = 0; i < n - 7; ++i)
        for (int l = 0; l < m - 7; ++l)
            minimum = min(minimum, min(check(i, l, 'B'), check(i, l, 'W')));

    cout << minimum;

    return 0;
}