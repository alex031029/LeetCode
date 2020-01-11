class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // a hash to store the relationship of parentheses
        char hash[128];
        hash['(']=')';
        hash['[']=']';
        hash['{']='}';
        for(int i=0;i<s.size();i++)
        {
            // cout<<s[i]<<endl;
            switch(s[i])
            {
                case '(':
                case '{':
                case '[':
                    // cout<<"case left"<<endl;
                    st.push(s[i]);
                    break;
                case ')':
                case '}':
                case ']':
                    // cout<<"case right"<<endl;
                    if(st.empty()||hash[st.top()]!=s[i])
                        return false;
                    st.pop();
                    break;
                // default:
                //    return false;
            }
        }
        // return true if the stack is empty
        return st.empty();
        
    }
};
