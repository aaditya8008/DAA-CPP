#include <iostream>
#include <cmath>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    void frontInsert(int data)
    {
        Node *n = new Node(data);
        n->next = head;
        head = n;
    }
    void frontDelete()
    {
        if (head == NULL)
        {
            cout << "Empty list\n";
            return;
        }
        if (head->next == NULL)
        {
            cout << "List became Empty list\n";
            Node *temp = head;
            head = NULL;
            delete temp;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void endInsert(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            Node *h = head;
            while (h->next != NULL)
            {
                h = h->next;
            }
            h->next = n;
        }
    }
    void endDelete()
    {
        if (head == NULL)
        {
            cout << "Empty list\n";
            return;
        }
        Node *h = head;
        while (h->next->next != NULL)
        {
            h = h->next;
        }
        Node *temp = h->next;
        h->next = NULL;
        delete temp;
    }
    void midInsert(int data, int idx)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            Node *h = head;

            for (int i = 0; i < idx - 1; i++)
            {

                h = h->next;
            }
            n->next = h->next;
            h->next = n;
        }
    }
    void midDelete(int idx)
    {
        if (head == NULL)
        {
            cout << "Empty list\n";
            return;
        }
        Node *h = head;
        for (int i = 0; i < idx - 1; i++)
        {
            if (head == NULL)
            {
                cout << "Invalid Index\n";
                return;
            }
            h = h->next;
        }
        Node *temp = h->next;
        h->next = h->next->next;
        delete temp;
    }

    int search(int data)
    {
        int idx = 0;
        Node *h = head;
        while (h != NULL)
        {
            if (h->data == data)
            {
                return idx;
            }
            h = h->next;
            idx++;
        }
        return -1;
    }

    int max()
    {
        if (head == NULL)
        {
            cout << "Empty list\n";
            return -1;
        }
        int m = head->data;
        Node *h = head;
        while (h != NULL)
        {
            if (h->data > m)
            {
                m = h->data;
            }
            h = h->next;
        }
        return m;
    }

    int min()
    {
        if (head == NULL)
        {
            cout << "Empty list\n";
            return -1;
        }
        int m = head->data;
        Node *h = head;
        while (h != NULL)
        {
            if (h->data < m)
            {
                m = h->data;
            }
            h = h->next;
        }
        return m;
    }

    void sort()
    {
        if (head == NULL)
        {
            return;
        }

        Node *h1;
        Node *h2 = NULL;
        int temp;

        bool swapped;
        do
        {
            swapped = false;
            h1 = head;

            while (h1->next != h2)
            {
                if (h1->data > h1->next->data)
                {
                    temp = h1->data;
                    h1->data = h1->next->data;
                    h1->next->data = temp;
                    swapped = true;
                }
                h1 = h1->next;
            }
            h2 = h1;
        } while (swapped);
    }

    double avg(){
        Node *h=head;
        double sum=0;
        int size=0;
        while(h!=NULL){
            sum+=h->data;
            size++;
            h=h->next;
        }
        return sum/size;
    }
    double standardDeviation(){
        Node *h=head;
        double mean=avg();
        double sumDiff=0;
        int size=0;
        while(h!=NULL){
            sumDiff+=(h->data-mean)*(h->data-mean);
            size++;
            h=h->next;
        }
        double var=sumDiff/size;
        double sd=sqrt(var);
        return sd;
    }
bool isPrime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

void findPrime(){
    Node *h=head;
    while(h!=NULL){
        if(isPrime(h->data)){
            cout << "->" << h->data;
        }
        h=h->next;
    }
    cout<<endl;
}
void findOdd(){
    Node *h=head;
    while(h!=NULL){
        if(h->data%2!=0){
            cout << "->" << h->data;
        }
        h=h->next;
    }
     cout<<endl;

}



    void pr()
    {
        Node *h = head;
        while (h != NULL)
        {
            cout << "->" << h->data;
            h = h->next;
        }
        cout << endl;
    }
    
};
int main()
{
    LinkedList ll;
   for (int i = 0; i < 100; i++) {
       ll.endInsert(rand()%100+1);
    }
    ll.pr();
}