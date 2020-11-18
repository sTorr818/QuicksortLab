#include<iostream>
#include<vector>
#include <string>
#include<iomanip>
#include<chrono>
#include<Windows.h>
#include<cstdlib>
#include<algorithm>
#include<ctime>
using namespace std;

int step = 0;
void display(vector<int>& iiArrayay)
{
	//to display the vector and see that the sorts work
	for (int x = 0; x < iiArrayay.size(); x++)
	{
		cout << iiArrayay[x] << " ";
	}
}
void merge(vector<int>& iiArrayay, int begin, int mid, int end)
{

	//split in two in order to perform the merges
	vector<int>leftA(mid - begin + 1);
	vector<int>rightA(end - mid);
	step += 2;
	for (int i = 0; i < leftA.size(); ++i)
		leftA[i] = iiArrayay[begin + i];
	step += 3;
	for (int i = 0; i < rightA.size(); ++i)
		rightA[i] = iiArrayay[mid + 1 + i];
	step += 3;
	int l = 0, r = 0;
	step = +2;
	int main = begin;
	step++;
	while (l < leftA.size() && r < rightA.size())
	{
		step += 2;
		if (leftA[l] <= rightA[r]) {
			iiArrayay[main] = leftA[l];
			l++;
			step += 2;
		}
		else {
			iiArrayay[main] = rightA[r];
			r++;
			step += 2;
		}
		main++;
		step++;
	}
	//gotta combine the sides
	while (l < leftA.size())
	{
		iiArrayay[main++] = leftA[l++];
		step + 2;
	}
	while (r < rightA.size())
	{
		iiArrayay[main++] = rightA[r++];
		step += 2;
	}
}
void mergeSort(vector<int>& iiArrayay, int begin, int end)
{
	int mid;
	step++;
	if (begin < end)
	{
		mid = (end + begin) / 2;
		mergeSort(iiArrayay, begin, mid);
		mergeSort(iiArrayay, mid + 1, end);
		merge(iiArrayay, begin, mid, end);
		step += 4;
	}
}
void insertionSort(vector<int>& iiArrayay)
{
	int num, spot;
	step++;
	for (int i = 0; i < iiArrayay.size(); i++)
	{
		num = i;
		step += 3;
		while (num > 0 && iiArrayay[num - 1] > iiArrayay[num])
		{
			step += 2;
			spot = iiArrayay[num];
			iiArrayay[num] = iiArrayay[num - 1];
			iiArrayay[num - 1] = spot;
			num--;
			step += 3;
		}
	}
}

void heapMax(vector<int>& iiArrayay, int i, int x)
{
	int highestNum;
	//Obtaining variable to use in comparisons
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	step += 3;
	//compare with l
	if (l < x && iiArrayay[l] > iiArrayay[i])
		highestNum = l;
	else
		highestNum = i;
	step += 2;
	//compare with r
	if (r < x && iiArrayay[r] > iiArrayay[highestNum])
		highestNum = r;
	step += 2;
	//move on
	if (highestNum != i) {
		swap(iiArrayay[i], iiArrayay[highestNum]);
		heapMax(iiArrayay, highestNum, x);
	}
	step += 2;
}
void heapSort(vector<int>& iiArrayay)
{
	//start with this to obtain the max
	for (int i = iiArrayay.size() / 2; i >= 0; i--)
		heapMax(iiArrayay, i, iiArrayay.size());
	step += 3;
	int x = iiArrayay.size();
	step++;
	//now continue to sort the rest
	for (int i = iiArrayay.size() - 1; i >= 0; i--)
	{
		swap(iiArrayay[0], iiArrayay[i]);
		x--;
		heapMax(iiArrayay, 0, x);

	}
	step += 4;
}

int part(vector<int>& iArray, int l, int r)
{
	int random = l + rand() % (r - l);
	//In random, must swap the random attribute with r
	swap(iArray[random], iArray[r]);
	step ++;
	int pivot = iArray[r];
	int x = (l - 1);
	step += 2;
	for (int y = l; y <= r - 1; y++)
	{
		if (iArray[y] < pivot)
		{
			x++;
			//If array at i is lesser, switch with position x
			swap(iArray[x], iArray[y]);
			step ++;
		}
		step+=2;
	}
	//keep it going
	swap(iArray[x + 1], iArray[r]);
	step ++;
	return (x + 1);
}

void randomquickSort(vector<int>& iArray, int l, int r)
{
	//use while loops to continue calling the part function
	while (l < r) {
		int p = part(iArray, l, r);
		step++;
		if (p - l < r - p) {
			//now it is necessary to recall the randomquicksort
			randomquickSort(iArray, l, p - 1);
			step++;
			l = p + 1;
			step++;
		}
		else {
			//do it again like for the above 
			randomquickSort(iArray, p + 1, r);
			step++;
			r = p - 1;
			step++;
		}
		step++;
	}
	step++;
}

void quickSort(vector<int>& input, int l, int r) {
	//attain the new variables
	int p = (l + r) / 2;
	step++;
	int pivot = input[p];
	step++;
	int d = l;
	step++;
	int u = r;
	step++;
	//this loop will check conditions needed to pass off as a quicksort
	while (d <= u) {
		while (input[d] < pivot) {
			++d;
			step++;
		}
		while (input[u] > pivot) {
			--u;
			step++;
		}
		if (d <= u) {
			int tmp = input[d];
			step++;
			input[d] = input[u];
			input[u] = tmp;
			++d;
			--u;
			step += 2;
		}
		step += 2;
	}
	//recall function if needed
	if (l < u) {
		
		quickSort(input, d, u);
		step++;
	}
	step++;
	//recall if needed
	if (d < r) {
		quickSort(input, d, u);
		step++;
	}
	step += 2;
}

//The setting up of numbers do not require counts because they are not in the process of sorting!!
void alreadySort(vector<int>& iiArrayay, int n)
{
	for (int i = 0; i < n; i++) {
		iiArrayay.push_back(i + 1);
	}
}
void reverselySort(vector<int>& iiArrayay, int n)
{
	for (int i = n; i > 0; i--) {
		iiArrayay.push_back(i);
	}
}

void randPerm(vector<int>& iiArrayay, int n)
{
	for (int i = 0; i < n; i++) {
		iiArrayay.push_back(i + 1);
	}
	random_shuffle(iiArrayay.begin(), iiArrayay.end());
}

void rand(vector<int>& iArray, int n)
{
	int num;
	for (int i = 0; i < n; i++)
	{
		num = 1 + rand() % n;
		iArray.push_back(num);
	}
}


int main()
{

	vector<int> iiArrayay = {};
	//n will become a vector since a normal iArrayay requires a const
	vector<int> niArrayay = { 100,200,300,400,500,1000,4000,10000 };
	
	for (int i = 0; i < niArrayay.size(); i++)
	{
		cout << "These are the CPU running times for n at the value of " << niArrayay[i] << "." << endl;

		//Part1 - already sort
		alreadySort(iiArrayay, niArrayay[i]);
		chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
		insertionSort(iiArrayay);
		chrono::steady_clock::time_point t2 = chrono::steady_clock::now();

		chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Insertion for Already Sorted took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / pow(niArrayay[i], 2));
		cout << std::endl;
		step = 0;
		iiArrayay.clear();
		alreadySort(iiArrayay, niArrayay[i]);
		t1 = chrono::steady_clock::now();
		mergeSort(iiArrayay, 0, static_cast<int>(iiArrayay.size() - 1));
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Merge for already sorted took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / (niArrayay[i] * log(niArrayay[i])));
		cout << std::endl;
		step = 0;
		iiArrayay.clear();
		alreadySort(iiArrayay, niArrayay[i]);
		t1 = chrono::steady_clock::now();
		heapSort(iiArrayay);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Heap for Already Sorted took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / pow(niArrayay[i], 2));
		cout << std::endl;
		step = 0;


		iiArrayay.clear();
		alreadySort(iiArrayay, niArrayay[i]);
		t1 = chrono::steady_clock::now();
		quickSort(iiArrayay, 0 ,iiArrayay.size()-1);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Quicksort for Already Sorted took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / pow(niArrayay[i], 2));
		cout << std::endl;
		step = 0;

		iiArrayay.clear();
		alreadySort(iiArrayay, niArrayay[i]);
		t1 = chrono::steady_clock::now();
		randomquickSort(iiArrayay, 0, iiArrayay.size() - 1);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Randomized Quicksort for Already Sorted took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / pow(niArrayay[i], 2));
		cout << std::endl;
		step = 0;

		//Part2 - Reverse Sort
		iiArrayay.clear();
		reverselySort(iiArrayay, niArrayay[i]);
		t1 = chrono::steady_clock::now();
		insertionSort(iiArrayay);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
		cout << "Insertion for reversely sorted took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / pow(niArrayay[i], 2));
		cout << std::endl;
		step = 0;
		iiArrayay.clear();
		reverselySort(iiArrayay, niArrayay[i]);
		t1 = chrono::steady_clock::now();
		mergeSort(iiArrayay, 0, static_cast<int>(iiArrayay.size() - 1));
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Merge for reversely sorted took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / (niArrayay[i] * log(niArrayay[i])));
		cout << std::endl;
		step = 0;
		iiArrayay.clear();
		reverselySort(iiArrayay, niArrayay[i]);
		t1 = chrono::steady_clock::now();
		heapSort(iiArrayay);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Heap for reversely sorted took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / (niArrayay[i] * log(niArrayay[i])));
		cout << std::endl;
		step = 0;


		iiArrayay.clear();
		alreadySort(iiArrayay, niArrayay[i]);
		t1 = chrono::steady_clock::now();
		quickSort(iiArrayay, 0, iiArrayay.size() - 1);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Quicksort for reversely Sorted took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / pow(niArrayay[i], 2));
		cout << std::endl;
		step = 0;

		iiArrayay.clear();
		alreadySort(iiArrayay, niArrayay[i]);
		t1 = chrono::steady_clock::now();
		randomquickSort(iiArrayay, 0, iiArrayay.size() - 1);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Randomized Quicksort for reversely Sorted took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / pow(niArrayay[i], 2));
		cout << std::endl;
		step = 0;


		//Part3 - Random Permutation
		iiArrayay.clear();
		randPerm(iiArrayay, niArrayay[i]);
		t1 = chrono::steady_clock::now();
		insertionSort(iiArrayay);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Insertion for randomn permutation took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / pow(niArrayay[i], 2));
		cout << std::endl;
		step = 0;
		iiArrayay.clear();
		randPerm(iiArrayay, niArrayay[i]);
		t1 = chrono::steady_clock::now();
		mergeSort(iiArrayay, 0, static_cast<int>(iiArrayay.size() - 1));
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Merge for random permutation took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / (niArrayay[i] * log(niArrayay[i])));
		cout << std::endl;
		step = 0;
		iiArrayay.clear();
		randPerm(iiArrayay, niArrayay[i]);
		t1 = chrono::steady_clock::now();
		heapSort(iiArrayay);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Heap for random permutation took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / (niArrayay[i] * log(niArrayay[i])));
		cout << std::endl;
		step = 0;


		iiArrayay.clear();
		alreadySort(iiArrayay, niArrayay[i]);
		t1 = chrono::steady_clock::now();
		quickSort(iiArrayay, 0, iiArrayay.size() - 1);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Quicksort for random permutation took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / pow(niArrayay[i], 2));
		cout << std::endl;
		step = 0;

		iiArrayay.clear();
		alreadySort(iiArrayay, niArrayay[i]);
		t1 = chrono::steady_clock::now();
		randomquickSort(iiArrayay, 0, iiArrayay.size() - 1);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Randomized Quicksort for random permutation took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / pow(niArrayay[i], 2));
		cout << std::endl;
		step = 0;


		//Part4 - 50 instances of n random numbers
		int total = 0, total2 = 0, total3 = 0, total4 = 0, total5 = 0, countStep = 0, countStep2 = 0, countStep3 = 0, countStep4 =0, countStep5 =0;
		for (int y = 0; y < 50; y++)
		{
			iiArrayay.clear();
			rand(iiArrayay, niArrayay[i]);
			t1 = chrono::steady_clock::now();
			insertionSort(iiArrayay);
			t2 = chrono::steady_clock::now();

			time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
			total = time_span.count() + total;
			countStep += step;
			iiArrayay.clear();
			rand(iiArrayay, niArrayay[i]);
			t1 = chrono::steady_clock::now();
			mergeSort(iiArrayay, 0, static_cast<int>(iiArrayay.size() - 1));
			t2 = chrono::steady_clock::now();

			time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
			total2 = time_span.count() + total2;
			countStep2 += step;
			iiArrayay.clear();
			rand(iiArrayay, niArrayay[i]);
			t1 = chrono::steady_clock::now();
			heapSort(iiArrayay);
			t2 = chrono::steady_clock::now();

			time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
			total3 = time_span.count() + total2;
			countStep3 += step;
			iiArrayay.clear();
			rand(iiArrayay, niArrayay[i]);
			t1 = chrono::steady_clock::now();
			quickSort(iiArrayay, 0, iiArrayay.size() - 1);
			t2 = chrono::steady_clock::now();

			time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
			total4 = time_span.count() + total2;
			countStep4 += step;
			iiArrayay.clear();
			rand(iiArrayay, niArrayay[i]);
			t1 = chrono::steady_clock::now();
			randomquickSort(iiArrayay, 0, iiArrayay.size() - 1);
			t2 = chrono::steady_clock::now();

			time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
			total5 = time_span.count() + total2;
			countStep5 += step;

		}

		//time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
		cout << endl;
		cout << "Insertion for 50 instances of random took " << total << " seconds in " << countStep << " steps with an approximation of c at " << (step / pow(niArrayay[i], 2));
		cout << std::endl;


		//time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Merge for 50 instances of random took " << total2 << " seconds in " << countStep2 << " steps with an approximation of c at " << (step / (niArrayay[i] * log(niArrayay[i])));
		cout << std::endl;
		step = 0;

		cout << "Heap for 50 instances of random took " << total3 << " seconds in " << countStep3 << " steps with an approximation of c at " << (step / (niArrayay[i] * log(niArrayay[i])));
		cout << std::endl;
		step = 0;

		cout << "Quicksort for 50 instances of random took " << total4 << " seconds in " << countStep4 << " steps with an approximation of c at " << (step / pow(niArrayay[i], 2));
		cout << std::endl;
		step = 0;

		cout << "Randomized Quicksort for 50 instances of random took " << total5 << " seconds in " << countStep5 << " steps with an approximation of c at " << (step / pow(niArrayay[i], 2));
		cout << std::endl << endl << endl;
		step = 0;

	}
	system("pause");
	return 0;
};