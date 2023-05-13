#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int> > v;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            v.push_back(make_pair(a, b));
        }

        sort(v.begin(), v.end());

        int cnt=1;
        int temp=0;
        for(int i=1;i<n;i++){
            if(v[temp].second>v[i].second) {
                cnt++;
                temp=i;
            }
        }
        cout << cnt << endl;
    }
}