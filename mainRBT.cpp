#include "RBTree.hpp"

int main(){
    RBTree<std::string> tree;
    RBTree<int> treeInt;
    std::string mystring("1st element");
    tree.print();
    tree.insert(mystring);
    try {
        tree.insert(mystring);
    } catch (const std::exception &e) {
        std::cout << "catch:" << e.what() << "\n";
    }
    tree.print();

    treeInt.insert(76);
    treeInt.insert(101);
    treeInt.insert(16);
    treeInt.insert(90);
 
    treeInt.insert(85);
    treeInt.insert(65);
    treeInt.insert(55);
    treeInt.insert(20);
    treeInt.insert(71);
    treeInt.insert(81);
    treeInt.insert(93);
    treeInt.insert(52);
    treeInt.insert(100);
    treeInt.insert(61);
    treeInt.print();

    // treeInt.insert(7);
    // treeInt.insert(6);
    // treeInt.insert(9);
    // treeInt.print();
    // treeInt.insert(8);
    // treeInt.print();
    // treeInt.insert(2);
    // treeInt.print();
    // treeInt.insert(3);
    // treeInt.insert(1);
    // treeInt.print();


    return 0;
}