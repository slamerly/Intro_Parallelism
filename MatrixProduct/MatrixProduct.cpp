#include <iostream>
#include <thread>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<vector<int>> matrixProd(vector<vector<int>> &matA, vector<vector<int>> &matB) {
	vector<vector<int>> result;
	vector<int> currentLine;
	int currentRes = 0;

	for (int i = 0; i < matA.size(); i++)
	{
		for (int j = 0; j < matB[0].size(); j++)
		{
			for (int k = 0; k < matA[0].size(); k++)
			{
				currentRes += matA[i][k] * matB[k][j];
			}
			currentLine.push_back(currentRes);
			currentRes = 0;
		}
		result.push_back(currentLine);
		currentLine.clear();
	}

	return result;
}

void somProd(vector<vector<int>> &matriceRes, int positionI, int positionJ, vector<vector<int>>& matA, vector<vector<int>>& matB)
{
	int som = 0;

	for (int k = 0; k < matA[0].size(); k++)
	{
		som += matA[positionI][k] * matB[k][positionJ];
	}

	matriceRes[positionI][positionJ] = som;
}

vector<vector<int>> matrixProdThread(vector<vector<int>>& matA, vector<vector<int>>& matB) {
	vector<vector<int>> result(matA.size(), vector<int>(matB[0].size(), 0));
	vector<int> currentLine;
	int currentRes = 0;

	std::vector<std::thread> threads;

	for (int i = 0; i < matA.size(); i++)
	{
		for (int j = 0; j < matB[0].size(); j++)
		{
			threads.emplace_back(somProd, std::ref(result), i, j, std::ref(matA), std::ref(matB));
		}
	}

	cout << threads.size() << endl;
	for (unsigned int i = 0; i < threads.size(); ++i)
	{
		if (threads[i].joinable())
			threads.at(i).join();
	}

	return result;
}

void displayMatrix(vector<vector<int>> &mat)
{
	for (vector<int> line : mat)
	{
		for (int column : line)
		{
			cout << column << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {

	vector<vector<int>> matA = {
		{0, 1, 2},
		{1, 2, 3},
		{2, 3, 4} };

	vector<vector<int>> matB = {
		{0, 1, 2},
		{1, 2, 3},
		{2, 3, 4} };

	vector<vector<int>> matProd;

	cout << "Sequential version:" << endl;
	matProd = matrixProd(matA, matB);
	displayMatrix(matProd);

	matProd.clear();
	
	cout << "Thread version:" << endl;
	matProd = matrixProdThread(matA, matB);
	displayMatrix(matProd);

	return 0;
}