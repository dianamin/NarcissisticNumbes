#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int k;
int kmax;
int v[40];
int a[40], p[40];

void aduna (int x)
{
    a[1]+=x;
    int i=1;
    while (a[i]>9)
    {
        a[i+1]+=a[i]/10;
        a[i]=a[i]%10;
        i++;
    }
}

int putere (int x, int k)
{
    for (int i=1; i<=k; i++) p[i]=1;
    int c=1;
    for (int i=1; i<=k && c<=k; i++)
    {
        p[1]=p[1]*x;
        for (int j=2; j<=c; j++)
        {
            p[j]=p[j]*x;
            p[j]+=p[j-1]/10;
            p[j-1]=p[j-1]%10;
        }
        while (p[c]>9)
        {
            p[c+1]=p[c]/10;
            p[c]=p[c]%10;
            c++;
        }
    }
    if (c>k) return 0;
    return c;
}


void aduna2 (int k)
{

    for (int i=k; i>=1; i--)
    {
        a[i]+=p[i];
        a[i+1]+=a[i]/10;
        a[i]=a[i]%10;
    }
    if (a[k+1]>9)
    {
        k++;
        while (a[k]>9)
        {
            a[k+1]=a[k]/10;
            a[k]=a[k%10];
            k++;
        }
    }

}

int compara (int k)
{
    for (int i=1; i<=k; i++)
        if (v[i]!=a[i]) return 0;
    return 1;
}


int verif (int k)
{
    if (k<3) return 0;
    int x, c;
    for (int i=1; i<=k; i++) a[i]=0;
    for (int i=k; i>=1; i--)
    {
        //x=pow(v[i], k);
        //aduna (x);
        c=putere(v[i], k);
        if (c==0) return 0;
        aduna2(c);

    }
    return compara (k);
}

void swag (int k)
{
    for (int i=k; i>=1; i--) cout<<v[i];
    cout<<'\n';
}

void genereaza (int k)
{
    v[k]=0;
    if (k<kmax) genereaza(k+1);
    for (int i=1; i<=9; i++)
    {
        v[k]=i;
        if (verif(k)) swag (k);
        if (k<kmax) genereaza(k+1);

    }
}

int main ()
{
    int x=0;
    while (!x)
    {
        cout<<"Welcome to Generatorul de numere narcisiste!"<<'\n';
        cout<<"Care sa fie numarul maxim de cifre?"<<'\n';
        cout<<"Pune maxim 7 daca nu vrei sa astepti prea mult ;)"<<'\n';
        cin>>kmax; cout<<'\n';
        cout<<"Esti sigur de afirmatia ta? :D"<<'\n';
        cout<<"1,enter daca da, 0,enter daca nu."<<'\n'<<'\n';
        cin>>x;
        cout<<'\n';
    }
    cout<<"*generez*"<<'\n'<<'\n';

    genereaza(k+1);
    return 0;
}
