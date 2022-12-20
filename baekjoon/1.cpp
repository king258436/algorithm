#include <iostream>

using namespace std;

int main() {
	int n, digit = 1;
	long long m = 1;
	while (cin >> n) {
		while (m % n != 0) {
			m %= n;
			m = 10 * m + 1;
			digit++;
		}
		cout << digit << '\n';
		m = 1, digit = 1;
	}

	return 0;
}