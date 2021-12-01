// LAB-6.1(2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// LAB_06_1(2).cpp
// Сушинський Ігор
// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву ітераційним та рекурсивним способом.
// Варіант 18
// Рекурсивний спосіб

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

void Random(int* r, int n, int a, int b)
{
	for (int i = 0; i < n; i++) // i - додаткова змінна
		r[i] = rand() % (b - a + 1) + a;
}

int Count(int* r, int n, int i) // функція обчислення к-ті елементів
{
	if (i == n)
		return 0;
	else
	{
		if ((r[i] % 2) != 0 || (r[i] % 7 == 0))
			return Count(r, n, i + 1) + 1;
		else
			return Count(r, n, i + 1);
	}
}

int Sum(int* r, int n, int i) // функція обчислення суми елементів
{
	if (i < n)
	{
		if ((r[i] % 2) != 0 || (r[i] % 7 == 0))
			return r[i] + Sum(r, n, i + 1);
		else
			return Sum(r, n, i + 1);
	}
	else
		return 0;
}

void Replace(int* r, int n) // функція заміни нюлями цих елементів
{
	for (int i = 0; i < n; i++)
		if (r[i] % 2 != 0 || r[i] % 7 == 0)
			r[i] = 0;
}

void Print(int* r, int n) // форматне виведення
{
	for (int i = 0; i < n; i++)
		cout << setw(3) << r[i] << " ";
	cout << "\n";
}

int main()
{
	srand((unsigned)time(0)); // ініціалізація генератора випадкових чисел

	const int n = 26; // поточна розмірність масиву n = 1..26
	int r[n]; // заданий масив
	int a = 3, b = 92; // діапазон

	Random(r, n, a, b);
	cout << "Before = ";  Print(r, n);

	cout << "count = " << Count(r, n, 0) << "\n";
	cout << "S = " << Sum(r, n, 0) << "\n";

	Replace(r, n);
	cout << "After = "; Print(r, n);

	return 0;
}