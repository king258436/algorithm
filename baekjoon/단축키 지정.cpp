#include <iostream>
#include <string>
using namespace std;
bool hotKey[1000];

void print(string str, int j) {
    for (int i = 0; i < str.length(); i++) {
        if (i == j)
            cout << '[' << str[j] << ']';
        else
            cout << str[i];
    }
    cout << '\n';
}

int main() {
    int n;

    cin >> n;
    cin.ignore(1, '\n');
    while (n--) {
        string str;
        bool flag = false;
        getline(cin, str);
        for (int j = 0; j < str.length(); j++) {
            if (j == 0) {
                if (hotKey[str[j] - 'A'] == false) {
                    print(str, j);
                    flag = true;
                    hotKey[str[j] - 'A'] = true;
                    if (str[j] <= 91)
                        hotKey[tolower(str[j]) - 'A'] = true;
                    else
                        hotKey[toupper(str[j]) - 'A'] = true;
                    break;
                }
            }
            if (str[j] == ' ') {
                if (hotKey[str[++j] - 'A'] == false) {
                    print(str, j);
                    flag = true;
                    hotKey[str[j] - 'A'] = true;
                    if (str[j] < 91)
                        hotKey[tolower(str[j]) - 'A'] = true;
                    else
                        hotKey[toupper(str[j]) - 'A'] = true;
                    break;
                }
            }
        }
        if (!flag) {
            for (int j = 0; j < str.length(); j++) {
                if (str[j] == ' ') continue;
                if (hotKey[str[j] - 'A'] == false) {
                    print(str, j);
                    flag = true;
                    hotKey[str[j] - 'A'] = true;
                    if (str[j] < 91)
                        hotKey[tolower(str[j]) - 'A'] = true;
                    else
                        hotKey[toupper(str[j]) - 'A'] = true;
                    break;
                }
            }
        }
        if (!flag) cout << str<< '\n';
    }
}
