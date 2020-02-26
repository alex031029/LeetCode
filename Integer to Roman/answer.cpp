// a greedy algorithm

class Solution {
public:
    string intToRoman(int num) {
        if(num==0)
            return "";
        string ret;
        
        // possibl decimal expression and corresponding roman expression
        int decimal[] =  {1000,900,500, 400, 100, 90, 
        50,  40, 10,   9,  5,   4,   1};
        string roman[] = {"M","CM","D", "CD","C","XC",
        "L","XL","X","IX","V","IV","I"};
        
        // size of decimal
        const int n = sizeof(decimal)/sizeof(int);
        // cout<<n<<endl;
        int i=0;
        while(i<n)
        {
            if(num>=decimal[i])
            {
                // cout<<num<<ret<<endl;
                ret+=roman[i];
                num-=decimal[i];
                // cout<<num<<ret<<endl;
            }
            else
                i++;
        }
        return ret;
    }
};
