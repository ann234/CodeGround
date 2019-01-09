/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const long long INF = 1000001;

int Answer;

//	<����� ����, ����ġ>
typedef std::vector<pair<int, int>> Node;

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
		int first_answer, second_answer;
		first_answer = second_answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		int N, M, K;
		cin >> N >> M >> K;

		std::vector<Node> graph(N + 1);
		for (int i = 1; i <= M; i++)
		{
			//	from, to, cost
			int l, r, w;
			cin >> l >> r >> w;
			graph[l].push_back(make_pair(r, w));
			graph[r].push_back(make_pair(l, w));
		}

		//	�� ����� ���Ǽұ����� �ּҰŸ�
		//	<���Ǽ� ��� ��ȣ, ��� �Ÿ�>
		std::vector<pair<int, int>> min_distances(N + 1, make_pair(0, INF));
		min_distances[0] = make_pair(0, 0);

		std::vector<int> goals;
		for (int i = 1; i <= K; i++)
		{
			int goal;
			cin >> goal;
			goals.push_back(goal);
			graph[0].push_back(make_pair(goal, 0));
			//	���Ǽ� �ڽ��� �Ÿ� 0
			min_distances[goal].first = goal;
		}

		//	��忡�� ���Ǽұ����� �ּҰŸ�
		priority_queue<pair<int, int>> pq;
		pq.push(make_pair(0, 0));

		while (!pq.empty())
		{
			int cost = pq.top().first;
			int here = pq.top().second;
			pq.pop();

			//	���� ���� ���� �ͺ��� �� ª�� ��θ� �˰��ִٸ�
			//	���� ���� ���� �����Ѵ�
			if (min_distances[here].second < cost) continue;

			//	������ �������� ��� �˻��Ѵ�
			for (int i = 0; i < graph[here].size(); ++i)
			{
				int there = graph[here][i].first;
				int next_dist = cost + graph[here][i].second;

				//	���� ��κ��� �� ª�� ��θ� �߰��ϸ�, dist[]�� �����ϰ�
				//	�켱���� ť�� �ִ´�
				if (min_distances[there].second > next_dist)
				{
					min_distances[there].second = next_dist;
					pq.push(make_pair(next_dist, there));

					//	���Ǽ� ��ü
					if (here != 0)
					{
						min_distances[there].first = min_distances[here].first;
					}
				}
				//	���� ���
				else if (min_distances[there].second == next_dist)
				{
					//	��ȣ�� ���� ���ǼҸ� ���Ѵ�
					if (min_distances[there].first > min_distances[here].first)
						min_distances[there].first = min_distances[here].first;
				}
			}
		}
		for (int i = 1; i < min_distances.size(); i++)
		{
			first_answer += min_distances[i].second;
			second_answer += min_distances[i].first;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////


		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << "\n" << first_answer << "\n" << second_answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}