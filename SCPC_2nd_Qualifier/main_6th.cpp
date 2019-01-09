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
		int N;
		cin >> N;
		std::vector<int> P, Q;
		for (int i = 0, p; i < N; i++)
		{
			cin >> p;
			P.push_back(p);
		}
		for (int i = 0, q; i < N; i++)
		{
			cin >> q;
			Q.push_back(q);
		}

		int i = 0;
		while(i < N)
		{
			//	i�� N - 2���� �۰ų� ���Ƽ� 2��ġ Q�� ���� �� �� �ְ�,
			//	Q�� (i + 1)���� ������ P�� (i) + (i+1)���󺸴� Ŭ���
			if ((i <= N - 2) && (Q[i + 1] > P[i] + P[i + 1]))
			{
				if (Q[i + 1] + P[i + 2] > P[i] + Q[i + 2])
				{

				}
				else
				{

				}
				Answer += Q[i + 1];
				i += 2;	//	2�� �ǳʶ�
			}
			//	ù ���̰� Q�� P���� Ŭ ���
			else if (i == 0 && Q[i] > P[i])
			{
				Answer += Q[i++];
			}
			else
			{
				Answer += P[i++];
			}
		}
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}