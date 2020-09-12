#include <vector>
#include <algorithm>
#include<iostream>

#define ll long long
#define n_max 1000

using namespace std;
class Solution
{
private:
    int n;
    int szz[n_max];
    ll ans;
    vector<pair<int, int>> g[n_max];
public:
    /**
     * 
     * @param n int整型 
     * @param u int整型vector 
     * @param v int整型vector 
     * @param w int整型vector 
     * @return long长整型
     */
    long long solve(int n, vector<int> &u, vector<int> &v, vector<int> &w)
    {
        // 补全代码
        this->n = n;
        for (int i = 1; i < n; ++i)
        {
            int a = u[i - 1], b = v[i - 1], c = w[i - 1];
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
        dfs(1);
        return ans;
    }
    void dfs(int x, int fa = 0)
    {
        szz[x] = 1;
        for (auto cur : g[x])
        {
            int v = cur.first, w = cur.second;
            if (v == fa)
                continue;
            dfs(v, x);
            szz[x] += szz[v];
            ll tmp = 1ll * szz[v] * (n - szz[v]) * w;
            ans = max(ans, tmp);
        }
    }
};

int N, x;
vector<int> U;
vector<int> V;
vector<int> W;
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d", &x);
        U.push_back(x);
    }
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d", &x);
        V.push_back(x);
    }
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d", &x);
        W.push_back(x);
    }
    Solution sol;
    printf("%lld\n", sol.solve(N, U, V, W));
}