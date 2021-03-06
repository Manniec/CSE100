#include <iostream>
#include <cstdlib>
using namespace std;

int partition(int* arr, int start, int end){
    int pivot = arr[end], i = start-1, temp; 
    for (int j = start; j <= end-1; j++){
        if (arr[j] <= pivot){
            i = i + 1;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;
    return (i + 1);
}

int randomPartition(int* arr, int start, int end){
    int temp, i = rand() % (end-start) + (start);
    temp = arr[end];
    arr[end] = arr[i];
    arr[i] = temp;
    return partition(arr, start, end);
}

int quicksort(int* arr, int start, int end){
    if (start < end){
        int mid = randomPartition(arr, start, end); //QuickSort using random partition
        quicksort(arr, start, mid-1);
        quicksort(arr, mid+1, end);
    }
    return 0;
}

void printArr(int*arr, int length){
    for (int i = 0; i < length; i++){
        cout<<arr[i]<<";";
    }
}

int main(){
    //Read Test Files
    int N;
    cin >> N;

    int* arr = new int [N]; //initalize array size N
    for (int i = 0; i < N; i++){
        
        int temp;
        cin >> temp;
        arr[i] = temp;

    }

    //Sort
    quicksort(arr, 0, N-1);
    printArr(arr,N);

}