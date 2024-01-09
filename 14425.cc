#include <bits/stdc++.h>

using namespace std;

bool search(vector<string> &words, string tgt, int start, int end)
{
    if (start > end)
        return false;

    int mid = (start + end) / 2;
    if (words[mid] == tgt)
        return true;
    else if (words[mid] < tgt)
        return search(words, tgt, mid + 1, end);
    else
        return search(words, tgt, start, mid - 1);
}

int _main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<string> words(n);
    for (auto &x : words)
    {
        char input[501];
        scanf("%s", input);
        x = input;
    }

    sort(words.begin(), words.end());

    int result = 0;
    for (int i = 0, x; i < m; ++i)
    {
        char tgt[501];
        scanf("%s", tgt);
        search(words, string(tgt), 0, n - 1) ? ++result : 0;
    }

    printf("%d", result);

    return 0;
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    unordered_map<string, bool> dict;
    for (int i = 0; i < n; ++i)
    {
        char word[501];
        scanf("%s", word);
        dict.insert({string(word), true});
    }

    int result = 0;
    for (int i = 0; i < m; ++i)
    {
        char word[501];
        scanf("%s", word);
        if (dict[string(word)])
            ++result;
    }

    printf("%d", result);
    return 0;
}