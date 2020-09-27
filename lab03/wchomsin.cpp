#include<iostream>
#include<climits> 
using namespace std; 

int printArr(int* arr, int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << ";";
    }
    return 0;
}

int merge(int* arr, int arrStart, int arrMid, int arrEnd){
    int nL = arrMid - arrStart; //length 1st subarray
    int nR = arrEnd - arrMid; //length 2nd subarray

         
    cout << "\nlength nL: " << arrMid << " - " << arrStart << " = " << nL <<endl;
    cout << "length nR: " << arrEnd << " - " << arrMid <<  " = " << nR <<endl;
    
    
    //initialize incrementers
    int i, j = 0, k;

    //copy subarrays
    int* left = new int[nL+1];  //leave room for sentinals
    int* right = new int[nR+1];
    for (i = 0; i < nL; i++){
        left[i] = arr[ arrStart +i ];
    }
    for (i = 0; i < nR; i++){
        right[i] = arr[ arrMid +i ];
    }
    left[nL] = INT_MAX;         //set sentinals
    right[nR] = INT_MAX;
    
    
    printArr(left, nL+1);
    cout << "\n";
    printArr(right, nR+1);
    cout << "\n";
    

    //sort
    i = 0; //i & j = 0
    for (k = arrStart; k < arrEnd; k++){
        if (right[j] < left[i]){
            arr[k] = right[j];
            j++;
        } else {
            arr[k] = left[i];
            i++;
        }
    }

    return 0;
    
}

int mergeSort(int* arr, int arrStart, int arrEnd){

    cout<< "arrStart: " << arrStart <<"; arrEnd: " << arrEnd<<endl;

    if (arrStart < arrEnd){
        int mid = (arrStart + arrEnd)/2;
        cout<<"mid: "<< mid << endl;
        mergeSort(arr, arrStart, mid);
        mergeSort(arr, mid+1, arrEnd);
        merge(arr, arrStart, mid, arrEnd);
    }
    return 0;
}


int main(){
    /*
    // Read array of values
    int N; //num of elements to be sorted
    cin >> N;

    int* arr = new int[N];
    for (int i = 0; i < N; i++){

        int temp;
        cin >> temp;
        arr[i] = temp;

    }
    */

    //Test arr
    int arr[] = {8, 50, 24, 9};
    int N = 4;


    //Call function
    //printArr(arr, N);
    mergeSort(arr, 0, N);
    printArr(arr, N);

    return 0;
}