// several tricky cases have failed my several submissions

class Solution {
public:
    // it return the a sub version number from version[left]
    int toVersion(string& version, int& left)
    {
        // 0 as default result
        if(left>=version.size())
            return 0;
        
        int pos = version.find('.', left);
        // cout<<version.substr(left, pos - left);
        
        // if the sub version is last version number
        if(pos>=version.size())
        {
            int ret = stoi(version.substr(left), NULL);
            left = int(version.size());
            return ret;
        }
        else
        {
            int ret = stoi(version.substr(left, pos-left), NULL);
            left = pos +1;
            return ret;
        }
        // return 0;
    }
    int compareVersion(string version1, string version2) {
        int l1 = 0;
        int l2 = 0;
        // the loop terminates when both version numbers have been fully traversed
        while(l1<version1.size()||l2<version2.size())
        {
            // cout<<l1<<l2<<endl;   
            int v1 = toVersion(version1, l1);
            int v2 = toVersion(version2, l2);
            // cout<<v1<<v2<<endl;
            if(v1>v2)
                return 1;
            else if(v1<v2)
                return -1;
        }
        // cout<<l1<<l2<<endl;
        return 0;
    }
};
