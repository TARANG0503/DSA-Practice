#include <bits/stdc++.h>
using namespace std;
#define IOS                  
    ios::sync_with_stdio(0); 
    cin.tie(0);              
    cout.tie(0);
#define PB push_back
typedef long long ll;
#define endl "\n"

class Term
{
public:
    int coeff;
    int exp;
};
class Poly
{
private:
    int n;
    Term *terms;

public:
    friend istream &operator>>(istream &in, Poly &p);
    friend ostream &operator<<(ostream &out, Poly &p);
    Poly operator+(Poly &p);
};

istream &operator>>(istream &in, Poly &p)
{
    cout << "Number of terms : ";
    cin >> p.n;
    p.terms = new Term[p.n];
    cout << "Enter terms (coeff exp) : \n";
    for (int i = 0; i < p.n; i++)
        cin >> p.terms[i].coeff >> p.terms[i].exp;
    cout << endl;
    return in;
}

ostream &operator<<(ostream &out, Poly &p)
{
    for (int i = 0; i < p.n; i++)
    {
        cout << p.terms[i].coeff << "*x^" << p.terms[i].exp;
        if (i < p.n - 1)
            cout << " + ";
    }
    cout << endl;
    return out;
}

Poly Poly::operator+(Poly &p)
{
    int i, j, k;
    Poly *sum = new Poly;
    sum->terms = new Term[n + p.n];
    i = j = k = 0;
    while (i < n && j < p.n)
    {
        if (terms[i].exp > p.terms[j].exp)
            sum->terms[k++] = terms[i++];
        else if (terms[i].exp < p.terms[j].exp)
            sum->terms[k++] = p.terms[j++];
        else
        {
            sum->terms[k].exp = terms[i].exp;
            sum->terms[k++].coeff = terms[i++].coeff + p.terms[j++].coeff;
        }
    }
    for (; i < n; i++)
        sum->terms[k++] = terms[i];
    for (; j < p.n; j++)
        sum->terms[k++] = p.terms[j];

    sum->n = k;
    return *sum;
}
int main()
{
    Poly p1, p2;
    cin >> p1;
    cin >> p2;
    Poly sum = p1 + p2;
    cout << "First Polynomial : " << p1 << endl;
    cout << "Second Polynomial : " << p2 << endl;
    cout << "Resultant Polynomial : " << sum << endl;
    return 0;
}
