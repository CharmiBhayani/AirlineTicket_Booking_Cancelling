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


