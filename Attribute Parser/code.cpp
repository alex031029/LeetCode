#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int n;
int q;
string eol="$$$$$$";

map<pair<string, string>, string> json;

bool closingTag(const char s[])
{
    if(s[0]=='<'&&s[1]=='/')
    {
        return true;
    }
    return false;
}
string extractTag(const char s[], int & i)
{
    char ret[500];
    int j=0;
    for(;;i++)
    {   
        if(s[i]=='\0'||s[i]==' '||s[i]=='>')
            break;
        ret[j++]=s[i];
        // printf("%d\t%c\n",i,s[i]);
    }
    ret[j]='\0';
    //cout<<"tag"<<ret<<endl;
    return string(ret);
}

string extractAttribute(const char s[], int & i)
{
    char ret[500];
    // cout<<s<<endl;
    while(1)
    {
        // cout<<"p:"<<i<<s[i]<<endl;
        if(s[i]=='\0'||s[i]=='>')
        {
            // cout<<"eol"<<eol<<endl;
            return eol;
        }
        if(s[i]=='\"'||s[i]==' ')
        {
            i++;
            continue;
        }
        break;
    }
    //cout<<"p2"<<i<<s[i]<<endl;
    int j=0;
    for(;;i++)
    {   
        if(s[i]=='\0'||s[i]==' ')
            break;
        ret[j++]=s[i];
    }
    ret[j]='\0';
    // printf("attribute:%s\n",ret);
    //cout<<"attribute:"<<ret<<endl;
    return string(ret);
}

string extractValue(const char s[], int & i)
{
    char ret[500];
    while(1)
    {
        if(s[i]!='\"')
        {
            i++;
            continue;
        }
        break;
    }
    i++;
    int j=0;
    for(;;i++)
    {   
        if(s[i]=='\0'||s[i]==' '||s[i]=='\"')
            break;
        ret[j++]=s[i];
    }
    ret[j]='\0';
    // printf("value:%s\n",ret);
    // cout<<"value:"<<ret<<endl;
    return string(ret);
}

string mash(vector<string> v)
{
    string ret=v[0];
    for (int i=1;i<v.size();i++)
    {
        ret = ret + "." +v[i];
    }
    return ret;
}

void init()
{
    vector<string> currentTag;
    string attribute="";
    string value="";
    scanf("%d%d\n",&n,&q);
    for(int i=0;i<n;i++)
    {
        // char temp[500];
        string temp;
        // gets(temp);
        getline(cin,temp);
        // cout<<"temp:"<<temp<<endl;
        if(closingTag(temp.c_str()))
        {
            // cout<<"closeTag"<<endl;
            currentTag.pop_back();
            continue;
        }
        int p=1;
        // cout<<"!!!"<<endl;
        currentTag.push_back(extractTag(temp.c_str(),p));
        while(true)
        {
            attribute = extractAttribute(temp.c_str(), p);
            if(attribute == eol)
                break;
            value = extractValue(temp.c_str(), p);
            json[pair<string,string>(mash(currentTag),attribute)]=value;
        }
    }
}
void query()
{
    for(int i=0;i<q;i++)
    {
        string temp;
        getline(cin, temp);
        int pos = temp.find("~");
        auto x = pair<string,string>(temp.substr(0,pos-0),temp.substr(pos+1));
        if(json.find(x)!=json.end())
            cout<<json[x]<<endl;
        else
            cout<<"Not Found!"<<endl;
    }
}
void printJson()
{
    map<pair<string,string>,string>::iterator i;
    for(i=json.begin();i!=json.end();i++)
    {
        pair<string,string> key = i->first;
        string value = i->second;
        cout<<key.first<<" "<<key.second<<" "<<value<<endl;
    }

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    init();
    query();
    // printJson();
    // printf("%d,%d\n",n,q);
    return 0;
}
