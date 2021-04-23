#include <iostream>
#include<vector>
#include<iomanip>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

int Nhap(vector<double>&, int&, string);
int Xuat(vector<double>);
int Xuat(vector<double>, string);
void QuickSort(vector<double>&, int, int);
int Partition(vector<double>&, int, int);

int main()
{


	for (int i = 8; i <= 8; i++)
	{
		vector<double> b;
		int k;
		string filename = "data";
		if (i < 10)
			filename += '0';
		filename += to_string(i);

		string filenameinp = filename;
		filenameinp += ".txt";

		if (Nhap(b, k, filenameinp) == 1)
		{
			auto start = high_resolution_clock::now();

			QuickSort(b, 0, b.size() - 1);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			cout << "Time taken by function: "
				<< duration.count() << " millisecond" << endl;
			string filenameout = filename;
			filenameout += ".out";
			cout << "Xuat ra file: ";
			Xuat(b, filenameout);
			cout << filenameout << " Done ";
			cout << endl;
		}
		else
			cout << "\n Khong mo duoc file " << filename << "\n";
	}
	cout << "\n End Game ";
	cout << "\n\n\n";
	return 1;

}

int Nhap(vector<double>& a, int& n, string filename)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	fi >> n;
	for (int i = 0; i < n; i++)
	{
		double temp;
		fi >> temp;
		a.push_back(temp);
	}
	return 1;
}

int Xuat(vector<double> a, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	fo << a.size() << endl;
	for (size_t i = 0; i < a.size(); i++)
		fo << setw(5) << a[i];
	return 1;
}


int Xuat(vector<double> a)
{
	for (size_t i = 0; i < a.size(); i++)
		cout << setw(7) << setprecision(2) << fixed << a[i];
	return 1;
}

int Partition(vector<double>& values, int left, int right)
{
	int pivotIndex = left + (right - left) / 2;
	int pivotValue = values[pivotIndex];
	int i = left, j = right;
	while (i <= j) {
		while (values[i] < pivotValue) {
			i++;
		}
		while (values[j] > pivotValue) {
			j--;
		}
		if (i <= j) {
			swap(values[i], values[j]);
			i++;
			j--;
		}
	}
	return i;
}


void QuickSort(vector<double>& a, int Left, int Right)
{
	while (Left < Right)
	{
		int iPivot = Partition(a, Left, Right);
		if (iPivot - Left <= Right - (iPivot + 1))
		{
			QuickSort(a, Left, iPivot - 1);
			Left = iPivot + 1;
		}
		else
		{
			QuickSort(a, iPivot, Right);
			Right = iPivot - 1;
		}
	}
}

