#include <iostream>
#include <windows.h>

using namespace std;

int selection;
int *header;


void ready(int x, int y)// funkcja odpowiedzialna za koordynaty
{
  COORD c;
  c.X=x-1;
  c.Y=y-1;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


    int data[16];
    bool emptyy[16];



void display()// display binary tree
{
system("CLS");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
//wyswietlenie drzewa
ready(40,1); if (emptyy[1]==true) cout<<"_"; else cout<<data[1];
ready(20,4); if (emptyy[2]==true) cout<<"_"; else cout<<data[2];
ready(60,4); if (emptyy[3]==true) cout<<"_"; else cout<<data[3];
ready(10,6); if (emptyy[4]==true) cout<<"_"; else cout<<data[4];
ready(30,6); if (emptyy[5]==true) cout<<"_"; else cout<<data[5];
ready(50,6); if (emptyy[6]==true) cout<<"_"; else cout<<data[6];
ready(70,6); if (emptyy[7]==true) cout<<"_"; else cout<<data[7];
ready(5,10); if (emptyy[8]==true) cout<<"_"; else cout<<data[8];
ready(15,10); if (emptyy[9]==true) cout<<"_"; else cout<<data[9];
ready(25,10); if (emptyy[10]==true) cout<<"_"; else cout<<data[10];
ready(35,10); if (emptyy[11]==true) cout<<"_"; else cout<<data[11];
ready(45,10); if (emptyy[12]==true) cout<<"_"; else cout<<data[12];
ready(55,10); if (emptyy[13]==true) cout<<"_"; else cout<<data[13];
ready(65,10); if (emptyy[14]==true) cout<<"_"; else cout<<data[14];
ready(75,10); if (emptyy[15]==true) cout<<"_"; else cout<<data[15];
cout<<endl<<endl<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

void add()
{
    int number;
    cout<<"Jaka liczbe dodac do drzewa: ";
    cin>>number;

    //drzewo puste
    if (emptyy[1]==true)
    {
        header=&data[1];
        *header=number;
        emptyy[1]=false;
    }
    else
    {
    bool f_place=false;
    int wezel=1;

    while (f_place==false)
    {
        if (emptyy[wezel]==true)
        {
            f_place=true;
            data[wezel]=number;
            emptyy[wezel]=false;

        }
        else if(number<data[wezel])
        {
            wezel=2*wezel;
        }
        else
        {
            wezel=2*wezel+1;
        }
        if(wezel>15)
        {
            cout<<"Potrzebne byloby wieksze drzewo!";
            Sleep(3000);
            f_place=true;
        }
    }
    }
}

void find()
{
int number;
cout<<"Jaka liczbe znalezc w drzewie: ";
cin>>number;

bool find=false;
int wezel=1;

    while (find==false)
    {
        if(number==data[wezel])
        {
            cout<<"Znaleziono liczbe w wezle nr: "<<wezel;
            Sleep(3000);

            find=true;
        }
        else if(number<data[wezel])
        {
            wezel=2*wezel;
        }
        else
        {
            wezel=2*wezel+1;
        }
        if(wezel>15)
        {
            cout<<"Not find!";
            Sleep(3000);
            find=true;
        }
    }
}

int main()
{
    for (int i=1; i<=15; i++)
    {
        emptyy[i]=true;
    }
    header=NULL;

    do
    {
    display();

    cout<<"----------------------------------"<<endl;
    cout<<"   BINARY TREE "<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"1. ADD "<<endl;
    cout<<"2. FIND "<<endl;
    cout<<"3. EXIT "<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"   selection: ";
    cin>>selection;
    cout<<endl;

    switch(selection)
    {
        case 1: add(); break;
        case 2: find(); break;
    }

    }while (selection!=3);




    return 0;
}
