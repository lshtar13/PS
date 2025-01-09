#include <bits/stdc++.h>

using namespace std;
int result = 0;
void nqueen(int n, vector<int> &cords)
{
    if (cords.size() == n)
    {
        // printf("cords : \n");
        // for (auto &x : cords)
        //     printf("%d %d\n", x.first, x.second);
        ++result;
    }
    else
        for (int x = cords.size(), i = 0; i < n; ++i)
        {
            bool isok = true;
            for (int l = 0; l < x; ++l)
                if (i == cords[l] || abs(x - l) == abs(i - cords[l]))
                    isok = false;
            if (isok)
            {
                cords.push_back(i);
                nqueen(n, cords);
                cords.pop_back();
            }
        }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    vector<int> cords;
    nqueen(n, cords);
    printf("%d", result);
    return 0;
}