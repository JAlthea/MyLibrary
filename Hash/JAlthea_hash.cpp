#include <cmath>
#include <algorithm>
using namespace std;

/*
GCD(R, M) = 1
R : prime number1, M : prime number2
*/
const unsigned R = 31;
const unsigned M = 1234567891;

unsigned hashFunction(string & st) {
    unsigned ret = 0;
    for (unsigned i = st.size() - 1; i >= 0; --i) {
        unsigned R_pow = 1;
        for (unsigned j = 0; j < i; ++j) {
            R_pow *= R;
            R_pow %= M;
        }
        
        ret += st[i] * R_pow % M;
    }
    
    return ret;
}

template <typename T>
enable_if_t<is_integral_v<T>, unsigned> hashFunction(vector<T> & seq) {
    unsigned ret = 0;
    for (unsigned i = seq.size() - 1; i >= 0; --i) {
        unsigned R_pow = 1;
        for (unsigned j = 0; j < i; ++j) {
            R_pow *= R;
            R_pow %= M;
        }
        
        ret += seq[i] * R_pow % M;
    }
    
    return ret;
}

template <typename T>
enable_if_t<is_integral_v<T>, unsigned> hashFunction(T & num) {
    unsigned ret = 0;
    T ret_num = num;
    unsigned i = 0;
    while (ret_num) {
        unsigned R_pow = 1;
        for (unsigned j = 0; j < i; ++j) {
            R_pow *= R;
            R_pow %= M;
        }
        
        unsigned a = ret_num % 10;
        ret_num /= 10;
        
        ret += a * R_pow % M;
    }
    
    return ret;
}

