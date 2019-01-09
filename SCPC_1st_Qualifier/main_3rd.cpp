/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <cmath>

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
		int num;
		cin >> num;
		const int init_num = num;

		Answer = 2;
		bool is_answer = false;
		while (Answer < init_num && !is_answer)
		{
			num = init_num;
			is_answer = true;
			int base = 1;
			int index = 0;	//	최고 자리수

			//	O(logn)
			while (true)
			{
				if (num - base < 0)
				{
					index -= 1;
					break;
				}

				index++;
				base *= Answer;
			}

			int* num_list = new int[index + 1];
			//std::vector<int> num_list(index + 2);
			for (int i = index; i >= 0; i--)
			{
				int j = 0;	//	자리수 값
				while (true)
				{
					j++;
					if (num - powl(Answer, i)*j < 0)
					{
						j -= 1;
						break;
					}
				}
				num_list[index - i] = j;
				num -= powf(Answer, i)*j;

				if (num_list[0] != num_list[index - i])
				{
					is_answer = false;
					break;
				}
			}

			/*bool is_answer = true;
			int tmp = num_list[0];

			for (int i = 0; i < index + 1; i++)
			{
				if (num_list[i] != tmp)
				{
					is_answer = false;
					break;
				}
			}*/

			if (!is_answer)
				Answer++;

			free(num_list);
		}
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
