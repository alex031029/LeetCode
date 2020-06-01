public class Solution {
    public IList<bool> KidsWithCandies(int[] candies, int extraCandies) {
        IList<bool> ret = new List<bool>();
        
        // find the max value of candies
        // int max = candies[0];
        // foreach(int candy in candies)
        // {
        //     if(candy>max)
        //         max = candy;
        // }

        // A LINQ method to find the max value
        int max = candies.Max();

        foreach(int candy in candies)
        {
            if(candy+extraCandies>=max)
                ret.Add(true);
            else
                ret.Add(false);
        }
        return ret;
    }
}
