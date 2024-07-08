#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class info{
    public:
        int level;
        char c;
        map<char, info*> childs;

        info(char _c)
        {
            c = _c;
        }

        void push(string &word, int tgt)
        {
            if(tgt>=word.size())
            {
                return;
            }
            if(childs.find(word[tgt]) == childs.end())
            {
               childs[word[tgt]] = new info(word[tgt]);
            }
            childs[word[tgt]]->push(word, tgt+1);
        }

        bool find(string &word, int tgt)
        {
            if(tgt>=word.size())
            {
                return !childs.size();
            }

            if(childs.find(word[tgt]) == childs.end())
            {
                return false;
            }
            else
            {
                return childs[word[tgt]]->find(word, tgt+1);
            }
            
        }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    info rootInfo(0);
    cin>>n>>m;

    for(int i = 0; i<n; ++i)
    {
        string word;
        cin>>word;
        word += "0";
        rootInfo.push(word, 0);
    }

    int result = 0;
    for(int i = 0; i<m; ++i)
    {
        string word;
        cin>>word;
        word += "0";
        result = rootInfo.find(word, 0) ? result + 1: result;
    }

    cout<<result;

    return 0;
}


/*
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
*/