#include <iostream>
#include <bits/stdc++.h>
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

// print subsequences with sum = k
void subsum(int idx,vector<int>&ds,int s,int sum,int arr[],int n){
    if(idx==n){
        if(s==sum){
            for(auto i : ds){
            cout<< i << " ";
        }
        cout<<endl;
        return;
        }
        return;
    }
    s += arr[idx];
    ds.push_back(arr[idx]);
    subsum(idx+1,ds,s,sum,arr,n);
    s-=arr[idx];
    ds.pop_back();
    subsum(idx+1,ds,s,sum,arr,n);
}

// combination sum - I ( my method)

void comb(int idx,int s,int sum,vector<int>&ds,int arr[],int n){
    if(s>sum) return;
    if(idx == n){
        if(s == sum){
            for(auto i : ds){
                cout<<i<<" ";
            }
            cout<<endl;
            return;
        }
        return;
    }

    s+=arr[idx];
    ds.push_back(arr[idx]);
    comb(idx,s,sum,ds,arr,n);
    s-=arr[idx];
    ds.pop_back();
    comb(idx+1,s,sum,ds,arr,n);
}

// combination sum - I by striver

void combstr(int idx,int target,vector<int>&ds,int arr[],int n){
    if(idx == n){
        if(target == 0){
            for(auto i : ds){
                cout<<i<<" ";
            }
            cout<<endl;
            return;
        }
        return;
    }

    if(arr[idx]<=target){
    ds.push_back(arr[idx]);
    combstr(idx,target-arr[idx],ds,arr,n);
    ds.pop_back();
    }
    
    combstr(idx+1,target,ds,arr,n);
}

// subset sum - I

void subsetsum(int idx,int sum,int arr[],int n,vector<int>&ds){
    if(idx==n){
        ds.push_back(sum);
        return;
    }
    subsetsum(idx+1,sum+arr[idx],arr,n,ds);
    subsetsum(idx+1,sum,arr,n,ds);
}

// subset sum - II

void subsetsum2(int idx,vector<int>arr,vector<int>&ds,vector<vector<int>>&ans){
    ans.push_back(ds);
    for(int i = idx;i<arr.size();i++){
        if(i>idx && arr[i]==arr[i-1])
            continue;
        ds.push_back(arr[i]);
        subsetsum2(i+1,arr,ds,ans);
        ds.pop_back();
    }
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
    vector<int>ds;
    vector<vector<int>>ans;
    vector<int>num = {1,2,2};
    sort(num.begin(),num.end());
    subsetsum2(0,num,ds,ans);
    for (int i = 0; i < ans.size(); i++) {
        for (auto it = ans[i].begin();it!=ans[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
    return 0;
}