#include<bits/stdc++.h>
using namespace std;
void preKMP(string s,int lps[])
{
	int n=s.length(),index=0,i=1;
	lps[0]=0;
	while(i<n)
	{
		if(s[i]==s[index])
		{
			lps[i]=index+1;
			index++;
			i++;
		}
		else
		{
			if(index>0)
			{
				index=lps[index-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}
vector<int> KmpOccurences(string text,string pattern,int lps[])
{
	int i=0,j=0,n=text.length(),m=pattern.length();
	vector<int> ans;
	while(i<n)
	{
		if(text[i]==pattern[j])
		{
			i++;j++;
			if(j==m)
			{
				ans.push_back(i-m+1);
				j=lps[j-1];
			}
		}
		else
		{
			if(j!=0)
			j=lps[j-1];
			else
			i++;
		}
	}
	return ans;
}
int main()
{
	string text,pattern;
	cin>>text>>pattern;
	int lps[pattern.length()];
	preKMP(pattern,lps);
	vector<int> res=KmpOccurences(text,pattern,lps);
	for(int i=0;i<res.size();i++)
	{
		cout<<"at shift="<<res[i]-1<<endl;;
	}
	if(res.size()==0)
	cout<<"not found"<<endl;
	cout<<endl;
}
