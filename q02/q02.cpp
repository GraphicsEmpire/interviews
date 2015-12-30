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
#include <algorithm>

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

template<typename T>
int vector_to_comma_delimited(const vector<T>& input, string& output) {
	ostringstream os;
	//os << "[";

	for(int i=0; i < (int)input.size(); i++) {
		os << input[i];
		if(i < (int)(input.size() - 1))
			os << ",";
	}

	//os << "]";

	output = os.str();

	return input.size();
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
	cout << "[Before Sort] A is: " << v1 << endl;

	int T = 0;
	s2 >> T;

	cout << "T is = " << T << endl;

	vector<int> vlist1;
	comma_delimited_to_vector<int>(v1, vlist1);

	//best sorting algorithm can do in O(nlog(n))
	std::sort(vlist1.begin(), vlist1.end());

	string v1sorted;
	vector_to_comma_delimited(vlist1, v1sorted);

	cout << "[After Sort] A is: " << v1sorted << endl;

	int i=0;
	int j=vlist1.size() - 1;
	int found = 0;

	while(i < j) {
		int a = vlist1[i];
		int b = vlist1[j];
		int sum = a + b;

		cout << " >> examine (" << a << ", " << b << ")" << endl;
		if(sum == T) {
			cout << "Output is: a = " << a << " ,b = " << b << endl;
			found ++;
			i++;
		}
		else {
			int d = abs(sum - T);
			if(d < a)
				j --;
			else
				i ++;
		}
	}

	if(found == 0)
		cout << "No pairs could be found!" << endl;

	return 0;
}
