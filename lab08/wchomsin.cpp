#include <iostream>
#include <vector>
using namespace std;

void printVect(vector<double> vect){
    for (int i = 0; i < vect.size(); i++){
        cout<<vect[i]<<endl;
    }
}

void printVectInline(vector<double> vect){
    for (int i = 0; i < vect.size(); i++){
        cout<<vect[i]<<";";
    }
}

vector<double> insertionSort(vector<double> vect){
    double temp = 0;
    int i, j;
    for (j = 1; j < vect.size(); j++){
        temp = vect[j];
        //cout<<"key: "<<temp<<"; moves: ";
        i = j - 1;
        while ((i >= 0) && (vect[i]>temp)){
            vect[i+1] = vect[i];
            i = i - 1;
            //cout<<"["<<i<<"]";
            //printVectInline(vect);
            //cout<<" -> ";
        }
        vect[i+1] = temp;
        //cout<<"["<<i<<"]";
        //printVectInline(vect);
        //cout<<endl;
    }
    return vect;
}

vector<double> bucketSort(double* arr, int n){
    vector<double> temp[n];
    for (int i = 0; i < n; i++){ //change to i=0 & i<n
        //cout<<arr[i]<<endl;
        temp[(int)(n * arr[i])].push_back(arr[i]);
    }
    
    
    for (int i = 0; i < n; i++){
        //cout<<"B["<<i<<"]: ";
        //printVectInline(temp[i]);
        //cout<<" -> ";
        temp[i] = insertionSort(temp[i]);
        //printVectInline(temp[i]);
        //cout<<endl;
    }
    /*
    //printing tempArr
    for (int i = 0; i < n; i++){ 
        cout<<"B["<<i<<"]: ";
        printVectInline(temp[i]);
        cout<<endl;
    }*/

    //concatinate B[0], B[1],...
    vector<double> output;
    for(int i = 0; i < n; i++){
        output.insert(output.end(), temp[i].begin(), temp[i].end());
    }
    return output;
}

int main(){
    //Read Test Files
    int N;
    cin >> N;

    double* arr = new double [N]; //initalize array size N
    for (int i = 0; i < N; i++){
        
        double temp;
        cin >> temp;
        arr[i] = temp;

    }

    /* //Testing insertionSort();
    double testArr[] = {5.1,2.1,4.1,6.1,1.0,3.1};
    //double testArr[] = {5,2,4,6,1,3};
    vector <double> test;
    test.insert(test.begin(), std::begin(testArr), std::end(testArr));
    test = insertionSort(test);
    printVectInline(test);
    */
    
    //Sort
    vector<double> output;
    output = bucketSort(arr, N);
    printVect(output);
    

}