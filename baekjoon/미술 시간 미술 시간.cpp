#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
 
    set <int> S;
    for (int i(1); i <= n; S.insert(i++));
 
    vector <int> ans(n + 1);
    while (q--)
    {
        int a, b, x; cin >> a >> b >> x;
 
        queue <int> Q;
        for (auto it(S.lower_bound(a)); it != S.end() && *it <= b; it++)
            ans[*it] = x, Q.push(*it);
 
        for (; Q.size(); Q.pop())
            S.erase(Q.front());
    }
 
    for (int i(1); i <= n; cout << ans[i++] << ' ');
}
