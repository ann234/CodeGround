/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#define MOD 1000000009

#include <iostream>

using namespace std;

int Answer;

int max_step;
int num_stone;
bool* mines_list;
int num_mines;
int step_forward(int curr_stone, int step);

int** memory;

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
		cin >> num_stone;
		cin >> max_step;
		memory = new int*[num_stone + 1];
		for (int i = 0; i < num_stone + 1; i++)
		{
			memory[i] = new int[max_step + 1];
			for (int j = 0; j <= max_step; j++)
			{
				memory[i][j] = 0;
			}
		}
		memory[num_stone][0] = 1;

		mines_list = new bool[num_stone + 1];
		for (int i = 0; i < num_stone + 1; i++)
			mines_list[i] = false;
		cin >> num_mines;
		for (int i = 0, mine; i < num_mines; i++)
		{
			cin >> mine;
			mines_list[mine] = true;
		}

		int* per_stone = new int[num_stone + 1];
		per_stone[num_stone] = 1;
		for (int i = num_stone - 1; i >= 0; i--)
		{
			per_stone[i] = 0;
			if (mines_list[i])
			{
				continue;
			}

			for (int j = 1; j <= max_step && (i + j) <= num_stone; j++)
			{
				int next_stone = i + j;

				memory[i][j] = ((per_stone[next_stone] + MOD) - memory[next_stone][j])%MOD;
				per_stone[i] = (per_stone[i] + memory[i][j])%MOD;
			}
		}

		Answer = per_stone[0] % 1000000009;
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;

		free(mines_list);
	}

	return 0;//Your program should return 0 on normal termination.
}

int step_forward(int curr_stone, int step)
{
	int next_stone = curr_stone + step;
	if (next_stone == num_stone)
		return 1;

	for (int i = 0; i < num_mines; i++)
	{
		if (mines_list[i] == next_stone)
			return 0;
	}

	int ret = 0;
	for (int i = 1; i <= max_step; i++)
	{
		if (i != step)
			ret += step_forward(next_stone, i);
	}

	return ret;
}