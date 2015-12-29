/*
 * q01.cpp
 *
 *  Created on: Dec 29, 2015
 *      Author: Pourya Shirazian
 *
 *  Q: Given two sorted lists of integer numbers, write an algorithm that merges and sorts those lists into one
 *  output list in linear time.
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
	if (argc != 3) {
		printf("Supply two arrays in the format of [1,2,3,...] [4,6,7,...]\n");
		return -1;
	}

	std::istringstream s1(argv[1]);
	std::istringstream s2(argv[2]);

	string v1 = s1.str();
	string v2 = s2.str();

	if (v1[0] != '[' || v1[v1.length() - 1] != ']') {
		printf("Array 1 should start with [ and end with ] \n");
		return -1;
	}

	if (v2[0] != '[' || v2[v2.length() - 1] != ']') {
		printf("Array 2 should start with [ and end with ] \n");
		return -1;
	}

	v1 = v1.substr(1, v1.length() - 2);
	v2 = v2.substr(1, v2.length() - 2);

	cout << "First array is: " << v1 << endl;
	cout << "Second array is: " << v2 << endl;

	//list of first and second ints
	vector<int> vlist1;
	vector<int> vlist2;

	comma_delimited_to_vector<int>(v1, vlist1);
	comma_delimited_to_vector<int>(v2, vlist2);

	printf("I detected %d numbers in first list and %d in second\n",
			(int) vlist1.size(), (int) vlist2.size());

	vector<int> output;
	output.reserve(vlist1.size() + vlist2.size());

	unsigned int i1 = 0;
	unsigned int i2 = 0;


	for(;;) {
		if(i1 == vlist1.size()) {
			//notice that we append the second list to output starting at location pointed to by i2
			output.insert(output.end(), vlist2.begin() + i2, vlist2.end());
			break;
		}
		else if(i2 == vlist2.size()) {
			//and here we append the first list to output starting at location pointed to by i1
			output.insert(output.end(), vlist1.begin() + i1, vlist1.end());
			break;
		}
		else {
			if(vlist1[i1] <= vlist2[i2]) {
				output.push_back(vlist1[i1]);
				i1++;
			}
			else {
				output.push_back(vlist2[i2]);
				i2++;
			}
		}
	}


	ostringstream os;
	os << "[";

	for(int i=0; i < (int)output.size(); i++) {
		os << output[i];
		if(i < (int)(output.size() - 1))
			os << ",";
	}

	os << "]";

	cout << "output vector is: " << os.str() << endl;

	return 0;
}

