/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;

int Answer;

enum ERAY
{
	LEFT, RIGHT, UP, DOWN,
	OUT
};

ERAY ray_result(ERAY ray, char mirror)
{
	switch (ray)
	{
	case ERAY::RIGHT:
		switch (mirror)
		{
		case '0':
			return ERAY::RIGHT; 
		case '1':
			return ERAY::UP;
		case '2':
			return ERAY::DOWN;
		}
		break;
	case ERAY::LEFT:
		switch (mirror)
		{
		case '0':
			return ERAY::LEFT;
		case '1':
			return ERAY::DOWN;
		case '2':
			return ERAY::UP;
		}
		break;
	case ERAY::UP:
		switch (mirror)
		{
		case '0':
			return ERAY::UP;
		case '1':
			return ERAY::RIGHT;
		case '2':
			return ERAY::LEFT;
		}
		break;
	case ERAY::DOWN:
		switch (mirror)
		{
		case '0':
			return ERAY::DOWN;
		case '1':
			return ERAY::LEFT;
		case '2':
			return ERAY::RIGHT;
		}
		break;
	}
}

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
		int side;
		cin >> side;
		char** mirrors = new char*[side];
		bool** is_touched = new bool*[side];
		for (int i = 0; i < side; i++)
		{
			mirrors[i] = new char[side];
			is_touched[i] = new bool[side];

			cin >> mirrors[i];
			for (int j = 0; j < side; j++)
			{
				is_touched[i][j] = false;
			}
		}

		ERAY curr_ray = ERAY::RIGHT;
		int row = 0, col = 0;
		
		while (curr_ray != ERAY::OUT)
		{
			char curr_mirror = mirrors[row][col];
			is_touched[row][col] = true;

			curr_ray = ray_result(curr_ray, curr_mirror);
			switch (curr_ray)
			{
			case ERAY::RIGHT:
				col++;
				break;
			case ERAY::LEFT:
				col--;
				break;
			case ERAY::UP:
				row--;
				break;
			case ERAY::DOWN:
				row++;
				break;
			}
			if (row >= side || row < 0 || col >= side || col < 0)
			{
				curr_ray = ERAY::OUT;
			}
		}

		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				if (is_touched[i][j] && mirrors[i][j] != '0')
				{
					Answer++;
				}
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}