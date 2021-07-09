#include<iostream>
#include<string>
#include<iomanip>
#include<stdio.h>
using namespace std;

class Product{
	private:
		string name;
		string category;
		double price;
		int quantity;
	public:
		Product(){
			name="";
			category="";
			price=0.0;
			quantity=0;
		}
		Product(string N,string C,double P){
			name=N;
			category=C;
			price=P;
		}
		//mutators
		void setQuantity(int q){
			quantity=q;
		}
		//accessors
		string getName(){
			return name;
		}
		string getCategory(){
			return category;
		}
		double getPrice(){
			return price;
		}
		double getQuantity(){
			return quantity;
		}
};//end of Product class


class Name{
	private:
		string firstName;
		string lastName;
	public:
		Name(string fN,string lN){
			firstName=fN;
			lastName=lN;
		}
		string getFullName(){
			return(firstName+lastName);
		}
};//end of Name class

class Customer {
	private:
		string address;
		int numProduct;
	public:
		Product *product;//aggregration of class product
		int arrayN=4;
		//p=new Product[4];
		Name n;//composition of class Name
		double totalPrice;
		
		Customer(string firstname,string lastname,string AD):n(firstname,lastname){
			address=AD;
			numProduct=0;
			product=new Product[arrayN]; // dynamic array allocation 
		}
		void buy(Product p, int num){
				if (numProduct<arrayN){
					p.setQuantity(num);
					product[numProduct++]=p;
				}
				else 
					cout << "Sorry!! You already reached the maximum number of products purchased." << endl;
		}
		void print(){
			cout<<"Name: "<<n.getFullName()<<endl;
			cout<<"Address: "<<address<<endl;
			cout<<"Number of product purchased: "<<numProduct<<endl;
		  cout <<left<< setw(12) << "No";

			cout <<left<< setw(15) << "Product Name";
            cout <<left<< setw(12) << "Category";
            cout <<left<< setw(12) << "Quantity";
            cout <<left<< setw(12) << "Price(RM)";
            cout <<left<< setw(12) << "Amount(RM)"<<endl;
            
            for(int i=0;i<numProduct;i++){
                cout<< setw(12) << (i+1);
            	cout<< setw(15) << product[i].getName();
                cout<<left<< setw(15) << product[i].getCategory();
                cout<< setw(12) << product[i].getQuantity();
                cout<< setw(12) <<fixed<<setprecision(2)<< product[i].getPrice();
                cout<< setw(12) <<fixed<<setprecision(2)<< product[i].getQuantity()*product[i].getPrice();
                totalPrice+=product[i].getQuantity()*product[i].getPrice();
                cout<<endl;
			}//end of for loop
			cout<<endl<<endl<<"Total Price : "<<totalPrice<<" (RM)";
			
		}
};//endd of Customer class


int main () {
	Customer cust("Amir", " Jalil", "Masai, Johor");
	Product p1("Jacob", "Biscuit", 14.8);
	Product p2("Twister", "Drink", 7.5);	
	Product p3("Ayamas", "Nugget", 18.4);
	Product p4("Oreo", "Biscuit", 3.8);
	cust.buy(p4, 5);
	cust.buy(p2, 4);
	cust.buy(p3, 2);
	cust.buy(p1, 3);
	cust.print();
	return 0;
}
