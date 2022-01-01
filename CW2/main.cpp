#include <iostream>
#include "Stuck/Stuck.h"
int Menu_Main();
void moveStucks(Stuck<int>&A,Stuck<int>&B);
void copyAtoB(Stuck<int>&A,Stuck<int>&B);
int main() {
    Menu_Main();
}

int Menu_Main(){
    Stuck<int>A;
    Stuck<int>B;
    int res;
    int tmp;

    do{
        printf("*------------------------------------------------------------------*\n");
        printf("1)Place In stuck A\n");
        printf("2)Pop from stucκ A\n");
        printf("3)Move All from A to B\n");
        printf("4)Pop from B\n");
        printf("5)Copy A to B\n");
        printf("6)Exit\n");
        printf("*------------------------------------------------------------------*\n");
        scanf("%d",&res);
        try{
            switch (res){
                case 1:printf("Number? ");scanf("%d",&tmp);A.push(tmp);break;
                case 2:std::cout<<"Number -> "<<A.pop()<<std::endl;break;
                case 3:moveStucks(A,B);break;
                case 4:std::cout<<"Number -> "<<B.pop()<<std::endl;break;
                case 5:copyAtoB(A,B);
            }
        }catch (PopNotAvailable &e){
            printf("Non Available\n");
        }


    }while(res!=6);
    return EXIT_SUCCESS;

}
void moveStucks(Stuck<int>&A,Stuck<int>&B){
    try{
        while(1){
            B.push(A.pop());
        }
    }catch (PopNotAvailable &e){
        return ;
    }
}

void copyAtoB(Stuck<int> &A, Stuck<int> &B) {
    try{
        while(1)B.pop();
    }catch (PopNotAvailable&e){}
    Stuck<int>tmp;
    try{
        while(1)tmp.push(A.pop());
    }catch (PopNotAvailable&e){}
    try{
        while(1)B.push(tmp.pop());
    }catch (PopNotAvailable&e){}


}
