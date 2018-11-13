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
int main()
{
	string text,pattern;
	cin>>text>>pattern;
	int n=text.length(),m=pattern.length();
	string t=text,p=pattern;
	int lps[pattern.length()];
	preKMP(pattern,lps);
	int sigma=3;
	int delta[m+1][sigma];
	for(int j=0;j<sigma;j++)
	{
		delta[0][j]=0;
	}
	delta[0][p[0]-'a']=1;
	for(int q=1;q<=m;q++)
	{
		for(int j=0;j<sigma;j++)
		{
			if(q==m||p[q]!=j+'a')
			{
				delta[q][j]=delta[lps[q-1]][j];
			}
			else
			{
				delta[q][j]=q+1;
			}
			//cout<<delta[q][j]<<" ";
		}//cout<<endl;
	}
	int q=0;
	for(int i=0;i<n;i++)
	{
		q=delta[q][t[i]-'a'];
		if(q==m)
		{
			cout<<"occurs at shift= "<<i-m+1<<endl;
		}
		else
		{
			cout<<q<<" chars match at shift= "<<i-q+1<<endl;
		}
	}
}
/*
aabaabacabaacbaaaba
*/	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
