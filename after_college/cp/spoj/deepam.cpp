#include <bits/stdc++.h>
using namespace std;

int randomPartition(int*, int , int);
int SELECT2helper(int*,int,int,int);
int SELECT3helper(int*, int, int, int); 


int SELECT1(int arr[], int n, int k) {
    sort(arr, arr+n);
    return arr[k-1];
}


int SELECT2(int arr[], int n, int k) {
    if(n < 25) {
        return SELECT1(arr, n, k);
    }
    return SELECT2helper(arr,0,n-1,k);
}

int SELECT3(int arr[], int n, int k) {
    if(n < 25) {
        return SELECT1(arr, n, k);
    }
   return SELECT3helper(arr, 0, n-1, k);
}

void print(string algo, int n, int k, int x) {
    cout<<"Algorithm "<<algo<<": "<<n<<","<<k<<","<<x<<endl;
}

int main() {
    int tenK = 10000;
    int hundredK = 100000;
    int million = 1000000;
    int array10k[tenK];
    int array100k[hundredK];
    int array1m[million];
    for(int i = 0; i < tenK; i++) {
        array10k[i] = floor(rand()*tenK);
    }
    for(int i = 0; i < hundredK; i++) {
        array100k[i] = floor(rand()*1000);
    }
    for(int i = 0; i < million; i++) {
        array1m[i] = floor(rand()*1000);
    }


    print("SELECT1",tenK,tenK/2,SELECT1(array10k, tenK, tenK/2));
    print("SELECT2",tenK,tenK/2,SELECT2(array10k, tenK, tenK/2));
    print("SELECT3",tenK,tenK/2,SELECT3(array10k, tenK, tenK/2));
    cout<<endl;
    print("SELECT1",hundredK,hundredK/2,SELECT1(array100k, hundredK, hundredK/2));
    print("SELECT2",hundredK,hundredK/2,SELECT2(array100k, hundredK, hundredK/2));
    print("SELECT3",hundredK,hundredK/2,SELECT3(array100k, hundredK, hundredK/2));
    cout<<endl;
    print("SELECT1",tenK,tenK/2,SELECT1(array1m, million, million/2));
    print("SELECT2",tenK,tenK/2,SELECT2(array1m, million, million/2));
    print("SELECT3",tenK,tenK/2,SELECT3(array1m, million, million/2));

    return 0;
}


int SELECT2helper(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) { 
        int pos = randomPartition(arr, l, r); 
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)
            return SELECT2helper(arr, l, pos-1, k); 
        return SELECT2helper(arr, pos+1, r, k-pos+l-1); 
    }
    return INT_MAX; 
}


void swap(int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

int partitionForSelect2(int arr[], int l, int r) { 
    int x = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++) { 
        if (arr[j] <= x) { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    }
    swap(&arr[i], &arr[r]); 
    return i; 
} 

int randomPartition(int arr[], int l, int r) { 
    int n = r-l+1; 
    int pivot = rand() % n; 
    swap(&arr[l + pivot], &arr[r]); 
    return partitionForSelect2(arr, l, r); 
} 


int findMedian(int arr[], int n) { 
    sort(arr, arr+n);
    return arr[n/2];
} 

int partitionForSelect3(int arr[], int l, int r, int x) { 
    int i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 

    i = l; 
    for (int j = l; j <= r - 1; j++) { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 

int SELECT3helper(int arr[], int l , int r, int k) {
    if (k > 0 && k <= r - l + 1) { 
        int n = r-l+1;
  
        int i, median[(n+4)/5];
        for (i=0; i<n/5; i++) 
            median[i] = findMedian(arr+l+i*5, 5); 
        if (i*5 < n){ 
            median[i] = findMedian(arr+l+i*5, n%5);  
            i++; 
        }     
  
        int medOfMed = (i == 1)? median[i-1]: SELECT3helper(median, 0, i-1, i/2); 
  
        int pos = partitionForSelect3(arr, l, r, medOfMed); 

        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)
            return SELECT3helper(arr, l, pos-1, k); 

        return SELECT3helper(arr, pos+1, r, k-pos+l-1); 
    } 

    return INT_MAX; 
}