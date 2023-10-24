#include <iostream>
#include <thread>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<vector<int>> matrixProd(vector<vector<int>> matA, vector<vector<int>> matB) {
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

void somProd(int positionI, int positionJ, vector<int> line, vector<int> col)
{
	vector<int> result = { positionI, positionJ };
	int som = 0;

	for (int i = 0; i < line.size(); i++)
	{
		som += line[i] * col[i];
	}
	result.push_back(som);
}

vector<vector<int>> matrixProdThread(vector<vector<int>> matA, vector<vector<int>> matB) {
	vector<vector<int>> result;
	vector<int> currentLine;
	int currentRes = 0;

	vector<std::thread> threads;

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

void displayMatrix(vector<vector<int>> mat)
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

	matProd = matrixProd(matA, matB);

	displayMatrix(matProd);

	return 0;
}