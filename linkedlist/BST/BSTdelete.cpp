#include<bits/stdc++.h> 
using namespace std; 

struct node{ 
    int data; 
    node *left; 
    node *right; 
}; 

node *root = NULL; 
node *curr_node = NULL; 
node *prev_node = NULL; 

void BST_insert(int value){ 
    node *temp=new node(); 
    temp->data=value; 
    temp->left=NULL; 
    temp->right=NULL; 

    if(root==NULL) 
        root=temp; 
    else{ 
      curr_node=root; 
      prev_node=root; 

      while(curr_node!=NULL){ 
          prev_node=curr_node; 
          if(curr_node->data < value) 
              curr_node=curr_node->right; 
          else 
              curr_node=curr_node->left; 
      } 
      
      if(prev_node->data < value) 
          prev_node->right=temp; 
      else 
          prev_node->left=temp; 
    } 
}

void preOrder(node*root){ 
    if(root!=NULL){ 
      cout<<root->data<<" "; 
      preOrder(root->left); 
      preOrder(root->right); 
    } 
} 

void deleteNode(int val){
  node *curr = NULL,*prev = NULL;
  curr = root;
  prev = root;
  
  while(curr != NULL){
    if(curr->data == val)
      break;
    
    prev = curr;
    if(val > curr->data)
      curr = curr->right;
    else
      curr = curr->left;
  }
  
  cout << endl << "target node: " << curr->data << endl;
  cout << "previous node: " << prev->data << endl;
  
  //faka tree
  if(curr == NULL){
    cout << "shurutei return." << endl;
    return;
  }
    
    
  // leaf node
  else if(curr->left == NULL && curr->right == NULL){  
    cout << "leaf node block e dhukse" << endl;
    if(prev->right == curr)
      prev->right = NULL;
    else
      prev->left = NULL;
  }
  
  // ekta child shoho node
  else if(curr->left == NULL || curr->right == NULL){
    cout << "ekta child" << endl;
    node *child = new node();
    
    if(curr->left == NULL)
      child = curr->right;
    else
      child = curr->left;
      
    cout << endl << "child data: " << child->data << endl;
    
    if(prev == NULL){
      root = child;
      cout << "1" << endl;
    }
    else if(prev->right == curr){
      prev->right = child;
      cout << "2" << endl;
    }
    else{
      prev->left = child;
      cout << "3" << endl;
    }
  }
  
  //duita child
  else if (curr->left != NULL || curr->right != NULL){
    cout << "duita child" << endl;
     node *temp = curr;
     prev = curr;
     curr = curr->left;
     
     while(curr->right != NULL){
       prev = curr;
       curr = curr->right;
     }
     
     temp->data = curr->data;
     if(prev->left == curr){
       prev->left = curr->left;
     }
     else
       prev->right = curr->left;
  }
  else{
    cout << "kisui hoy nai." << endl;
  }
}

int main(){ 
    int x; 
    for(int i=1; i<=11; i++){ 
      cin>>x; 
      BST_insert(x); 
    } 

    cout << endl << "pre order : "; 
    preOrder(root); 
    
    deleteNode(5);
    
    cout << endl << "pre order : "; 
    preOrder(root);
} 

// 12 6 9 18 4 10 5 16 49 31 43