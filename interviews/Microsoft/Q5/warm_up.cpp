// a warm up exercise
// output the number of words in a string
// the delimiter is space
// 

// map<string,bool> hash;

void toSmallLetter(char& c)
{
	if(c>='A'&&c<='Z')
		c = c - 'A' +'a';
}
 
int wordNum(string& s)
{
	int ret = 0;
	if(s.empty())
		return 0;
	int pre = 0;
	while(pre<s.size()&&s[pre]==' ')
		pre++;
	int cur = pre;
	while(cur<s.size())
	{
		while(cur<s.size()&&s[cur]!=' ')
			cur++;
		ret++;
		pre = cur;
		while(pre<s.size()&&s[pre]==' ')
			pre++;
		cur = pre;
	}
	if(pre!=cur)
		ret++;

	return ret;
}
