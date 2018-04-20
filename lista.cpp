// LISTA JEDNOKIERUNKOWA -> mozna dodawac z przodu i z tylu push_front oraz back
#include <iostream>
#include <list>
#include <windows.h>
//#include<unistd.h> pod linuksa
using namespace std;

list <int> lista; //utworzenie listy przechowujacej liczby calkowite
int selection;


void display()
{
    system("CLS");
    cout<<" LIST ALGORITHM: "<<endl;
    cout<<"---------------------------"<<endl;

    for(list<int>::iterator i=lista.begin(); i!= lista.end(); ++i)
       cout<<*i<<" ";

    cout<<endl;
    cout<<"---------------------------"<<endl<<endl;
}

void push_front()
{
    int number;
    cout<<"Podaj jaka liczbe wstawic na pocz\245tek listy: ";
    cin>>number;
    lista.push_front(number);
}

void push_back()
{
    int number;
    cout<<"Podaj jaka liczbe wstawic na koniec listy: ";
    cin>>number;
    lista.push_back(number);
}

void pop_front()
{
    cout<<"Nast\245pi usuni\251cie liczby z pocz\245tku listy";
    Sleep(2000);
    //usleep -> jesli jestesmy na linuxie
    lista.pop_front();
}

void pop_back()
{
    cout<<"Nast\245pi usuni\251cie liczby z konca listy";
    Sleep(2000);
    //usleep -> linuxie
    lista.pop_back();
}

void size()
{
    cout<<"Liczb na li\230cie: "<<lista.size();
    Sleep(2000);
    //usleep -> linux
}

void max_size()
{
    cout<<"Max liczb na li\230cie: "<<lista.max_size();
    Sleep(5000);
    //usleep -> linux
}

void empty()
{
    cout<<"Czy lista pusta? -> ";
    if (lista.empty()==1) cout<<"TRUE"; else cout<<"FALSE";
    Sleep(2000);
    //usleep -> linux
}

void remove()
{
    int number;
    cout<<"Remove value from list  ";
    cin>>number;
    lista.remove(number);
}

void sort()
{
    cout<<"Next, SORT list ";
    lista.sort();
    Sleep(2000);
}

void reverse()
{
    cout<<"Next, REVERSE VALUE";
    lista.reverse();
    Sleep(2000);
}

void exit()
{
    cout<<"END";
    Sleep(2000);
}

int main()
{

do
{

display();

cout << " MENUFILE:"<<endl;
cout << "---------------------------"<<endl;
cout << "1.  push_front"<<endl;
cout << "2.  push_back"<<endl;
cout << "3.  pop_front"<<endl;
cout << "4.  pop_back"<<endl;
cout << "5.  size"<<endl;
cout << "6.  max_size"<<endl;
cout << "7.  empty"<<endl;
cout << "8.  remove"<<endl;
cout << "9.  sort"<<endl;
cout << "10. reverse"<<endl;
cout << "11. exit"<<endl;
cout << "---------------------------"<<endl;
cout << "selection: ";
cin >> selection;

	switch (selection)
	{
        case 1:  push_front(); break;
        case 2:  push_back();  break;
        case 3:  pop_front();  break;
        case 4:  pop_back();   break;
        case 5:  size();       break;
        case 6:  max_size();   break;
        case 7:  empty();      break;
        case 8:  remove();     break;
        case 9:  sort();       break;
        case 10: reverse();    break;
        case 11: exit();       break;

        default:
        cout<<"WRONG WAY!";
        Sleep(2000);
        //usleep -> linux
        break;
	}

}
while(selection!=11);

    return 0;
}
