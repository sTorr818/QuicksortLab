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

void quickSort(vector<int>& iArray)
{

}



int main()
{

	vector<int> iArray = {};
	//n will become a vector since a normal array requires a const
	vector<int> nArray = { 100,200,300,400,500,1000,4000,10000 };
	for (int i = 0; i < nArray.size(); i++)
	{
		


	}
	system("pause");
	return 0;
};