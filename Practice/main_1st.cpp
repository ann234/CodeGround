/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	 // freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		int n;
		cin >> n;
		std::unordered_map<int, int>* data = new std::unordered_map<int, int>;
		for (int i = 0; i < n; i++)
		{
			int j;	cin >> j;
			std::unordered_map<int, int>::iterator iter = data->find(j);
			if (iter != data->end())
			{
				iter->second++;
			}
			else
			{
				data->insert(std::unordered_map<int, int>::value_type(j, 1));
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////

		std::vector<int> vec;
		for (auto iter = data->cbegin(); iter != data->cend(); iter++)
		{
			if ((iter->second % 2) != 0)
			{
				vec.push_back(iter->first);
			}
		}

		if (vec.size() > 0)
		{
			Answer = vec[0];
			for (int i = 1; i < vec.size(); i++)
			{
				Answer ^= vec[i];
			}
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}