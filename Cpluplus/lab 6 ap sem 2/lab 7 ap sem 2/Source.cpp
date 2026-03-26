#include <iostream>
#include "ttTree.h"

int main()
{

    ttTree mytree;
    mytree.ttTreeInsert(20);
    mytree.ttTreeInsert(34);
    mytree.ttTreeInsert(29);
    mytree.ttTreeInsert(100);
    mytree.ttTreeInsert(4);
    mytree.ttTreeInsert(6);
    mytree.ttTreeInsert(13);
    mytree.ttTreeInsert(19);
    mytree.ttTreeInsert(130);
    mytree.ttTreeInsert(8);
    mytree.ttTreeInsert(15);
    std::cout<<mytree.search(26)<<std::endl;
    mytree.ttTreePrint();
    mytree.ttTreeDelete(8);
    mytree.ttTreeDelete(130);
    mytree.ttTreeDelete(13);
    mytree.ttTreeDelete(20);
    mytree.ttTreePrint();
    return 0;
}