#include <iostream>
#include <climits>
using namespace std;
void printArr(int*arr, int length){
    for (int i = 0; i < length; i++){
        cout<<arr[i]<<";";
    }
    cout<<endl;
}

int maxHeapify(int* arr, int root, int N){ //let node be index of node array, N be heap size
    int oldMaxVal=0, newMaxNode, left = 2*root, right = (2*root)+1; //indexes for left and right children of node
    cout<< "root: "<< root << "; arr[root]: "<<arr[root-1];
    if ((left <= N) && (arr[left-1] > arr[root-1])){
        newMaxNode = left;
    }else {
        newMaxNode = root;
    }
    if ((right <= N) && (arr[right-1] > arr[newMaxNode-1])){
        newMaxNode = right;
    }
    cout<< "; newRoot: "<<newMaxNode<< "; newMax: " << arr[newMaxNode-1] <<endl;
    printArr(arr,N);
    if (newMaxNode != root){
        oldMaxVal = arr[root-1];
        arr[root-1] = arr[newMaxNode-1];
        arr[newMaxNode-1] = oldMaxVal;
        maxHeapify(arr, newMaxNode, N);
    }
    return 0;
}

int buildMaxHeap(int* arr, int N){
    for (int i = N/2; i >= 1; i--){
        maxHeapify(arr, i, N);
    }
    return 0;
}

int HeapSort(int* arr, int N){
    buildMaxHeap(arr, N);
    int newMax;
    for (int i = N-1; i > 0; i--){
        newMax = arr[i];
        arr[i] = arr[0];
        arr[0] = newMax;
        maxHeapify(arr, 0, N-1);
    }
    return 0;
}

int main(){
    //Read test files into array
    /*
    int N;
    cin >> N;

    int* arr = new int [N]; //initalize array size N
    for (int i = 0; i < N; i++){
        
        int temp;
        cin >> temp;
        arr[i] = temp;

    }
    */
    
    //tester arr
    int arr [] = {16,4,10,14,7,9,3,2,8,1};//for max heapify
    //int arr [] = {16,4,10,14,7};
    int N = 10;
    //int i = 2;

    //call Heap Sort
    buildMaxHeap(arr, N);
    //maxHeapify(arr, 2, N);
    //HeapSort(arr, N);

    //print sorted output (non-decreasing)
    for (int i = 0; i < N; i++){
        cout << arr[i]<<";";
    }


}