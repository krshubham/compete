#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef pair<int, int> ii;
void operator -= (ii &A, ii B) { A.x -= B.x; A.y -= B.y; }
long long ccw (ii O, ii A, ii B) { A -= O; B -= O; return 1LL * A.x * B.y - 1LL * A.y * B.x; }
ii a[100005];
int n;

bool check(int a1,int b1){
  ii p;
  p.x=a1;
  p.y=b1;
  if(ccw(a[1], a[2], p) >= 0) return 0;
  if(ccw(a[1], a[n], p) <= 0) return 0;
  int l = 2, r = n;
  while(l != r) {
     int mid = (l + r) >> 1;
     if(ccw(a[1], a[mid], p) < 0) l = mid + 1;
     else r = mid;
 }
 if(ccw(a[l - 1], a[l], p) >= 0) return 0;

 return 1;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        map <pair<int,int>,bool> mp;
        cin>>n;
        vector<pair <int,int> >lol;
        queue < pair<int,int> > que;
        int cen1=0,cen2=0,l1,l2,l3,l4;
        int input1,input2;
        cin>>input1>>input2;
        a[n].x=input1;
        cen1+=input1;
        cen2+=input2;
        a[n].y=input2;

        que.push(make_pair(input1,input2));
        for(int i=n-1;i>=1;i--){
            cin>>input1>>input2;
            a[i].x=input1;
            a[i].y=input2;
            que.push(make_pair(input1,input2));
        }
        int cnt=0,lim=floor(n/10);
        int ans=0;
    //lol.push_back(make_pair(input1,input2));
        while(!que.empty() && ans!=lim){

            pair<int,int> P = que.front();
            que.pop();
            pair<int,int>x1,x2,x3,x4,x5,x6,x7,x8;
            x1.x=P.x+1;
            x1.y=P.y+1;

            x2.x=P.x+1;
            x2.y=P.y;

            x3.x=P.x;
            x3.y=P.y+1;

            x4.x=P.x-1;
            x4.y=P.y-1;

            x5.x=P.x-1;
            x5.y=P.y;


            x6.x=P.x;
            x6.y=P.y-1;

            x7.x=P.x-1;
            x7.y=P.y+1;

            x8.x=P.x+1;
            x8.y=P.y-1;

            if(check(x1.x,x1.y)==1 && mp[x1]==0){
                ans++;
                mp[x1]=1;
       // pri(x1);
                que.push(x1);
                lol.push_back(x1);
                if(ans==lim){break;}
            }
            if(check(x2.x,x2.y)==1 && mp[x2]==0){
                ans++;
                mp[x2]=1;
       // pri(x2);
                que.push(x2);
                lol.push_back(x2);
                if(ans==lim){break;}
            }
            if(check(x3.x,x3.y)==1 && mp[x3]==0){
                ans++;
                mp[x3]=1;
       // pri(x3);
                que.push(x3);
                lol.push_back(x3);
                if(ans==lim){break;}
            }
            if(check(x4.x,x4.y)&& mp[x4]==0){
                ans++;
                mp[x4]=1;
       // pri(x4);
                que.push(x4);
                lol.push_back(x4);
                if(ans==lim){break;}
            }
            if(check(x5.x,x5.y) && mp[x5]==0){
                ans++;
                mp[x5]=1;
        //pri(x5);
                que.push(x5);
                lol.push_back(x5);
                if(ans==lim){break;}
            }
            if(check(x6.x,x6.y)&& mp[x6]==0){
                ans++;
                mp[x6]=1;
        //pri(x6);
                que.push(x6);
                lol.push_back(x6);
                if(ans==lim){break;}
            }
            if(check(x7.x,x7.y) && mp[x7]==0){
                ans++;
                mp[x7]=1;
       // pri(x7);
                que.push(x7);
                lol.push_back(x7);
                if(ans==lim){break;}
            }
            if(check(x8.x,x8.y) && mp[x8]==0){
                ans++;
                mp[x8]=1;
        //pri(x8);
                que.push(x8);
                lol.push_back(x8);
                if(ans==lim){break;}
            }

        }
        if(ans==lim){
            for(int j=lol.size()-1;j>=0;j--){
                cout<<lol[j].x<<" "<<lol[j].y<<endl;
            }
        }
        else{
            cout<<-1<<endl;
        }

    }
}
