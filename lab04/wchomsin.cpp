/*
MAX SUBARRAY PSEUDOCODE (pg72)
maxSubArr(A, low, high)
    if high == low
        return (low, high, A[low]); //basecase = 1 element
    else mid = floor((low+high)/2)
        (left-low, left-high, left-sum) = maxSubArr(A,low,mid);
        (right-low, right-high, right-sum) = maxSubArr(A, mid +1, high);
        (cross-low, cross-high, cross-sum) = maxCrossSubArr(A, low,mid,high);
        if left-sum >= right sum and left-sum >= cross-sum
            return (left-low, left...)
        else if right-sum >= ...
            return (right-low, righ...)
        else return (cross-low, cros...)
*/

#include <iostream>
#include <climits> //for INT_MAX and INT_MIN etc...
using namespace std;

int* maxCrossSubArr(int* arr, int start, int mid, int end){
    int lsum = INT_MIN, rsum = INT_MIN, sum = 0; //preset left-sum and right-sum to negative infinity
    int* ans = new int[3]; //dynamic arr allocation
    for (int i = mid; i >= start; i--){ //search for max subarr of left
        sum = sum + arr[i];
        if (sum > lsum){
            lsum = sum; //left-sum
            ans[0] = i; //maxLeft
        }
    }
    sum = 0;
    for (int i = mid+1 ; i <= end; i++){ //search for max subarr of right
        sum = sum + arr[i];
        if (sum > rsum){
            rsum = sum; //right-sum
            ans[1] = i; //maxRight
        }
    }
    ans[2] = lsum + rsum;
    return ans;
}


int* maxSubArr(int* arr, int start, int end){ //returns pointer
    if (start == end){
        int* ans = new int[3]; //dynamic memory allocation (arr should exist after func ends)
        ans[0] = start;
        ans[1] = end;
        ans[2] = arr[end];
        return ans;
    }
    else {
        int mid = (start + end)/2, *left, *right, *cross; //declare pointers & mid
        left = maxSubArr(arr, start, mid); 
        right = maxSubArr(arr, mid+1, end);
        cross = maxCrossSubArr(arr, start, mid, end);
        //compare maxSubArrays of left,right,cross
        if ((left[2] >= right[2]) && (left[2] >= cross[2])){
            delete[] right; //clear memory, dont need these dynamic arrays
            delete[] cross;
            return left;
        } else if ((right[2] >= left[2]) && (right[2] >= cross[2])){
            delete[] left;
            delete[] cross;
            return right;
        } else {
            delete[] right;
            delete[] left;
            return cross;
        }
    }
}

int main(){
    // Read array of values
    int N; //num of elements to be sorted
    cin >> N;

    int* arr = new int[N];
    for (int i = 0; i < N; i++){

        int temp;
        cin >> temp;
        arr[i] = temp;

    }

    int* ans = maxSubArr(arr, 0, N-1);
    
    /*
    for(int i = 0; i < 3; i++){
        cout << ans[i];
    }
    */

    cout<<ans[2];
    
    delete[] ans;
    return 0;
}