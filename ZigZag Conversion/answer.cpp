class Solution {
public:
    stringc convert(string s, int numRows) {
        // return the s if numRows == 1
        if(numRows == 1)
        {
            return s;
        }
        // initilize an arry of strings to store the result
        const int constRows = numRows;
        string ret[constRows];
        int divisor = numRows*2-2;
        for(int i=0;i<s.size();i++)
        {
            int cnt = i%divisor;
            int halfDivisor = numRows-1;
            int row = (cnt/halfDivisor==0)?cnt%halfDivisor:(numRows-1-cnt%halfDivisor);
            ret[row]+=s[i];
        }
        // return a merged string from ret[] using lambda function
        return [&]()->string
        { string r; 
         for(int i =0;i<constRows;i++) 
         {
             cout<<i<<"\t"<<ret[i]<<endl;
             r+=ret[i]; 
         }
         return r;}();
        
    }
};
