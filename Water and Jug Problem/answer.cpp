// a mathemetical solution
// 贝祖定理
// this question equals to finding integer a and b such that ax + by = z and x + y <= z

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) 
            return false;
        if (x == 0 || y == 0) 
            return z == 0 || x + y == z;
            
        // std::gcd function
        return z % gcd(x, y) == 0;
    }
};
