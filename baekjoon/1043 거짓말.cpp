#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int> know_people, party[50];
int parent[51];

int get_parent(int x) {
    if (parent[x] == x) {
        return x;
    }
    return get_parent(parent[x]);
}

void union_parent(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    if (a > b) {
        parent[a] = b;
    } else {
        parent[b] = a;
    }
}

bool find_parent(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    if (a == b) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int know_people_cnt;
    cin >> n >> m;
    cin >> know_people_cnt;
    for (int i = 0; i < know_people_cnt; i++) {
        int a;
        cin >> a;
        know_people.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int mem;
            cin >> mem;
            party[i].push_back(mem);
        }
    }

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (auto cur: know_people) {
        union_parent(know_people[0], cur);
    }

    for (int i = 0; i < m; i++) {
        for (auto cur: party[i]) {
            union_parent(cur, party[i][0]);
        }
    }

    int cnt = 0;
    if (know_people_cnt == 0) {
        cnt = m;
    } else {
        for (int i = 0; i < m; i++) {
            if (!find_parent(know_people[0], party[i][0])) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}