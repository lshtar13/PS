#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    printf("herere");
    char input[200001];
    scanf("%s", input);

    int sum[26][200001] = {{0}}, inputl = strlen(input);
    for (int i = 1; i <= inputl; ++i)
    {
        sum[input[i] - 'a'][i] += 1;
        for (int l = 0; l < 26; ++l)
            sum[l][i] += sum[l][i - 1];
    }

    char a;
    int q;
    scanf("%d", &q);
    for (int l, r, i = 0; i < q; ++i)
    {
        scanf("%c %d %d", &a, &l, &r);
        a -= 'a', l += 1, r += 1;
        printf("%d\n", sum[a][r] - sum[a][l]);
    }

    return 0;
}