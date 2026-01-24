#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std;
class customer{
public:
char name[30];
char seatno[5];
char status[10];
char phno[11];


void input(char bsno[]){
  cout<<"Enter the Following details of Customer:\n";
  cout<<"Name: ";cin>>name;
  strcpy(seatno,bsno);
  cout<<"Phone Number: ";cin>>phno;
  strcpy(status,"B");
}
};

class seat{
public:
char seat[20];
char statuss[10];
};

fstream f;
seat s1;
fstream fout;
void set_seat(){
  fout.open("seat.dat",ios::binary|ios::in);
  if(!fout){
    for(int i=65;i<75;i++){
      for(int j=1;j<=7;j++){
        char s[20];
        sprintf(s,"%c",i);
        char sn[20];
        sprintf(sn,"%d",j);
        strcat(s,sn);
        strcpy(s1.seat,s);
        strcpy(s1.statuss,"A");
        f.open("seat.dat",ios::binary|ios::app);
        f.write((char *)&s1,sizeof(s1));
        f.close();
      }
    }
  }
  fout.close();
}
customer c;
void display()
{
    int cs=0,cn=0,c=0;
    f.open("seat.dat",ios::binary|ios::in);
    cout<<"AIR INDIA\t\t\t\t\t"<<"Flight Number-5241\t\t\t\t\t"<<"Date-6/12/2023\n"<<endl;
    while(f.read((char *)&s1,sizeof(s1)))
    {
        cout<<"|"<<s1.seat<<"-"<<s1.statuss<<"|";
        cs++;
        if(cs==3)
        {
            cout<<"\t\t";
        }
        if(cs==7)
        {
            cout<<endl;
            cs=0;
            cn++;
        }
        if(cn==6)
        {
            if(c==0)
            {
            cout<<endl<<"\t\t\t----------";
            cout<<endl<<"\t\t\tPASSAGE\n";
            cout<<"\t\t\t----------\n";
            c++;
            }
        }
    }
    f.close();
}
void book(){
  int flag=0;
    char bsno[10];
    cout<<"ENter seat number to Book.\n";
    fflush(stdin);gets(bsno);
    f.open("seat.dat",ios::binary|ios::in|ios::out);
    while(f.read((char *)&s1,sizeof(s1)))
    {
        int tell=f.tellp();

        if(strcmp(bsno,s1.seat)==0)
        {
            flag++;
            if(strcmp(s1.statuss,"A")==0)
            {
                c.input(bsno);
                fout.open("user.dat",ios::binary|ios::app);
                fout.write((char *)&c,sizeof(c));
                fout.close();
                strcpy(s1.statuss,"B");
                f.seekp(tell-sizeof(s1));
                f.write((char *)&s1,sizeof(s1));
                cout<<endl<<"Booked Successfully.\n";
                break;
            }
        }
    }
    f.close();
    if(flag==0)
    {
        cout<<"Invalid Seat Number.\n";
    }
}
fstream ff;
void cancel()
{
    char csno[10];
    int flag1=0,flag2=0;
    cout<<"Enter the seat number to Cancel booking.\n";
    fflush(stdin);
    gets(csno);
    f.open("user.dat",ios::binary|ios::in);
    fout.open("new.dat",ios::binary|ios::app);
    while(f.read((char *)&c,sizeof(c)))
    {
        if(strcmp(csno,c.seatno)==0 )
        {

                cout<<"Ticket canceled successfully.\n";
                ff.open("seat.dat",ios::binary|ios::in|ios::out);
                while(ff.read((char *)&s1,sizeof(s1)))
                {

                     int tell=ff.tellp();
                    if(strcmp(s1.seat,csno)==0)
                    {
                        strcpy(s1.statuss,"A");
                        ff.seekp(tell-sizeof(s1));
                        ff.write((char *)&s1,sizeof(s1));
                        break;
                    }

                }
                ff.close();
            }

        else
        {
            fout.write((char *)&c,sizeof(c));
        }
    }
    f.close();
    fout.close();
    remove("user.dat");
    rename("new.dat","user.dat");

}
int main()
{
    int ch;
    set_seat();
    while(1)
    {
    cout<<"*****MENU*****\n";
    cout<<"1.Booking\n2.Canceling\n3.exit\n";
    cout<<"Enter your choice: ";cin>>ch;
    system("cls");
    switch(ch)
    {
        case 1:
           display();book();break;
        case 2:
            display();cancel();break;
        case 3:exit(0);
        default:
            cout<<"Invalid choice.\n";
    }
    }
    return 0;
}



