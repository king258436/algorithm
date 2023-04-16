#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;

string input;
int zero_point;
int number_cnt = 0;

string Make_zero(int cnt)
{
	string ret = "";
	string temp = ":0000";

	for (int i = 0; i < cnt; i++)
		ret += temp;

	return ret;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> input;

	string temp = "";
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == ':')
		{
			if (temp != "")
				number_cnt++; //숫자 단어의 개수를 센다

			temp = "";
		}

		else
		{
			temp += input[i];

			if (i == input.size() - 1)
				number_cnt++;
		}
	}

	//0으로만 이루어진 단어를 개수에 맞게 만든다
	string zero_number = Make_zero(8 - number_cnt);

	//0으로만 이루어진 단어를 넣을 위치를 찾는다
	zero_point = input.find("::");

	if (zero_point != string::npos)
	{
		input.erase(zero_point, 1); //':'를 하나 지우고
		input.insert(zero_point, zero_number); //0으로만 이루어진 단어를 넣는다

		//첫번째와 마지막 체크
		if (input[0] == ':')
			input = input.substr(1, input.size() - 1);
		if (input[input.size() - 1] == ':')
			input = input.substr(0, input.size() - 1);
	}

	string result = "";
	temp = "";
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == ':')
		{
			int temp_size = temp.size();

			//생략된 0을 넣는다
			for (int j = 0; j < 4 - temp_size; j++)
			{
				temp = '0' + temp;
			}

			result += temp;
			result += ':';

			temp = "";
		}

		else
		{
			temp += input[i];

			if (i == input.size() - 1)
			{
				int temp_size = temp.size();
				for (int j = 0; j < 4 - temp_size; j++)
				{
					temp = '0' + temp;
				}

				result += temp;
			}
		}
	}

	cout << result;

	return 0;
}