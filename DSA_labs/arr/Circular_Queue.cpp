#include<bits/stdc++.h>
using namespace std;
#define MaxSize 10

bool IsFull(int *f,int *r)
{
    return (*f==*r+1)||(*f==0 &&*r== MaxSize-1);
    
}

bool IsEmpty(int *front,int *rear)
{
    return *front>*rear||(*front<0&&*rear<0) ;
}

void EnQueue(int CQ[],int *front, int *rear, int element)
{
    if(IsFull(front,rear))
    cout<<"Queue is Full"<<endl;
    else
    {
        if(*front<0)
         *front+=1;

        *rear=(*rear+1)%MaxSize;
        CQ[*rear] = element;
    }
}

int DeQueue(int CQ[],int *front,int *rear)
{
    int element;
    if(IsEmpty(front,rear))
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    else
    {
        element = CQ[*front];
        if(*front==*rear)
        {
            *front = *rear = -1;
        }
        else
        {
            *front = (*front + 1)%MaxSize ;
        }
        cout<<"Deleted element:"<<element<<endl;
        return element;
    }
}

void display(int CQ[],int *front, int *rear)
{
    int i;
    if(IsEmpty(front,rear))
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"Front:"<<*front<<endl;
        for(i=*front;i!=*rear;i=(i+1)%MaxSize)
        {
            cout<<CQ[i]<<" ";
            cout<< CQ[i];
            cout<<"Rear:"<<*rear<<endl;
        }
    }
}
int main()
{
   int front = -1, rear = -1, CQ[MaxSize];

   for(int i=0;i<= MaxSize; i++)
   {
       int ele;
       cout<< "Enter queue element:"<<endl;
       cin>>ele;
       EnQueue(CQ,&front,&rear,ele);
   }

   cout<<"Dequeuing first 3 elements"<<endl;
   for (int i = 0; i < 3; i++)
   {
    DeQueue(CQ,&front,&rear);
   }

   cout<<"Entering 3 new elements:"<<endl;
   EnQueue(CQ,&front,&rear, 78);
   EnQueue(CQ,&front,&rear, 92);
   EnQueue(CQ,&front,&rear,101);
   display(CQ,&front,&rear);
}