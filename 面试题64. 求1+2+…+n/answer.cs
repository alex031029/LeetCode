// similar to c++ version, but this cversion has some notable difference

public class Solution {
    public int SumNums(int n) {
        // if we use a temporary variable here, it should be initialized
        // otherwise, an error would be raised
        
        int temp = 0;
        
        // the boolean variable b, although is not used, cannot be omitted
        // it is because C# forbids a boolean expression as a statement
        bool b = ((n != 0) && ((temp = SumNums(n-1) + n)>0));
        return temp;
    }
}
