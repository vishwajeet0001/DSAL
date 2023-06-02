#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class stud
 {

 public:
 int rollNo;
 char name[10];
 char div;
 char address[20];
 

 void accept()
 {
  cout<<"Enter Roll Number : ";
  cin>>rollNo;
  cout<<"Enter the Name : ";
  cin>>name;
  cout<<"Enter the Division:";
  cin>>div;
  cout<<"Enter the Address:";
  cin>>address;
 }

void display()
  {
  cout<<"\n\t"<<rollNo<<"\t\t"<<name<<"\t\t"<<div<<"\t\t"<<address;
  }
};


int main()
{
 int ch,ch1;
 stud s;
 fstream f,g;
 do
 {
  cout<<"\n>>>>>>>>>>>>>>>>>>>>>>MENU<<<<<<<<<<<<<<<<<<<<";
  cout<<"\n1.Accept\n2.Display\n3.Delete a Student Record\n4.Search\n5.exit\nEnter a Choice:";
  cin>>ch;
  switch(ch)
  {
     case 1:
     f.open("s.txt",ios::out);
     x:s.accept();
     f.write((char*) &s,(sizeof(s)));
     cout<<"\nDo you want to enter more records?\n1.Yes\n2.No"<<endl;
     cin>>ch1;
     if(ch1==1)
      goto x;
     else
     {
     f.close();
     break;
     }

  case 2:
   f.open("s.txt",ios::in);
   f.read((char*) &s,(sizeof(s)));
   while(f)
   {
    s.display();
    f.read((char*) &s,(sizeof(s)));
   }
   f.close();
   break;
   
  
   case 3:
     f.open("s.txt",ios::in);        //original file
     g.open("temp.txt",ios::out);       //temp file
     cout<<"enter a roll no. for which data to be deleted";
     int key;
     cin>>key;
     while(f.read((char*) &s,(sizeof(s))))
     {
        if(key!=s.rollNo)
        {
           g.write((char*) &s,(sizeof(s)));    //here writing all record on temp file rather than deleting record part
        }
     }
     f.close();
     g.close();
     remove("s.txt");
     rename("temp.txt","s.txt");
     break;

    case 4:
    f.open("s.txt",ios::in);
    cout<<"enter a roll no. to search:";
    int k;
    cin>>k;
    if(k==s.rollNo)
    {
        cout<<"record found:";
        cout<<s.rollNo<<endl;
        cout<<s.name<<endl;
        cout<<s.div<<endl;
        cout<<s.address<<endl;
    }
    else
    {
        cout<<"record not found";
    }
    f.close();
    break;
     
    
    case 5:
       cout<<"\n\tThank you";
       break;


        }
  }while(ch!=5);
}
