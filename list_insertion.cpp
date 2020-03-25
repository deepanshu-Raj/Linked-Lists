#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class node
{
public:
	ll data;
	node * next;

	node(ll d)
	{
		data=d;
		next=NULL;
	}
};
void insertatbegin(node *&head,ll data);


//inserts at the end.
void insertatend(node *&head,ll data)
{
	node *n=new node(data);
	if(head==NULL)
		insertatbegin(head,data);
	else{
	node *i=head;
	while(i->next!=NULL)
		i=i->next;
	i->next=n;}
}


//to find the length of the linked list.
ll length(node *head)
{
	ll len=0;
	while(head!=NULL){
		len+=1;
		head=head->next;
	}
	return len;
}


//if you want to insert at pos. 4,you will have to enter pos. 3.
void insertinmiddle(node *&head,ll data,ll x)
{
	node *n=new node(data);
	if(head==NULL || x==0)
		insertatbegin(head,data);
	else if(x>length(head))
		insertatend(head,data);
	else{
	node *i=head;
	ll c=1;
	while(c<=x-1 && i!=NULL)
	{
		i=i->next;
		c+=1;
	}
	n->next=i->next;
	i->next=n;}
}

//inserts in the beginning of the list. 
void insertatbegin(node *&head,ll data)
{
	node * n=new node(data);
	n->next = head;
	head = n;
}


//for printing the elements of the linked list.
void print(node *head)
{
	node *i=head;
	while(i!=NULL)
	{
		cout<<i->data<<"->";
		i=i->next;
	}
}

int main()
{
	node *head=NULL;
	ll n;cin>>n;
	insertatend(head,5);
	insertatend(head,6);
	for(ll i=0;i<n;i++){
		ll data;cin>>data;
		insertatbegin(head,data);}
	insertinmiddle(head,12,3);
	//must return the 3 element.
	//cout<<(*((*head).next)->next).data<<endl;
	print(head);
	return 0;
}