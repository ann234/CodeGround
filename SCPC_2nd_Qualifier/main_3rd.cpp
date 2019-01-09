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
		int K, L;
		cin >> K >> L;
		int N, M;
		cin >> N >> M;

		bool** graph = new bool*[N + 1];
		for (int i = 1; i <= N; i++)
		{
			graph[i] = new bool[N + 1];
			for (int j = 1; j <= N; j++)
				graph[i][j] = false;
		}

		for (int i = 0; i < M; i++)
		{
			int l, r;
			cin >> l >> r;
			graph[l][r] = graph[r][l] = true;
		}

		int* nConnected = new int[N + 1];
		for (int i = 1; i <= N; i++)
		{
			nConnected[i] = 0;
			for (int j = 1; j <= N; j++)
				if (graph[i][j])
					++nConnected[i];
		}

		std::vector<int> disabled_robot;
		int i = 1;
		while (true)
		{
			for (i = 1; i <= N; i++)
			{
				bool is_disabled = false;
				for (int robot : disabled_robot)
					if (robot == i)
					{
						is_disabled = true;
						break;
					}
				if (is_disabled)
					continue;

				//	1. K개 미만 로봇과 통신중인 경우
				//	2. 감염 시 남은 로봇 개수가 L개 미만인 경우
				//	: 전체 로봇N - (폐기된 로봇 + 로봇i + i와 연결된 로봇 개수)
				if (nConnected[i] < K || L > (N - (disabled_robot.size() + nConnected[i] + 1)))
				{
					disabled_robot.push_back(i);
					//cout << "dispose " << i << endl;
					//	1. K개 이상 로봇 통신 가능
					for (int j = 1; j <= N; j++)
					{
						if (graph[i][j])
						{
							--nConnected[j];
							graph[i][j] = graph[i][j] = false;
						}
					}
					break;
				}
			}

			if (i >= N + 1)
				break;
		}

		for (int robot : disabled_robot)
			Answer += robot;
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}