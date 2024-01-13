#include <bits/stdc++.h>

using namespace std;

string cache[531442];

string cantor(int n)
{
    string result;
    if (cache[n].length())
        result = cache[n];
    else
    {
        result.append(n / 3, ' ');
        cache[n] = result = cantor(n / 3) + result + cantor(n / 3);
    }
    return result;
}

int main(void)
{
    for (auto &x : cache)
        x = "";
    cache[1] = "-", cache[3] = "- -";

    string line;
    while (getline(cin, line))
    {
        int n = pow(3, stoi(line));
        printf("%s\n", cantor(n).c_str());
    }
    return 0;
}