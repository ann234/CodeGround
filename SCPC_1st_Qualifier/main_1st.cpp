/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;

int Answer;
int location[3000002];

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
		int nStone;	//	돌 갯수
		cin >> nStone;
		nStone += 1;	//	시작돌 추가
		location[0] = 0;
		for (int i = 1; i < nStone; i++)
		{
			cin >> location[i];
		}
		int max_step;	//	최대 이동거리
		cin >> max_step;

		int start_stone = 0;
		int next_stone = 1;

		do
		{
			//	건널 수 있는 경우
			if (location[next_stone] - location[start_stone] <= max_step)
			{
				//	목표에 도달한 경우
				if (next_stone == nStone)
				{
					Answer++;
					break;
				}
				next_stone++;
			}
			else
			{
				//	한 번도 못건넌 경우
				if (next_stone - 1 == start_stone)
				{
					Answer = -1;
					break;
				}
				else
				{
					Answer++;
					start_stone = next_stone - 1;
				}
			}
		} while (true);
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}