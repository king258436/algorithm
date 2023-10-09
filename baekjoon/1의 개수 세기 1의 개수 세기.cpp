#include <string>
#include <vector>
#include<iostream>
#include<memory.h>
#include<map>
#include<algorithm>
#include<queue>
#include<set>
#include<math.h>
using namespace std;
long long d[56];

long long solution(long long n);
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	d[0] = 1;
	long long n,n2;
	cin >> n>>n2;
	for (int i = 1; i <= 55; i++)
	{
		d[i] = d[i - 1] * 2 +((long long)1<<i);
	}
	cout << solution(n2)-solution(n-1)<<'\n';
}
long long solution(long long n)
{
	vector<int> v;
	long long tmp = n;
	while (tmp != 0) {
		v.push_back(tmp % 2);
		tmp /= 2;
	}
	long long ans = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i] == 1)
		{
			ans += d[i - 1]+n - ((long long)1<<i) + 1;
			n -= ((long long)1 << i);
		}
	}
	return ans;
}