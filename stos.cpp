#include <iostream>
#include <windows.h>
//#include<unistd.h> w przypadku zastosowania systemu linux potrzebne do biblioteki usleep zamiast Sleep

using namespace std;

int date[6];
int size;

//------------------------------------------------------------------------

void display()
{
    cout<<endl;
    cout<<"----------------"<<endl;
    cout<<"LIFO algorithm:"<<endl;
    cout<<"----------------"<<endl;

    for (int i=size; i>=1; i--)
    {
        cout<<date[i]<<endl;
    }

    if (size==0) cout<<"pusty"<<endl;

    cout << "----------------"<<endl<<endl;

}

//------------------------------------------------------------------------

void push()
{
    if (size>=5)
    {
        cout << "Stos pelny!";
        Sleep(1000);
    }
    else
    {
        cout<<endl<< "PUSH (jaka liczbe polozyc na stosie): ";

        size=size+1;
        cin>>date[size];
    }
}

//------------------------------------------------------------------------

void pop()
{
    if (size>=1)
    {
        cout<<endl<<"POP - nastapi usuniecie ze stosu liczby: "<<date[size];
        Sleep(2000);

        size=size-1;
    }
    else
    {
        cout << "Stos pusty!";
        Sleep(1000);
    }
}
//------------------------------------------------------------------------

void sizee()
{
    cout<<endl<<"Liczba elementow na stosie: "<<size;
    Sleep(2000);
}

//------------------------------------------------------------------------

void empty()
{

    if (size==0) cout<<endl<<"EMPTY (stos pusty?) ->  TRUE";
    else cout<<endl<<"EMPTY (stos pusty?) ->  FALSE";
    Sleep(2000);
}

//------------------------------------------------------------------------


int main()
{

    int selection;
    size=0;

    do
    {
        display();

        cout << "MENUFILE:"<<endl;
        cout << "------------------------------------------"<<endl;
        cout << "1. PUSH "<<endl;
        cout << "2. POP "<<endl;
        cout << "3. SIZE  "<<endl;
        cout << "4. EMPTY ? "<<endl;
        cout << "5. END "<<endl;
        cout << "------------------------------------------"<<endl;
        cout << ": ";
        cin >> selection;

        switch (selection)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            sizee();
            break;

        case 4:
            empty();
            break;

        }

    }
    while (selection != 5);

    return 0;
}
