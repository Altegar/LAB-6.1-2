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

void Random(int* r, const int n, const int a, const int b, int i)
{
	r[i] = rand() % (b - a + 1) + a;
	if (i < n - 1)
		Random(r, n, a, b, i + 1);
}

int Count(int* r, const int n, int i) // функція обчислення к-ті елементів
{
	if (i == n)
		return 0;
	else
	{
		if (!(r[i] % 2 != 0 || i % 7 == 0))
			return Count(r, n, i + 1) + 1;
		else
			return Count(r, n, i + 1);
	}
}

int Sum(int* r, const int n, int i) // функція обчислення суми елементів
{
	if (i < n)
	{
		if (!(r[i] % 2 != 0 || i % 7 == 0))
			return r[i] + Sum(r, n, i + 1);
		else
			return Sum(r, n, i + 1);
	}
	else
		return 0;
}

void Replace(int* r, const int n, int i) // функція заміни нюлями цих елементів
{
	if (i == 0)
	{
		if (!(r[i] % 2 != 0 || i % 7 == 0))
			r[i] = 0;
		else
			return Replace(r, n, i + 1) + 1;
	}
	else
		return Replace(r, n, i + 1);
}

void Print(int* r, const int n, int i) // форматне виведення
{
	cout << setw(3) << r[i];
	if (i < n - 1)
		Print(r, n, i + 1);
	else
		cout << endl;
}

int main()
{
	srand((unsigned)time(0)); // ініціалізація генератора випадкових чисел

	const int n = 26; // поточна розмірність масиву n = 1..26
	int r[n]; // заданий масив
	int a = 3, b = 92; // діапазон

	Random(r, n, a, b, 0);
	cout << "Before = ";  Print(r, n, 0);

	cout << "Count = " << Count(r, n, 0) << "\n";
	cout << "Sum = " << Sum(r, n, 0) << "\n";

	Replace(r, n, 0);
	cout << "After = "; Print(r, n, 0);

	return 0;
}