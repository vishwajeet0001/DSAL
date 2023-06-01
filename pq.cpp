#include<iostream>
using namespace std;
#define size 30

class PQueue{

   int r=-1;
   int f=-1;
   string a[size]; 
   string priority[size];
   public:
      
   void enqueue(string name,string priority_name){
      
      //if full
      if(r==size-1){
        cout<<"Hotel Capacity overloaded";
      }
      else{
       
        if(r==-1 && f==-1){
           r=0;
           f=0;
           a[r]=name;  
           priority[r]=priority_name;
         
        }
        else{
            if(priority_name=="VIP"){
               if(priority[r]!="VIP"){
                  int i=r;
                  while(priority[i]!="VIP" && i!=-1){
                  
                    pq[i+1]=pq[i];
                    priority[i+1]=priority[i];
                    i--;
                  }
                  pq[i+1]=name;
                  priority[i+1]=priority_name;
                  r++;
                 
               }
               else{
                 r++;
                 pq[r]=name;
                 priority[r]=priority_name;
               }
            
          }
          else if(priority_name=="Reserved"){
            if(priority[r]!="Reserved"){
                 int i=r;
                  while((priority[i]!="VIP" && priority[i]!= "Reserved") && i!=-1){
                  pq[i+1]=pq[i];
                  priority[i+1]=priority[i];
                  i--;
                 }

                 pq[i+1]=name;
                 priority[i+1]=priority_name;
                 r++;
            }
            else{
              r++;
              pq[r]=name;
              priority[r]=priority_name;
            }
            
          }
          else{
                 r++;
                 pq[r]=name;
                 priority[r]=priority_name;
          }
        }
      }
      cout<<"Order Accepted "<<endl;
      display();
   }

   void display(){

      for(int i=0;i<=r;i++){
        cout<<pq[i]<<" -> "<<priority[i]<<endl;
      }
   }

   void dequeue(){

     if(f==-1 && r==-1){
      cout<<"Queue is empty ";
     }
     else{
       for(int i=0;i<r;i++){
         pq[i]=pq[i+1];
         priority[i]=priority[i+1];
       }
       r--;
     }
     cout<<"Order Delivered "<<endl;
     display();
   }
   
   
};

int main(){
  int ch;
  int s;
  string name;
  string priority_name;
  char c;
  PQueue obj;
  do{
      cout<<"--------------------------HOTEL MANAGEMENT OPERATIONS--------------------------";
      cout<<"\n\t1:To accept Order";
      cout<<"\n\t2:To Deliver Order";
      cout<<"\n\t3:Display all Orders";
      cout<<"\nEnter choice : ";
      cin>>ch;
      cout<<endl;

      if(ch==1){
           cout<<"Enter Your Order : "<<endl;
           cin>>name;
           cout<<endl;
           cout<<"Enter nature of Order accordingly : ";
           cout<<"\nEnter 1 : VIP";
           cout<<"\nEnter 2 : RESERVED ";
           cout<<"\nEnter 3 : Normal ";
           cout<<"\nEnter number : ";
           cin>>s;
           if(s==1){
            priority_name="VIP";
           }else if(s==2){
            priority_name="Reserved";
           }else{
            priority_name="Normal";
           }
           obj.enqueue(name,priority_name);
      }
      else if(ch==2){
        obj.dequeue();
      }
      else{
        obj.display();
      }
      cout<<"Do you want to continue?(y/n) : ";
      cin>>c;
  }while(c=='y');

  return 0;
}