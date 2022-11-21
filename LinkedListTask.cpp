#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node* link;

    Node(int val) {
        data= val;
        link= NULL;
    }
};

void insertAtHead(Node* &head, int val) {
    Node* n= new Node(val);
    n->link= head;
    head= n;
}

void insertAtN(Node* head, int x, int val) {
    Node* n= new Node(val);
    Node* temp= head;
    for(int i=0;i<x;i++) {
        temp= temp->link;
    }

    n->link= temp->link;
    temp->link= n;
 
}

void insertAtTail(Node* &head, int val) {
    Node * n= new Node(val);

    if(head==NULL) {
        head=n;
        return;
    }
    Node* temp= head;

    while(temp->link!=NULL) {
        temp= temp->link;
    }
    temp->link= n;

}

void delVal(Node* head, int val) {
    Node* temp= head;

    while(temp->link->data!=val) {
        temp= temp->link;
    }

    Node* todel= temp->link;
    temp->link= temp->link->link;
    delete todel;
}

void delAtN(Node* head, int n) {
    Node* temp= head;
    for(int i=1;i<n;i++) {
        temp= temp->link;
    }
    Node* todel= temp->link;
    temp->link= temp->link->link;
    delete todel;

}


void printAll(Node* head) {
    Node *temp = head;

    while(temp!=NULL) {
        cout<< temp->data << " ";
        temp= temp->link;
    }
    cout<<"\n"<<endl;
    cout<<"Enter anything to continue:" << endl;
    string x;
    cin>> x;
}

void delHead(Node* &head) {
    Node* temp= head;
    head= head->link;
    delete temp;
}

void delTail(Node* head) {
    Node* temp= head;

    while(temp->link->link!=NULL) {
        temp= temp->link;
    }

    Node* todel= temp->link;
    temp->link= NULL;
    delete todel;
}


int main() {
    
    Node* head= NULL;

    string choice, value, position;
    int ch, val, pos;
    bool wronginput=false;

    while(1) {
        system("cls");
        cout<<"\n\nLinked List Manageer" << endl;
        if(wronginput) {
            cout<<"You entered a wrong choice. Please try again. ";
            wronginput=false;
        }
        cout<<"1. Display All Nodes" << endl;
        cout<<"2. Insert at Tail" << endl;
        cout<<"3. Insert at Head" << endl;
        cout<<"4. Insert at N position" << endl;
        cout<<"5. Delete a value" << endl;
        cout<<"6. Delete Head" << endl;
        cout<<"7. Delete Tail" << endl;
        cout<<"8. Delete at N Position" << endl;
        cout<<"0. Exit" << endl;
        cout<<"\nEnter your choice:" << endl;

        cin>> choice;

        ch= int(choice[0]) ;
        ch-=48;

        cout<< ch<<endl;


        switch(ch) {
            case 1:
                printAll(head);
                break;
            case 2:
                system("cls");
                cout<<"Enter a value to add at Tail: " << endl;
                cin>> val;
                insertAtTail(head,val);
                break;
            case 3:
                system("cls");
                cout<<"Enter a value to add at Head:" << endl;
                cin>> val;
                insertAtTail(head, val);
                break;
            case 4:
                system("cls");
                cout<<"Enter a value to add:" << endl;
                cin>> val;
                cout<<"Enter the position for the value:" << endl;
                cin>> pos;
                insertAtN(head, pos, val);
                break;
            case 5:
                system("cls");
                cout<<"Enter a value you want to delete:" << endl;
                cin>> val;
                delVal(head, val);
                break;
            case 6:
                system("cls");
                delHead(head);
                cout<<"Head Deleted.\nEnter anything to continue" << endl;
                cin>> choice;
                break;
            case 7:
                system("cls");
                delTail(head);
                cout<<"Tail deleted. \nEnter anything to continue:" << endl;
                cin>> choice;
                break;
            case 8: 
                cout<<"Enter the position  you want to delete:" << endl;
                cin>> pos;
                delAtN(head, pos);
                break;
            case 0:
                return 0;
            default: 
                wronginput=true;

        }
    }

    return 0;
}

