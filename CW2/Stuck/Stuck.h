//
// Created by stefstef on 20/5/2017.
//

#ifndef INC_2_STUCK_H
#define INC_2_STUCK_H

#include <stdio.h>
#include <iostream>
#include "Errors/PopNotAvailable.h"


template <class T>class Stuck {
private:
    struct Node{
        T Datum;
        struct Node *Next;
        Node(T _Datum):Datum(_Datum),Next(NULL){}
    }*Head=NULL;
    int Data=0;
public:
    void push(T element){
        this->Data+=1;
        if(Head==NULL){
            Head = new Node(element);
        }
        else{
            Node *ptrToNewHead = new Node(element);
            ptrToNewHead->Next=Head;
            Head=ptrToNewHead;
        }
    }
    T pop(){
        if(!Data)throw PopNotAvailable();
        this->Data-=1;
        Node*ptrToRemoveHead = Head;
        T returnData = Head->Datum;
        Head=Head->Next;
        delete ptrToRemoveHead;
        return returnData;
    }
};


#endif //INC_2_STUCK_H
