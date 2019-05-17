// Scobki.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include<string>
#include <iomanip>
using namespace std;
int main()
{
	//последовательность s длины n
	
	string s = ")???";
	int k = 0;
	int n = (int)s.size();
	s = ' ' + s;
	int** graphmatrix;
	graphmatrix = new int*[1+n];
	for (int i = 0; i < 1 + n; i++)
	{
		graphmatrix[i] = new int[1 + n];
	}
	for (int i = 0; i < 1 + n; i++) 
	{ 
		for (int j = 0; j < 1 + n; j++)
		{
			graphmatrix[i][j] = 0;
		}
	}

	graphmatrix[0][0] = 1;
	for (int len = 1; len <= n; len++) 
	{
		for (int open = 0; open <= n; open++) 
		{
			if (open - 1 >= 0 && (s[len] == '?' || s[len] == '(')) 
			{
				graphmatrix[len][open] += graphmatrix[len - 1][open - 1];
			}
			if (open + 1 <=n && (s[len] == '?' || s[len] == ')'))
			{
				graphmatrix[len][open] += graphmatrix[len - 1][open + 1];
			}
		}
	}
	for (int i = 0; i < 1 + n; i++)
	{
		for (int j = 0; j < 1 + n; j++)
			std::cout << std::setw(4) << graphmatrix[i][j];
		std::cout << std::endl;
	}
	cout << "Otvet: "<<graphmatrix[n][0]<<"\n";
	delete[] graphmatrix;
	system("pause");
}

 
