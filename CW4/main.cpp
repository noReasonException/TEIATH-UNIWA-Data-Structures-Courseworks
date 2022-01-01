#include <iostream>
#include "Tree/Tree.h"


int main() {
    Tree e;

    e.insert(50,"Lesson 01");
    e.insert(30,"Lesson 02");
    e.insert(70,"Lesson 03");
    e.insert(20,"Lesson 04");
    e.insert(40,"Lesson 05");
    e.insert(60,"Lesson 06");
    e.insert(80,"Lesson 07");

    e.Delete(50);

    std::cout<<"Μαθημα με κωδικο 30 "<<e.SimpleSearch(30)<<std::endl;


    e.TraverseBFS();
    e.Inorder();
    std::cout<<std::endl;
    e.PostOrder();
    std::cout<<std::endl;
    e.PreOrder();









}