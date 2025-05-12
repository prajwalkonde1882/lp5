#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

int main()
{
	int n;
	cout<<"enter no. of elements: ";
	cin>>n;
	
	vector<int>data(n);
	cout<<" Enter "<< n << " elemnets:\n ";
	for (int i=0; i<n; i++){
		cin>>data[i];
	}
	
	int minVal = data[0];
	int maxVal = data[0];
	long long sum = 0;
	
	#pragma omp parallel for reduction(min:minVal) reduction(max:maxVal) reduction(+:sum)
	for (int i=0; i<n; i++){
		if(data[i] < minVal) minVal = data[i];
		if(data[i] > maxVal) maxVal = data[i];
		sum +=data[i];	
	}
	
	double avg = static_cast<double>(sum) / n;
	cout<<"min"<<minVal<<"\nmax"<<maxVal<<"\nsum"<<sum<<"\nAverage"<<avg<<endl;
	
	return 0;
}

