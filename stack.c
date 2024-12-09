//implementation of linked list using stack
#include <stdio.h>
#include <stdlib.h>

typedef struct lili{
int data;
struct lili *next;
}sl;

sl* push(sl*);
sl* pop(sl*);
void display(sl*);
int main()
{
        sl *top=NULL;
        int n;
        do{
        {
                printf("1 to push\n2 to pop\n3 to display\n");
                scanf("%d",&n);
                switch(n)
                {
                        case 1:
                                top=push(top);
                                break;
                        case 2:
                                top=pop(top);
                                break;
                        case 3:
                                display(top);
                                break;                                
                }
        }}while(n<=3);
        return 0;
}

sl* push(sl *tp)
{
        sl *p=NULL;  //p is a temporary node
        p=(sl*)malloc(sizeof(sl));
        int v;
        if(p!=NULL)
        {
                printf("Enter element to enter:");
                scanf("%d",&v);
                p->data=v;
                p->next=tp;
                tp=p;
        }
        else
        {
                printf("memory allocation failed\n");
        }
        return tp;
}

sl* pop(sl *tp)
{
        sl*p=NULL;
        if(tp==NULL)
        {
                printf("Stack is empty\n");
        }
        else
        {
                p=tp;
                printf("popped element is:%d\n",tp->data);
                tp=tp->next;
                free(p);
        }
        return tp;
}                                                                

void display(sl* tp)
{
        if(tp==NULL)
        {
                printf("Stack is empty\n");
        }
        else
        {
                while(tp!=NULL)
                {
                        printf("%d ",tp->data);
                        tp=tp->next;
                }
                printf("\n");
        }
}