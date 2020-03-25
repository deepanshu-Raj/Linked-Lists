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

//iterative function to reverse the linked list.
void reverse(node *&head){
	node *pre=NULL;
	node *p=head;
	node *n=NULL;
	while(p!=NULL){
		n=p->next;
		p->next=pre;
		pre=p;
		p=n;
	}
	head=pre;
}

//reversing a linked list using recursion.(recursive approach)
node *reverserec(node *head){
	if(head->next==NULL || head==NULL){
		return head;
	}
	node *H=reverserec(head->next);
	node *p=head;
	(p->next)->next=p;
	p->next=NULL;
	return H;
}


//add node at the end.
void addatend(node *&head,ll d){
	node *n=new node(d);
	if(head==NULL){
		head=n;
		return;
	}
	node *i=head;
	while(i->next!=NULL){
		i=i->next;
	}
	i->next=n;
}

//continuous data entry in the linked list, given that the sequence of numbers terminate with a -1.
void linkedlist(node* &head){
	ll d;
	cin>>d;
	while(d!=-1){
		addatend(head,d);
		cin>>d;
	}
}

//function to print the linked list.
void print(node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

/*//if you want single input,at cin in main,operator overloading might be done using void function.
void operator >>(istream &is,node *&head){
	linkedlist(head);
}


void operator <<(ostream &os,node *&head){
	print(head);
}*/

//for multiple inputs from cin in the main,operator overloading might be done using a pointer of <istream or ostream>type.
ostream& operator <<(ostream &os,node *&head){
	print(head);
	return os;
}

istream& operator >>(istream &is,node *&head){
	linkedlist(head);
	return is;
}

int main()
{
	node *head1=NULL;

	cin>>head1;
	head1=reverserec(head1);
	cout<<head1;
	return 0;
}