#include <bits/stdc++.h>

using namespace std;

u_int8_t board[9][9];

void sudoku(int x, int y)
{
    if (x == 9 && y == 9)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int l = 0; l < 9; ++l)
                printf("%d ", board[i][l]);
            printf("\n");
        }
        exit(0);
    }
    if (!board[x][y])
        for (int n = 1; n <= 9; ++n)
        {
            bool isok = true;
            for (int i = 0; isok && i < 9; ++i)
                if (board[x][i] == n || board[i][y] == n)
                    isok = false;
            for (int xb = x - x % 3, i = 0; isok && i < 3; ++i)
                for (int yb = y - y % 3, l = 0; isok && l < 3; ++l)
                    if (board[xb + i][yb + l] == n)
                        isok = false;

            if (!isok)
                continue;

            board[x][y] = n;
            sudoku(x, y);
            board[x][y] = 0;
        }
    else
    {
        int i, l;
        for (i = x; i < 9; ++i)
            for (l = 0; l < 9; ++l)
                if (!board[i][l])
                    return sudoku(i, l);
        return sudoku(i, l);
    }
}

int main(void)
{
    for (int i = 0; i < 9; ++i)
        for (int l = 0; l < 9; ++l)
            scanf("%hhd", &board[i][l]);
    // printf("---------------\n");
    sudoku(0, 0);
    return 0;
}