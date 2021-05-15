using namespace std;

int countBit(long long tmp) {
    int count = 0;
    
    //O(?)
    //count = __builtin_popcount(tmp);
        
    /*
    //O(logn)
    while (tmp && count <= 2) {
        count += tmp & 1;
        tmp >>= 1;
    }
    */
        
    /*
    //O(logn)
    while (tmp && count <= 2) {
        tmp &= tmp - 1;
        ++count;
    }
    */
        
    /*
    //O(logn)
    for (long long twoPow = 1; twoPow <= tmp && count <= 2; twoPow *= 2) {
        if ((tmp | twoPow) == tmp)
            ++count;
    }
    */
    
    return count;
}
