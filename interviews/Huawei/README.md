# First Round

## Q1

For all prime numbers in the range `[low, high)`, we calculate the sum of the units digit and the tens digit, respectively. 
Output the smaller one。

Example:

    input: 151 158
    output: 8
    explanation:
    The prime numbers are 151 and 157. Thus, the tens digit is 5+5=10, units digit is 1+7=8
    
The only trick is that both `low` and `high` can be pretty large! Thus, I used `unsigned long long` for all integers involved in the code.    
    
## Q2

Given an string, convert all capital letters to small letters, and convert spaces to 0s.

The only trick is that this string contains space. 
Thus, we need to use `getline(cin, input)` instead of regular `cin>>input`.
