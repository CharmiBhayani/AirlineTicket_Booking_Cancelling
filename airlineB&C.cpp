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
