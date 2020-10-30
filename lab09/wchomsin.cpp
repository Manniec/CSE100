#include <iostream>
#include <list>
#include <string>
using namespace std;

void printHashTable (list<int>* table, int m){
    //list <int> :: iterator it; //create list iterator
    for (int i = 0; i < m; i ++){
        cout<< i << " : ";
        for(list <int> :: iterator it = table[i].begin(); it != table[i].end(); it++){
            cout<<"->"<< *it;
        }
        cout<<endl;
    }
}

void chainedHashInsert (list<int>* table, int key){

}

bool chainedHashDelete (list<int>* table, int key){
    return true; //key was found: DELETED
    return false; //key was not found: DELETE FAILED
}

int* chainedHashSearch (list<int>* , int key){
    int* location = new int [2];
    return location;
}

int main(){
    //Read Test Files
    int m, temp;
    cin >> m; //size of hash table
    
    list<int> hashTable[m]; //initalize hashtable (array of linked lists)

    string command = "";
    while (command != "e"){
        cin >> command;
        if (command == "e"){
            return 0;
        }else if(command == "o"){
            //cout<<"Output Hashtable"<<endl;
            printHashTable(hashTable, m);
        }else if (command == "i"){
            cin >> temp;
            cout<< "insert "<<temp<<endl;
        }else if (command == "d"){
            cin >> temp;
            cout<< "delete "<<temp<<endl;
        }else if (command == "s"){
            cin >> temp;
            cout << "search "<< temp <<endl;
        }
    }
}