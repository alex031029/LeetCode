// O(n) solution

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        
        // find a possible candidate
        int candidate = 0;
        for(int i=1;i<n;i++)
        {
            if(knows(candidate,i))
                candidate = i;
        }
        
        // check if the candidate fits the definition of celebrity
        for(int i=0;i<n;i++)
        {
            if(i==candidate)
                continue;
            if(!knows(i,candidate)||knows(candidate,i))
                return -1;
        }
        return candidate;
    }
};
