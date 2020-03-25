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

node *findmid(node *head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	node *slow=head;
	node *f=head->next;
	while(f!=NULL && f->next!=NULL){
		f=f->next->next;
		slow=slow->next;
	}
	return slow;
}

node *merge(node *h1,node *h2){
	if(h1==NULL)
		return h2;
	else if(h2==NULL)
		return h1;
	node *c;
	if(h1->data < h2->data){
		c=h1;
		c->next=merge(h1->next,h2);
	}
	else{
		c=h2;
		c->next=merge(h1,h2->next);
	}
	return c;
}

node *mergesort(node *head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	node *mid=findmid(head);
	node *a=head;
	node *b=mid->next;
	mid->next=NULL;

	a=mergesort(a);
	b=mergesort(b);

	node *c=merge(a,b);
	return c;
}

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

int main()
{
	node *head=NULL;
	cin>>head;
	cout<<head;
	node *p=mergesort(head);
	cout<<p;
	return 0;
}