#include <bits/stdc++.h>

int main(int argc, char *argv[])
{
    int n;
    std::cin >> n;

    while (n--)
    {
        int p;
        std::cin >> p;

        int price, maxPrice = 0;
        std::string name, maxName;
        while (p--)
        {
            std::cin >> price >> name;
            if (price > maxPrice)
            {
                maxPrice = price, maxName = name;
            }
        }

        if (maxName.length() <= 20)
            std::cout << maxName;
        else
            std::cout << maxName.substr(0, 20);
    }

    return 0;
}