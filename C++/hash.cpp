/*-----------------CODED BY NISHCHAY-----------------*/
#include <bits/stdc++.h>
#include<chrono>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define REP(i, j, k) FOR(i, j, k, 1)
typedef std::vector<int> VI;
using namespace std;
using namespace std::chrono;

///*------------------------FUNCTIONS-----------------------*///

class hashTable{
    static const int size = 10;
    int hashvalue;
    vector <pair<int,string>> row[size];

public:
    void insertItem(int key, string s);
    void deleteItem(int key);
    void print();
    int hashFunc(int key);

};

void hashTable::print(){

    REP(x,0,size){
        cout << x << " :: "; 
        auto it = row[x].begin();
        while(it != row[x].end()){

            if(it == --row[x].end()){
                cout << "(key : " << it->first << " || name : "<<it->second << ")";
            }
            else{
                cout << "(key : " << it->first << " || name : "<<it->second << ") --> ";
            }
            it++;
        }
        cout << "\n";
    }
    cout <<"\n---------------------------------------------------------------------\n";

}

int hashTable::hashFunc(int key){
    return key%size;
}

void hashTable::insertItem(int key, string s){

    int hashValue = hashFunc(key);
    pair <int,string> temp;
    temp.first = key;
    temp.second = s;
    row[hashValue].push_back(temp);
    cout << "\nInserted item :: "<< "(key : " << key << " || name : "<< s << ")\n\n";
    print();

}

void hashTable::deleteItem(int key){
    
    int hashValue = hashFunc(key);
    auto it = row[hashValue].begin();
    while(it != row[hashValue].end()){
        if(it->first == key){
            cout << "\nDeleted item :: "<< "(key : " << it->first << " || name : "<< it->second << ")\n\n";
            it = row[hashValue].erase(it);
            print();
            return;
        }
        it++;
    }
    cout << "\n(KEY NOT FOUND:: "<<key<<")\n\n";

}


///*--------------------CODE BEGINS HERE--------------------*///

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
cout << endl;

hashTable h;

h.insertItem(1, "Abhist");
h.insertItem(2, "Gupta");
h.insertItem(3, "Mandal");
h.insertItem(4, "Suryawanshi");
h.insertItem(13, "Nishchay");
h.insertItem(14, "Srikar");
h.insertItem(12, "Laanith");
h.insertItem(17, "Subhash");
h.insertItem(19, "Thanish");
h.insertItem(20, "Varun");

h.deleteItem(3);


cout << endl;
return 0;
}