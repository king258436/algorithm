#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

int primeNum[5000001];

void select(int n, priority_queue<int> &my_pq, priority_queue<int> &other_pq, long long &my_p, long long &other_p) {
    if (primeNum[n] == 0) {
        primeNum[n] = -1;
        my_pq.push(n);
    } else if (primeNum[n] == 1) {
        if (other_pq.size() >= 3) {
            vector<int> v;
            for (int i = 0; i < 2; i++) {
                int temp = other_pq.top();
                v.push_back(temp);
                other_pq.pop();
            }
            other_p += other_pq.top();
            for (int i = 0; i < 2; i++) {
                int temp = v.back();
                other_pq.push(temp);
                v.pop_back();
            }
        } else {
            other_p += 1000;
        }
    } else if (primeNum[n] == -1) {
        my_p -= 1000;
    }
}

int main() {
    priority_queue<int> a_pq;
    priority_queue<int> b_pq;
    long long a_point = 0, b_point = 0;

    int n;
    cin >> n;
    primeNum[0] = 1;
    primeNum[1] = 1;
    for (int i = 2; i <= sqrt(5000000); i++) {
        if (primeNum[i] == 1) continue;
        for (int j = i * i; j <= 5000000; j += i) {
            primeNum[j] = 1;
        }
    }
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        select(a, a_pq, b_pq, a_point, b_point);
        select(b, b_pq, a_pq, b_point, a_point);
    }
    if (a_point > b_point)
        cout << "소수의 신 갓대웅";
    else if (a_point < b_point)
        cout << "소수 마스터 갓규성";
    else
        cout << "우열을 가릴 수 없음";
}