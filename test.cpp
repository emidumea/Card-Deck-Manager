#include <iostream>

using namespace std;

struct nod {
	int info;
	nod* urm;
	nod* ant;
};
int main()
{
	int n;
	cout << "n=";
	cin >> n;
	nod* prim, * ultim;
	int i, x;
	prim = ultim = NULL;
	for (i = 1; i <= n; i++)
	{
		nod* q;
		cout << "introduceti nr:";
		cin >> x;
		q = new nod;
		q->info = x;
		q->urm = NULL;
		q->ant = ultim;
		if (ultim)
			ultim->urm = q;
		else
			prim = q;
		ultim = q;
	}
	nod* r;
	for (r = prim; r; r = r->urm)
		cout << r->info;

	return 0;
}