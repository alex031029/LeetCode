// recursive method
// the tricky part is about a lot of caseas

class Solution {
public:
    // vector<string> words = {"", "enO", "owT", "eerhT", "ruoF", "eviF", "xiS", "neveS", "thgiE", "eniN", "neT", "nevelE", "evlewT", "neetrihT", "neetruoF", "neetfiF", "neetxiS", "neetneveS", "neethgiE", "neeteniN", "ytenwT", "ytirhT", "ytroF", "ytfiF", "ytxiS", "ytneveS", "ythgiE", "yteniN", "derdnuH", "dnasuohT", "noilliM", "noilliB"};
    // I used to think of use a reversed string to reduce time overhead
    
    vector<string> words = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", "Hundred", "Thousand", "Million", "Billion"};

    vector<int> nums = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,80,90,100,1000,1000000,1000000000};
    
    // base case; it works when num<10,000
    string helper(int num){
        if(num==0)
            return "";
        string ret;
        for(int i=words.size()-3;i>=1;i--)
        {
            if(num>=nums[i])
            {
                int digit = num/nums[i];
                num = num%nums[i];
                // cout<<digit<<"\t"<<num<<endl;
                if(nums[i]>=100)
                    ret = ret + words[digit] + " " + words[i] + " ";
                else if(nums[i]>=20)
                    ret = ret + words[i] + " ";
                else 
                    ret = ret + words[i] + " ";
            }
        }
        ret.pop_back();
        return ret;
    }
    // it works for numbers smalleer than 1,000,000 
    string helperThousands(int num)
    {
        if(num<10000)
            return helper(num);
        else
            return helper(num/1000) + " Thousand " + helper(num%1000);
    }
    // it works for numbers smaller than 1,000,000,000
    string helperMillions(int num)
    {
        if(num>=1000000)
            return helperThousands(num/1000000) + " Million " +helperThousands(num%1000000);
        else
            return helperThousands(num%1000000);
    }
    
    // it works for numbers no less than 1,000,000,000
    string helperBillions(int num)
    {
        return helperThousands(num/1000000000) + " Billion " + helperMillions(num%1000000000);
    }
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        
        string ret;
        if(num < 10000)
            ret = helper(num);
        else if(num<1000000)
            ret = helperThousands(num);
        else if(num<1000000000)
            ret = helperMillions(num);
        else 
            ret = helperBillions(num);
        if(ret.back()==' ')
            ret.pop_back();
        return ret;

    }
};
