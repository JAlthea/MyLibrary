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

//Example
struct hashFunctor {
    unsigned operator()(const string & s) const {
        unsigned ret = 0;
        unsigned R_pow = 1;
        for (unsigned i = 0; i < s.size(); ++i) {
            ret += (s[i] - 96) * R_pow % M;
            R_pow *= R % M;
        }

        return ret % M;
    }
};

void TestHashCollision() {

    string s1 = "aabbccz";
    string s2 = "ababzcc";
    string s3 = "ababzcd";

    cout << hashFunction(s1) << '\n';
    cout << hashFunction(s2) << '\n';
    cout << hashFunction(s3) << '\n';
	
    unordered_set<string, hashFunctor> hashMap;
    hashMap.insert(s1);
    hashMap.insert(s2);
    hashMap.insert(s3);
}
