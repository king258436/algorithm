#include <iostream>
#include <string>
using namespace std;

bool comp(int a, int b)
{
    if (a == b)
        return 1;
    else
        return 0;
}
int arr[4];
int main()
{
    string str;
    cin >> str;
    int flag = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'w')
        {
            flag = 0;
            arr[flag]++;
            while (str[i + 1] == 'w')
            {
                i++;
                arr[flag]++;
            }
            if (str[i+1] != 'o')
            {
                cout << 0;
                return 0;
            }
        }
        else if (str[i] == 'o')
        {
            flag = 1;
            arr[flag]++;
            while (str[i + 1] == 'o')
            {
                i++;
                arr[flag]++;
            }
            if (comp(arr[0], arr[1]) == 0)
            {
                cout << 0;
                return 0;
            }
            if (str[i+1] != 'l')
            {
                cout << 0;
                return 0;
            }
        }
        else if (str[i] == 'l')
        {
            flag = 2;
            arr[flag]++;
            while (str[i + 1] == 'l')
            {
                i++;
                arr[flag]++;
            }
            if (comp(arr[1], arr[2]) == 0)
            {
                cout << 0;
                return 0;
            }
            if (str[i+1] != 'f')
            {
                cout << 0;
                return 0;
            }
        }
        else
        {
            flag = 3;
            arr[flag]++;
            while (str[i + 1] == 'f')
            {
                i++;
                arr[flag]++;
            }
            if (comp(arr[2], arr[3]) == 0)
            {
                cout << 0;
                return 0;
            }
            if (str[i+1] != 'w' && str[i+1] != '\0')
            {
                cout << 0;
                return 0;
            }
            for (int j = 0; j < 4; j++)
            {
                arr[j] = 0;
            }
        }
    }
    cout << 1;
    return 0;
}