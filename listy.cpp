#include <iostream>

typedef struct Lista 
{
	int liczba;
	struct Lista *next;
}TLista;


TLista *add(TLista *L, int x)
{
	TLista *temp;
	if(L==NULL)
	{
		L=new Lista;
		L->liczba=x;  // G.liczba=12;
		L->next=NULL;
	} else
	{
		temp=L;
		while(temp->next!=NULL) temp=temp->next;
		temp->next=new Lista;
		temp=temp->next;
		temp->liczba=x;
		temp->next=NULL;
	}
	return L;
}

TLista *add_first(TLista *L, int x)
{
	TLista *temp;
	if(L==NULL)
	{
		L=new Lista;
		L->liczba=x;  // G.liczba=12;
		L->next=NULL;
	} else
	{
		temp=new Lista;
		temp->liczba=x;
		temp->next=L;
		L=temp;
	}
	return L;
}

void print(TLista *L)
{
	TLista *temp;
	temp=L;
	while(temp!=NULL)
	{
		std::cout << temp->liczba << ",";
		temp=temp->next;
	}
}

int main()
{
	TLista *Lx;
	int ile, i, licz;
	Lx=NULL;
	std::cin >> ile;
	for(i=1;i<=ile;i++)
	{
		std::cin >> licz;
		Lx=add_first(Lx, licz);
	}
	print(Lx);
	return 0;
}

