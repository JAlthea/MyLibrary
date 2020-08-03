#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//integer : string -> vector<int>
vector<int> convertToBigInteger(const string &s)
{
    vector<int> result(s.size(), 0);
    for(int i=0; i<s.size(); ++i)
        result[i] = s[i] - 48;
    reverse(result.begin(), result.end());
    return result;
}

//a += b * (10^k);
void addTo(vector<int> &a, const vector<int> &b, int k)
{
    for(int i=0; i<max(b.size() + k, a.size()); ++i)
        a.push_back(0);
    
    for(int i=0; i<b.size(); ++i)
        a[i+k] += b[i];
}

//a -= b; (input : a >= b)
void subFrom(vector<int> &a, const vector<int> &b)
{
    //102, 21 => {2, 0, 1}, {1, 2}
    for(int i=0; i<b.size(); ++i)
    {
        int now = a[i] - b[i];
        if(now < 0)
        {
            while(int next=i+1; next<a.size(); ++next)
            {
                if(a[next] > 0)
                {
                    --a[next];
                    for(int between=i+1; between<next; ++between)
                        a[between] = 9;
                    a[i] += 10 - b[i];
                    break;
                }
            }
        }
        else
        {
            a[i] = now;
        }
    }
}

//calculrate integer digit rounding
void normalize(vector<int> &n)
{
    n.push_back(0);
    for(int i=0; i+1<n.size(); ++i)
    {
        if(n[i] < 0)
        {
            int borrow = (abs(n[i]) + 9) / 10;
            n[i+1] -= borrow;
            n[i] += borrow * 10;
        }
        else
        {
            n[i+1] += n[i] / 10;
            n[i] %= 10;
        }
    }
    
    while(n.size() > 1 && n.back() == 0)
        n.pop_back();
}

//extra long integer A X B, O(n^2)
//example : multiply({3, 2, 1}, {6, 5, 4}) = 123 * 456 = 56088 = {8, 8, 0, 6, 5}
vector<int> multiply(const vector<int> &a, const vector<int> &b)
{
    vector<int> result(a.size() + b.size() + 1, 0);
    for(int i=0; i<a.size(); ++i)
        for(int j=0; j<b.size(); ++j)
            result[i+j] += a[i] * b[j];
    
    normalize(result);
    return result;
}

//extra long integer A X B, O(n^log3)
vector<int> karatsuba(const vector<int> &a, const vector<int> &b)
{
    int aSize = a.size(), bSize = b.size();
    
    //swap(a, b)
    if(aSize < bSize)
        return karatsuba(b, a);
    
    //base case 1
    if(aSize == 0 || bSize == 0)
        return vector<int>();

    //base case 2
    if(aSize <= 100)
        return multiply(a, b);
        
    int half = aSize >> 1;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
    
    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);
    //a0 += a1; b0 += b1;
    addTo(a0, a1, 0); addTo(b0, b1, 0);
    
    vector<int> z1 = karatsuba(a0, b0);
    //z1 -= z0 + z2;
    subFrom(z1, z0); subFrom(z1, z2);
    
    vector<int> result;
    //result += z0 + z1 * (10^half) + z2 * (10^(2*half));
    addTo(result, z0, 0); addTo(result, z1, half); addTo(result, z2, half + half);
    return result;
}
