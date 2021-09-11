#include <numbers.h>

//10진수(n) -> k진수
string convertN(long long n, int k) {
    string result;
    char intToChar[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    
    while (n / k) {
        result = intToChar[n % k] + result;
        n /= k;
    }
    result = intToChar[n % k] + result;
    
    return result;
}
