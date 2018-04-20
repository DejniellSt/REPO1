#include <iostream>
//#include <unistd.h> // NALEZY ZASTOSOWAC PRZY LINUXIE I ZAMIAST Sleep -> usleep
#include<windows.h>

using namespace std;

int data[5];
int counter;
int header;
int tail;

void display()
{
    system("CLS");
    cout<<endl;
    cout<<"-------------------"<<endl;
    cout<<"FIFO algorithm: "<<endl;
    cout<<"-------------------"<<endl;


    if (counter==0)
    {
        cout<<"Now is empty!";
    }

    else
    {

        int index;

        for (int i=0; i<counter; i++)
        {
            index=header+i;
            if (header+i>=5) index=header+i-5;
            cout<<data[index]<<" ";
        }

    }

    cout<<endl<<"-------------------"<<endl<<endl;
}

void push()
{
    if (counter>=5)
    {
        cout << "FIFO algorithm is full!";
        Sleep(1000);
    }
    else
    {
        cout<<endl<< "PUSH - add value to FIFO: ";
        cin>>data[tail];
        tail=(tail+1)%5;
        counter=counter+1;
    }
}

void pop()
{
    if (counter==0)
    {
        cout<<"FIFO algorithm is empty!";
        Sleep(1000);
    }
    else
    {
        cout<<endl<<"POP - remove value from the FIFO: "<<data[header];
        header=(header+1)%5;
        counter=counter-1;
		Sleep(1000);
    }
}

void size()
{
    cout<<endl<<"Number of value in FIFO: "<<counter;
    Sleep(1000);
}

void empty()
{

    if (counter==0) cout<<endl<<"EMPTY ->  TRUE";
    else cout<<endl<<"EMPTY ->  FALSE";
    Sleep(1000);
}

int main()
{

    int selection;
    counter=0;
    header=0;
    tail=0;

    do
    {

        display();

        cout<<"header="<<header<<"   tail="<<tail<<"   counter="<<counter<<endl<<endl;

        cout << "MENU:"<<endl;
        cout << "------------------------------------------"<<endl;
        cout << "1. PUSH (add value) "<<endl;
        cout << "2. POP (remove value) "<<endl;
        cout << "3. SIZE  "<<endl;
        cout << "4. EMPTY "<<endl;
        cout << "5. END "<<endl;
        cout << "------------------------------------------"<<endl;
        cout << "selection: ";
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
            size();
            break;

        case 4:
            empty();
            break;
        }

    }
    while (selection != 5);

    return 0;
}
