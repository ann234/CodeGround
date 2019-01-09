/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Answer;
int num = 3000002;

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
		int nStudent;
		cin >> nStudent;
		int* score = new int[nStudent];

		int highest = -1;	//	1등 학생점수
		//	학생점수 저장 및 가장 높은 점수 구함
		for (int i = 0; i < nStudent; i++)
		{
			cin >> score[i];
		}
		sort(score, score + nStudent);

		for (int i = 0; i < nStudent; i++)
		{
			if (score[i] + nStudent - i > highest) highest = score[i] + nStudent - i;
		}

		std::vector<int> vec;
		
		for(int i : vec)
		{
			i = 10;
		}

		//	1등 점수 + 1과 비교하여 높을 경우 우승가능성
		for (int i = 0; i < nStudent; i++)
		{
			if (score[i] + nStudent >= highest)
				Answer++;
		}
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}