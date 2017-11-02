#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
typedef __int64 ll;
#define maxn 200005
map<string,int>q;
string s[maxn];
int parent[maxn],relation[maxn];
int find (int x){
	if(parent[x]==x)
		return x;
	int tmp=parent[x];
	parent[x]=find(parent[x]);
	relation[x]=(relation[x]+relation[tmp])%2;
	return parent[x];
}
int  main()
{
	int n,m,p,i,z;
	string s1,s2;
	scanf("%d%d%d",&n,&m,&p);
	for(i=1;i<=n;i++)
	{
		cin >> s[i];
		q[s[i]]=i;
		parent[i]=i;
		relation[i]=0;
	}
	for(i=1;i<=m;i++)
	{
		cin >> z >> s1 >> s2;
		z--;
		int x=q[s1],y=q[s2];
		int t1=find(x),t2=find(y);
		if(t1!=t2)
		{
			parent[t2]=t1;
			relation[t2]=(z+relation[x]-relation[y])%2;
			printf("YES\n");
		}
		else
		{
			int tmp=(2+relation[x]-relation[y])%2;
			if(z!=tmp)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
	for(i=1;i<=p;i++)
	{
		cin >> s1 >> s2;
		int x=q[s1],y=q[s2];
		int t1=find(q[s1]);
		int t2=find(q[s2]);
		if(t1!=t2)
			printf("3\n");
		else
		{
			int ans=(2+relation[x]-relation[y])%2;
			printf("%d\n",ans+1);
		}
	}
}