#pragma comment(lib, "winmm.lib")
#include<iostream>
#include<string.h>
#include<Windows.h>
#include<mmsystem.h>
#include<stdlib.h>
#include<conio.h>
int counts=0;
using namespace std;
struct node
{
	char data[100];
	struct node *next,*prev;
};
class linkedlist
{
	node *start,*tail;
public:
	linkedlist()
	{
		start=tail=NULL;
	}
	void insert_first(char []);
	void play();
	void display();
	void previous();
	void next();
};
struct node *prt;
void linkedlist::insert_first(char item[100])
{
	struct node *n;
	n=new node;
	strcpy(n->data,item);
	n->prev=NULL;
	n->next=start;
	counts++;
	if(start==NULL)
	{
		start=tail=n;
	}
	else
	{
		start->prev=n;
		n->next=start;
		start=n;
	}
}
void linkedlist::play()
{
	prt=start;
	int ch1;
	cout<<"playing the "<<prt->data<<"song for u......"<<endl;
	play_mus:
	PlaySound(TEXT(start->data), NULL, SND_SYNC);
	cout<<"1.STOP\n2.NEXT";
	cin>>ch1;
	cout<<"press any key to continue";
	cin.ignore();
	cin.get();
	if(ch1==1)
	{
		PlaySound(0,0,0);
		cout<<"to restart music"<<endl;
		system("pause");
		system("cls");
		goto play_mus;
	}
	else if(ch1==2)
	{
		system("cls");
		next();
	}
}
void linkedlist::display()
{
	system("cls");
	struct node *ptr;
	ptr=start;
    do
	{   cout<<ptr->data<<endl;
		ptr=ptr->next;
	}while(ptr!=NULL);
}
void linkedlist::previous()
{
	int ch1;
pre:
		prt=prt->prev;
		cout<<"playing the "<<prt->data<<" song for u......"<<endl;
		PlaySound(TEXT(prt->data), NULL, SND_SYNC);
	cout<<"1.STOP\n2.NEXT\n3.PREVIOUS";
	cin>>ch1;
	cout<<"press any key to continue";
	cin.ignore();
	cin.get();
	if(ch1==1)
	{
        PlaySound(0,0,0);
    }
    else if(ch1==2)
    {
        system("cls");
        next();
    }
    else
    {
        system("cls");
        goto pre;
    }
}
void linkedlist::next()
{
	int ch1;
label:
		prt=prt->next;
		cout<<"playing the "<<prt->data<<" song for u......"<<endl;
		PlaySound(TEXT(prt->data), NULL, SND_SYNC);
        cout<<"1.STOP\n2.NEXT\n3.PREVIOUS";
        cin>>ch1;
        cout<<"press any key to continue";
        cin.ignore();
        cin.get();
	if(ch1==1)
	{
        PlaySound(0,0,0);
    }
    else if(ch1==2)
    {
        system("cls");
        goto label;
    }
    else if(ch1==3)
    {
        system("cls");
        previous();
    }
}
int main()
{
    cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
    cout<<"\t\t\t\t\t\t|                                           	                  |\n";
    cout<<"\t\t\t\t\t\t|                                                                 |\n";
    cout<<"\t\t\t\t\t\t|                                                                 |\n";
    cout<<"\t\t\t\t\t\t|            WELCOME TO THE MUSIC PLAYER SYSTEM                   |\n";
    cout<<"\t\t\t\t\t\t|                                                                 |\n";
    cout<<"\t\t\t\t\t\t|                                                                 |\n";
    cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
	linkedlist l,r;
	music:
	int j=1,k=1,choice,a;
	char item[100];
    cout<<"Do you want to add a song to your playlist(1/0)";
	cin>>a;
	if (a==1)
	{
	while(j)
	{
	cout<<"song name: ";
	cin>>item;
	l.insert_first(item);
	cout<<"do you want to continue to add songs(1/0)";
	cin>>j;
	}
	}
	while(k)
	{
	system("cls");
	cout<<"1.play your playlist\n2.Display your playlist\n3.Total songs\n4.Add songs\n5.Add to favourites";
    cin>>choice;
	switch(choice)
	{
    case 1:
			system("cls");
            l.play();
            break;
	case 2:
            system("cls");
            cout<<"The list of songs in the playlist: ";
            l.display();
			//cout<<"press any key to exit";
			//cin.ignore();
			//cin.get();
			break;
	case 3:
			system("cls");
			cout<<"you have "<<counts<<" songs in your list\n";
			break;
	case 4:
			system("cls");
			goto music;
			break;
    case 5:
            system("cls");
            cout<<"List of songs available: ";
            l.display();
            int a,b,j=1;
            char item[100];
            cout<<"Do you want to add a song to your favourite playlist(1/0)";
            cin>>a;
            if (a==1)
            {
            while(j)
            {
            cout<<"song name: ";
            cin>>item;
            r.insert_first(item);
            cout<<"Do you want to continue to add songs to your favourites(1/0)";
            cin>>j;
            }
            }
            cout<<"Do you want to display your favourite playlist(1/0)";
            cin>>b;
            if(b==1)
            {
                r.display();
            }
            break;
	}
	cout<<"Do you want to continue(1/0)"<<endl;
	cin>>k;
	}
}
