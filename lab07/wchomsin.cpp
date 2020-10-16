#include <iostream>
#include <vector>
using namespace std;

void printArr(int*arr, int length){
    for (int i = 0; i < length; i++){
        cout<<arr[i]<<";";
    }
}

void printVect(vector<int> vect){
    for (int i = 0; i < vect.size(); i++){
        cout<<vect[i]<<";";
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

void countingsortArr(vector<int>* arr, vector<int>* output, int range, int lengthArr, int digit){
    int* temp = new int [range + 1] (); // () initialized arr to zero

    for (int i = 0; i < lengthArr; i++){    //temp contains number of elements equal to i
        temp[arr[i][digit]] = temp[arr[i][digit]] + 1;
    }
    for (int j = 1; j <= range; j++){        //temp contians elements less than or equal to i
        temp[j] = temp[j] + temp[j-1];
    }
    for (int i = lengthArr - 1; i >= 0; i--){
        output[temp[arr[i][digit]]-1] = arr[i];
        temp[arr[i][digit]] = temp[arr[i][digit]]-1; 

    }
    delete[] temp; //delete temp at end
}

void radixsort(vector<int>* arr, int lengthArr, int digit){
    vector<int> temp[lengthArr];
    for (int i = digit-1; i >= 0; i--){
        countingsortArr(arr, temp, 9, lengthArr, i);
        for(int j = 0; j < lengthArr; j++){
            arr[j] = temp[j];
            temp[j].clear();
        }
    }
   
}

int main(){
    
    //Read Test Files
    int N, temp;
    cin >> N;

    vector<int> arr[N];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < 10; j++){
            
            cin >> temp;
            arr[i].push_back(temp);

        }
    }

    radixsort(arr, N, 10);
    
    /*
    for( int j = 9; j >=0 ; j--){
        vector<int> b[N];
        countingsortArr(arr, b, 9, N, j);
        cout<<"digit "<<j<<": "<<endl;
        //Print output
        for (int i = 0; i < N; i++){
            printVect(arr[i]);
            cout<<"\t";
            printVect(b[i]);
            cout<<endl;
        }
        for (int k = 0; k < N; k++){
            arr[k] = b[k];
        }
        
    }
    */
   
   //Print output
    for (int i = 0; i < N; i++){
        printVect(arr[i]);
        cout<<endl;
    }

    

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