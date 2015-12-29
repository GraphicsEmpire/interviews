/*
 * q02.cpp
 *
 *  Created on: Dec 29, 2015
 *      Author: Pourya Shirazian
 *
 *  Q: Given an array of ints A and a number T. Find (if any) two pairs of numbers in A which add up to T.
 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

template<typename T>
int comma_delimited_to_vector(const string& input, vector<T>& output) {

	T i;
	istringstream ss(input);

	while (ss >> i) {
		output.push_back(i);

		if (ss.peek() == ',')
			ss.ignore();
	}

	return output.size();
}

int main(int argc, char* argv[]) {

	if(argc != 3) {
		printf("Supply array A and an integer number T as follows: [1,3,5] 8\n");
		return -1;
	}

	std::istringstream s1(argv[1]);
	std::istringstream s2(argv[2]);
	string v1 = s1.str();
	if (v1[0] != '[' || v1[v1.length() - 1] != ']') {
		printf("Array 1 should start with [ and end with ] \n");
		return -1;
	}

	v1 = v1.substr(1, v1.length() - 2);
	cout << "A is: " << v1 << endl;

	int T = 0;
	s2 >> T;

	cout << "T is = " << T << endl;

	return 0;
}
