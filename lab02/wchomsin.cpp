#include<iostream>
using namespace std; 

int binarySearch(int* arr, int low, int high, int ans){
    int mid;
    while (low < high){
        mid = (low+high)/2;
        if (ans == arr[mid]){
            return mid;
        } else if (ans < arr[mid]) {
            return binarySearch(arr, low, mid, ans);
        } else {
            return binarySearch(arr, mid+1, high, ans);
        }

    }
    return -1;
    
}

int main(){
    int N, as;
    cin >> N;
    cin >> as;

    int* arr = new int[N];
    for (int i = 0; i < N; i++){

        int temp;
        cin >> temp;
        arr[i] = temp;

    }

    cout<< binarySearch(arr, 0, N, as);

    return 0;
}