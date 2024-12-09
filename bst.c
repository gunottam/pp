#include <stdio.h>
#include <stdlib.h>

typedef struct node {
      struct node * l;
      struct node * r;
      int data;
      }node;

void insert(node **, int);
void inorder(node *);
void del(node **,int);
node * findnext(node * a){
      while(a != NULL && a->r != NULL)
            a = a->l;
      return a;
}
int main(){
      int c = 1;
      node*root = NULL;
      while (c!=-1)
      {
            printf("\n1. Insert\n2. Inorder\n3. Delete\n4. Exit\n");
            scanf("%d",&c);
            switch(c){
                  case 1:
                        int x;
                        scanf("%d",&x);
                        insert(&root, x);
                        break;
                  case 2:
                        inorder(root);
                        break;
                  case 3:
                        int y;
                        scanf("%d",&y);
                        del(&root,y);
                        break;
                  default:
                        c=-1;
                        break;
            }
      }
      

      return 0;
}

void insert(node ** root , int d){
      if(*root == NULL){
            *root = (node*)malloc(sizeof(node));
            (*root)->data = d;
            (*root)->l = NULL;
            (*root)->r = NULL;
      }
      else if(d < (*root)->data)
            insert(&((*root)->l),d);
      else if(d>(*root)->data)
            insert(&((*root)->r),d);
}

void inorder(node * root){
      if(root == NULL) return;

      inorder(root->l);
      printf("%d ",root->data);
      inorder(root->r);
}

void del(node ** rootref, int key){
      node * root = *rootref;
      if(root == NULL)
            return;
      
      else if(key < root->data)
            del(&(root->l),key);
      else if(key>root->data)
            del(&(root->r),key);
      else{
            if(root->l == NULL && root->r == NULL){
                  free(root);
                  *rootref = NULL;
            }
            else if(root->l == NULL){
                  node * temp = root->r;
                  free(root);
                  *rootref = temp;
                  }
            else if(root->r == NULL){
                  node * temp = root->l;
                  free(root);
                  *rootref = temp;
            }
            else{
                  node * temp = findnext(root->r);
                  root->data = temp->data;
                  del(&(root->r),temp->data);
            }
      }
}
      
