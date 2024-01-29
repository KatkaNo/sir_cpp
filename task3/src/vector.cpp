#include <iostream>
#include "vector.h"
#include <vector>
#include <algorithm>

using namespace std;

void vector(std::vector<float>& v, float c) {
	int i = 0;
	while (i < v.size()) {
		if (v[i] < 0 || v[i] < c)
			v.erase(v.begin() + i);
		else
			i++;
	}
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}

void vector(std::vector<int>& vec) {
	vector<int> v;
	for (int j : vec) {
		if (j % 2 == 0) {
			v.push_back(j);
		}
	}
	vec.insert(vec.end(), v.begin(), v.end());
	for (int j : vec) {
		cout << j << " ";
	}
}