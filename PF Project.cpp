#include <iostream>
using namespace std;
// for separation
void separation(){
    cout<<"--------------------------------"<<endl;
}
// customer detail struct
struct customerDetails{
    string customerName;
    int customerID;
    string phoneNumber;
};
// product detail struct
struct productDetails{
    string productName;
    int productQuantity;
    int productPrice;
};
// customer detail
void addCustomerDetails(customerDetails c[],int &Ccount){
    cout<<"enter customer id: ";
    while(!(cin >> c[Ccount].customerID)){  // input validation added
        cout << "Invalid input! Enter numeric customer ID: ";
        cin.clear();
        cin.ignore(1000,'\n');
    }
    cin.ignore();
    
    cout<<"enter customer name: ";
    getline(cin,c[Ccount].customerName);
    
    cout<<"enter customer phone number: ";
    cin>>c[Ccount].phoneNumber;
    Ccount++;
}
// product detail
void addProductDetails(productDetails p[],int &Pcount){
    cin.ignore();
    cout<<"enter product name: ";
    getline(cin,p[Pcount].productName);
    
    cout<<"enter product quantity: ";
    while(!(cin >> p[Pcount].productQuantity) || p[Pcount].productQuantity <= 0){  // input validation added
        cout<<"Invalid quantity! Enter positive number: ";
        cin.clear();
        cin.ignore(1000,'\n');
    }

    cout<<"enter product price: ";
    while(!(cin >> p[Pcount].productPrice) || p[Pcount].productPrice <= 0){  // input validation added
        cout<<"Invalid price! Enter positive number: ";
        cin.clear();
        cin.ignore(1000,'\n');
    }
    Pcount++;
     
}
// billing and redeem points deatail
void addBillingDetails(productDetails p[],int &Pcount){
    // for total bill
    int total = 0;

    // for showing  product details 
    separation();
    cout << "Product Details:" << endl;
    for(int i=0;i<Pcount;i++){
        cout << "Product Name: " << p[i].productName << endl;
        cout << "Quantity: " << p[i].productQuantity << endl;
        cout << "Price: " << p[i].productPrice << endl;
        cout << "Total: " << p[i].productQuantity * p[i].productPrice << endl;
        separation();
        total += p[i].productQuantity * p[i].productPrice;
    }

    int finalBill = total;
    // loyalty points logic
    int loyaltyPoints=(total/500)*100;
    cout<<"your loyalty points are :"<<loyaltyPoints<<endl;
    // redeem logic
    cout<<"do you want to redeem your points?"<<endl;
    string redeemChoice;
    cin>>redeemChoice;
    
    
    if(redeemChoice == "yes" || redeemChoice == "Yes" || redeemChoice == "YES"){
        if(loyaltyPoints < 500 ){
            cout<<"sorry! you don't have enough points to redeem "<<endl;
        }else{
        cout<<"how many points do you want to redeem?"<<endl;
        int redeemPoints;
        cin>>redeemPoints;
        if(redeemPoints > loyaltyPoints){
            cout<<"you cannot redeem more points than you have "<<endl;
        }else{
            int discountPerct = (redeemPoints / 100) * 10;

            if(discountPerct > 100){
                discountPerct = 100;
            }
        
        cout<<"you will get discount of "<<discountPerct<<"%"<<endl;
        int discountAmount =(total/100)*discountPerct;
        int afterDiscount = total - discountAmount;
        separation();
        
           finalBill = afterDiscount;
           
            int remainingPoints =loyaltyPoints - redeemPoints;
            cout<<"your remaining loyalty points are :"<<remainingPoints<<endl;
            
        }
    }
    
}

       // at the end will appear
        cout<<"your total bill is :"<<finalBill<<endl;
        cout<<"thanks for shopping!!"<<endl;
}
int main() {
   int Ccount = 0;
   int Pcount = 0;
   string choice;
   string Pchoice;
   
   customerDetails c[100];
   productDetails p[100];
   
//   for adding more then one customer based on user input
   do{
        Pcount = 0;
        addCustomerDetails( c,Ccount);
        separation();
 
//  for adding more then one product based on user input
   do{
    
       addProductDetails(p,Pcount);
       separation();
       cout<<"do you want to add new product? "<<endl;
       cin>>Pchoice;

    }while(Pchoice == "yes" || Pchoice == "Yes" || Pchoice == "YES");
//  outer do-while loop is continue
      addBillingDetails(p,Pcount);
      cout<<"do you want to add another customer?"<<endl;
      cin>>choice;
   
   
    }while(choice == "yes" || choice == "Yes" || choice == "YES");
    
      separation();
    
    return 0;
}