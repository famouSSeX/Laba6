#include <fstream>
#include <iostream>
using namespace std;

void matrix_in(int n, int mass[20][20]) //Ввод матрицы
{
	ifstream fin("input.txt");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fin >> mass[i][j];
		}
	}
}
void matrix_out(int n, int mass[20][20]) //Вывод матрицы
{
	ofstream fout("output.txt");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fout << mass[i][j] << "\t";
		}
		fout << endl;
	}
	fout << endl;
}
bool isPrime(int x) //Проверка на простоту числа
{
	if (x == 2 || x == 3)
	{
		return true;
	}
	if (x <= 1)
	{
		return false;
	}
	for (int i = 2; i < sqrt(x); i++)
	{
		if (x % i == 0)
		{
			return false;
		}
		return true;
	}
}
bool matrix_func(int n, int mass[20][20]) //Проверка по условию
{
	bool flag = false;
	int line_sum = 0;
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		flag = false;
		line_sum = 0;
		for (int j = 0; j < n; j++)
		{
			line_sum += mass[i][j];
			if (isPrime(mass[i][j]) == true)
			{
				flag = true;
			}
		}
		if (line_sum == 0 && flag == true)
		{
			return true;
		}
	}
}
void matrix_sort(int n, int mass[20][20]) //Свап столбцов
{
	for (int i = 0; i < n; i++)
	{
		for (int k = i + 1; k < n; k++)
		{
			int colomn_sum1 = 0;
			int colomn_sum2 = 0;
			for (int j = 0; j < n; j++)
			{
				colomn_sum1 += abs(mass[j][i]);
				colomn_sum2 += abs(mass[j][k]);
			}
			for (int j = 0; j < n; j++)
			{
				if (colomn_sum1 < colomn_sum2)
				{
					swap(mass[j][i], mass[j][k]);
				}
			}

		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cin >> n;
	int matrix[20][20];
	matrix_in(n, matrix);
	if (matrix_func(n, matrix) == true)
	{
		matrix_sort(n, matrix);
		matrix_out(n, matrix);
	}
	else
	{
		cout << "Ошибка" << endl;
	}
}