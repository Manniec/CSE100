#include<iostream>
#include<climits> 
using namespace std; 

int printArr(int* arr, int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << ";";
    }
    //cout<<endl;
    return 0;
}

int printArr(int* arr, int start, int end){
    for (int i = start; i < end; i++){
        cout << arr[i] << ";";
    }
    //cout<<endl;
    return 0;
}


int merge(int* arr, int arrStart, int arrMid, int arrEnd){
    int nL = arrMid - arrStart + 1; //length 1st subarray
    int nR = arrEnd - arrMid; //length 2nd subarray

    /*     
    cout << "length nL: " << arrMid << " - " << arrStart << " + 1 = " << nL <<endl;
    cout << "length nR: " << arrEnd << " - " << arrMid <<  " = " << nR <<endl;
    */

    //copy subarrays
    int* left = new int[nL+1];  //leave room for sentinals
    int* right = new int[nR+1];
    for (int i = 0; i < nL; i++){
        left[i] = arr[ arrStart +i ];
    }
    for (int j = 1; j <= nR; j++){
        right[j-1] = arr[ arrMid +j];
    }
    left[nL] = INT_MAX;         //set sentinals
    right[nR] = INT_MAX;
    
    /*
    printArr(left, nL+1);
    printArr(right, nR+1);
    */

    //sort
    //initialize incrementers
    int i = 0, j = 0, k;
    for (k = arrStart; k <= arrEnd; k++){
        if (right[j] <= left[i]){
            arr[k] = right[j];
            j++;
        } else {
            arr[k] = left[i];
            i++;
        }
    }

    //printArr(arr, arrStart, arrEnd+1);
    
    return 0;
    
}


int mergeSort(int* arr, int arrStart, int arrEnd){

    //cout<< "arrStart: " << arrStart <<"; arrEnd: " << arrEnd<<endl;

    if (arrStart < arrEnd){
        int mid = (arrStart + arrEnd)/2;
        /*
        cout<<"mid: "<< mid << endl;
        cout<< "1st half sort:" <<endl;
        */
        mergeSort(arr, arrStart, mid);
        //cout<< "2nd half sort:" <<endl;
        mergeSort(arr, mid+1, arrEnd);
        //cout<< "Merge:" <<endl;
        merge(arr, arrStart, mid, arrEnd);
    }
    return 0;
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
    
    /*
    //Test arr
    int arr[] = {8, 50, 24, 9, 131};
    int N = 5;
    */

    //Call function
    //printArr(arr, N);
    mergeSort(arr, 0, N-1);
    printArr(arr, N);

    return 0;
}