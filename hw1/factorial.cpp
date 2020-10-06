#include<iostream>
using namespace std;

int factorial(int n, int m){
    cout<<endl<<"n: "<<n<<"; m: "<<m<<endl;
    if (n == m){
        return (n);
    //} else if (n < m){
        //return 1;
    } else {
        int left,right;
        int mid = ((n + m)/2);
        cout<<"mid: "<<mid<<endl;
        left = factorial (n, mid+1);  //n(n-1)...((m+n)/2 +1 )((m+n)/2)
        right = factorial (mid, m);   //((m+n)/2)((m+n)/2 - 1)...(m-1)(m)
        cout <<"left: "<<left<<"; right: "<<right<<"; return: "<<(left*right)<<endl;
        return(left*right);
        //return (factorial (n, mid) * factorial (mid-1, m));
    }
}

int main(){
    int n;
    cout<<"Please enter a number: ";
    cin >> n;
    cout<<n<<" factorial is: "<<factorial(n,1)<<endl;
}