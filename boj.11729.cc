#include <bits/stdc++.h>

using namespace std;

int total = 0;

void hanoi(int n, int src, int dst, stringstream &out)
{
    ++total;
    if (n == 1)
    {
        out << src << " " << dst << endl;
    }
    else
    {
        int empty = 6 - src - dst;
        hanoi(n - 1, src, empty, out);
        out << src << " " << dst << endl;
        hanoi(n - 1, empty, dst, out);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    stringstream result;
    hanoi(n, 1, 3, result);

    printf("%d\n", total);
    string line;
    while (getline(result, line))
        printf("%s\n", line.c_str());
    return 0;
}