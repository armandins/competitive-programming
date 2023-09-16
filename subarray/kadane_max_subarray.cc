/*
 -----------------------------------
 ------------Algorithm--------------
 -----------------------------------
	A program to find the maximum sub-array of an array using Kadane's algorithm.

	- To demonstrate how the algorithm works :
		1. We will keep track of the array using two integers: maxSofar and currentSum
		2. Since negative numbers in give array will always result in lower amount of sum, 
		   we will try to ignore them when we can, meaning if both currentSum and maxSofar
		   are negative, we'll start fresh from the next index.

		3. Take a look at the example below: 
			arr[] = {-2 , 1, -3, 4, -1, 2, 1, -5, 4}
			different sub-array cases:
			{-2} ,          {1, -3}, 		{4, -1, 2, 1,   -5, 4}
			 |                 |            	   |
			start fresh		start fresh		keep going but till 1

			answer will be 6. 


*/	

#include <iostream>
#include <vector>
using namespace std;

int maxSubarr(vector<int> nums){
	int maxSoFar = nums[0];
	int currentSum = nums[0];

	for (int i = 1; i < int(nums.size()); i++){
		if (currentSum < 0)
			currentSum = 0;

		currentSum = currentSum + nums[i];
		if (currentSum > maxSoFar)
			maxSoFar = currentSum;
	}

	return maxSoFar;
}

// -----------------------------------
// -------------Example---------------
// -----------------------------------

int main(){
	vector<int> A {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << maxSubarr(A) << '\n';
}
