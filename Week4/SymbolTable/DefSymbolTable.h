#ifndef DEFSYMBOLTABLE_H_INCLUDED
#define DEFSYMBOLTABLE_H_INCLUDED

#include <iostream>

using namespace std;

struct Node{
    string key;
    int value;
    Node *next;
};

struct SymbolTableLL{
    Node *head;
    int n;

    SymbolTableLL(){
        head = nullptr;
        n = 0;
    }

    void put(string k, int v){
        Node *h = head;
        while(h != nullptr){
            if(h -> key == k){
                h -> value = v;
            }
            h = h -> next;
        }
        Node *newNode = new Node{k, v, head};
        head = newNode;
        n++;
    }

    int get(string k){
        Node *h = head;
        while(h != nullptr){
            if(h -> key == k){
                return h -> value;
            }
            h = h -> next;
        }
        return -1;
    }

    int size(){
        return n;
    }
};

struct SymbolTableL{
    string key[100];
    int value[100];
    int sizze;

    SymbolTableL(){
        sizze = 0;
    }

    void put(string k, int v){
        for(int i = 0; i < sizze; i++){
            if(key[i] == k){
                value[i] = v;
            }
        }
        key[sizze] = k;
        value[sizze] = v;
        sizze++;
    }

    int get(string k){
        for(int i = 0; i < sizze; i++){
            if(key[i] == k){
                return value[i];
            }
        }
        return -1;
    }

    int size(){
        return sizze;
    }
};

#endif // DEFSYMBOLTABLE_H_INCLUDED
