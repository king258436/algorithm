#include <bits/stdc++.h>
using namespace std ;
int item, buget, discount ;
long long int sum ;
int flag, answer ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> item >> buget >> discount ;
    vector<int> gift(item), ds_idx(item) ;

    for(int &it : gift)
        cin >> it ;

    sort(gift.begin(), gift.end()) ;
    
    for(int i = 0 ; i < item ; i++)
    {
        if(sum + gift[i] <= buget)
        {
            sum += gift[i] ;
            answer = i + 1;
        }
        else
        {
            flag = 0 ;
            for(int j = i ; j >= 0 ; j--)
            {
                if(ds_idx[j]) continue ;
                if(discount == 0) break ;
                sum -= gift[j] / 2 ;
                discount-- ;
                ds_idx[j] = 1 ;
                if(sum + gift[i] <= buget)
                {
                    flag = 1 ;
                    sum += gift[i] ;
                    answer = i + 1;
                    break ;
                }
            }
            if(!flag) break ;
        }
    }
    cout << answer ; 
}