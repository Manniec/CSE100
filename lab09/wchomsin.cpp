#include <iostream>
#include <list>
#include <string>
using namespace std;

void printHashTable (list<int>* table, int m){
    //list <int> :: iterator it; //create list iterator
    for (int i = 0; i < m; i ++){
        cout<< i << " : ";
        for(list <int> :: iterator it = table[i].begin(); it != table[i].end(); ++it){
            cout<< *it; 
            if(it != --table[i].end()){ //dont print arrow for last item (-- refers to item before last)
                cout << "->";
            }
        }
        cout<<endl;
    }
}

void chainedHashInsert (list<int>* table, int m, int key){
    //cout<< "insert "<<key<<endl;
    int hashFunc = key % m; //h(k)
    table[hashFunc].push_front(key);
}

bool chainedHashDelete (list<int>* table, int m, int key){
    //cout<< "delete "<<key<<endl;
    int hashFunc = key % m; //initialize location to null pointer
    for(list <int> :: iterator it = table[hashFunc].begin(); it != table[hashFunc].end(); ++it){//iterate list
            if(*it == key){ //Checking for Key
                table[hashFunc].erase(it);
                return true; //key was found: DELETED
            }
    }
    return false; //key was not found: DELETE FAILED
}

int* chainedHashSearch (list<int>* table, int m, int key){
    //cout << "search "<< key <<endl;
    int listIndex = 0, hashFunc = key % m, *location = NULL; //initialize location to null pointer
    for(list <int> :: iterator it = table[hashFunc].begin(); it != table[hashFunc].end(); ++it){//iterate list
            if(*it == key){ //Checking for Key
                location = new int [2]; //dynamic alloc & set location to {hashTableindex, linkedListIndex} 
                location[0] = hashFunc;
                location[1] = listIndex;
                return location; //return here so it returns first found instance instead of last
            }
            listIndex++;
    }
    return location; //returns null pointer if "NOT FOUND"
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
            cout<<"++++++++++++++++++++"<<endl;
        }else if (command == "i"){
            cin >> temp;
            chainedHashInsert(hashTable, m, temp);
        }else if (command == "d"){
            cin >> temp;
            if(chainedHashDelete (hashTable, m, temp)){
                cout<<temp<<" : DELETED"<<endl;
            }else{
                cout<<temp<<" : DELETE FAILED"<<endl;
            }
            cout<<"++++++++++++++++++++"<<endl;
        }else if (command == "s"){
            cin >> temp;
            int* loc = chainedHashSearch(hashTable, m, temp);
            if (loc){ //if not null pointer, prints loc, else prints NOT FOUND
                cout<< temp << " : FOUND AT "<< loc[0]<<","<<loc[1]<<endl;
            }else{
                cout<< temp << " : NOT FOUND"<<endl;
            }
            delete[] loc; //free allocated array memory
            cout<<"++++++++++++++++++++"<<endl;
        }
    }
}