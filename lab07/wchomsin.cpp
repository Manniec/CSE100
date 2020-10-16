#include <iostream>
using namespace std;

void printArr(int*arr, int length){
    for (int i = 0; i < length; i++){
        cout<<arr[i]<<";";
    }
}

void countingsort(int* arr, int* output, int range, int lengthArr){
    int* temp = new int [range + 1] (); // () initialized arr to zero
    // cout<<"A: ";
    // printArr(arr, lengthArr);
    // cout<<endl<<"B: ";
    // printArr(output, lengthArr);
    // cout<<endl<<"C: ";
    // printArr(temp, range + 1);
    // cout<<endl;
    for (int i = 0; i < lengthArr; i++){    //temp contains number of elements equal to i
        temp[arr[i]] = temp[arr[i]] + 1;
    }
    for (int j = 1; j <= range; j++){        //temp contians elements less than or equal to i
        temp[j] = temp[j] + temp[j-1];
    }
    for (int i = lengthArr - 1; i >= 0; i--){
        output[temp[arr[i]]-1] = arr[i];
        temp[arr[i]] = temp[arr[i]]-1; 
        
        // cout<<"A: ";
        // printArr(arr, lengthArr);
        // cout<<endl<<"B: ";
        // printArr(output, lengthArr);
        // cout<<endl<<"C: ";
        // printArr(temp, range + 1);
        // cout<<endl;
    }
    delete[] temp; //delete temp at end
}

int main(){
    /*
    //Read Test Files
    int N;
    cin >> N;

    int* arr = new int [N]; //initalize array size N
    for (int i = 0; i < N; i++){
        
        int temp;
        cin >> temp;
        arr[i] = temp;

    }
    */

    /* Checking if array is initialized to zero
    int range = 9;
    int* temp = new int [range] ();
    printArr(temp, range);
    */
    
    // //test counting sort
    // int arr[] = {2,5,3,0,2,3,0,3};
    // int b[8] = { };
    // countingsort(arr, b, 5, 8);
    // printArr(b, 8);

    //Sort

    //printArr(arr,N);

}