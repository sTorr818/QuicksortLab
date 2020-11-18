#include<iostream>
#include<vector>
#include<iomanip>
#include<chrono>
#include<Windows.h>
#include<cstdlib>
#include<algorithm>
#include<ctime>
using namespace std;

int step = 0;
void display(vector<int>& iArray)
{
	//to display the vector and see that the sorts work
	for (int x = 0; x < iArray.size(); x++)
	{
		cout << iArray[x] << " ";
	}
}
void merge(vector<int>& iArray, int begin, int mid, int end)
{

	//split in two in order to perform the merges
	vector<int>leftA(mid - begin + 1);
	vector<int>rightA(end - mid);
	step += 2;
	for (int i = 0; i < leftA.size(); ++i)
		leftA[i] = iArray[begin + i];
	step += 3;
	for (int i = 0; i < rightA.size(); ++i)
		rightA[i] = iArray[mid + 1 + i];
	step += 3;
	int l = 0, r = 0;
	step = +2;
	int main = begin;
	step++;
	while (l < leftA.size() && r < rightA.size())
	{
		step += 2;
		if (leftA[l] <= rightA[r]) {
			iArray[main] = leftA[l];
			l++;
			step += 2;
		}
		else {
			iArray[main] = rightA[r];
			r++;
			step += 2;
		}
		main++;
		step++;
	}
	//gotta combine the sides
	while (l < leftA.size())
	{
		iArray[main++] = leftA[l++];
		step + 2;
	}
	while (r < rightA.size())
	{
		iArray[main++] = rightA[r++];
		step += 2;
	}
}
void mergeSort(vector<int>& iArray, int begin, int end)
{
	int mid;
	step++;
	if (begin < end)
	{
		mid = (end + begin) / 2;
		mergeSort(iArray, begin, mid);
		mergeSort(iArray, mid + 1, end);
		merge(iArray, begin, mid, end);
		step += 4;
	}
}
void insertionSort(vector<int>& iArray)
{
	int num, spot;
	step++;
	for (int i = 0; i < iArray.size(); i++)
	{
		num = i;
		step += 3;
		while (num > 0 && iArray[num - 1] > iArray[num])
		{
			step += 2;
			spot = iArray[num];
			iArray[num] = iArray[num - 1];
			iArray[num - 1] = spot;
			num--;
			step += 3;
		}
	}
}

void heapMax(vector<int>& iArray, int i, int x)
{
	int highestNum;
	//Obtaining variable to use in comparisons
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	step += 3;
	//compare with l
	if (l < x && iArray[l] > iArray[i])
		highestNum = l;
	else
		highestNum = i;
	step += 2;
	//compare with r
	if (r < x && iArray[r] > iArray[highestNum])
		highestNum = r;
	step += 2;
	//move on
	if (highestNum != i) {
		swap(iArray[i], iArray[highestNum]);
		heapMax(iArray, highestNum, x);
	}
	step += 2;
}
void heapSort(vector<int>& iArray)
{
	//start with this to obtain the max
	for (int i = iArray.size() / 2; i >= 0; i--)
		heapMax(iArray, i, iArray.size());
	step += 3;
	int x = iArray.size();
	step++;
	//now continue to sort the rest
	for (int i = iArray.size() - 1; i >= 0; i--)
	{
		swap(iArray[0], iArray[i]);
		x--;
		heapMax(iArray, 0, x);

	}
	step += 4;
}


//The setting up of numbers do not require counts because they are not in the process of sorting!!
void alreadySort(vector<int>& iArray, int n)
{
	for (int i = 0; i < n; i++) {
		iArray.push_back(i + 1);
	}
}
void reverselySort(vector<int>& iArray, int n)
{
	for (int i = n; i > 0; i--) {
		iArray.push_back(i);
	}
}

void randPerm(vector<int>& iArray, int n)
{
	for (int i = 0; i < n; i++) {
		iArray.push_back(i + 1);
	}
	random_shuffle(iArray.begin(), iArray.end());
}

void rand(vector<int>& arr, int n)
{
	int num;
	for (int i = 0; i < n; i++)
	{
		num = 1 + rand() % n;
		arr.push_back(num);
	}
}

int main()
{

	vector<int> iArray = {};
	//n will become a vector since a normal array requires a const
	vector<int> nArray = { 100,200,300,400,500,1000,4000,10000 };
	for (int i = 0; i < nArray.size(); i++)
	{
		cout << "These are the CPU running times for n at the value of " << nArray[i] << "." << endl;

		//Part1 - already sort
		alreadySort(iArray, nArray[i]);
		chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
		insertionSort(iArray);
		chrono::steady_clock::time_point t2 = chrono::steady_clock::now();

		chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Insertion for Already Sorted took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / pow(nArray[i], 2));
		cout << std::endl;
		step = 0;
		iArray.clear();
		alreadySort(iArray, nArray[i]);
		t1 = chrono::steady_clock::now();
		mergeSort(iArray, 0, static_cast<int>(iArray.size() - 1));
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Merge for already sorted took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / (nArray[i] * log(nArray[i])));
		cout << std::endl;
		step = 0;
		iArray.clear();
		alreadySort(iArray, nArray[i]);
		t1 = chrono::steady_clock::now();
		heapSort(iArray);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Heap for Already Sorted took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / pow(nArray[i], 2));
		cout << std::endl;
		step = 0;

		//Part2 - Reverse Sort
		iArray.clear();
		reverselySort(iArray, nArray[i]);
		t1 = chrono::steady_clock::now();
		insertionSort(iArray);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
		cout << "Insertion for reversely sorted took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / pow(nArray[i], 2));
		cout << std::endl;
		step = 0;
		iArray.clear();
		reverselySort(iArray, nArray[i]);
		t1 = chrono::steady_clock::now();
		mergeSort(iArray, 0, static_cast<int>(iArray.size() - 1));
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Merge for reversely sorted took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / (nArray[i] * log(nArray[i])));
		cout << std::endl;
		step = 0;
		iArray.clear();
		reverselySort(iArray, nArray[i]);
		t1 = chrono::steady_clock::now();
		heapSort(iArray);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Heap for reversely sorted took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / (nArray[i] * log(nArray[i])));
		cout << std::endl;
		step = 0;

		//Part3 - Random Permutation
		iArray.clear();
		randPerm(iArray, nArray[i]);
		t1 = chrono::steady_clock::now();
		insertionSort(iArray);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Insertion for randomn permutation took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / pow(nArray[i], 2));
		cout << std::endl;
		step = 0;
		iArray.clear();
		randPerm(iArray, nArray[i]);
		t1 = chrono::steady_clock::now();
		mergeSort(iArray, 0, static_cast<int>(iArray.size() - 1));
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Merge for random permutation took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / (nArray[i] * log(nArray[i])));
		cout << std::endl;
		step = 0;
		iArray.clear();
		randPerm(iArray, nArray[i]);
		t1 = chrono::steady_clock::now();
		heapSort(iArray);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Heap for random permutation took " << time_span.count() << " seconds in " << step << " steps with an approximation of c at " << (step / (nArray[i] * log(nArray[i])));
		cout << std::endl;
		step = 0;

		//Part4 - 50 instances of n random numbers
		int total = 0, total2 = 0, total3 = 0, countStep = 0, countStep2 = 0, countStep3 = 0;
		for (int y = 0; y < 50; y++)
		{
			iArray.clear();
			rand(iArray, nArray[i]);
			t1 = chrono::steady_clock::now();
			insertionSort(iArray);
			t2 = chrono::steady_clock::now();

			time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
			total = time_span.count() + total;
			countStep += step;
			iArray.clear();
			rand(iArray, nArray[i]);
			t1 = chrono::steady_clock::now();
			mergeSort(iArray, 0, static_cast<int>(iArray.size() - 1));
			t2 = chrono::steady_clock::now();

			time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
			total2 = time_span.count() + total2;
			countStep2 += step;
			iArray.clear();
			rand(iArray, nArray[i]);
			t1 = chrono::steady_clock::now();
			heapSort(iArray);
			t2 = chrono::steady_clock::now();

			time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
			total3 = time_span.count() + total2;
			countStep3 += step;
		}

		//time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Insertion for 50 instances of random took " << total << " seconds in " << countStep << " steps with an approximation of c at " << (step / pow(nArray[i], 2));
		cout << std::endl;


		//time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

		cout << "Merge for 50 instances of random took " << total2 << " seconds in " << countStep2 << " steps with an approximation of c at " << (step / (nArray[i] * log(nArray[i])));
		cout << std::endl;
		step = 0;

		cout << "Heap for 50 instances of random took " << total3 << " seconds in " << countStep3 << " steps with an approximation of c at " << (step / (nArray[i] * log(nArray[i])));
		cout << std::endl << endl << endl;
		step = 0;


	}
	system("pause");
	return 0;
};