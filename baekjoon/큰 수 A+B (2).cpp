#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std; 
int main() {
	string s1, s2; 
	cin >> s1 >> s2; 
	reverse(s1.begin(), s1.end()); 
	reverse(s2.begin(), s2.end()); 
	if (s1.length() < s2.length()) {
		while (s1.length() < s2.length())
			s1 += '0';
	}
	 

	else if (s1.length() > s2.length()) {
		while (s1.length() > s2.length())
			s2 += '0';
	}
	s1 += '0';
	s2 += '0'; 
	string result; 
	if (s1.length() == s2.length()) {
		int cnt = 0; 
		for (int i = 0; i < s1.length(); i++) {
			int a = s1[i] - '0';
			int b = s2[i] - '0'; 
			int sum = a + b+cnt; 
			if (sum > 9) {
				result += sum- 10 + '0'; cnt = 1; 
			}
			else {
				result += sum + '0'; cnt = 0; 
			}
		
		}
	}
	reverse(result.begin(), result.end());
	if (result[0] != '0') {
		cout << result[0]; 
	}
	for (int i = 1; i < result.length(); i++) {
		
		cout << result[i]; 
	}
}