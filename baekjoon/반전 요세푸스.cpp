#include <iostream>
#include <deque>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K, M, cnt = 0;
	bool check;
	deque <int> d;
	cin >> N >> K >> M;
    
	for(int i = 1; i <= N; i++){
		d.push_back(i);
	}
    
	while(!d.empty()){
		if(check == 0){
			for(int i = 0; i < K - 1; i++){
				d.push_back(d.front());
				d.pop_front();
			}
			cout << d.front() << "\n";
			d.pop_front();
		}
		else{
			for(int i = 0; i < K - 1; i++){
				d.push_front(d.back());
				d.pop_back();
			}
			cout << d.back() << "\n";
			d.pop_back();
		}
		cnt++;
		if(cnt == M){
			check = !check;
			cnt = 0;
		}
	}
}