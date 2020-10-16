#include <iostream>
using namespace std;

void printArr(int*arr, int length){
    for (int i = 0; i < length; i++){
        cout<<arr[i]<<";";
    }
    cout<<endl;
}

int main(){

    int arr [] = {6,4,2};
    int n = 3;
    int temp;

    for (int i = 0; i < n-1; i++){
        for (int j = n; j > i+1; j--){
            cout<<"for i = "<<i+1<<" and j = "<<j<<": ";
            printArr(arr,n);
            cout<<" -> ";
            if (arr[j-1] < arr[j - 2]) {
                temp = arr[j-2];
                arr[j-2] = arr[j-1];
                arr[j-1] = temp;
            }
            printArr(arr,n);
        }
    }

    printArr(arr,n);
    return 0;

}