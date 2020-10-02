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
    int lsum = INT_MIN, rsum = INT_MIN, sum = 0;
    int* ans = new int[3];
    for (int i = mid; i >= start; i--){
        sum = sum + arr[i];
        if (sum > lsum){
            lsum = sum;
            ans[0] = i; //maxLeft
        }
    }
    sum = 0;
    for (int i = mid ; i <= end; i++){
        sum = sum + arr[i];
        if (sum > rsum){
            rsum = sum;
            ans[1] = i; //maxRight
        }
    }
    ans[2] = lsum + rsum;
    return ans;
}


int* maxSubArr(int* arr, int start, int end){
    if (start == end){
        int* ans = new int[3];
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
        if ((left[2] >= right[2]) && (left[2] >= cross[2])){
            delete[] right;
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