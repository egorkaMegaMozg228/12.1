#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CreateBIN(char* fname) // створення файлу чисел
{
	ofstream fout(fname, ios::binary); // відкрили файл для запису
	char ch; // відповідь користувача
	int num; // число для запису
	do
	{
		cout << "Enter number: ";
		cin >> num; // ввели число
		fout.write((char*)&num, sizeof(num)); // записали число у файл
		cout << "Continue? (y/n): ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void PrintBIN(char* fname) // виведення числового файлу на екран
{
	ifstream fin(fname, ios::binary); // відкрили файл для зчитування
	int num; // змінна для зчитування чисел
	while (fin.read((char*)&num, sizeof(num))) // поки можна прочитати число
	{
		cout << num << endl; // виводимо число на екран
	}
	cout << endl;
}


void ProcessBIN1(char* fname, char* gname)
{
	ifstream f(fname, ios::binary); // відкрили файл для зчитування
	ofstream g(gname, ios::binary); // відкрили файл для запису
	int num; // змінна для зчитування чисел
	while (f.read((char*)&num, sizeof(num))) // поки можна прочитати число
	{
		if (num >= -1 && num <= 1) // якщо число в діапазоні [-1; 1]
			g.write((char*)&num, sizeof(num)); // записуємо число у файл g
	}
}




int main()
{
	// binary files
	char fname[100]; // ім'я першого файлу
	cout << "enter file name 1: "; cin >> fname;
	CreateBIN(fname); // ввели рядки файлу з клавіатури
	PrintBIN(fname); // вивели вміст першого файлу на екран
	char gname[100]; // ім'я другого файлу
	cout << "enter file name 2: "; cin >> gname;
	ProcessBIN1(fname, gname);
	PrintBIN(gname); // вивели вміст другого файлу на екран

	return 0;
}