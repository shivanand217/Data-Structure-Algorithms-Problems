#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

// using hashing
struct node *newnode(int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));

    tmp->data = data;
    tmp->next = NULL;

    return tmp;
}

void push(struct node **head, int data)
{
     if((*head) == NULL)
     {
        (*head) = newnode(data);
        return;
     }

     struct node *new_ = new struct node;
     new_->data = data;
     new_->next = NULL;

     struct node *tmp = *head;

     while(tmp->next != NULL)
     {
        tmp = tmp->next;
     }

     tmp->next = new_;

     return;
}

void printlist(struct node **head)
{
    struct node *tmp = *head;

    while(tmp != NULL)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }cout<<endl;
}

bool solve(struct node **head)
{
    set<struct node *> hash_;

    struct node *tmp = *head;

    while(tmp != NULL)
    {
        if(hash_.find(tmp) != hash_.end())
        {
            return true;
        }

        hash_.insert(tmp);

        tmp = tmp->next;
    }

    return false;
}

int main()
{
    struct node *head = NULL;

    push(&head, 1);
    push(&head, -2);
    push(&head, -3);
    push(&head, 4);

    head->next->next->next->next = head;

    if(solve(&head))
    {
        cout<<"loop in the linked list exist"<<endl;
    }
    else
    {
        cout<<"no loop exist"<<endl;
    }

    return 0;
}
