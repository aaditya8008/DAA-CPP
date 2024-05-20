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
    int choice, data, index;

    while (true)
    {
        cout << "Menu:\n";
        cout << "1. Insert at front\n";
        cout << "2. Delete from front\n";
        cout << "3. Insert at end\n";
        cout << "4. Delete from end\n";
        cout << "5. Insert at index\n";
        cout << "6. Delete at index\n";
        cout << "7. Search\n";
        cout << "8. Find max\n";
        cout << "9. Find min\n";
        cout << "10. Sort\n";
        cout << "11. Print\n";
        cout << "12. Find average\n";
        cout << "13. Find standard deviation\n";
        cout << "14. Find prime numbers\n";
        cout << "15. Find odd numbers\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            ll.frontInsert(data);
            break;
        case 2:
            ll.frontDelete();
            break;
        case 3:
            cout << "Enter data: ";
            cin >> data;
            ll.endInsert(data);
            break;
        case 4:
            ll.endDelete();
            break;
        case 5:
            cout << "Enter data and index: ";
            cin >> data >> index;
            ll.midInsert(data, index);
            break;
        case 6:
            cout << "Enter index: ";
            cin >> index;
            ll.midDelete(index);
            break;
        case 7:
            cout << "Enter data: ";
            cin >> data;
            cout << "Index: " << ll.search(data) << endl;
            break;
        case 8:
            cout << "Max: " << ll.max() << endl;
            break;
        case 9:
            cout << "Min: " << ll.min() << endl;
            break;
        case 10:
            ll.sort();
            break;
        case 11:
            ll.pr();
            break;
        case 12:
            cout << "Average: " << ll.avg() << endl;
            break;
        case 13:
            cout << "Standard Deviation: " << ll.standardDeviation() << endl;
            break;
        case 14:
            cout << "Prime numbers: ";
            ll.findPrime();
            break;
        case 15:
            cout << "Odd numbers: ";
            ll.findOdd();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }
}