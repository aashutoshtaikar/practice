#pragma once

class BTree{
private:
    int key_value;
    BTree* root;
    BTree* left;
    BTree* right;

private:
    void insert(int key, BTree* leaf);
    BTree* search(int key, BTree* leaf);
    void destroy_tree(BTree* leaf);
    

public:
    BTree();    //constructor
    ~BTree();   //1. destructor
                //2. copy constructor required -- rule of 3
    BTree(const BTree &other);
                //3. assingment operator required -- rule of 3
    const BTree &operator=(const BTree &other);

    void insert(int key);
    BTree* search(int key);
    void destroy_tree();

    int getVal()const;

};



