#include<iostream>
using namespace std; 

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

    for (int i = 0; i < N; i++){

        if (arr[i] == as) {
            cout << i;
            return 0;
        }
        
    }
        
    cout << -1;

    return 0;

}