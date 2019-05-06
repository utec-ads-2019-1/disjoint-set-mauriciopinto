#include <iostream>
#include<map>
#include"Node.h"
//#include"set.h"

using namespace std;

map<int, Node*> mymap;
map<int, Node*>::iterator iterator1;

Node* findNode(int data){
    for(iterator1 = mymap.begin(); iterator1 != mymap.end(); iterator1++){
        if(data == iterator1->first){
            return iterator1->second;
        }
    }
}

void print(Node* node){
    cout << node->data << "'s root is " << node->findRoot()->data << endl;
}

void merge(int i1, int i2){
    findNode(i2)->findRoot()->parent = findNode(i1)->findRoot();
    print(findNode(i1));
    print(findNode(i2));
    findNode(i1)->joints = findNode(i2)->joints + 1;
    findNode(i1)->rank += (findNode(i2)->rank + 1);
}

void mergeRank(int i1, int i2){
    if(findNode(i1)->findRoot()->rank > findNode(i2)->findRoot()->rank){
        findNode(i2)->findRoot()->parent = findNode(i1)->findRoot();
        findNode(i1)->joints = findNode(i2)->joints + 1;
        findNode(i1)->rank += (findNode(i2)->rank + 1);
    }
    else{
        findNode(i1)->findRoot()->parent = findNode(i2)->findRoot();
        findNode(i2)->joints = findNode(i1)->joints + 1;
        findNode(i1)->rank += (findNode(i2)->rank + 1);
    }
}
void mergeSize(int i1, int i2){
    if(findNode(i1)->findRoot()->joints > findNode(i2)->findRoot()->joints){
        findNode(i2)->findRoot()->parent = findNode(i1)->findRoot();
        findNode(i1)->joints = findNode(i2)->joints + 1;
        findNode(i1)->rank += (findNode(i2)->rank + 1);
    }
    else{
        findNode(i1)->findRoot()->parent = findNode(i2)->findRoot();
        findNode(i2)->joints = findNode(i1)->joints + 1;
        findNode(i1)->rank += (findNode(i2)->rank + 1);
    }
}

void newNode(int data){
    Node* newNode = new Node(data);
    mymap.insert({data, newNode});
}

void insertAll(){
    for(int i = 1; i < 17; i++){
        newNode(i);
    }
}

int main() {
    insertAll();
    merge(1,6);
    mergeRank(1,8);
    print(findNode(1));
    print(findNode(6));
    print(findNode(8));
}