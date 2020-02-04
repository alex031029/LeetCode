// I am willing to implement an FSA version 

class Solution {
public:
    struct state{
        char c;
        map<char, state*> next;
        state(char x)
        {
            c = x;
        }
    };
    state * constructStates(string p)
    {
        state * head = new state('#');
        state * cur = head;
        for(int i=0;i<p.size();i++)
        {
            state * st = new state(p[i]);

        }
    }
    bool isMatch(string s, string p) {
        
    }
};
