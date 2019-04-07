#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<cstring>
 
using namespace std;
bool qp[15][15];
char out[5000][4];
int n,m;
int l=0;
int t;
inline void puc(int i)
{
	printf("%d %d %d %d\n",out[i][0],out[i][1],out[i][2],out[i][3]);
}
void cun(int i,int j,int p,int q)
{
	out[l][0]=i;
	out[l][1]=j;
	out[l][2]=p;
	out[l][3]=q;
	l++;
}
bool check()
{
	int u=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(qp[i][j])u++;
		}
	}
	if(u==1)return true;
	return false;
}
bool change()
{
	bool flag = false;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(qp[i][j])
			{
				if(qp[i+1][j]&&(!qp[i-1][j])&&i-1>0&&i+1<=n)
				{
					qp[i+1][j] = false;
					qp[i][j] = false;
					qp[i-1][j] = true;
					flag = true;
					cun(i+1,j,i-1,j);
				}
				else if(qp[i-1][j]&&(!qp[i+1][j])&&i-1>0&&i+1<=n)
				{
					qp[i-1][j] = false;
					qp[i][j] = false;
					qp[i+1][j] = true;
					flag = true;
					cun(i-1,j,i+1,j);
				}
				else if(qp[i][j+1]&&(!qp[i][j-1])&&j-1>0&&j+1<=m)
				{
					qp[i][j+1] = false;
					qp[i][j] = false;
					qp[i][j-1] = true;
					flag = true;
					cun(i,j+1,i,j-1);
				}
				else if(qp[i][j-1]&&(!qp[i][j+1])&&j-1>0&&j+1<=m)
				{
					qp[i][j-1] = false;
					qp[i][j] = false;
					qp[i][j+1] = true;
					flag = true;
					cun(i,j-1,i,j+1);
				}
			}
		}
	}
	return flag;
}
void dd(int i,int j)
{
	while(true)
	{
		j--;
		if(!qp[i][j])
		{
			cun(i,j+1,i,j);
			qp[i][j+1]=false;
			qp[i][j]=true;
		}
		else
		{
			j++;
			break;
		}
	}
	while(true)
	{
		i--;
		if(!qp[i][j])
		{
			cun(i+1,j,i,j);
			qp[i+1][j]=false;
			qp[i][j]=true;
		}
		else
		{
			i++;
			break;
		}
	}
}
void dui()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(qp[i][j])
			{
				dd(i,j);
			}
		}
	}
}
void slove()
{
	if((n==2&&m==2)||(n==1&&m==1))
	{
		printf("-1\n");
	}
	else
	{
		dui();
		while(true)
		{
			bool flag = false;
			if(check())break;
			while(change())
			{
				flag=true;
			}
			if(check())break;
			if(!flag)
			{
				if(check())break;
				else
				{
					if(qp[1][2])
					{
						qp[1][2] = false;
						qp[2][2] = true;
						cun(1,2,2,2);
					}
					if(qp[1][1])
					{
						qp[1][1] = false;
						qp[1][2] = true;
						cun(1,1,1,2);
					}
				}
			}
			else dui();
		}
		printf("%d\n",l);
		for(int i=0;i<l;i++)
		{
			puc(i);
		}
	}
}
void Init()
{
	for(int i=0;i<=m;i++)
	{
		qp[0][i]=true;
	}
	for(int i=0;i<=n;i++)
	{
		qp[i][0]=true;
	}
	char ch;
	for(int i=1;i<=n;i++)
	{
		getchar();
		for(int j=1;j<=m;j++)
		{
			ch=getchar();
			if(ch=='*')qp[i][j] = true;
			else qp[i][j] = false;
		}
	}
}
int main()
{
 
	scanf("%d",&t);
	while(t--)
	{
		l=0;
		memset(out,0,sizeof(out));
		memset(qp,0,sizeof(qp));
		scanf("%d%d",&n,&m);
		Init();
		slove();
	}
} 