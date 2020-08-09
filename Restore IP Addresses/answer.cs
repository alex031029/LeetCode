// interpretted from c++ version
// a brute and force solution

public class Solution {
    public IList<string> RestoreIpAddresses(string s) {
        IList<string> ret = new List<string>();
        for(int a=1;a<4;a++)
        {
            for(int b=1;b<4;b++)
            {
                for(int c=1;c<4;c++)
                {
                    for(int d=1;d<4;d++)
                    {
                        if(a+b+c+d!=s.Length)
                            continue;
			// Convert is necessary 
			// otherwise LeetCode would raise an error
			int s1 = Convert.ToInt32(s.Substring(0, a));
                        int s2 = Convert.ToInt32(s.Substring(a, b));
                        int s3 = Convert.ToInt32(s.Substring(a + b, c));
                        int s4 = Convert.ToInt32(s.Substring(a+b+c));
                        if(s1<=255&&s2<=255&&s3<=255&&s4<=255)
                        {
                            // it is to remove the meaning less 0 in the integers 
			    // and similarly, Convert cannot be omitted
                            string ip = Convert.ToString(s1)+'.'+Convert.ToString(s2)+'.'+Convert.ToString(s3)+'.'+Convert.ToString(s4);
                            if(ip.Length == s.Length+3)
                                ret.Add(ip);
                        }
                    }
                }
            }
        }
        return ret; 
    }
}
