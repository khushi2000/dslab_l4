/**
* @file l4p2
* @this FIND the largest subarray having the given sum
* @author khushi
* @date 18-8-2019
*/ 
// C++ implementation to find the length 
// of longest subarray having sum k 
#include <bits/stdc++.h> 
using namespace std; 
  int a=0;
  int b=0;
// function to find the length of longest 
// subarray having sum k 
int lenOfLongSubarr(int arr[],  
                    int n, 
                    int k) { 
    // unordered_map 'um' implemented  
    // as hash table 
    unordered_map<int, int> um; 
    int sum = 0, maxLen = 0; 
    // traverse the given array 
    for (int i = 0; i < n; i++) { 
        // accumulate sum 
        sum += arr[i]; 
        // when subarray starts from index '0' 
        if (sum == k) {
            maxLen = i + 1; 
            a = 0;
            b = i;
        }
        // make an entry for 'sum' if it is 
        // not present in 'um' 
        if (um.find(sum) == um.end()) 
            um[sum] = i; 
        // check if 'sum-k' is present in 'um' 
        // or not 
        if (um.find(sum - k) != um.end()) { 
            // update maxLength 
            if (maxLen < (i - um[sum - k])) 
                maxLen = i - um[sum - k]; 
                a = um[sum - k]+1;
                b = i;
        } 
    } 
    //cout << "index from " << a << " to " << b << endl;
    // required maximum length 
    return maxLen; 
} 
// Driver Code 
int main() 
{ 
    // int arr[] = {10, 5, 2, 7, 1, 9}; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // int k = 15; 
    int n,k;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    cout<<"enter the value of sum"<<endl;
    cin>>k;
    int arr[n];
    cout<<"enter the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout << "Length of longest subarray= "
         << lenOfLongSubarr(arr, n, k)<<endl; 
         if(lenOfLongSubarr(arr,n,k)>0){
         cout<<"index is from "<< a<<" to "<<b<<endl;
     }
        else{
            cout<<"no such subarray exist"<<endl;
        }
    return 0; 
} 
