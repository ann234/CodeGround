/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>

using namespace std;

int Answer;

//	[의뢰, 마감, 필요 시간]
typedef int shoes_t[3];

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
		int N, K;
		cin >> N >> K;

		shoes_t* shoes_infos = new shoes_t[N];
		for (int i = 0; i < N; i++)
		{
			cin >> shoes_infos[i][0] >> shoes_infos[i][1] >> shoes_infos[i][2];
		}

		//	<시작, 끝 시간>
		std::vector<pair<int, int>> masters;
		for (int i = 0, s, e; i < K; i++)
		{
			cin >> s >> e;
			masters.push_back(make_pair(s, e));
		}


		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}