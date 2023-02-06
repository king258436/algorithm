#include<iostream>
using namespace std;
long long A, B, C;

long long divide(long long a, long long b, long long c) {
	if (b == 1) { // 탈출조건
		return a % c;
	}
	long long tmp = divide(a, b/2, c) % c;
	if( b % 2 == 0 ){//짝수면 구한거 바로 더하기
		return tmp * tmp % c;
	}
	else {//홀수면 나누고 a한번 더 곱
		return tmp * tmp % c * a % c;
	}
}
int main() {
	cin >> A >> B >> C;
	cout << divide(A, B, C);
}