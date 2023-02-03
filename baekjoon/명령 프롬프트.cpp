#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char str[50][51];
    char std[51];
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str[i];
    }
    strcpy(std,str[0]);
    for(int i=0;i<n;i++){
        for(int j=0;j<strlen(std);j++){
            if(str[i][j]!=std[j]) std[j]='?';
        }
    }
    cout<<std;
}