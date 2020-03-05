#include<iostream>
#include<string>

using namespace std;
int greatestCommonDividend(int a, int b)
{
	if(a<b)
		greatestCommonDividend(b,a);
	if(b!=0)
		return greatestCommonDividend(b, a%b);
	else
		return a;
}

string greatestCommonFactor(string& s1, string& s2)
{
	if(s1+s2!=s2+s1)
		return "No exist";
	int x = greatestCommonDividend(s1.size(),s2.size());
	return s1.substr(0, x);
}

int main()
{
	string s1 = "abcabc";
	string s2 = "abcabcabcabc";
	cout<<greatestCommonFactor(s1,s2)<<endl;  // abcabc
	string s3 = "abc";
	string s4 = "abef";
	cout<<greatestCommonFactor(s3,s4)<<endl;  // No exist
}
