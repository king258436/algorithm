#include<iostream>
#include<string>

using namespace std;

int main() {
    int s, c;
    int n;
    cin >> n;
    string result;
    if (n % 2 == 1) {
        result = "SK";
    } else {
        result = "CY";
    }
    cout << result;
}