// design a prefix tree for the input method

struct Node
{
	char c; // unnecessary; can be removed
  // next can be based on 2~9 instead of letters
	// vector<Node*> next(26);
	vector<Node*> next2(8);
  // a list of Chinese characters
	vector<string> characters;
	bool end;
	Node(char& x);c(x),end(false){
		for(int i=0;i<26;i++)
		{
			next[i] = NULL;
		}
	}
}

class PrefixTree
{
	Node * head;
	void insert(string& s, string& character)
	{
		Node * p = head;
		for(int i=0;i<s.size();i++)
		{
			if(p->next[s[i]-'a']==NULL)
			{
				Node * temp = new Node(s[i]);
				p->next[s[i]-'a'] = temp;
				p = temp;
			}
			else
				p = p->next[s[i]-'a']
		}
		p->characters.push_back(character);
		p->end = true;
	}
	void check(string& s)
	{
		Node * p = head;
		for(int i=0;i<s.size();i++)
		{
			if(p->next[s[i]-'a']==NULL)
				return false;
			p = p->next[s[i]-'a'];
		}
		return p->end;
	}
	void prefixCheck(string& s)
	{
		Node * p = head;
		for(int i=0;i<s.size();i++)
		{
			if(p->next[s[i]-'a']==NULL)
				return false;
			p = p->next[s[i]-'a'];
		}
		return true;
	}
	PrefixTree()
	{
		head = new Node('$');
	}
}
