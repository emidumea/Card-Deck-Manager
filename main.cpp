#include <iostream>
#include "fct.h"

using namespace std;

int main()
{
    int x, y;
    jucator* p = 0; 
    jucator* u = 0;
    deck* c = 0;
    deck* l = 0;
    int ok;
    cout << "Introduceti un numar:\n";
    cout << "0-exit \t 1-add_deck \t 2-del_deck \t 3-del_card \t 4-add_cards \t 5-deck_number \t 6 deck_len \t 7-shuffle_deck \t 8-merge_decks \t 9-show_all \t 10-show_deck\t 11-reverse_deck\t 12-sort_dect\t 13-split_deck\n";
    cin >> ok;
    while (ok != 0)
    {
        switch (ok)
        {
        case 1:
            cout << "introduceti nr de carti:";
            cin >> x;
            add_deck(p, u, c, l, x);
            break;
        case 2:
            cout << "introduceti indexul pachetului pe care vreti sa il stergeti:";
            cin >> x;
            del_deck(p,u,x);
            break;
        case 3:
            cout << "introduceti indexul pachetului din care vreti sa stergeti cartea:";
            cin >> x;
            cout << "introduceti indexul cartii pe care vreti sa o stergeti:";
            cin >> y;
            del_card(p,c,l,x,y);
            break;
        case 4:
            cout << "introduceti indexul pachetului in care vreti sa adaugati carti:";
            cin >> x;
            cout << "introduceti nr de carti pe care vreti sa il adaugati: ";
            add_cards(p, c, l, x, y);
            break;
        case 5:
            deck_number(p);
            break;
        case 6:
            cout << "introduceti indexul pachetului al carui numar de carti vreti sa il vedeti:";
            cin >> x;
            deck_len(p, c, x);
            break;
        case 7:
            cout << "introduceti indexul pachetului caruia vreti sa ii dati shuffle:";
            cin >> x;
            shuffle_deck(p, c, l, x);
            break;
        case 8:
            cout << "introduceti indexul primului pachet";
            cin >> x;
            cout << "introduceti indexul celui de-al doilea pachet:";
            cin >> y;
            merge_decks(p, u, c, l, x, y);
            break;
        case 9:
            show_all(p);
            break;
        case 10:
            cout << "introduceti indexul pachetului pe care vreti sa il vedeti:";
            cin >> x;
            show_deck(p, x);
            break;
        case 11:
            cout << "Introduceti indexul pachetului pe care vreti sa il inversati:";
            cin >> x;
            reverse_deck(p, c, x);
            break;
        case 12:
            cout << "Introduceti indexul pachetului pe care vreti sa il sortati:";
            cin >> x;
            sort_deck(p, c, x);
        case 13:
            cout << "Introduceti indexul pachetului pe care vreti sa il impartiti:";
            cin >> x;
            cout << "Introduceti pozitia de la care vreti sa il impartiti:";
            cin >> y;
            split_deck(p, u, c, l, x, y);
        case 0:
            break;
        default:
            cout << "Invalid command.Please try again.\n";
            break;
        }
        cout << "Introduceti un numar:\n";
        cout << "0-exit \t 1-add_deck \t 2-del_deck \t 3-del_card \t 4-add_cards \t 5-deck_number \t 6 deck_len \t 7-shuffle_deck \t 8-merge_decks \t 9-show_all \t 10-show_deck\t 11-reverse_deck\t 12-sort_deck\t 13-split_deck\n";
        cin >> ok;
                   
    }
    return 0;
}