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

//basic insert at end function to add elements at the end of the linked list.
void insertatend(node *&head,ll data){
	node *n=new node(data);
	if(head==NULL){
		head=n;
		return;
	}
	node *i=head;
	while(i->next!=NULL)
		i=i->next;
	i->next=n;
}

//function to print the elements of the linked list.
void print(node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

//get the current length of the linked list.
ll length(node *head){
	ll len=0;
	while(head!=NULL){
		head=head->next;
		len+=1;
	}
	return len;
}

//function to delete the first node of the linked list.
void delatstart(node *&head){
	if(head==NULL)
		return;
	node *temp=head;
	head=temp->next;
	temp->next=NULL;
	delete temp;
}


//function to delete the last node of the linked list.
void delatend(node *&head)
{
	node *p=head;
	node *q=NULL;
	if(p->next==NULL){
		delatstart(head);
		return;
	}
	while((p->next)!=NULL){
		q=p;
		p=p->next;
	}
	q->next=NULL;
	delete p;
}

//function to delete ith node in the linked list.
void delinmiddle(node *&head,ll i){
	ll j=1;
	if(i==1){
		delatstart(head);
		return;
	}
	else if(i>=length(head)){
		delatend(head);
		return;
	}
	else{
		node *p=head;
		while(j<i-1){
			j+=1;
			p=p->next;}
		node *temp=p->next;
		p->next=temp->next;
		temp->next=NULL;
		delete temp;
	}
}

int main()
{
	node *head=NULL;ll i,n;cin>>n;
	for(i=0;i<n;i++){
		ll x;cin>>x;
		insertatend(head,x);
	}
	print(head);
	delinmiddle(head,1);
	ll l=length(head);
	delinmiddle(head,l);
	//cout<<length(head)<<endl;
	delinmiddle(head,1);
	print(head);
	return 0;
}