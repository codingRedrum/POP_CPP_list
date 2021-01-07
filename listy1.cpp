#include <iostream>

typedef struct Lista 
{
	int liczba;
	struct Lista *next;
}TLista;

typedef struct Listy
{
  TLista *Pociag;
  TLista *Ostatni; 	
} TListy;

TListy add(TListy L, int x)
{
	if(L.Pociag==NULL)
	{
		L.Pociag=new Lista;
		L.Pociag->liczba=x; 
		L.Pociag->next=NULL;
		L.Ostatni=L.Pociag;
	} else
	{
	  L.Ostatni->next=new Lista;
	  L.Ostatni=L.Ostatni->next;
	  L.Ostatni->liczba=x;
	  L.Ostatni->next=NULL;	
	}
	return L;
}

TLista *add_rek(TLista *L, int x)
{
	if(L==NULL)
	{
		L=new Lista;
		L->liczba=x; 
		L->next=NULL;
	} else
	{
		L->next=add_rek(L->next, x);
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

void print(TListy L)
{
	TLista *temp;
	temp=L.Pociag;
	while(temp!=NULL)
	{
		std::cout << temp->liczba << ",";
		temp=temp->next;
	}
}

int main()
{
	TListy Ly;
	int ile, i, licz;
	Ly.Pociag=NULL;
	Ly.Ostatni=NULL;
	std::cin >> ile;
	for(i=1;i<=ile;i++)
	{
		std::cin >> licz;
		Ly=add(Ly, licz);
	}
	print(Ly);
	return 0;
}

