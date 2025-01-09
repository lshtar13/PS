#include <bits/stdc++.h>

using namespace std;

bool comp(tuple<int, int, string> t0, tuple<int, int, string> t1)
{
    return get<0>(t0) != get<0>(t1) ? get<0>(t0) < get<0>(t1) : get<1>(t0) != get<1>(t1) ? get<1>(t0) < get<1>(t1)
                                                                                         : get<2>(t0) > get<2>(t1);
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    map<string, int> frq;
    for (int i = 0; i < n; ++i)
    {
        char input[11];
        scanf("%s", input);

        string word = input;
        if (word.length() >= m)
            frq[word] ? ++frq[word] : frq[word] = 1;
    }

    vector<tuple<int, int, string>> voca;
    for (auto &word : frq)
        voca.push_back({word.second, word.first.length(), word.first});

    sort(voca.begin(), voca.end(), comp);
    reverse(voca.begin(), voca.end());

    for (auto &x : voca)
        printf("%s\n", get<2>(x).c_str());

    return 0;
}