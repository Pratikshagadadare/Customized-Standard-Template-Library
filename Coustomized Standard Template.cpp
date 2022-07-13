//Generic
#include<iostream>
using namespace std;

template <typename T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template <class T>
class SinglyLL
{
private:
    node<T>* first;
    int size;
    
public:
    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T , int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
   
};
 template <class T>
 SinglyLL<T>::SinglyLL()
   {
       first = NULL;
       size = 0;
   }

   template <class T>
   void SinglyLL<T>::InsertFirst(T no)
   {
        node<T>* newn = new node<T>;  // newn = (PNODE)malloc(sizeof(NODE))
       
       newn->data = no;
       newn->next = NULL;
       
       if(first == NULL)
       {
           first = newn;
       }
       else
       {
           newn->next = first;
           first = newn;
       }
       size++;
   }

   template <class T>
   void SinglyLL<T>::InsertLast(T no)
   {
        node<T>* newn = new  node<T>;  // newn = (PNODE)malloc(sizeof(NODE))
       
       newn->data = no;
       newn->next = NULL;
       
       if(first == NULL)
       {
           first = newn;
       }
       else
       {
         node<T>* temp = first;
           
           while(temp->next != NULL)
           {
               temp = temp->next;
           }
           temp->next = newn;
       }
       size++;
   }

   template <class T>
   void SinglyLL<T>::InsertAtPos(T no, int ipos)
   {}

   template <class T>
   void SinglyLL<T>::DeleteFirst()
   {
        node<T>* temp = first;
       
       if(first != NULL)
       {
           first = first->next;
           delete temp;
           
           size--;
       }
   }

   template <class T>
   void SinglyLL<T>::DeleteLast()
   {
        node<T>* temp = first;
       
       if(first == NULL)
       {
           return;
       }
       else if(first->next == NULL)
       {
           delete first;
           first = NULL;
           size--;
       }
       else
       {
           while(temp->next->next != NULL)
           {
               temp = temp->next;
           }
           
           delete temp->next;
           temp->next = NULL;
           size--;
       }
   }

   template <class T>
   void SinglyLL<T>::DeleteAtPos(int ipos)
   {}

   template <class T>
   void SinglyLL<T>::Display()
   {
        node<T>* temp = first;
       
       while(temp!= NULL)
       {
           cout<<temp->data<<"\t";
           temp = temp->next;
       }
       cout<<"\n";
   }

   template <class T>
   int SinglyLL<T>::Count()
   {
       return size;
   }
   template <class T>
class DoublyLL
{
    private:
    node<T>*first;
    int size;

    public:
    DoublyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T , int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};
template<class T>
DoublyLL<T>::DoublyLL()
{
     first = NULL;
     size = 0;
}
template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    node<T>*newn=new node<T>;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(first==NULL)
    {
        first=newn;
    }
    else
    {
        newn->next=first;
        first->prev=newn;
        first=newn;
    }
    size++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    node<T>*newn=new node<T>;
   // node<T>* temp = first;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(first==NULL)
    {
        first=newn;
    }
    else
    {
     node<T>* temp = first;
     while (temp->next!=NULL)
     {
         temp=temp->next;
     }
     temp->next=newn;
     newn->prev=temp;
    }
    size++;
}
template<class T>
void DoublyLL<T>::DeleteFirst()
{
     node<T>* temp = first;
       
       if(first != NULL)
       {
           first = first->next;
           delete temp;
           
           size--;
       }
}
template <class T>
void DoublyLL<T>::DeleteLast()
{
  node<T>* temp = first;
       
       if(first == NULL)
       {
           return;
       }
       else if(first->next == NULL)
       {
           delete first;
           first = NULL;
           size--;
       }
       else
       {
           while(temp->next != NULL)
           {
               temp = temp->next;
           }
           
          temp->prev->next=NULL;
          delete temp;          
       }
       size--;
}
template<class T>
void DoublyLL<T>::Display()
   {
        node<T>* temp = first;
       
       while(temp!= NULL)
       {
           cout<<temp->data<<"\t";
           temp = temp->next;
       }
       cout<<"NULL\n";
   }
   template <class T>
   int DoublyLL<T>::Count()
   {
       return size;
   }
///////////////////////////////////////////////////////////////////////////
int main()
{
    SinglyLL <int>iobj;
    // iret = obj.Count();
    int iret = 0;
    
    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);
    
    iobj.InsertLast(101);
    iobj.InsertLast(111);
    iret = iobj.Count();
    iobj.Display();
    
    
    cout<<"Number of elemensts are : "<<iret<<"\n";
    ////////////////////////////////////////
DoublyLL<char>cobj;
   // int iret=0;

        
    cobj.InsertFirst('A');
    cobj.InsertFirst('B');
    cobj.InsertFirst('C');
    
    cobj.InsertLast('D');
    cobj.InsertLast('E');
    
    cobj.Display();
    
    iret = cobj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
    
    return 0;
}

//////////////////////////////////////////////////////

 /*SinglyLL <int>cobj;
     
    int iret = 0;
    
    iobj.InsertFirst('A');
    iobj.InsertFirst('B');
    iobj.InsertFirst('C');
    
    iobj.InsertLast('D');
    iobj.InsertLast('E');
    
    iobj.Display();
    
    iret = obj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
    
    return 0;*/

















/*
 Type 1
 
 wihle(temp!= NULL)
 {
    temp = temp->next;
 }
 
 --------------------------------------
 
 Type 2
 
 while(temp->next != NULL)
 {
    temp = temp->next;
 }
 
 ---------------------------------------
 
 Type 3
 
while(temp->next->next != NULL)
 {
 temp = temp->next;
 }
 
 
 
 */










