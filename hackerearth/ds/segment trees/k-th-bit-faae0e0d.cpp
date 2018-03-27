/*
* @Author: krshubham
* @Date:   2018-03-13 19:26:27
* @Last Modified by:   ks
* @Last Modified time: 2018-03-13 20:41:37
*/
const int MAXN = 1e6+5;
int bit[MAXN];

int query(int k){
    int sum = 0;
    while(k > 0){
        sum += bit[k];
        k -= (k & -k);
    }
    return sum;
}

void update(int i, int v){
    while(i <= N){
        bit[i]+=v;
        i += (i & -i);
    }
}

int main(){
	fill(bit,bit+MAXN,1);
	int n;
	cin>>n;
	
	return 0;
}