#pragma once
//source : https://www.cprogramming.com/tutorial/lesson18.html
#include<iostream>
using namespace std;

struct node{
    int key_value;
    node *left;
    node *right;
};

class BTree{
    public:
    BTree();
    ~BTree();

    void insert(int key);
    node *search(int key);
    void destroy_tree();

    private:
    void destroy_tree(node *leaf);
    void insert(int key,node *leaf);
    node* search(int key, node *leaf);
    node* searchSimpler(int key,node *leaf);
    node *root;
};

//constructor
BTree::BTree(){
    root=NULL;
}

//destructor
BTree::~BTree(){
    destroy_tree();
}

//public:
void BTree::destroy_tree(){
    destroy_tree(root);
}

void BTree::insert(int key){
    if(root!=NULL){            //if root is present
        insert(key,root);
    }
    else{                    //create root
        root = new node;
        root->key_value=key;
        root->left = NULL;
        root->right=NULL;
    }
}

node* BTree::search(int key){
    return search(key,root);
}


//private:
void BTree::destroy_tree(node *leaf){
    if(leaf!=NULL){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void BTree::insert(int key,node *leaf){
    if(key < leaf->key_value){
        if(leaf->left!=NULL){
            insert(key,leaf->left);
        }
        else{
            leaf->left=new node;
            leaf->key_value = key;
            leaf->left = NULL;
            leaf->right = NULL;
        }
    }
    else if(key > leaf->key_value){
        if(leaf->right!=NULL){
            insert(key,leaf->right);
        }
        else{
            leaf->right = new node;
            leaf->key_value = key;
            leaf->left = NULL;
            leaf->right = NULL;
        }
    }
}

node* BTree::search(int key, node *leaf){
    if(key<leaf->key_value){
        if(leaf->left!=NULL){
            search(key,leaf->left);
        }
        else{
            return leaf;
        }
    }
    else if(key>leaf->key_value){
        if(leaf->right!=NULL){
            search(key,leaf->right);
        }
        else{
            return leaf;
        }
    }
}

node* BTree::searchSimpler(int key,node *leaf){
    if(leaf!=NULL){
        if(key==leaf->key_value){
            return leaf;
        }
        if(key<leaf->key_value){
            search(key,leaf->left);
        }
        else{
            search(key,leaf->right);
        }
    }
}





