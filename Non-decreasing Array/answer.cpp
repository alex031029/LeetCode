// This problem is pretty trcicky, even though it is labelled as an easy one
// the trikcy part is that you may omit some special casees
// I list cases in ./cases.md for references

// this solution is referred from the discussion
// the main idea is that when nums[i-1]>nums[i], it is less risky to modify nums[i-1] instead of nums[i]
// since augumenting nums[i] may incur a cascade of error for numbers after position i
// however, if nums[i] is smaller than nums[i-2], we have no choice but enlarge nums[i]
// then we return if the number of modification is no more than 1

class Solution {
public:
    void printVector(vector<int>& nums) 
    {
        for(int i=0;i<nums.size();i++)
            cout<<i<<": "<<nums[i]<<"\t";
        cout<<endl;
    }
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<=2)
            return true;

        int flag = 0;
        for(int i=1;i<nums.size()&&flag<=1;i++)
        {
            if(nums[i]<nums[i-1])
            {
                flag++;
                
                if(i>=2&&nums[i-2]>nums[i])
                {
                    nums[i]=nums[i-1];
                }
                else
                    nums[i-1]=nums[i];
            }
            // printVector(nums);
        }
        return (flag<=1);
    }
};


// my previous answer, which is wrong
// my original though is to set up two pointers to find the non-decreasing point
// and return the answer by examining some special cases
// however, these "special cases" is pretty messy, and is damn hard to list all of them

// class Solution {
// public:
//     bool checkPossibility(vector<int>& nums) {
//         if(nums.size()<=2)
//             return true;
        
//         int previous = 0x80000000;
//         int next = 0x7fffffff;
//         int i=0;
//         int j=nums.size()-1;
//         for(;i<nums.size();i++)
//         {
//             if(nums[i]<previous)
//             {
//                 cout<<i<<nums[i]<<previous<<endl;
//                 break;
//             }
//             previous = nums[i];
//         }
//         if(i == nums.size())
//             return true;
//         for(;j>=0;j--)
//         {
//             if(nums[j]>next)
//             {
//                 cout<<j<<nums[j]<<next<<endl;
//                 break;
//             }
//             next = nums[j];
//         }
            
//         if(i!=j+1)
//             return false;
//         // if(j>0&&j<nums.size()-2&&nums[j-1]>nums[j+1])
//         //     return false;
//         else
//         {
//             if(j==0||j>nums.size()-2||i==0||i>nums.size()-2)
//                 return true;
//             bool statement1 = j>0&&j<nums.size()-2&&nums[j-1]<nums[j+1];
//             bool statement2 = i>0&&i<nums.size()-2&&nums[i-1]<nums[i+1];
//             if(statement1||statement2)
//                 return true;
//             else
//                 return false;
//         }
//     }
// };
