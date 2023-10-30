//Problem : LOJ-1035


#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

vector<bool> isPrime(N, true);
vector<int> prime;
map<int, int> mp;

void seive(int n)
{
    n += 10;
    int sq = sqrt(n);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < sq; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
            prime.push_back(i);
    }
}

void factorise(int n)
{
    for (auto i : prime)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                mp[i]++;
                n /= i;
            }
        }
    }
    if (n > 1)
        mp[n]++;
}

int main()
{
    seive(1000);

    int t, c = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 2; i <= n; i++)
        {
            factorise(i);
        }
        int ct = 1;
        cout << "Case " << c++ << ": " << n << " = ";
        for (auto i : mp)
        {

            cout << i.first << " (" << i.second;
            if (ct == mp.size())
                cout << ")";
            else
                cout << ") * ";
            ct++;
        }

        mp.clear();
        cout << '\n';
    }
}
