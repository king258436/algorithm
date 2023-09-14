#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int result;
int str_point;

int main() {
    string str;

    string str_sub;
    cin >> str;
    while (1) {
        string str_copy = str.substr(str_point, str.length() - str_point);
        string str_copy_reverse = str_copy;

        reverse(str_copy_reverse.begin(), str_copy_reverse.end());

        if (str_copy == str_copy_reverse) {// str 이 팰린드롬 인지 확인.
            result = (str.length() - str_copy.length()) * 2 + str_copy.length();
            break;
        } else {
            str_point++;
        }
    }
    cout << result;
}