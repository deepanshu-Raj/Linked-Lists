#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class node{
public:
	ll data;
	node *next;

	node(ll d){
		data=d;
		next=NULL;
	}
};

void delnode(node *&head,ll d){
	node *pre=NULL;
	node *temp=head;
	if(head->data==d){pre=head;
		while(pre->next!=head){
			pre=pre->next;
		}
		head=temp->next;
		pre->next=temp->next;
		temp->next=NULL; 
	}
	else{
	while(temp->data!=d && temp->next!=head){
		pre=temp;
		temp=temp->next;
	}if(temp->next==head && temp->data!=d){
		cout<<"data you wanted to delete is not present!!"<<endl;
		return;
	}
	else{
		pre->next=temp->next;
		temp->next=NULL;
	}}
	delete temp;
}

//gettail gives you the tail of the linked list.
node *gettail(node *head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	node *temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	return temp;
}

//adds a node at the end of the linked list.
node *addatend(node *&head,node *&tail,ll data){
	node *n=new node(data);
	if(head==NULL){
		head=n;
		tail=n;
		tail->next=head;
	}
	else{
		tail->next=n;
		n->next=head;
		tail=n;
	}
	return tail;
}

//creates a linked list.
void linkedlist(node *&head){
	node *tail=NULL;
	ll data;
	cin>>data;
	while(data!=-1){
		tail=addatend(head,tail,data);
		cin>>data;
	}
}

//prints the linked list.
void print(node *head){
	node *temp=head;
	while(temp->next!=head){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data<<endl;
}

//operator overloading to take input from cin and cout.
ostream &operator <<(ostream &os ,node *&head){
	print(head);
	return os;
}

istream &operator >>(istream &is ,node *&head){
	linkedlist(head);
	return is;
}

int main()
{
	node *head=NULL;
	cin>>head;
	cout<<head;
	ll val=gettail(head)->data;
	cout<<val<<endl;
	delnode(head,3);
	cout<<head;
	return 0;
}