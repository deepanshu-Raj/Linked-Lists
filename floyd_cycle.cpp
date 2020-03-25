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



void addatend(node *&head,ll data){
	node *n=new node(data);
	if(head==NULL){
		head=n;
		return;
	}
	node *p=head;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=n;
}

void print(node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

void linkedlist(node *&head){
	ll data;
	cin>>data;
	while(data!=-1){
		addatend(head,data);
		cin>>data;
	}
}

istream &operator >>(istream &is,node *&head){
	linkedlist(head);
	return is;
}

ostream &operator <<(ostream &os,node *&head){
	print(head);
	return os;
}


//function to detect weather there is a cycle present in the linked list or not.
//if a cycle is present,function returns 1 else the function will return 0.
ll cycle(node *head){
	if(head==NULL || head->next==NULL){
		return 0;
	}
	node *slow=head;
	node *fast=head;
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow){
			return 1;
		}
	}
	return 0;
}


//function to create a cycle between the last node and the second node of the linked list.
void createcycle(node *head){
	if(head==NULL || head->next==NULL){
		return;
	}
	node *p=head->next;
	while(head->next!=NULL){
		head=head->next;
	}
	head->next=p;
}

//use of floyd's theorum to remove the cycle present in the linear linked list.
void removecycle(node *head){
	if(head==NULL || head->next==NULL){
		return;
	}
	node *fast=head;
	node *slow=head;
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow)
			break;
	}
	//according to floyd's theorum.
	slow=head;
	while(slow!=fast){
		slow=slow->next;
		fast=fast->next;
	}
	//now to remove the cycle,terminate the slow->next from pointing to 'fast' to 'NULL'.
	while(slow->next!=fast){
		slow=slow->next;
	}
	slow->next=NULL;
}

int main()
{
	node *head=NULL;
	cin>>head;
	cout<<head;
	createcycle(head);
	if(cycle(head))
		cout<<"yes,cycle is present!!"<<endl;
	else
		cout<<"linked list has no cycle present in it!!"<<endl;
	removecycle(head);
	if(cycle(head))
		cout<<"nopes, cycle not removed"<<endl;
	else
		cout<<"cycle removed!!"<<endl;
	cout<<head;
	return 0;
}
