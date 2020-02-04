// an NFA solution with some early termination optimizations
// the optimizations can return a false by some coarse determination functions 
// withouth these optimizations, this code cannot be accepted by LeetCode due to time limit

class Solution {
public:
    // state
    struct state{
        // the accepted char
        char c;
        // the transition function.
        // since it is an NFA solution
        // given a states and a input char c, the possible next states can be multiple
        map<char, vector<state*>> next;
        // if it is an end state
        bool end = false;
        state(char x)
        {
            c = x;
        }
    };
    // generate the NFA for p
    // offset is not implemented yet
    state * constructStates(string p, int offset)
    {
        state * head = new state('#');
        state * cur = head;
        state * prev = cur;
        if(offset > p.size())
            return head;
        for(int i=offset;i<p.size();i++)
        {
            // the '$' is used as epsilon in NFA
            // when p[i] is *, we first add an edge pointing to itself
            // then add an epsilon edge from the previous state to the current one
            if(p[i]=='*')
            {
                cur->next[cur->c].push_back(cur);
                prev->next['$'].push_back(cur);
            }
            else
            {
                state * st = new state(p[i]);
                cur->next[p[i]].push_back(st);
                prev = cur;
                cur = st;
            }    
        }
        // only the last state can be accepted
        cur->end = true;
        return head;
    }
    // helper is called recursively to find if there exists an path return true
    bool helper(string s, state * cur, int offset)
    {
        // cout<<offset<<cur->c<<cur->end<<endl;
        if(offset>=s.size()&&cur->end)
            return true;
        if(offset>=s.size())
        {
            // iff offset = s.size, it is possible that there exists an epsilon path pointing to the end
            if(cur->next.find('$')!=cur->next.end())
            {
                auto next = cur->next['$'];
                // cout<<"case wild card:"<<next.size()<<endl;
                for(int j=0;j<next.size();j++)
                {
                    if(helper(s, next[j], offset))
                        return true;
                }
            }
            return false;
        }
        
        int i = offset;
        // case 1: s[i] is a normal char
        if(cur->next.find(s[i])!=cur->next.end())
        {
            auto next = cur->next[s[i]];
            // cout<<"case normal:"<<next.size()<<endl;
            for(int j=0;j<next.size();j++)
            {
                if(helper(s, next[j], offset+1))
                    return true;
            }
        }
        
        // case 2: s[i] is wild card .
        if(cur->next.find('.')!=cur->next.end())
        {
            auto next = cur->next['.'];
            // cout<<"case wild card:"<<next.size()<<endl;
            for(int j=0;j<next.size();j++)
            {
                if(helper(s, next[j], offset+1))
                    return true;
            }
        }
        // case 3: s[i] has epsilon edge
        if(cur->next.find('$')!=cur->next.end())
        {
            auto next = cur->next['$'];
            // cout<<"case epsilon:"<<next.size()<<endl;
            for(int j=0;j<next.size();j++)
            {
                if(helper(s, next[j], offset))
                    return true;
            }
        }
        return false;
    }
    
    // an early termination
    // check if p has corresponding letter for lettes in s
    bool quickFalse1(string s, string p) 
    {
        sort(s.begin(),s.end());
        sort(p.begin(),p.end());
        for(int i=0;i<p.size();i++)
        {
            if(p[i]=='.')
                return true;
        }
        int i = s.size()-1;
        int j = p.size()-1;
        while(i>=0&&j>=0)
        {
            if(s[i]!=p[j])
                j--;
            else
            {
                i--;
            }
        }
        if(i>=0&&s[i]!=p[0])
            return false;
        return true;
    }
    
    // an early determination 
    // from the ends of s and p, if each letter are corresponding (without considering *)
    bool quickFalse2(string s, string p)
    {
        int i=s.size()-1, j=p.size()-1;
        while(i>=0&&j>=0)
        {
            if(p[j]=='*')
                return true;
            if(s[i]!=p[j]&&p[j]!='.')
                return false;
            i--;
            j--;
        }
        return true;
    }
    bool quickFalse(string s, string p)
    {
        if(s.empty())
            return true;
        return quickFalse1(s,p)&&quickFalse2(s,p);
    }
    // int prune(string s, string p)
    // {
    //     if(s.empty())
    //         return 0;
    //     for(int i=0;i<p.size();i++)
    //     {
    //         if(p[i]==s[0]||p[i]=='.')
    //             return i;
    //     }
    //     return INT_MAX;
    // }
    bool isMatch(string s, string p) {

        // int offset = prune(s,p);
        // cout<<offset<<endl;
        state * head = constructStates(p,0);
        state * cur = head;
        if(!quickFalse(s, p))
        {
            // cout<<"quick false"<<endl;
            return false;
        }
        return helper(s, cur, 0);
    }
};
