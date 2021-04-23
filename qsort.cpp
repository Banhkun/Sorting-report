#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stack>
using namespace std;


void Nhap(string, float[]);
void Xuat(string, float[]);
int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
float v[1000000];

int main()
{

	for (int i = 1; i <= 1; i++)
	{
		string name = "data";
		if (i < 10)
			name += "0";
		name = name + to_string(i);
		string nameinp = name + ".txt";
		Nhap(nameinp, v);

		//Tinh thoi gian chay cua QuickSort()
		clock_t start, end;
		start = clock();
		qsort(v, 999999, sizeof(int), compare);
		end = clock();

		string nameout = name + ".out";
		Xuat(nameout, v);
		cout << "Sap xep file " << nameinp << " thanh cong" << endl;
		cout << "Time_used = " << (float)(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	}
}

void Nhap(string fn, float a[])
{
	ifstream fi(fn);
	if (fi.fail())
		cout << "Nhap file " << fn << " that bai" << endl;
	else
	{
		for (int i = 0; i < 1000000; i++)
			fi >> a[i];
		cout << "Nhap file " << fn << " thanh cong" << endl;
	}
}

void Xuat(string fn, float a[])
{
	ofstream fo(fn);
	if (fo.fail())
		cout << "Xuat file " << fn << " that bai" << endl;
	else
	{
		for (int i = 0; i < 1000000; i++)
			fo << setw(10) << a[i];
	}
}
