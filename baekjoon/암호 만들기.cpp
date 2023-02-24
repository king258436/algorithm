#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int L, C;
vector<char> vec;

bool visited[15];

void dfs(int cnt, string s) {
    if (cnt == L) {
        int mo = 0;
        int ja = 0;
        for (int i = 0; i < L; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                mo++;
            } else
                ja++;
        }
        if (mo >= 1 && ja >= 2) cout << s << '\n';
        return;
    }
    for(int i=0;i<C;i++){
        if(!visited[i]){
            if(!s.empty()){
                if(s.back()>vec[i]) continue;
            }
            visited[i]=true;
            s.push_back(vec[i]);
            dfs(cnt+1,s);
            s.pop_back();
            visited[i]=false;
        }
    }
}

int main() {
    int i, j;
    cin>>L>>C;
    for (i = 0; i < C; i++) {
        char tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    dfs(0,"");
}