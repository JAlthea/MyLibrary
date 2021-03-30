#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;


/*
[Integer For Hash Collision Solution]
GCD(R, M) = 1
R : prime number1, M : prime number2
*/
const unsigned R = 31;
const unsigned M = 1234567891;



unsigned hashFunction(string & s) {
	unsigned ret = 0;
	unsigned long long R_pow = 1;
	for (auto & c : s) {
		ret += (c - 96) * R_pow % M;
		R_pow = R_pow * R % M;
	}

	return ret;
}

template <typename T>
enable_if_t<is_integral_v<T>, unsigned> hashFunction(vector<T> & seq) {
	unsigned ret = 0;
	unsigned long long R_pow = 1;
	for (auto & n : s) {
		ret += n * R_pow % M;
		R_pow = R_pow * R % M;
	}
    
    return ret;
}

template <typename T>
enable_if_t<is_integral_v<T>, unsigned> hashFunction(T & num) {
	unsigned ret = 0;
	unsigned long long R_pow = 1;
    
    T ret_num = num;
    while (ret_num) {
        unsigned a = ret_num % 10;
        ret_num /= 10;
        
        ret += a * R_pow % M;
        R_pow = R_pow * R % M;
    }
    
    return ret;
}



void TestHashCollision() {
	//write struct type hashFunction. i'm sleepy.
    unordered_map<string, int, hashFunction()> hashMap;
    vector<int> d = { 1, 1234, 45, 7, 11, 199, 22, 19, 101, 55555555, 77345, 918 };
	string s1 = "aabbccz";
	string s2 = "ababzcc";
	string s3 = "ababzcd";
	
	hashMap.insert(s1);
	hashMap.insert(s2);
	hashMap.insert(s3);
	cout << hashMap[s1] << '\n';
	cout << hashMap[s2] << '\n';
	cout << hashMap[s3] << '\n';
}
