 #include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next,*pre;
}*start;
void create()
{
    int n,val,i;
    struct node*newnode,*temp;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    newnode=(struct node*)malloc(sizeof(struct node));
    start=newnode;
    printf("Enter the value of node 1:\n");
    scanf("%d",&val);
    newnode->data=val;
    temp=start;
    for(i=1;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the value of node %d:\n",i+1);
        scanf("%d",&val);
        newnode->data=val;
        temp->next=newnode;
        newnode->pre=temp;
        temp=newnode;
    }
}
void InsertBefore()
{
    int val,x;
    struct node*newnode,*temp,*p;
    printf("Enter value before which you want to insert:\n");
    scanf("%d",&x);
    printf("Enter value to be inserted:\n");
    scanf("%d",&val);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    temp=start;
    while(temp->data!=x)
    {
        p=temp;
        temp=temp->next;
    }
    if(temp==start)
    {
        newnode->next=temp;
        temp->pre=newnode;
        start=newnode;
    }
    else
    {
    p->next=newnode;
    newnode->pre=p;
    newnode->next=temp;
    temp->pre=newnode;
    }
}
void InsertAfter()
{
    int val,x;
    struct node*newnode,*temp,*post;
    printf("Enter value after which you want to insert:\n");
    scanf("%d",&x);
    printf("Enter value to be inserted:\n");
    scanf("%d",&val);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    temp=start;
    while(temp->data!=x)
    {
        temp=temp->next;
    }
    post=temp->next;
    newnode->next=post;
    newnode->pre=temp;
    temp->next=newnode;
    if(post!=NULL)
        post->pre=newnode;
}
void Delete()
{
    int val;
    struct node*temp,*post,*p;
    printf("Enter value to be deleted:\n");
    scanf("%d",&val);
    temp=start;
    while(temp!=NULL && temp->data!=val)
    {
        p=temp;
        temp=temp->next;
    }
    if(temp==NULL)
        printf("Value not found");
    else if(temp==start)
    {
        post=temp->next;
        post->pre=temp->pre;
        start=post;
        free(temp);
    }
    else{
        post=temp->next;
        p->next=post;
        if(post!=NULL)
            post->pre=p;
    free(temp);
    }
}
void Display()
{
    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%d""\t",temp->data);
        temp=temp->next;
    }
}
int main()
{
    int ch,n;
    start=NULL;
    create(n);
    do
    {
        printf("\nMenu");
        printf("\n1.Insert Before");
        printf("\n2.InsertAfter");
        printf("\n3.Delete ");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\nEnter your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
        InsertBefore();
        break;
        case 2:
        InsertAfter();
        break;
        case 3:
        Delete();
        break;
        case 4:
        Display();
        break;
        }
    }
    while(ch!=5);
return 0;
}