// an FSA solution with some early termination optimizations

class Solution {
public:
    struct state{
        char c;
        map<char, vector<state*>> next;
        bool end = false;
        state(char x)
        {
            c = x;
        }
    };
    state * constructStates(string p, int offset)
    {
        state * head = new state('#');
        state * cur = head;
        state * prev = cur;
        if(offset > p.size())
            return head;
        for(int i=offset;i<p.size();i++)
        {
            if(p[i]=='*')
            {
                cur->next[cur->c].push_back(cur);
                prev->next['$'].push_back(cur);
            }
            else
            {
                state * st = new state(p[i]);
                // if(cur->next.find(p[i])==cur->next.end())
                //     cur->next[p[i]] = st;
                // else
                //     cur->next[p[i]-'a'+'A'] = st;
                cur->next[p[i]].push_back(st);
                prev = cur;
                cur = st;
            }    
        }
        cur->end = true;
        return head;
    }
    bool helper(string s, state * cur, int offset)
    {
        // cout<<offset<<cur->c<<cur->end<<endl;
        if(offset>=s.size()&&cur->end)
            return true;
        if(offset>=s.size())
        {
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
