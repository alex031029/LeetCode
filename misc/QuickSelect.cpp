// the question is to find the k-th largest number in time complexity of O(n)
// heap solution may yield an O(nlog n) soluton in cases like k = n
// this program implements a quick sort algorithm

// I have found out the bug!
// Thanks for your time and consideration!

#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int quickSelect(int nums[], int l, int r);
int kthLargestNumber(int nums[], int l, int r, int k)
{

    if( (r-l < k -1)|| (k < 0))
    {
        return 0x7fffffff;
    }

    int pivot = quickSelect(nums, l, r);

    // the bug is here. I should compare k-1 with pivot-l instead of pivot
    // this bug yields the error when entering the else statement
    if(pivot -l == k-1)
        return nums[pivot];
    if(pivot -l > k-1)
    {
        cout <<"pivot" << pivot<< "k:" << k <<endl;
        return kthLargestNumber(nums, l, pivot-1, k);
    }
    else
        // the else statement is also wrong for the 3rd parameter, which should be k-(pivot-l)-1
        return kthLargestNumber(nums, pivot+1, r, k-(pivot-l)-1);

}


void swap(int nums[], int x, int y)
{
    int temp = nums[x];
    nums[x] = nums[y];
    nums[y] = temp;
    return;
}

int quickSelect(int nums[], int l, int r)
{
    if(l==r)
        return l;
    int pivot = nums[r];
    int ret = l;
    for(int i=l;i<=r-1;i++)
    {
        if(nums[i]>=pivot)
        {
            swap(nums, ret, i);
            ret++;
        }
    }
    swap(nums, ret, r);
    return ret;
}

int main()
{
    int nums[] = {5,4,3,1,6,8};
    cout<<kthLargestNumber(nums, 0, 5, 5)<<endl;
}
