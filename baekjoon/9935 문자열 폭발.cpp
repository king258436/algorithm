#include<iostream>
#include<string>

using namespace std;

int main() {
    string str, tmp, sub;
    cin >> str;
    cin >> sub;
    for (int i = 0; i < str.size(); i++) {
        tmp.push_back(str[i]);
        if (tmp.size() >= sub.size()) {
            for (int subIdx = sub.size() - 1, tmpIdx = tmp.size() - 1; subIdx >= 0; subIdx--, tmpIdx--) {

//                cout << tmp[tmpIdx] << " " << sub[subIdx] << "\n";

                if (tmp[tmpIdx] != sub[subIdx])break;

                if (subIdx == 0) {
                    for (int j = 0; j < sub.size(); j++) {
                        tmp.pop_back();
                    }
                }
            }
        }
    }
    if (tmp.size()) cout << tmp;
    else cout << "FRULA";
}