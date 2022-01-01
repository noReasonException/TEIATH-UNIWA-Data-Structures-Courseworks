#ifndef TREE
#define TREE

#include <stdio.h>
#include <iostream>
#include <queue>

class Tree {
public:
    struct Node {
    public:
        int ID;
        std::string Name;
        struct Node *Left = NULL, *Right = NULL;

        Node(int _ID, std::string _Name) : Name(_Name), ID(_ID) {}
        Node(const Node &e):ID(e.ID),Name(e.Name),Left(e.Left),Right(e.Right){}
    };

private:
    struct Node *getHead(){return this->ptrToHead;}
    void setHead(struct Node *ptr){this->ptrToHead=ptr;}
    struct Node *ptrToHead = NULL;
    bool isLeaf(struct Node *ptr){
        return ptr->Right==NULL and ptr->Left==NULL;
    }
    bool hasOneChild(struct Node *ptr){
        return (ptr->Left==NULL and ptr->Right!=NULL) or (ptr->Left!=NULL and ptr->Right==NULL) ;
    }
    struct Node *getOnlyChildOf(struct Node *ptr){
        if(ptr==NULL)return NULL;
        if(ptr->Left!=NULL)return ptr->Left;
        else return ptr->Right;
    }
    Node *getCurrentFromPreviousPointer(struct Node *ptr,bool &isLeft,int ID){
        isLeft=false;
        if(ptr==NULL)return NULL;
        if(ptr->ID==ID)return ptr;
        if(ptr->Left!=NULL){
            if(ptr->Left->ID==ID){
                isLeft=true;
                return ptr->Left;
            }
            else return ptr->Right;
        }

        return ptr->Right;

    }
    Node * getPreviousPointerSearch(int ID){
        struct Node *tmp = this->ptrToHead;
        struct Node *prevTmp = this->ptrToHead;
        do{
            if(ID<tmp->ID){
                prevTmp=tmp;
                tmp=tmp->Left;
            }
            else if(ID>tmp->ID){
                prevTmp=tmp;
                tmp=tmp->Right;
            } else return prevTmp;
            if(tmp==NULL)throw std::invalid_argument("No ID Found");
        }while(1);

    }
    void TraverseDFSPostorder(Node *Head){
        std::cout<<Head->ID<<"| ";
        if(Head->Left!=NULL)TraverseDFSPostorder(Head->Left);

        if(Head->Right!=NULL)TraverseDFSPostorder(Head->Right);
    }
    void TraverseDFSInorder(Node *Head) {

        if (Head->Left != NULL)TraverseDFSInorder(Head->Left);
        std::cout << Head->ID <<"| ";
        if (Head->Right != NULL)TraverseDFSInorder(Head->Right);
    }

    void TraverseDFSPrerder(Node *Head){
        if (Head->Left != NULL)TraverseDFSInorder(Head->Left);
        std::cout << Head->ID <<"| ";
        if (Head->Right != NULL)TraverseDFSInorder(Head->Right);
    }
    Node *getSmallestFromBiggest(Node *Root){
        if(Root->Right==NULL)
            return NULL;
        Node *StartingPoint = Root->Right;
        while(StartingPoint->Left!=NULL)StartingPoint=StartingPoint->Left;
        return StartingPoint;
    }
    Node* getBiggestFromSmallest(Node *Root){
        if(Root->Left==NULL)
            return NULL;
        Node *StartingPoint = Root->Left;
        while(StartingPoint->Right!=NULL)StartingPoint=StartingPoint->Right;
        return StartingPoint;
    }

public:

    void insert(int ID, std::string Name) {
        if (this->ptrToHead == NULL) {
            this->ptrToHead = new Node(ID, Name);
        } else {
            struct Node *ptrTemp = this->ptrToHead;
            struct Node *prev = ptrTemp;
            while (1) {
                if (ID < ptrTemp->ID) {
                    if (ptrTemp->Left == NULL) {
                        ptrTemp->Left = new Node(ID, Name);
                        break;
                    }
                    ptrTemp = ptrTemp->Left;
                } else if (ID > ptrTemp->ID) {
                    if (ptrTemp->Right == NULL) {
                        ptrTemp->Right = new Node(ID, Name);
                        break;
                    }
                    ptrTemp = ptrTemp->Right;
                } else throw std::invalid_argument("Duplicate key not allowed");
            }
        }
    }
    std::string SimpleSearch(int ID){
        struct Node *tmp = this->ptrToHead;
        do{

            if(ID<tmp->ID){
                tmp=tmp->Left;
            }
            else if(ID>tmp->ID){
                tmp=tmp->Right;
            } else return tmp->Name;
            if(tmp==NULL)throw std::invalid_argument("No ID Found");
        }while(1);

    }
    Node * Search(int ID){
        struct Node *tmp = this->ptrToHead;
        do{

            if(ID<tmp->ID){
                tmp=tmp->Left;
            }
            else if(ID>tmp->ID){
                tmp=tmp->Right;
            } else return tmp;
            if(tmp==NULL)throw std::invalid_argument("No ID Found");
        }while(1);

    }

    void Delete(int ID){
        bool isLeft;
        SimpleSearch(ID);
        Node *ptrPrevious = this->getPreviousPointerSearch(ID); //Προηγούμενος Pointer;
        Node*ptr=this->getCurrentFromPreviousPointer(ptrPrevious,isLeft,ID);
        if(isLeaf(ptr)){ //

            if(isLeft){
                ptrPrevious->Left=NULL;
            }
            else{
                ptrPrevious->Right=NULL;
            }
            delete ptr;

        }
        else if(hasOneChild(ptr)){
            if(isLeft){
                ptrPrevious->Left=getOnlyChildOf(ptr);
            } else{
                ptrPrevious->Right=getOnlyChildOf(ptr);
            }
            delete(ptr);
        }
        else{
            //Allocate Proper Node;
            Node *ReplacementNode=this->getBiggestFromSmallest(ptr);
            if(ReplacementNode==NULL){
                ReplacementNode=this->getSmallestFromBiggest(ptr);
            }
            int IDTmp=ReplacementNode->ID;
            std::string tmp(ReplacementNode->Name);
            Delete(ReplacementNode->ID);
            ptr->ID=IDTmp;
            ptr->Name=tmp;
        }
    }
    void Inorder(){
        this->TraverseDFSInorder(this->getHead());
    }
    void PostOrder(){
        this->TraverseDFSPostorder(this->getHead());
    }
    void PreOrder(){
        this->TraverseDFSPrerder(this->getHead());
    }
    void TraverseBFS(){
        std::queue<Node *> e;
        Node *tmp;
        e.push(this->getHead());
        while(!e.empty()){
            tmp=e.front();
            e.pop();
            std::cout<<(tmp->ID)<<"| ";
            if(tmp->Left!=NULL)e.push(tmp->Left);
            if(tmp->Right!=NULL)e.push(tmp->Right);

        }
        std::cout<<std::endl;
    }
};
#endif