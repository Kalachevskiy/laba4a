#include <iostream>
#include <fstream>
#include <locale>
#define MATRIX_SIZE 3
using namespace std;
//Дана квадратная матрица. Назовем псевдодиагональю множество
//элементов этой матрицы, лежащих на прямой, параллельной
//прямой, содержащей элементы ai, i.Найти сумму максимальных
//элементов всех псевдодиагоналей данной матрицы.

//Входные данные - двумерный массив фиксированного размера
//Выходные данные отсутствуют
//Назначение - ввод из файла
void ifile(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	ifstream input("Lab4.txt");
	for (int i = 0; i < MATRIX_SIZE; i++)
		for (int j = 0; j < MATRIX_SIZE; j++)
			input >> matrix[i][j];
	input.close();
}

//Входные данные - двумерный массив фиксированного размера
//Выходные данные отсутствуют
//Назначение - ввод из консоли
void iconsole(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	for (int i = 0; i < MATRIX_SIZE; i++)
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			cout << "Введите " << j + 1 << " элемент " << i + 1 << " строки матрицы: ";
			cin >> matrix[i][j];
		}
}

//Входные данные - двумерный массив фиксированного размера
//Выходные данные отсутствуют
//Назначение - выбор ввода и вызов функций ввода
void input(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	int choice;
	cout << "Введите 1 для ввода из консоли, иначе (файл. ввод) - любое другое число" << endl;
	cout << "Создайте или измените файл Lab4.txt и в него запишите по порядку элементы матрицы размером " << MATRIX_SIZE << "х" << MATRIX_SIZE << " через пробел" << endl;
	cin >> choice;
	if (choice != 1)
		ifile(matrix);
	else
		iconsole(matrix);
}

//Входные данные - двумерный массив фиксированного размера
//Выходные данные - число, которое является суммой максимальных элементов псевдодиагоналей
//Назначение - вычислить сумму максимальных элементов псевдодиагоналей
int FindMaxElements(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	int maxElementsSum = 0;
	int currentMaxNumber = 0;
	for (int i = 1; i < MATRIX_SIZE; i++)
	{
		for (int j = i; j < MATRIX_SIZE; j++)
		{
			if (matrix[j][j - i] >= currentMaxNumber)
				currentMaxNumber = matrix[j][j - i];

		}
		maxElementsSum += currentMaxNumber;
		currentMaxNumber = 0;
		for (int j = 0; j < MATRIX_SIZE - i; j++)
		{
			if (matrix[j][j + i] > currentMaxNumber)
				currentMaxNumber = matrix[j][j + i];
		}
		maxElementsSum += currentMaxNumber;
		currentMaxNumber = 0;
	}
	return maxElementsSum;
}


//Входные данные - двумерный массив фиксированного размера
//Выходные данные отсутствуют
//Назначение - ввод из консоли
void Show(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	cout << endl << endl;
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}
void ofile(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	ofstream file("Lab4aOutput.txt");
	file << FindMaxElements(matrix);
}
int main()
{
	setlocale(LC_ALL, "");
	int matrix[MATRIX_SIZE][MATRIX_SIZE];
	input(matrix);
	Show(matrix);
	cout << endl << "Сумма элементов: " << FindMaxElements(matrix);
	ofile(matrix);
}