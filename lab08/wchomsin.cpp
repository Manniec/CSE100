#include <iostream>
#include <vector>
using namespace std;

int insertionSort(vector<int> vect){
    int temp = 0, i, j;
    for (j = 1; j < vect.size(); j++){
        temp = vect[j];
        i = j - 1;
        while (i > 0 && vect[i]>temp){
            vect[i+1] = A[i];
            i = i - 1;
        }
        vect[i+1] = temp;
    }
}

int bucketsort(int* arr, vector<int> output, int n){
    vector<int> temp[N];
    for (int i = 1; i <= n; i++){ //change to i=0 & i<n
        temp[n * arr[i]].push_back(arr[1]);
    }
    for (int i = 0; i < n; i++){
        insertionSort(temp[i]);
    }
    //concatinate B[0], B[1],...
    for(int i = 0; i < n; i++){
        output.insert(output.end(), temp[i].begin(), temp[i].end());
    }
    return 0;
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

    vector<int> output;

    //Sort
    bucketSort(arr, output, N);
    printArr(output,N);

}