#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<queue>
using namespace std;

/*
输入若干单词，要求Trie数上的节点个数（别漏了根节点）
没必要建树，将所有的单词按照字典序排列后
比较后一个单词相比于前一个单词，有几个字母不同
注，是基于后一个单词比较，如果前一个单词长于后一个单词，多余部分不必比较
第一个单词就是其长度，可以预先放入一个不可能的单词
将这些差异值加起来，再加上根节点，就是总的节点数
*/

vector<string> str;

int getN(string &a,string &b)//获取b串与a串有几个字符不同
{
    int len1=a.size(),len2=b.size(),i,ans=0;
    for(i=0;i<len1&&i<len2;i++)
    {
        if(b[i]!=a[i])
        {
            break;
        }
    }
    ans+=len2-i;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int i,j,k,len,ans=0;
    string temp;
    str.reserve(10000);
    str.push_back("0");//预放一个不可能的单词
    while(cin>>temp)
    {
        str.push_back(temp);
    }
    sort(str.begin(),str.end());
    len=str.size();
    for(i=1;i<len;i++)
    {
        ans+=getN(str[i-1],str[i]);
    }
    cout<<ans+1;
    return 0;
}
