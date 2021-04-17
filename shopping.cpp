#include<fstream>
#include<iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
class file
{
public:
    file()
    {
      ofstream fout;
      fout.open("system.txt");
      fout<<"system";
      fout.close();
    }
};
class product:public virtual file
{
  public:
   int quan;
   string name;
   int id;
   double percost;
   double persell;
   double cost;
void file()
{
  string file;
  file=to_string(id);
  file=file+".txt";
  ofstream f(file);
  cost=percost*quan;
  f<<name<< " "<<id<<" " <<percost<<" "<<persell<<" "<<quan<<" "<<percost*quan<<" "<<cost;
  f.close();
}
void get()
{
  int p;
  int flag=0;
  cout<<"\nNumber of products you want to add:\n";
  cin>>p;
  for(int i=0;i<p;i++)
  {
  system("clear");
  cout<<"\nInput product name: \n";
  cin>>name;
  cout<<"\nInput product id: \n";
  cin>>id;
  cout<<"\nInput cost price of product: \n";
  cin>>percost;
  cout<<"\nInput selling price of product: \n";
  cin>>persell;
  cout<<"\nTotal product quantity: \n";
  cin>>quan;
  file();
  }

} 
};
class staff:public virtual file
{
  protected:
  double salary;
  string empname;
  int empid;
  void getstaff()
  {
    system("clear");
    cout<<"\nInput salary: \n";
    cin>>salary;
    cout<<"Input employee name\n";
    cin>>empname;
    cout<<"\nInput employee ID\n";
    cin>>empid;
    file();
  }
  void file()
  {  
    string file;
    file=to_string(empid);
    file=file+".txt";
    ofstream f(file);
    f << " "<<salary<< " "<<empname<<" "<<empid;
    f.close();
  }
};

class amount:public staff, public product
{

public:
void add()
{
	int ch;
	while(1)
	{
		cout<<"1.)Input for product\n2.)Input for employee\n3.)Exit\n";
		cout<<"Enter choice\n";
		cin>>ch;
		if(ch==1)
        {
			get();
		}
		else if(ch==2)
        {  
			getstaff();
		}
		else if(ch==3)
            break;
		else
            cout<<"Invaid Option. Please re-enter\n";

	}

}
void update_item()
{
    int id;
    char c;
    cout<<"\nINPUT product ID to modify\n";
    cin>>id;
    string file;
    file=to_string(id);
    file.append(".txt");
    fstream fout(file,ios::in|ios::out);
    if(!fout)
    {
    	cout<<"File couldn't be opened.Product ID not found. \n";
        cout<<"\nEnter a character to continue";
        cin.ignore();
        cin.get();
	}
	  else
    {
      cout<<"File found! \n";
      cout<<"\nUpdate product name: \n";
  	  cin>>name;
 	  cout<<"\nUpdate percost of product: \n";
  	  cin>>percost;
 	  cout<<"\nUpdate persell of product: \n";
  	  cin>>persell;
 	  cout<<"\nUpdate total product quantity: \n";
 	  cin>>quan;
      cost=percost*quan;
  	  fout<<" "<<name<< " "<<id<<" " <<percost<<" "<<persell<<" "<<quan<<" "<<cost<<"\n";
	  fout.close();
    }

}
  void update_emp()
{
    string ename;
    int eid;
    double sal;
    cout<<"\nINPUT employee ID to modify: ";
    cin>>eid;
    string file;
    file=to_string(eid);
    file.append(".txt");
    fstream fout(file,ios::in|ios::out);
    if(!fout)
    {								
      cout<<"File couldn't be opened. product ID not found. \n";
      cout<<"\nEnter a character to continue";
      cin.ignore();
      cin.get();
	}
    else
    {
        cout<<"Change employee name: \n";
        cin>>empname;
        cout<<"Change employee salary: \n";
        cin>>salary;
        fout<< " "<<salary<< " "<<empname<<" "<<eid;
 	    fout.close();       
    }
}
};

void admin()
{
  system("clear");
  int i=4,c=0,j,choice;
  string user="rajat";
  string use;
  while(i>=0)
  {
    i--;
    char p[9]= "rajatadk";
    char pass[9],ch;
    cout<<"Enter Password:";
    for(j=0;j<8;j++)
    {
      ch=getch();
      pass[i]=ch;
      ch='*';
      cout<<""<<"ch";
    }
    for (j=0;j<8;j++)
   {
      if (pass[j] == p[j])
        c = c+1;
   }
    if(c==8)
    {
      break;
    }
    else
    {
      cout<<"Incorrect Password Enter again\n"<<i<<" More chances available\n\n";
      cout<<"If you want to change password press 1\n";
      cin>>choice;
      if(choice==1)
      {
        system("clear");
        cout<<"Enter Username:";
        cin>>use;
        if(use==user)
        {
          cout<<"Enter new password:";
          cin>>pass;
        }
        else
        {
          cout<<"No username found\n";
          system("clear");
        }
        
      }
    }
    
    if(i==0)
    {
      exit(0);
    }
  }
  while(1)
  {
    system("clear");
 	cout<<"\n\t\t\t==============================\n";
	cout<<"\n\t\t\t     WELCOME TO THE SYSTEM  \n";
	cout<<"\n\t\t\t==============================\n\n";
 	cout<<"\n\t\t\t1. Add Entries\n\n\t\t\t2. Search Product Details\n\n\t\t\t3. Search Employee Details\n\n\t\t\t4. Modify Product Details\n\n\t\t\t5. Modify Employee Details\n\n\t\t\t6. Exit\n";
    cout<<"\n\n\t\t\tSelect your choice\n";
  int u;
  cin>>u;
  if(u==1)
  {
    system("clear");
    amount a;
    a.add();
  }
  else if(u==2)
  {  
    system("clear");
    int id;
    int q;
    string n;
    int i;
    double pc;
    double ps;
    double c;
    cout<<"\nINPUT ID to search\n";
    cin>>id;
    string file;
    file=to_string(id);
    file.append(".txt");
    ifstream x(file);
    if(!x)
    {
    	cout<<"File couldn't be opened. Product ID not found. \n";
	}
    else
    {
        while(x >> n >> i >> pc >> ps >> q >> c)
        {
            cout<<"\nProduct name:"<<n;
            cout<<"\nProduct id:"<<i;
            cout<<"\nCost Price:"<<pc;
            cout<<"\nSelling Price:"<<ps;
            cout<<"\nQuantity:"<<q;
            cout<<"\nTotal cost:"<<c;

        }
    }
    
    x.close();
    cout<<"\nEnter a character to continue....";
    cin.ignore();
    cin.get();
  }

   else if(u==3)
   {
    system("clear");
   	int eid;
    string en;
    int eid2;
    double sl;
   	char d;
   	cout<<"\nINPUT employee ID to search\n";
    cin>>eid;
   	string file;
   	file=to_string(eid);
   	file.append(".txt");
   	ifstream y(file);
   	if(!y)
    {
    	cout<<"File couldn't be opened.Employee ID not found. \n";
	}
    else
    {
        while( y >> sl >> en >> eid2)
        {
            cout<<"\nEmployee Salary:"<<sl;
            cout<<"\nEmployee Name:"<<en;
            cout<<"\nEmployee Id:"<<eid2;    
        }
    }
    y.close();
    cout<<"\nEnter a character to continue.....";
    cin.ignore();
    cin.get();
   }
  else if(u==4)
  {
      system("clear");
	  amount u;
	  u.update_item();
  }
  else if(u==5)
  {
      system("clear");
 	  amount v;
 	  v.update_emp();
  }
  else if(u==6)
  {
       system("clear");
       break;
  }
  else 
  cout<<"Invalid option. Please select one of the available options\n";
 }

}
class bil
{
    public:
    void getitem()
    {
        int choice,pid,q;
        int qu,qu1;
        string n,m;
        int i,flag=0;
        double pc,pc1;
        double ps,ps1;
        double c,c1,pr,tpr=0;
        string file;
        ofstream r("reciept.txt");
        r<<"       "<<"BILL"<<"       \n";
        r.close();
        while(1)
        {
            system("clear");
            cout<<"\nEnter 1:To add item 2:To exit";
            cin>>choice;
            if(choice==1)
            {
                system("clear");
                cout<<"\nEnter Product id:";
                cin>>pid;
                cout<<"\nEnter Quantity:";
                cin>>q;
                file=to_string(pid);
                file.append(".txt");
                ifstream f(file);
                if(!f)
                {
                    cout<<"\nNo Id Found";
                    break;
                }
                else
                {
                    while(f >> n >> i >> pc >> ps >> qu >> c)
                    {
                        m=n;
                        pc1=pc;
                        ps1=ps;
                        qu1=qu;
                        c1=c;
                        pr=ps*q;
                        if(q>qu)
                        {
                            cout<<"\nOnly"<<qu<<"left:";
                            f.close();
                            flag=1;
                            break;
                        }
                        else
                        {
                            f.close();
                            ofstream f(file);
                            f<<" "<<m<< " "<<pid<<" " <<pc1<<" "<<ps1<<" "<<qu1-q<<" "<<c1<<"\n";
                            f.close();
                            tpr=tpr+pr;
                            fstream f1("reciept.txt",ios::app);
                            f1<<"\nProduct Id: "<<pid<<"Product name: "<<m<<"Quantity: "<<q<<"Price: "<<pr<<"\n";
                            f1.close();
                        }
                        
                    }
                    if(flag==1)
                    {
                        break;
                    }
                }

                fstream f1("reciept.txt",ios::app);
                f1<<"\nTotal Bill:"<<tpr;
                f1.close();
                
            }
            if(choice == 2)
            {
                break;
            }
        }
    }
    void print()
    {
        ifstream f("reciept.txt");

    }
};


void bill()
{
    int i;
    bil b;
    while(1)
    {
      cout<<"Enter 1:To enter items 2:Print Bill 3:Exit";
      cin>>i;
      if(i==1)
      {
        system("clear"); 
        b.getitem();
      }
      if(i==2)
      {
        system("clear");
        b.print();
      }
      if(i==3)
      {
        break;
      }
      
    }
}


int main(){
    int ch;
    char  username[20];
    char password[20];
    char pwd[20];
    while(1)
    {
        cout<<"\n \t\t\t=========================\n";
        cout<<"\n\t\t\tWELCOME TO MY SHOPPING MALL MANAGEMENT SYSTEM  \n";
        cout<<"\n \t\t\t=========================\n\n";
        cout<<"\n \t\t\t* * * * * * * * * * * * ";
        cout<<"\n\t\t\t  1. ENTER SYSTEM";
        cout<<"\n\t\t\t  2. BILL";
        cout<<"\n\t\t\t  3. EXIT";
        cout<<"\n\t\t\t* * * * * * * * * * * *\n";
        cout<<"\n\t\t\t Enter Your choice: ";
        cin>>ch;
        switch(ch)
        {
          case 1:system("clear");
                 admin();
                 break;
          case 2:system("clear");
                 bill();
                 break;
          case 3:system("clear");
                 exit(0);
                 break;
          default:cout<<"Enter valid choice\n";
                  break;
        }
    }
    return 0;
}