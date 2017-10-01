#include<bits/stdc++.h>
//=====================================================================
using namespace std;
//=====================================================================
#define opt	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//=====================================================================
#define li	int64_t
#define lli	int64_t
#define ld	double_t
#define ulli	uint64_t
//=====================================================================
#define rep(i,a,b)	for(i=a;i<b;i++)
#define repr(i,a,b)	for(i=a;i<=b;i++)
#define repi(i,v)	for(i=v.begin();i!=v.end();i++)
#define elif		else if
#define mset(a,b)	memset(a,b,sizeof(a))
#define nl		cout<<'\n'
//=====================================================================
typedef vector<int>     vi;
typedef vector<li>      vli;
typedef vector<lli>     vlli;
typedef vector<string>	vstr;
typedef pair<int,int>   pii;
typedef pair<li,li>     pli;
typedef vector<pii >    vpi;
typedef vector<pli >    vpl;
//=====================================================================
#define pb	push_back
#define pob	pop_back
#define pf	push_front
#define pof	pop_front
#define all(v)	v.begin(),v.end()
#define itr	iterator
#define sz	size()
#define lb	lower_bound
#define ub	upper_bound
#define bs	binary_search
#define mp	make_pair
#define F	first
#define S	second
//=====================================================================
#define mod	1000000007
#define inf	1000000000000000005
#define MX1	100005
#define MX2	1000005
#define pi	acos(-1)
#define NO_OF_BITS sizeof(ulli)*8

#define SSTR( x ) static_cast< std::ostringstream & >( \
( std::ostringstream() << std::dec << x ) ).str()

//=====================================================================
lli power(lli a,lli b){lli ans=1;while(b){if(b&1){ans=(ans*a)%mod;}a=(a*a)%mod;b>>=1;}return ans;}
//=====================================================================
lli mmi(lli n){return power(n,mod-2);}
/*class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		int t;
		t=sc.nextInt();
		sc.next();
		String s,fi;
		Scanner sc=new Scanner(System.in);
		while(t>0)
		{   s=sc.nextLine();
		fi=s;
			int i=0,posi,pi;
			int count=0;
			for ( pi=0;pi<s.length();pi++)
			if(s.charAt(pi)!='L')
			break;
			s+="U";
			posi=pi;
			for(int i=posi;i<s.length();i++)
		{	if(s.charAt(i)== 'R')
			continue;
			 if(s.charAt(i)!= 'R')
          {
         if(s.charAt(i)=='L' &&s.charAt(i-1)== 'R')
         count++;
          }
		}
		
        fi+="D";
        	int i2=0,posi2,pi2;
			int coun2t=0;
			for ( pi2=0;pi2<fi.length();pi2++)
			if(fi.charAt(pi2)!= 'R')
			break;
			fi+="U";
			posi2=pi2;
			for(int i=posi2;fi.length();i++)
		{	if(fi.charAt(i)=='L')
			continue;
			 if(fi.charAt(i)!='L')
          {
         if(fi.charAt(i)== 'R' &&fi.scharAt(i-1)== 'R')
         coun2t++;
          }
		}
		if(count<=count2t)
		System.out.println(count);
		else
		
		t--;	System.out.println(coun2t);
		
  }
		}
	}*/

int main() {
  opt;
  int t;
  li i=0;
  li f=0;
  string s,f2;
  cin>>t;
  while(t>0)
    {  li i=0,posi;
      li f=0,count=0,c=0;
      cin>>s;
      f2=s;
      rep(i,0,s.length())
      {
        if(s[i]== 'R')
          c++;
      }
      rep(posi,0,s.length())
      {
        if(s[posi]!='L')
          break;
      }
      s+="U";
 //cout<<posi<<endl;
      rep(i,posi,s.length())
      {
        if(s[i]== 'R')
          continue;

        if(s[i]!= 'R')
        {
         if(s[i]=='L' &&s[i-1]== 'R')
           count++;
       }

     }
     li i2=0,posi2=0;
     li count2=0,c2=0;
     rep(posi2,0,f2.length())
     {
      if(f2[posi2]!= 'R')
        break;
    }
    f2+="D";
    rep(i,posi2,f2.length())
    {
      if(f2[i]=='L')
        continue;

      if(f2[i]!='L')
      {
       if(f2[i]== 'R' &&f2[i-1]=='L')
         count2++;
     }

   }

   cout<<min(count,count2)<<endl;
   t--;
 }
 
}