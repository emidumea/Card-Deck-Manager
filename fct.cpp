#include <iostream>
#include <ctype.h>
#include "fct.h"

using namespace std;

const char* simboluri[4] = { "PICA","CUPA","CARO","TREFLA" };
int k = 1;

void invalid_card()
{
	cout << "The provided card is not a valid one.\n";
}

void add_deck(jucator*& prim, jucator*& ultim, deck*& cap, deck*& last, int nr_carti)
{
	card x;
	jucator* list;
	cap = last = NULL;
	list = new jucator;
	int aux = nr_carti;
	while (aux)
	{
		//reading card data
		cout << "insert card number: ";
		cin >> x.valoare;
		cout << "insert card symbol: ";
		cin >> x.simbol;
		// checking the validity of the card
		bool ok = 0;
		for (int i = 0; i < 4; i++)
		{
			if (strcmp(simboluri[i], x.simbol) == 0)
			{
				ok = 1;
				break;
			}
		}
		if ((x.valoare < 1 || x.valoare>14) || ok == 0 )
			invalid_card();
		else
		{
			aux--;
			list->pachet = new deck;
			strcpy_s(list->pachet->carte.simbol,x.simbol);
			list->pachet->carte.valoare = x.valoare;
			list->pachet->urm = 0;
			list->pachet->prec = last;
			if (last)
			{
				last->urm = list->pachet;
			}
			else
			{
				cap = list->pachet;
				list->fs = cap;
			}
			last = list->pachet;
		}

	}
	list->next = 0;
	list->back = ultim;
	if (ultim)
		ultim->next = list;
	else
		prim = list;
	ultim = list;
	list->index = k;
	k++;
/*while (cap != 0)
	{
		deck* nod = cap;
		cap = cap->urm;
		delete nod;
	}*/

	cout << "\nThe deck was successfully created with " << nr_carti << " cards.\n";
}

void show_all(jucator*& prim)
{
	jucator* p;
	int x = 1;
	for (p = prim; p != 0; p = p->next)
	{
		cout << "Deck " << x << ":\n";
		deck* q = p->fs;
		while (q != 0)
		{
			cout << q->carte.valoare << " " << q->carte.simbol << "\n";
			q = q->urm;
		}
		cout << "\n";
		x++;
	}
}

void show_deck(jucator*& prim, int index)
{
	jucator* p=prim;
	int x = 0;
	while (x != index - 1 && p != 0)
	{
		x++;
		p = p->next;
	}
	if (p == 0)
		cout << "The provided index is out of bounds for the deck list\n";
	else
	{
		deck* q = p->fs;
		cout << "Deck " << x+1 << ":\n";
		while (q != 0)
		{
			cout << q->carte.valoare << " " << q->carte.simbol << "\n";
			q = q->urm;
		}
		cout << "\n";
	}
}

void del_deck(jucator*& prim, jucator*& ultim, int index)
{
	jucator* p=prim,*q;
	jucator* c;
	int i = 0;
	while (i != index - 1 && p != 0)
	{
		i++;
		p = p->next;
	}
	if (p != 0)
	{
		if (p == prim)
		{
			//	q = prim;
			prim = prim->next;
			q = prim;
			//delete q;
			delete p;
			if (prim)
				prim->back = NULL;
			else
				ultim = NULL;
		}
		else
			if (p == ultim)
			{
				//	q = ultim;
				ultim = ultim->back;
				//	delete q;
				q = ultim;
				delete p;
				if (ultim)
					ultim->next = NULL;
				else
					prim = NULL;
			}
			else
			{
				q = p->next;
				p->back->next = q;
				q->back = p->back;
				delete p;
			}
		cout << "The deck " << index << " was successfully deleted\n";
		int x = 1;
		for (c = prim; c != 0; c = c->next)
		{
			c->index = x;
			x++;
		}
	}
	else
		cout << "The provided index is out of bounds for the deck list.\n";
}

void del_card(jucator*& prim, deck*& cap,deck*&last, int index_deck,int index_card)
{
	jucator* p;
	int x = 0;
	for (p = prim; x != index_deck-1 && p != 0; p = p->next);
	if (p == 0)
		cout << "The provided index is out of bounds for the deck "<<index_deck<<"\n";
	else
	{
		deck* q = p->fs;
		deck* r;
		int i = 0;
		while (i != index_card - 1 && q != 0)
		{
			i++;
			q = q->urm;
		}
		if (q != 0)
		{
			if (q == cap)
			{
				cap = cap->urm;
				delete q;
				if (cap)
					cap->prec = NULL;
				else
					last = NULL;
			}
			else
				if (q == last)
				{
					last = last->prec;
					delete q;
					if (last)
						last->urm = NULL;
					else
						prim = NULL;
				}
				else
				{
					r = q->urm;
					q->prec->urm = r;
					r->prec = q->prec;
					delete q;
				}
			cout << "The card was succesfully deleted from deck " << index_deck << "\n";

		}
	}
}

void add_cards(jucator*& prim, deck*& cap,deck*&last, int index_deck, int nr_cards)
{
	jucator* p;
	int x = 0;
	for (p = prim; x != index_deck-1 && p != 0; p = p->next);
	if (p==0 || index_deck < 0)
		cout << "The provided index is out of bounds for the deck list\n";
	else
	{
	
		card x;
		int aux = nr_cards;
		while (aux)
		{
			//reading card data
			cout << "insert card number: ";
			cin >> x.valoare;
			cout << "insert card symbol: ";
			cin >> x.simbol;
			// checking the validity of the card
			bool ok = 0;
			for (int i = 0; i < 4; i++)
			{
				if (strcmp(simboluri[i], x.simbol) == 0)
				{
					ok = 1;
					break;
				}
			}
			if ((x.valoare < 1 || x.valoare>14) || ok == 0)
				invalid_card();
			else
			{
				aux--;
				deck* r = p->fs;
				while (r->urm != NULL)
					r = r->urm;

				deck* d = r->urm;
				deck* q;
				q = new deck;
				q->carte.valoare = x.valoare;
				strcpy_s(q->carte.simbol, x.simbol);
				q->prec = 0;
				q->urm = cap;
				cap->prec = q;
				cap = q;
			}
		}
		cout << "The cards were successfully added to deck " << index_deck << "\n";
	}
}

void deck_number(jucator*& prim)
{
	int i = 0;
	jucator* p;
	for (p = prim; p != 0; p = p->next)
		i++;
	cout << "The number of decks is " << i << "\n";

}

void deck_len(jucator*& prim, deck*& cap, int index_deck)
{
	jucator* p;
	int x = 0;
	int i = 0;
	for (p = prim; p->index != index_deck && p != 0; p = p->next);
	if (p != 0)
	{
		deck* q = p->fs;
		while (q != 0)
		{
			i++;
			q = q->urm;
		}
	
	}

	cout << "The length of " << index_deck << " is " << i << "\n";

}

void shuffle_deck(jucator*& prim, deck*& cap,deck*&last, int index_deck)
{
	jucator* p;
	for (p = prim; p->index != index_deck && p != 0; p = p->next);
	int i = 1;
	deck* t = NULL;
	deck* c = p->fs;
	while (c != NULL)
	{
		t = c->prec;
		c->prec = c->urm;
		c->urm = t;
		c = c->prec;
	}
	if (t != NULL)
	{
		p->fs = t->prec;
	}
	cout << "The deck " << index_deck << " was successfully shuffled.\n";
}

void merge_decks(jucator*& prim, jucator*& ultim, deck*& cap, deck*& last, int ind1, int ind2)
{
	jucator* p, * q;
	int z = 1, k = 1;
	for (p = prim; z != ind1; p = p->next);
	for (q = prim; k != ind2; q = q->next);
	deck* r, * s;
	r = p->fs;
	s = q->fs;
	while (r->urm != 0)
		r = r->urm;

	r->urm = s;
	s->prec = r;

	s = NULL;
	del_deck(prim,ultim,ind2);
	cout << "The deck " << ind1 << " and the deck " << ind2 << " were successfully merged.\n";
}

void reverse_deck(jucator*& prim, deck*& cap, int index_deck)
{
	int x = 0;
	jucator* j;
	for (j = prim; x != index_deck-1 && j != 0; j = j->next);

	deck* p, * q, * r;
	if (j != 0)
	{
		p = j->fs;
		q = p->urm;
		r = q->urm;
		while (r != 0)
		{
			if (p == j->fs)
				p->urm = NULL;
			q->urm = p;
			p = q;
			q = r;
			r = r->urm;
		}
	}
	cout << "The deck " << index_deck << " was successfully reversed.\n";
}

void sort_deck(jucator*& prim, deck*& cap, int index_deck)
{
	jucator* p = prim;
	deck* q, * r;
	card aux;
	int i = 0;
	while (i != index_deck - 1 && p != 0)
	{
		i++;
		p = p->next;
	}
	if (p == 0 || index_deck < 0)
		cout << "The provided index is out of bounds for the deck list\n";
	else
	{
		for (q = cap; q->urm != 0; q = q->urm)
		{

			for (r = q->urm; r != 0; r = r->urm)
			{
				if (r->carte.valoare < q->carte.valoare)
				{
					aux.valoare = q->carte.valoare;
					strcpy_s(aux.simbol, q->carte.simbol);
					q->carte.valoare = r->carte.valoare;
					strcpy_s(q->carte.simbol, r->carte.simbol);
					r->carte.valoare = aux.valoare;
					strcpy_s(r->carte.simbol, aux.simbol);
				}

			}
		}
		cout << "The deck " << index_deck << " was successfully sorted.\n";
	}
}
void split_deck(jucator*& prim,jucator*& ultim, deck*& cap, deck*&last, int index_deck, int index_split)
{
	jucator* p = prim, * d;
	int i = 0;
	while (i != index_deck - 1 && p != 0)
	{
		i++;
		p = p->next;
	}
	deck * q = p->fs;
	deck* r;
	int x = 0;
	while (x != index_split - 1 && q != 0)
	{
		x++;
		q = q->urm;
	}
	r = q;
	jucator* list;
	list = new jucator;
	while (r != 0)
	{
		list->pachet = new deck;
		strcpy_s(list->pachet->carte.simbol, r->carte.simbol);
		list->pachet->carte.valoare = r->carte.valoare;
		list->pachet->urm = 0;
		list->pachet->prec = last;
		if (last)
		{
			last->urm = list->pachet;
		}
		else
		{
			cap = list->pachet;
			list->fs = cap;
		}
		last = list->pachet;
		r = r->urm;
	}
	if (p == ultim)
	{
		list->next = 0;
		list->back = ultim;
		if (ultim)
			ultim->next = list;
		else
			prim = list;
		ultim = list;
		list->index = k;
		k++;
	}
	else
	{
		d = p->next;
		list->back = p;
		list->next = d;
		p->next = list;
		if (ultim == p)
			ultim = list;
		else
			d->back = list;
	}
	 while (q != 0)
		{
			if (q != 0)
			{
				if (q == cap)
				{
					cap = cap->urm;
					delete q;
					if (cap)
						cap->prec = NULL;
					else
						last = NULL;
				}
				else
					if (q == last)
					{
						last = last->prec;
						delete q;
						if (last)
							last->urm = NULL;
						else
							prim = NULL;
					}
					else
					{
						r = q->urm;
						q->prec->urm = r;
						r->prec = q->prec;
						delete q;
					}
			}
			q = q->urm;
		}
		cout << "The deck " << index_deck << " was successfully split by index " << index_split << "\n";
}