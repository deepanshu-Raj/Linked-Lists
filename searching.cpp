#include<iostream>
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

ll S(node *head,ll k){
	
	if(head==NULL)
		return 0;
	if(head->data==k)
		return 1;
	return S(head->next,k);
}

ll search(node* head,ll k){
	while(head!=NULL){
		if(head->data==k)
			return 1;
		head=head->next;
	}
	return 0;
}

ll length(node* head)
{
	ll len=0;
	while(head!=NULL){
		head=head->next;
		len+=1;
	}
	return len;
}

int main()
{
	node *head=NULL;ll i,n;cin>>n;
	for(i=0;i<n;i++){
		ll x;cin>>x;
		insertatend(head,x);
	}
	ll k;cin>>k;
	if(S(head,k)!=0 || search(head,k))
		cout<<"element found!!"<<endl;
	else
		cout<<"element not found!!"<<endl;
	return 0;
}