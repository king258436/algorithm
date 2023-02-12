#include <iostream>
#include <vector>

using namespace std;

pair<char, char> arr[50];

void preorder(char node) {
    if (node != '.') {
        cout << node;
        preorder(arr[node - 'A'].first);
        preorder(arr[node - 'A'].second);
    }
}

void inorder(char node) {
    if (node != '.') {
        inorder(arr[node - 'A'].first);
        cout << node;
        inorder(arr[node - 'A'].second);
    }
}

void postorder(char node) {
    if (node != '.') {
        postorder(arr[node - 'A'].first);
        postorder(arr[node - 'A'].second);
        cout << node;
    }
}

int main() {
    int n;
    cin >> n;
    char p, l, r;
    while (n--) {
        cin >> p >> l >> r;
        arr[p - 'A'].first = l;
        arr[p - 'A'].second = r;
    }
    preorder('A');
    cout<<'\n';
    inorder('A');
    cout<<'\n';
    postorder('A');
    return 0;
}