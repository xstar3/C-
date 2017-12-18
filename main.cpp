//
// Created by Zhxc on 2017.
//
#include <iostream>
#include <cstdlib>
#include <vector>
#include "TestHelper.h"

using namespace std;

//第一个思路：类似冒泡算法，前偶后奇数就交换，复杂度为O（n2）
void reOrderArray1(vector<int> *array){
	for (int i = 0; i < (*array).size(); ++i){
		for (int j = 0; j < (*array).size() - 1; ++j){
			if ((*array)[j] % 2 == 0 && (*array)[j + 1] % 2 == 1){
				swap((*array)[j], (*array)[j + 1]);
			}
		}
	}
}

//第二个思路：再创建一个数组，复杂度为O（n）
void reOrderArray2(vector<int> *array) {
	vector<int> vec1, vec2;
	for (auto i : (*array)){
		if (i % 2 == 1){
			vec1.push_back(i);
		}
		else{
			vec2.push_back(i);
		}
	}
	(*array).clear(); // 先清空
	for (auto i = 0; i < vec1.size(); ++i){
		(*array).push_back(vec1[i]);
	}
	for (auto i = 0; i < vec2.size(); ++i){
		(*array).push_back(vec2[i]);
	}
}

for (decltype(vec.size() i = 0; i != 10; ++i){
	vec[i] = i; // 严重错误： vec不包含任何元素！！
}

int main(){
	int n = 1000;
	vector<int>* array1 = TestHelper::generateRandomArray(n, 0, 100);
	vector<int>* array2 = TestHelper::copyIntArray(array1);

	cout << "调整前：" << endl;
//	TestHelper::printArray(array2);
	cout << endl;
	
	TestHelper::test("reOrderArray1", reOrderArray1, array1);
	TestHelper::test("reOrderArray2", reOrderArray2, array2);

	cout << "调整后：" << endl;

//	TestHelper::printArray(array1);
//	TestHelper::printArray(array2);

	delete[] array1;
	delete[] array2;

	cout << endl;
	system("pause");
	return 0;
}
