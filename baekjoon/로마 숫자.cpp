#include <iostream>
#include <string>

using namespace std;
int special[] = {4, 9, 40, 90, 400, 900};

int StrToNum(string str) {
    int cnt = 0;
    int idx = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'I') {
            if (str[i + 1] == 'V') {
                cnt += 4;
                i++;
            } else if (str[i + 1] == 'X') {
                cnt += 9;
                i++;
            } else
                cnt += 1;
        } else if (str[i] == 'V') {
            cnt += 5;
        } else if (str[i] == 'X') {
            if (str[i + 1] == 'L') {
                cnt += 40;
                i++;
            } else if (str[i + 1] == 'C') {
                cnt += 90;
                i++;
            } else
                cnt += 10;
        } else if (str[i] == 'L') {
            cnt += 50;
        } else if (str[i] == 'C') {
            if (str[i + 1] == 'D') {
                cnt += 400;
                i++;
            } else if (str[i + 1] == 'M') {
                cnt += 900;
                i++;
            } else
                cnt += 100;
        } else if (str[i] == 'D') {
            cnt += 500;
        } else if (str[i] == 'M') {
            cnt += 1000;
        }
    }
    return cnt;
}
string NumToStr(int a) {
    string s;
    while (a > 0) {
        if (a >= 1000) {
            s.push_back('M');
            a -= 1000;
        } else if (a >= 900) {
            s.push_back('C');
            s.push_back('M');
            a -= 900;
        } else if (a >= 500) {
            s.push_back('D');
            a -= 500;
        } else if (a >= 400) {
            s.push_back('C');
            s.push_back('D');
            a -= 400;
        } else if (a >= 100) {
            s.push_back('C');
            a -= 100;
        } else if (a >= 90) {
            s.push_back('X');
            s.push_back('C');
            a -= 90;
        } else if (a >= 50) {
            s.push_back('L');
            a -= 50;
        } else if (a >= 40) {
            s.push_back('X');
            s.push_back('L');
            a -= 40;
        } else if (a >= 10) {
            s.push_back('X');
            a -= 10;
        } else if (a >= 9) {
            s.push_back('I');
            s.push_back('X');
            a -= 9;
        } else if (a >= 5) {
            s.push_back('V');
            a -= 5;
        } else if (a >= 4) {
            s.push_back('I');
            s.push_back('V');
            a -= 4;
        } else {
            s.push_back('I');
            a -= 1;
        }
    }
    return s;
}
int main() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    int n1 = StrToNum(s1);
    int n2 = StrToNum(s2);
    int hap = n1 + n2;
    string hap_s = NumToStr(hap);
    cout << hap << endl;
    cout << hap_s;
}