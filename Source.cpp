#include <iostream>
#include <fstream>
#include <locale>
#define MATRIX_SIZE 3
using namespace std;
//���� ���������� �������. ������� ���������������� ���������
//��������� ���� �������, ������� �� ������, ������������
//������, ���������� �������� ai, i.����� ����� ������������
//��������� ���� ���������������� ������ �������.

//������� ������ - ��������� ������ �������������� �������
//�������� ������ �����������
//���������� - ���� �� �����
void ifile(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	ifstream input("Lab4.txt");
	for (int i = 0; i < MATRIX_SIZE; i++)
		for (int j = 0; j < MATRIX_SIZE; j++)
			input >> matrix[i][j];
	input.close();
}

//������� ������ - ��������� ������ �������������� �������
//�������� ������ �����������
//���������� - ���� �� �������
void iconsole(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	for (int i = 0; i < MATRIX_SIZE; i++)
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			cout << "������� " << j + 1 << " ������� " << i + 1 << " ������ �������: ";
			cin >> matrix[i][j];
		}
}

//������� ������ - ��������� ������ �������������� �������
//�������� ������ �����������
//���������� - ����� ����� � ����� ������� �����
void input(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	int choice;
	cout << "������� 1 ��� ����� �� �������, ����� (����. ����) - ����� ������ �����" << endl;
	cout << "�������� ��� �������� ���� Lab4.txt � � ���� �������� �� ������� �������� ������� �������� " << MATRIX_SIZE << "�" << MATRIX_SIZE << " ����� ������" << endl;
	cin >> choice;
	if (choice != 1)
		ifile(matrix);
	else
		iconsole(matrix);
}

//������� ������ - ��������� ������ �������������� �������
//�������� ������ - �����, ������� �������� ������ ������������ ��������� ����������������
//���������� - ��������� ����� ������������ ��������� ����������������
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


//������� ������ - ��������� ������ �������������� �������
//�������� ������ �����������
//���������� - ���� �� �������
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
	cout << endl << "����� ���������: " << FindMaxElements(matrix);
	ofile(matrix);
}