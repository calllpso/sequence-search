#include <iostream>

using namespace std;

int main()
{
	int size = -1, k = -1, finish = -1; // k - количество строк с последовательностями   
	bool a, b, c; // тип последовательности (a - возрастающая, b - убывающая, c - ни убываюищая ни возрастающая)
	a = b = c = 0;
	cout << "Set size of array = ";
	cin >> size;
	cout << endl;

	if (size == 1)
	{
		cout << "array with size=1 has no sequence" << endl;
		system("pause");
		return 0;
	}
	else if (size <= 0)
	{
		cout << "not correct size" << endl;
		system("pause");
		return 0;
	}
	if (size > 1)
	{
		//создание одномерного динамического массива
		int* array = new int[size];	// создал указатели на свои строки
		//создание двумерного динамического массива
		int** mass = new int* [size];
		for (int i = 0; i < size; i++)
		{
			mass[i] = new int[size];
		}

		cout << "Set space-separated elements of an integer square array with size: " << size << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cin >> mass[i][j];
			}
			cout << endl;
		}
		cout << endl;

		//определение последовательности	
		for (int i = 0; i < size; i++)
		{
			a = b = c = finish = 0;
			for (int j = 0; j + 1 < size; j = j + 2)
			{
				if (j == 0)
				{
					if (mass[i][j] < mass[i][j + 1])
					{
						a = 1; // возрастающая посл-ть		
					}
					else if (mass[i][j] > mass[i][j + 1])
					{
						b = 1; // убывающая посл-ть
					}
					else if (mass[i][j] == mass[i][j + 1])
					{
						c = 1; //неуб и невозр
					}
				}
				if (j > 0)
				{
					if (mass[i][j] < mass[i][j + 1])
					{
						a = 1; // возрастающая посл-ть
					}
					else if (mass[i][j] > mass[i][j + 1])
					{
						b = 1; // убывающая посл-ть
					}
					else if (mass[i][j] == mass[i][j + 1])
					{
						c = 1;
					}
					if (a == b == 1)
					{
						continue;
					}
				}
				if ((mass[i][j + 1] < mass[i][j + 2]) && ((j + 2) < size))
				{
					a = 1; // возрастающая посл-ть
				}
				else if ((mass[i][j + 1] > mass[i][j + 2]) && ((j + 2) < size))
				{
					b = 1; // убывающая посл-ть
				}
				else if ((mass[i][j + 1] == mass[i][j + 2]) && ((j + 2) < size))
				{
					c = 1;
					if (((j == size - 2) || (j == size - 3)) && ((a != 0) || (b != 0)))
					{
						finish = i;
					}
				}
				if (a == b == 1)
				{
					break;
				}
				if ((j == size - 2) && ((a != 0) || (b != 0)))
				{
					finish = j + 1;
				}
				else if ((j == size - 3) && ((a != 0) || (b != 0)))
				{
					finish = j + 2;
				}
			}
			cout << endl;
			if (finish == size - 1)
			{
				k++;
				array[k] = i;
			}
		}
		if (k == -1)
		{
			cout << "This array has no sequence" << endl;
			system("pause");
			return 0;
		}

		cout << "numbers of strings with monotonic sequences: " << endl;
		for (int i = 0; i <= k; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;

		//создание массива для требуемых строк
		int** arr = new int* [k];
		for (int i = 0; i <= k; i++)
		{
			arr[i] = new int[size];
		}
		for (int i = 0; i <= k; i++)
		{
			for (int j = 0; j < size; j++)
			{
				arr[i][j] = 0;
			}
			cout << endl;
		}
		//заполнение массива
		for (int i = 0; i <= k; i++)
		{
			for (int j = 0; j < size; j++)
			{
				arr[i][j] = mass[array[i]][j];
			}
			cout << endl;
		}
		cout << endl;
		//вывод массива с последовательностями
		cout << "array of strings with sequences" << endl;
		for (int i = 0; i <= k; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << arr[i][j] << "  ";
			}
			cout << endl;
		}
		delete[] array;
		for (int i = 0; i < size; i++)
		{
			delete[] mass[i];
		}
		delete[] mass;
	}
	system("pause");
	return 0;
}

