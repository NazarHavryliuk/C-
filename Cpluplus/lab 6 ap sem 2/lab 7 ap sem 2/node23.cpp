
#include "node23.h"


node23::node23(int data, node23* parentNode)
{
    leftChild = 0;
    middleChild = NULL;
    rightChild = NULL;
    parent = parentNode;
    smallData = data;
}
node23::node23()
{

}
void node23::nodeEdit(int data, node23* parentNode)
{
    smallData = data;
    bigData = 0;
    parent = parentNode;
    leftChild = middleChild = rightChild = NULL;

}

bool node23::isLeaf()
{
    return (!leftChild && !middleChild && !rightChild);
}

bool node23::isThreeTree()
{

    return (this->bigData != 0);
}
void node23::insert2Tree(int key, node23* leftChild, node23* rightChild)
{
    if (this->smallData > key)
    {
        this->bigData = this->smallData;
        this->smallData = key;
        this->leftChild = leftChild;
        this->rightChild = this->middleChild;
        this->middleChild = rightChild;

    }
    else
    {
        this->bigData = key;
        this->middleChild = leftChild;
        this->rightChild = rightChild;
    }
    this->dataFull = true;
}
