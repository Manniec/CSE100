#include <iostream>
#include <climits>
using namespace std;
void printArr(int*arr, int length){
    for (int i = 0; i < length; i++){
        cout<<arr[i]<<";";
    }
    cout<<endl;
}

int minHeapify(int* arr, int root, int N){ //let node be index of node array, N be heap size
    int oldMinVal=0, newMinNode, left = 2*root, right = (2*root)+1; //indexes for left and right children of node
    //cout<< "root: "<< root << "; arr[root]: "<<arr[root-1];
    if ((left <= N) && (arr[left-1] < arr[root-1])){
        newMinNode = left;
    }else {
        newMinNode = root;
    }
    if ((right <= N) && (arr[right-1] < arr[newMinNode-1])){
        newMinNode = right;
    }
    //cout<< "; newRoot: "<<newMinNode<< "; newMin: " << arr[newMinNode-1] <<endl;
    //printArr(arr,N);
    if (newMinNode != root){
        oldMinVal = arr[root-1];
        arr[root-1] = arr[newMinNode-1];
        arr[newMinNode-1] = oldMinVal;
        minHeapify(arr, newMinNode, N);
    }
    return 0;
}

int buildMinHeap(int* arr, int N){
    cout<<"building min heap:"<<endl;
    for (int i = N/2; i >= 1; i--){
        minHeapify(arr, i, N);
        printArr(arr,N);
    }
    cout<<"End build min heap:"<<endl;
    return 0;
}

int HeapSort(int* arr, int N){
    printArr(arr, N);
    buildMinHeap(arr, N);
    //cout<< "HEAPSORT:"<<endl;
    int newRoot;
    for (int i = N-1; i >= 1; i--){
        cout<<"for i = "<<i<<": ";
        printArr(arr, N);
        newRoot = arr[i];
        arr[i] = arr[0];
        arr[0] = newRoot;
        minHeapify(arr, 1, i);
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
    int arr [] = {16,4,10,14,7,9,3,2,8,1};//for min heapify
    //int arr [] = {4,1,3,2,16,9,10,14,8,7}; //for buildmaxheap & heapsort
    int N = 10;
    //int i = 2;

    //call Heap Sort
    //buildMaxHeap(arr, N);
    //maxHeapify(arr, 2, N);
    HeapSort(arr, N);

    //print sorted output (non-decreasing)
    printArr(arr,N);


}