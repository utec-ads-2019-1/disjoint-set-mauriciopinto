//
// Created by Malena on 5/2/2019.
//

#ifndef DISJOINTS_NODE_H
#define DISJOINTS_NODE_H

class Node {
public:
    int data;
    int rank;
    int joints;
    Node* parent;
    Node(int data) : data(data), parent(this), rank(0), joints(0){};

    Node* findRoot(){
        Node* current = this;
        while(current->parent != current){
            current = current->parent;
        }
        return current;
    }
};

#endif //DISJOINTS_NODE_H

