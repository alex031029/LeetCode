// a Java implementation
// it is interpreted from answer_recursive.cpp
// it is a recursive solution

class Solution {
    public List<String> generateParenthesis(int n) {
    
        // unlike C++, Java need a `new ArrayList()` statement to initialize a List
        List<String> ret = new ArrayList();
        if(n==0)
        {
            // add is a function similar to push_back() in C++
            // it can also insert an element in a particular index, like insert() funciton in C++
            ret.add("");
            return ret;
        }
        if(n==1)
        {
            ret.add("()");
            return ret;
        }
        for(int q=0;q<=n-1;q++)
        {
            List<String> temp1 = generateParenthesis(q);
            List<String> temp2 = generateParenthesis(n-1-q);

            for(int i=0;i<temp1.size();i++)
            {
                for(int j=0;j<temp2.size();j++)
                {
                    // it seems like square brackets [] operators are not supported in Java
                    // instead, a get() function is used to retrieve the element of a given index
                    String s = "("+temp1.get(i)+")"+temp2.get(j);
                    ret.add(s);
                }
            }
        }
        return ret;
    }
}
