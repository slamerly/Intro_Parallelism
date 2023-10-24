#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using std::cout;
using std::endl;
using std::vector;
using std::thread;
using std::mutex;

int sumTable(int *table, int n)
{
    int res = 0;

	for (int i = 0; i < n; i++)
	{
		res += table[i];
	}

	return res;
}

int sumTableThread(int* table, int start, int end)
{
	int res = 0;

	for (int i = start; i <= end; i++)
	{
		res += table[i];
	}

	return res;
}

int main()
{
	const int n = 5;
	int table[n];

	// variable thread
	int m = ceil((float)n / 2);
	int start = 0;
	int end = 0;
	vector<int> sumThread(m, 0);
	vector<thread> threads;

	// variable global & mutex
	int globalSum = 0;
	mutex mtx;

	for (int i = 0; i < n; i++)
	{
		table[i] = i;
	}

	// sequential
	int totalSum = sumTable(table, n);
	cout << "sequential: " << totalSum << endl;


	// thread
	/*for (int j = 0; j < m; j++)
	{
		start = j * ceil((float)n / (float)m);
		if (j == m - 1 && n % 2 != 0)
		{
			end = start;
		}
		else
		{
			end = start + 1;
		}

		threads.emplace_back(
			[&table, &sumThread, j, start, end]()
			{
				sumThread[j] = sumTableThread(table, start, end);
			}
		);
	}

	for (auto& thread : threads)
	{
		thread.join();
	}

	totalSum = 0;
	for (auto sum : sumThread)
	{
		totalSum += sum;
	}
	cout << "thread: " << totalSum << endl;*/


	// Global & mutex
	for (int j = 0; j < m; j++)
	{
		start = j * ceil((float)n / (float)m);
		if (j == m - 1 && n % 2 != 0)
		{
			end = start;
		}
		else
		{
			end = start + 1;
		}

		threads.emplace_back(
			[&table, &globalSum, &mtx, start, end]()
			{
				int sumThread = sumTableThread(table, start, end);
				std::lock_guard<mutex> lock(mtx);
				globalSum += sumThread;
			}
		);
	}

	for (auto& thread : threads)
	{
		thread.join();
	}

	cout << "global & mutex: " << globalSum << endl;

	return 0;
}
