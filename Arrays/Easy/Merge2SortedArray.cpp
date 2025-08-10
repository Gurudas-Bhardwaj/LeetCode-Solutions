#include <vector>
#include<iostream>
using namespace std;

void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
    int k = arr1.size()-1, i = m-1, j = n-1;

    while(i>=0 && j>=0){
        cout<<arr1[m]<<" "<<arr2[n]<<" "<<arr1[k]<<endl;
        if(arr2[j] > arr1[i]){
            arr1[k] = arr2[j];
            j--;
        }   
        else{
            arr1[k] = arr1[i];
            i--;
        }
        k--;
    }

    while(j>=0){
        arr1[k] = arr2[j];
        j--; k--;
    }

    
}

int main() {
    vector<int> nums1 = {2,5,6,0,0,0};
    vector<int> nums2 = {1,2,3};

    merge(nums1, 3, nums2, 3);

    for(int num : nums1)
        cout << num << " ";
}
