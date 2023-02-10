#include <iostream>
#include <vector>
using namespace std;

// void swap(int *i,int *j){
//     int *temp = i;
//     i = j;
//     j = temp;
// }

// print 1 to N using backtracking
void print(int i, int n){
    if(i<1)
        return;
    print(i-1,n);
    cout<<i<<endl;
}

// Sum of n integers - parameterised recursion
void sump(int i,int sum){
    if(i<1){
        cout<<sum;
        return;
    }
    sump(i-1,sum+i);
}

// reverse an array using recursion

void reverse(int i,int arr[],int n){
    if(i>=n/2)
        return;
    swap(arr[i],arr[n-i-1]);

    reverse(i+1,arr,n);

}

// Palindrome using functional recursion

bool palindrome(int i,string s){
    if(i>=s.size()/2)
        return true;
    if(s[i]!=s[s.size()-i-1])
        return false;
    return palindrome(i+1,s);
}

// Sum of n integers - functional recursion
int sumf(int i){
    if(i==0)
        return 0;
    return (i + sumf(i-1));
}

// fibonacci number - functional recursion

int fibonacci(int i){
    if(i<=1)
        return i;
    return fibonacci(i-1)+fibonacci(i-2);
}

void printF(int idx,vector<int>&ds,int arr[],int n){
    if(idx == n){
        if(ds.size()==0){
            cout<<"{}"<<" ";
        }
        for(auto i : ds){
            cout<< i << " ";
        }
        cout<<endl;
        return;
    }
    ds.push_back(arr[idx]);
    printF(idx+1,ds,arr,n);
    ds.pop_back();
    printF(idx+1,ds,arr,n);

}

int main(){
    int i;
    // cin>>i;
    // cout<<sumf(i);
    // int arr[] = {1,3,5,6,2,3,8};
    // reverse(0,arr,sizeof(arr)/sizeof(arr[0]));
    // for(int i =0;i<sizeof(arr)/sizeof(arr[0]);i++){
    //     cout<<arr[i]<<" ";
    // }
    // string s = "madam";
    // cout<<palindrome(0,s);

  int arr[] = {3,1,2};
  vector<int>ds;
  printF(0,ds,arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}