#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>     
#include <vector> 
#include<chrono>
using namespace std;
using namespace std::chrono;

int Nhap(vector<double>&, int&, string);
int Xuat(vector<double>);
int Xuat(vector<double>, string);
void BuildHeap(vector<double>, int);
void Heapify(vector<double>, int, int);
void HeapSort(vector<double>, int);

int main()
{


	for (int i = 2; i <= 2; i++)
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

			HeapSort(b, b.size());
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

void BuildHeap(vector<double> a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(a, n, i);
}

void Heapify(vector<double> a, int n, int vt)
{
	while (vt <= n / 2 - 1)
	{
		int lc = 2 * vt + 1;
		if (lc + 1 < n && a[lc] < a[lc + 1])
			lc++;
		if (a[vt] < a[lc])
			swap(a[vt], a[lc]);
		vt = lc;
	}
}

void HeapSort(vector<double> a, int n)
{
	BuildHeap(a, n);
	int length = n;
	while (length > 1)
	{
		swap(a[0], a[length - 1]);
		length--;
		Heapify(a, length, 0);
	}
}