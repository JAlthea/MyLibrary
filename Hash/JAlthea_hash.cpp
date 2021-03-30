#include <cmath>
#include <algorithm>
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

