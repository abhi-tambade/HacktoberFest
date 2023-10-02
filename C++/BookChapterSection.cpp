#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class book
{
	private:
		typedef struct node
		{
			char name[10];
			int ch_count;
			struct node *child[10];
		}b;
		
	public:
		b* root, new_node;
			
		book()
		{
			root = NULL;
		}
		
		void create_tree();
		void display(b* );
};

void book::create_tree()
{
	int n, s;
	root = new b;
	
	cout<<"\nEnter book name: ";
	cin>>root->name;
	
	cout<<"Enter no. of chapters: ";
	cin>>n;
	root->ch_count=n;
	
	for(int i=0; i<n; i++)
	{
		root->child[i] = new b;
		
		cout<<"\nEnter chapter "<<i+1<<" name: ";
		cin>>root->child[i]->name;
		
		cout<<"Enter no. of sections in chapter "<<i+1<<": ";
		cin>>s;
		root->child[i]->ch_count=s;
		
		for(int j=0; j<s; j++)
		{
			root->child[i]->child[j] = new b;
			
			cout<<"Enter section "<<j+1<<" name: ";
			cin>>root->child[i]->child[j]->name;	
		}	
	}
}

void book::display(b* root)
{
	b* temp = root;
	int n, s;
	
	if(root!=NULL)
	{
		cout<<"Book name: "<<temp->name;
		n = temp->ch_count;
		for(int i=0; i<n; i++)
		{
			cout<<"\n\tChapter "<<i+1<<": "<<temp->child[i]->name<<endl;
			s = temp->child[i]->ch_count;
			for(int j=0; j<s; j++)
			{
				cout<<"\t\tSection "<<j+1<<": "<<temp->child[i]->child[j]->name<<endl;
			}
		}
	}
}

int main()
{
	book obj;
	int ch;
	
	do
	{
		cout<<"\n_*_*_*_* MENU *_*_*_*_"<<endl;
		cout<<"1. Create"<<endl;
		cout<<"2. Display"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"--> Enter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1: obj.create_tree();
					break;
					
			case 2: obj.display(obj.root);
					break;
					
			case 3: break;
			
			default: cout<<"Invalid choice....."<<endl;
		}
	}
	while(ch!=3);
	
	return 0;
}
