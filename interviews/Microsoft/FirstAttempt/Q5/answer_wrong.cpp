

// the tricky part is to design a proper DFS

// map<string,bool> hash;

void toSmallLetter(char& c)
{
	if(c>='A'&&c<='Z')
		c = c - 'A' +'a';
}


// abc ab!c !!!abc!!!def!!!ghi!!! ! !xyz! gh!!i gh!i   g!h!i 
// 1    1         3    				  1     2    1       2
 
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
		// int cnt = 0;
		bool flagExclaimer = false;
		bool flagLetter = false;
		while(cur<s.size()&&s[cur]!=' ')
		{
			if(s[cur]=='!'&&!flagExclaimer)
			{
				flagExclaimer = true;
			}
			else if(flagExclaimer&&s[cur]!='!')
			{
				flagLetter = true;
			}
			else if(flagExclaimer&&flagLetter)
			{
				flagExclaimer = false;
				flagLetter = false;
				ret++;
			}
			cur++;
		}
		if()
		ret++;
		pre = cur;
		while(pre<s.size()&&s[pre]==' ')
		{
			pre++;
		}
		cur = pre;
	}
	if(pre!=cur)
		ret++;

	return ret;
}
