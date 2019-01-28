#include "BTree.h"

void BTree::insert(int key, BTree *leaf){
    if(key < leaf->key_value){
        if(leaf->left != nullptr) insert(key, leaf->left);
        else{
            leaf->left = new BTree;
            leaf->left->key_value = key;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
    }
    else if(key > leaf->key_value){
        if(leaf->right != nullptr) insert(key, leaf->right);
        else{
            leaf->right = new BTree;
            leaf->right->key_value = key;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr; 
        }
    }
}

BTree* BTree::search(int key, BTree *leaf){
    if(leaf!=nullptr){
        if(key == leaf->key_value) return leaf;
        if(key < leaf->key_value) search(key,leaf->left);
        else if(key >= leaf->key_value) search(key,leaf->right);
    }
    else return nullptr;
}

void BTree::destroy_tree(BTree *leaf){
    if(leaf!=nullptr){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

BTree::BTree(){
    root = nullptr;
}

//BTree::BTree(const BTree &other){   //copy constructor
//    *this = other;
//}

//const BTree &BTree::operator=(const BTree &other){  //assignment operator
//    this->key_value = other.key_value;
//    this->left = other.left;
//    this->right = other.right;
//    return *this;
//}

BTree::~BTree(){
    destroy_tree();
}

void BTree::insert(int key){
    if(root!=nullptr){
        insert(key,root);
    }
    else{
        root = new BTree();
        root->key_value = key;
        root->left = nullptr;
        root->right = nullptr;
    }
}

BTree* BTree::search(int key){
    return search(key,root);
}

 void BTree::destroy_tree(){
     destroy_tree(root);
 }

 int BTree::getVal()const{
     return key_value;
 }
