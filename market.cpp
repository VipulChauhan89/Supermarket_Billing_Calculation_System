#include<iostream>          // input output
#include<iomanip>           // output manipulators
#include<fstream>           // to perform file handling
#include<stdlib.h>          // to use clear screen function
#include<chrono>           // to input delay while displaying the outputs      
#include<thread>           // to input delay while displaying the outputs
#include<vector>           // to use vectors of stl
#include<sstream>          // allows a string object to be treated as a stream
#include<ctime>            // to display the current date and time 
#include <unistd.h>       //loding animation

using namespace std;
using namespace std::chrono;        // nanoseconds, system_clock, seconds
using namespace std::this_thread;   // sleep_for, sleep_until
class User
{  
    //  Abstract class as function pass_check() is a pure virtual function declared in the class
    private:
        ofstream write;
        ifstream read;
        string manager,cashier,customer;
        int order_no;
        float gst;
        string manager_pass,cashier_pass;
        vector<pair <string,int> > itm_q;           // itm_s for item and it's quantity
        vector<pair <int,float> > pr_t;              // price and total
        float Grand_total;
    
    protected:
        virtual int pass_check()=0;
        void initially()
        {
            Grand_total=0;
            gst=0;
        }
        void set_id_pass()              // the default id and password for owner manager and cashier
        {        
            read.open("password.txt");    
            read>>manager;
            read>>manager_pass;
            read>>cashier;
            read>>cashier_pass;
            read.close();
        } 
        void set_manager(string manager,string manager_pass)    // setter for setting the values for Manager
        {
            write.open("password.txt");
            this->manager=manager;
            write<<manager<<" ";
            this->manager_pass=manager_pass;
            write<<manager_pass<<endl;
            write<<this->cashier<<" ";
            write<<this->cashier_pass;
            write.close();
        }
        void set_cashier(string cashier,string cashier_pass)    // setter for setting the values for Cashier
        {
            write.open("password.txt");
            this->cashier=cashier;
            write<<this->manager<<" ";
            write<<this->manager_pass<<endl;
            write<<cashier<<" ";
            this->cashier_pass=cashier_pass;
            write<<cashier_pass;
            write.close();
        }
        bool check_manager(string id,string pass)       // to be continued to check if the user already exist and if you want to overwrite the user
        {
            if(id==manager && pass==manager_pass)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        int check_pass(string id,string pass)       // to be continued to check if the user already exist and if you want to overwrite the user
        {
            if(id==manager && pass==manager_pass )
            {
                return 1;
            }
            else if(id==cashier && pass==cashier_pass)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }

    public :
        void items(string search)
        {
            string item,item1;
            int stock,stock1,price,price1,n,num,count=0;
            
            read.open("items.txt");
            while(read>>item)
            {
                read>>stock;
                read>>price;
    
                if(item==search)
                {   
                    count=1;
                    do
                    {
                        system("clear");
                        cout<<"Item : "<<item<<endl;                
                        cout<<"Enter"<<endl; 
                        cout<<"1- To change the stock."<<endl;
                        cout<<"2- To change the price of item."<<endl;
                        cout<<"3- To Exit."<<endl;
                        cout<<"Enter your choice : ";
                        cin>>n;
                        if(n==1)
                        {                            
                            cout<<"Enter the number of items newly arrived : ";
                            cin>>num;
                            stock+=num;
                            system("clear");
                        }
                        else if(n==2)
                        {
                            cout<<"Enter the new price of the item : ";
                            cin>>price;
                            system("clear");
                        }
                        else if(n==3)
                        {
                            break;
                        }
                        else
                        {
                            cout<<"wrong choice"<<endl;                            
                        }
                    }while(n!=3);
                    break;
                }  
            }
            read.close();
            read.open("items.txt");                             // to write the updated items into file      
                
            write.open("new.txt");                              // to write the updated items into file                          
            while(read>>item1)
            {
                read>>stock1;
                read>>price1;
                if(item1==item)
                {
                    write<<item<<" ";
                    write<<stock<<" ";
                    write<<price<<endl;
                }
                else
                {
                    write<<item1<<" ";
                    write<<stock1<<" ";
                    write<<price1<<endl;
                }   
            }
            read.close();
            write.close();
            remove("items.txt");
            rename("new.txt","items.txt");
            if(count==0)
            {
                cout<<"Item doesn't exist in the stock please fist of all add the item to the stock.."<<endl;
                cout<<"Press Any Key to continue. ";
                fflush(stdin);
                getchar();
            }
        }
        float Cashier_items(string search)
        {
            string item,item1;
            int stock,stock1,price,price1,n,num,count=0;
            float total;
            read.open("items.txt");
            while(read>>item)
            {
                read>>stock;
                read>>price;
                if(item==search)
                {   
                    count=1;                     
                    cout<<"Enter how many "<<item<<" you want to buy :"; 
                    cin>>stock1;
                    itm_q.push_back(make_pair(item,stock1));  //vect.push_back( make_pair(string,quantity );
                    total=stock1*price;
                    pr_t.push_back(make_pair(price,total));
                    stock-=stock1;
                    break;                  
                }
            }
            read.close();
            if(count==0)
            {
                cout<<"Sorry but this item is not in our stock"<<endl;
            }
            read.open("items.txt");                             // to write the updated items into file      
                
            write.open("new.txt");                              // to write the updated items into file                          
            while(read>>item1)
            {
                read>>stock1;
                read>>price1;
                if(item1==item)
                {
                    write<<item<<" ";
                    write<<stock<<" ";
                    write<<price<<endl;
                }
                else
                {
                    write<<item1<<" ";
                    write<<stock1<<" ";
                    write<<price1<<endl;
                }   
            }
            read.close();
            write.close();
            remove("items.txt");
            rename("new.txt","items.txt");
            return total;
        }
        void items_stocks()
        {
            system("clear");
            string search;
            cout<<"Enter the item which you want to update : ";
            cin>>search;
            items(search);                
        }

        void add_item()
        {
            write.open("items.txt",ios::app);
            string item,item1;
            int stock,stock1,price,price1,count,n=0;
            do
            {
                count=0;
                cout<<"Enter the item which you want to add in the stock : ";
                cin>>item;
            
                read.open("items.txt");
                while(read>>item1)                                              // if the item already exist in the file
                {
                    read>>stock1;
                    read>>price1;
                    if(item1==item)
                    {
                        count=1;
                        cout<<"Item already exist in the stocks."<<endl;
                        cout<<"Please select the Right menu to update the existing item "<<endl;
                        fflush(stdin);
                        cout<<"Enter any key to continue.";
                        getchar();
                        system("clear");
                        count=1;
                        read.close();
                        break;
                    }
                }
                if(count==0)                                        // if the item is not in the file
                {
                    cout<<"Enter the stock of "<<item<<" :";
                    cin>>stock;
                    cout<<"Enter the price of "<<item<<" :";
                    cin>>price;
                    write<<item<<" ";
                    write<<stock<<" ";
                    write<<price<<endl; 
                }
                system("clear");
                cout<<"Press"<<endl<<"0-To add more items to the stock "<<endl;
                cout<<"1-To Exit."<<endl;
                cout<<"Enter your choice : ";
                cin>>n;
                read.close();
            }while(n!=1);
        }
        
        void Bill_generate()
        {
            sleep_for(nanoseconds(10));
            sleep_until(system_clock::now()+seconds(1)); 
            system("clear");
            float total;
            int i=1;
            cout<<"Enter 0 when you are done ."<<endl;
            cout<<"Enter the items :"<<endl; 
            string s;
            do
            {
                fflush(stdin);
                cout<<i<<" ";
                i++;
                getline(cin,s);                
                total=Cashier_items(s);
                Grand_total+=total;
            }while (s!="0");
            Bill_printing();
        }
        void load()
        {
            int i = 0; 
 	        char load[6]; 
 	        while(i < 5) 
 	        { 
 		        system("clear"); 
 		        load[i++] = '.'; 
 		        load[i] = '\0'; 
		        printf("\n\nLOADING %-5s", load); 
                //usleep suspends the execution of the program for specific duration of time
 		        usleep(199900); 
 	        } 
            system("clear"); 
            printf("\n"); 
        }
        void Bill_printing()
        {
            unsigned long long int receipt_number,order_number;
            read.open("order.txt");
            read>>receipt_number>>order_no;
            receipt_number++;
            order_no++;
            read.close();
            write.open("order.txt");
            write<<receipt_number<<endl<<order_no;
            write.close();

            gst=(.18*Grand_total);
            time_t now = time(NULL);            
            string t=ctime(&now);
            system("clear");
            cout<<"Enter customer's name :";
            getline(cin,customer);
            system("clear");
            load();
            sleep_for(nanoseconds(10));
            sleep_until(system_clock::now()+seconds(1));
            system("clear"); 
            cout<<"------------------------ BIG BAZAAR SUPERMARKET -------------------------"<<endl<<endl;
            cout<<"                     CITY JUNCTION MALL , DEHRADUN                   "<<endl;
            cout<<"                            PIN - 248001                          "<<endl<<endl;
            cout<<"                      FSSAI REG. NO. :- 22645678651                   "<<endl;
            cout<<"                        TAX NO. - OBN67539BHEW568                "<<endl<<endl;
            cout<<"  Reciept Number : "<<receipt_number<<endl;
            cout<<"  "<<t<<endl;
            cout<<"  Manager :  "<<manager<<endl;
            cout<<"  Cashier :  "<<cashier<<endl;
            cout<<"  Customer : "<<customer<<endl;
            cout<<"  Order Number : "<<order_no<<endl;
            cout<<"  ------------------------------------------------------------------ "<<endl;
            cout<<"  No Item \tQuantity\t\tRate\t\tNet Amt"<<endl;
            for(int i=0;i<itm_q.size();i++)
            {
                cout<<"  "<<i+1<<". "<<itm_q[i].first<<"\t   "<<itm_q[i].second<<"\t\tX\t₹"<<pr_t[i].first<<"\t=\t₹"<<pr_t[i].second<<endl; 
            }
            cout<<"  ------------------------------------------------------------------ "<<endl<<endl;
            cout<<"  Items Count : "<<itm_q.size()<<endl<<endl;
            cout<<"  ------------------------------------------------------------------ "<<endl<<endl;
            cout<<"  Subtotal :                                                ₹ "<<Grand_total<<endl;
            cout<<"  GST 18%  :                                                ₹ "<<gst<<endl<<endl;
            cout<<"  ------------------------------------------------------------------ "<<endl<<endl;
            cout<<"  \e[1mTOTAL\e[1m                                                    ₹ "<<Grand_total+gst<<endl<<endl;
            cout<<"  \e[0m\e[0m------------------------------------------------------------------ "<<endl<<endl;
            cout<<"  Thank You! "<<customer<<" for shopping with us."<<endl<<endl;
            cout<<"  ------------------------------------------------------------------ "<<endl;
            cout<<"                NOTE : NO RETURN, NO REFUND POLICIES"<<endl;
            cout<<"  ------------------------------------------------------------------ "<<endl;

            stringstream ss,cus;
            ss<<"bills/";
            cus<<customer;
            while(cus>>customer)
            {
                ss<<customer<<"_";
            }
            ss<<receipt_number<<".txt";
            string filename;
            ss>>filename;
            write.open(filename);
            write<<"------------------------ BIG BAZAAR SUPERMARKET -------------------------"<<endl<<endl;
            write<<"                     CITY JUNCTION MALL , DEHRADUN                   "<<endl;
            write<<"                            PIN - 248001                          "<<endl<<endl;
            write<<"                      FSSAI REG. NO. :- 22645678651                   "<<endl;
            write<<"                        TAX NO. - OBN67539BHEW568                "<<endl<<endl;
            write<<"  Reciept Number : "<<receipt_number<<endl;
            write<<"  "<<t<<endl;
            write<<"  Manager :  "<<manager<<endl;
            write<<"  Cashier :  "<<cashier<<endl;
            write<<"  Customer : "<<customer<<endl;
            write<<"  Order Number : "<<order_no<<endl;
            write<<"  ------------------------------------------------------------------ "<<endl;
            write<<"  No Item \tQuantity\t\tRate\t\tNet Amt"<<endl;
            for(int i=0;i<itm_q.size();i++)
            {
                write<<"  "<<i+1<<". "<<itm_q[i].first<<"\t   "<<itm_q[i].second<<"\t\tX\t₹"<<pr_t[i].first<<"\t=\t₹"<<pr_t[i].second<<endl; 
            }
            write<<"  ------------------------------------------------------------------ "<<endl<<endl;
            write<<"  Items Count : "<<itm_q.size()<<endl<<endl;
            write<<"  ------------------------------------------------------------------ "<<endl<<endl;
            write<<"  Subtotal :                                                ₹ "<<Grand_total<<endl;
            write<<"  GST 18%  :                                                ₹ "<<gst<<endl<<endl;
            write<<"  ------------------------------------------------------------------ "<<endl<<endl;
            write<<"  TOTAL                                                    ₹ "<<Grand_total+gst<<endl<<endl;
            write<<"  ------------------------------------------------------------------ "<<endl<<endl;
            write<<"  Thank You! "<<customer<<" for shopping with us."<<endl<<endl;
            write<<"  ------------------------------------------------------------------ "<<endl;
            write<<"                NOTE : NO RETURN, NO REFUND POLICIES"<<endl;
            write<<"  ------------------------------------------------------------------ "<<endl;
            getchar();
            system("clear");
            cout<<"Collect ₹"<<Grand_total+gst<<"/-"<<endl;
            cout<<"Press any key when done.";
            getchar();
            system("clear");
        }
};
// login using inherited properties of the Parent class User
class login:public User
{  
    public:
        login()
        {
            initially();
        }
        bool manager_check()
        {
            system("clear");
            string id,pass;
            fflush(stdin);
            cout<<"Enter the Manager's id : ";
            getline(cin,id);
            fflush(stdin);
            cout<<"Enter the Manager's password : ";
            getline(cin,pass);
            return check_manager(id,pass);
        }
        int pass_check()
        {
            system("clear");
            string id,pass;
            fflush(stdin);
            cout<<"Enter the id : ";
            getline(cin,id);
            fflush(stdin);
            cout<<"Enter the password : ";
            getline(cin,pass);
            return check_pass(id,pass);
        }
        void set_id_password()  // to set the id - password & call setter from the parent class
        {
            set_id_pass();
        }
        void sign_up()        //to set the id - password for Manager & Cashier
        {   
            int n;
            string id,pass;
            do
            {
                cout<<"Enter :"<<endl;
                cout<<"1-To Register a New Manager or to change the login ID/Pass of Manager"<<endl;
                cout<<"2-To Register a New Cashier or to change the login ID/Pass of Cashier."<<endl; 
                cout<<"3-To exit."<<endl;
                cout<<"Enter your choice : ";    
                cin>>n; 
                system("clear");
                if(n==1)
                {                  
                    cout<<"Enter the username for the Manager :";
                    fflush(stdin);
                    getline(cin,id);
                    cout<<endl<<"Enter the password for the Manager :";
                    fflush(stdin);
                    getline(cin,pass);
                    set_manager(id,pass);
                    cout<<"New Manager is Set"<<endl<<"Enter any key to continue : ";
                    getchar();
                    system("clear");            
                }
                else if(n==2)        
                {
                    cout<<"Enter the username for the Cashier :";
                    fflush(stdin);
                    getline(cin,id);
                    cout<<endl<<"Enter the password for the Cashier :";
                    fflush(stdin);
                    getline(cin,pass);
                    set_cashier(id,pass);
                    cout<<"New Cashier is Set"<<endl<<"Enter any key to continue : ";
                    getchar();
                    system("clear");                  
                }
                else if(n>3)
                {
                    cout<<"Wrong choice! Please, choose a valid option to proceed further."<<endl;
                }
            }while(n!=3);
        }
        void manager()
        {
            int n;
            do
            {
                system("clear");
                cout<<"Welcome Manager : "<<endl<<endl;
                cout<<"Enter what you want to do : "<<endl;
                cout<<"1- To manage the stock of items or change the price of the item ."<<endl;
                cout<<"2- To add new items in the list ."<<endl;
                cout<<"3- To Exit ."<<endl;
                cout<<"Enter your choice : ";
                cin>>n;
                switch(n)
                {
                    case 1:
                        items_stocks();
                        break;
                    case 2:
                        add_item();
                        break;
                    default:
                        cout<<"Wrong choice"<<endl;                        
                }
            } while (n!=3);
        }
        void cashier()
        {
            int n;
            do
            {
                system("clear");
                cout<<"Welcome Cashier : "<<endl<<endl;
                cout<<"Enter what you want to do : "<<endl;
                cout<<"1- To Generate the Bill."<<endl;
                cout<<"2- To Exit ."<<endl;
                cout<<"Enter your choice : ";
                cin>>n;
                switch(n)
                {
                    case 1:
                        Bill_generate();
                        break;
                    case 2:
                        break;
                    default:cout<<"You entered the wrong choice."<<endl;
                }
            } while(n!=2);
            
        }
};
int main()
{
    login a;       //Object for accessing the data members of the class User
    a.set_id_password();    
    int choice;
    int c;
    // Menu for displaying the login page
    do
    {
        system("clear");
        cout<<setfill('*')<<setw(70)<<"*"<<endl;        
        cout<<"---------------------BIG BAZAAR SUPERMARKET--------------------------"<<endl<<endl;
        cout<<"                     Welcome to login page                               "<<endl<<endl;
        cout<<"*******************           MENU          *************************"<<endl<<endl;
        cout<<"1.LOGIN"<<endl;
        cout<<"2.REGISTER OR CHANGE THE LOGIN ID/PASS"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"\nEnter your choice :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
            case 1:
                c=a.pass_check();
                if(c==1)//for manager
                {                    
                    system("clear");
                    cout<<endl<<"Access Granted"<<endl<<endl;
                    sleep_for(nanoseconds(10));
                    sleep_until(system_clock::now()+seconds(1));
                    
                    a.manager();    // Access the signup member function of class login
                }
                else if(c==2)//for cashier
                {
                    system("clear");
                    cout<<endl<<"Access Granted"<<endl<<endl;
                    sleep_for(nanoseconds(10));
                    sleep_until(system_clock::now()+seconds(1));
                    a.cashier();
                }
                else
                {
                    system("clear");
                    cout<<endl<<"Access Denied"<<endl<<endl;
                    sleep_for(nanoseconds(10));
                    sleep_until(system_clock::now()+seconds(1));            
                }
                break;
            case 2:
                if(a.manager_check())
                {
                    system("clear");
                    cout<<endl<<"Access Granted"<<endl<<endl;
                    sleep_for(nanoseconds(10));
                    sleep_until(system_clock::now()+seconds(1));
                    a.sign_up();    // Access the signup member function of class login
                }
                else
                {
                    system("clear");
                    cout<<endl<<"Access Denied"<<endl<<endl;
                    sleep_for(nanoseconds(10));
                    sleep_until(system_clock::now()+seconds(1));
                }
                break;
            case 3:
                break;
            default:
                system("clear");
                cout<<"You've made a mistake , give it a try again\n"<<endl; 
                main();
        }
    } while(choice!=3);
    return 0;
}