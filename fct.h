#pragma once

struct card {
	int valoare;
	char simbol[10];
};

struct deck {
	card carte;
	deck* urm;
	deck* prec;
	deck* pr;
	deck* ul;
};

struct jucator {
	deck *pachet;
	jucator* next;
	jucator* back;
	deck* fs;
	int index;
};

void invalid_card();
void add_deck(jucator*& prim, jucator*& ultim, deck*& cap, deck*& last, int nr_carti);
void del_deck(jucator*& prim, jucator*& ultim, int index);
void del_card(jucator*& prim, deck*& cap,deck*& last, int index_deck,int index_card);
void add_cards(jucator*& prim, deck*& cap,deck*&last, int index_deck, int nr_cards);
void deck_number(jucator*& prim);
void deck_len(jucator*& prim, deck*&cap,int index_deck);
void shuffle_deck(jucator*& prim, deck*& cap,deck*&last, int index_deck);
void merge_decks(jucator*& prim, jucator*& ultim, deck*& cap,deck*&last, int ind1, int ind2);
void show_deck(jucator*& prim, int index);
void show_all(jucator*& prim);
void reverse_deck(jucator*& prim, deck*& cap, int index_deck);
void sort_deck(jucator*& prim, deck*& cap, int index_deck);
void split_deck(jucator*& prim,jucator*& ultim, deck*& cap,deck*&last, int index_deck, int index_split);
//add_deck
//del_deck
//del_card
//add_cards
//deck_number
//deck_len
//shuffle_deck
//merge_decks
//split_deck
//reverse_deck
//show_deck
//show_all
//sort_deck
//exit
//invalid_command