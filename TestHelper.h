//
// Created by Zhxc on 2017.
//

#ifndef INCTESTHELPER_H
#define INCTESTHELPER_H

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>
#include <vector>

using namespace std;

namespace TestHelper{
	// 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR]
	vector<int>* generateRandomArray(int n, int range_l, int range_r){
		vector<int>* vec;
		vec = new vector<int>[n];
//		cout << vec.size() << endl; //

		srand(time(NULL));
		for (int i = 0; i < n; ++i){
			(*vec).push_back(rand() % (range_r - range_l + 1) + range_l);
		}

		return vec;
	}

	// 拷贝整型数组a中的所有元素到一个新的数组, 并返回新的数组
	vector<int>* copyIntArray(vector<int>* vec){
		vector<int>* newvec = new vector<int>[(*vec).size()];
		for (auto i : *vec){
			(*newvec).push_back(i);
		}

		return newvec;
	}

	void printArray(vector<int>* vec){
		for (auto i : *vec){
			cout << i << " ";
		}
		cout << endl;
	}

	// 测试算法排所得到结果运行时间
	void test(const string& fcn_name, void(*array)(vector<int>* vec), vector<int>* vec){
		clock_t startTime = clock();
		array(vec);
		clock_t endTime = clock();
		cout << fcn_name << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	}
};


#endif
