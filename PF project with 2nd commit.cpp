#include <iostream>
using namespace std;
void addCustomerDetails(int customerID[],string customerName[],string phoneNumber[],int &customerCount);
void separation();
void addProductDetails(string productName[],int productQuantity[],int productPrice[],int &productCount);
// for customer details
void addCustomerDetails(int customerID[],string customerName[],string phoneNumber[],int &customerCount){
    
    cout<<"Enter customer ID: ";
    cin>>customerID[customerCount];
    cout<<"Enter customer name: ";
    cin.ignore();
    getline(cin,customerName[customerCount]);
    cout<<"Enter Phone Number: ";
    cin>>phoneNumber[customerCount];
    customerCount++;
    
}
void separation(){
    cout<<"---------------------------"<<endl;
}
// for product deatails
void addProductDetails(string productName[],int productQuantity[],int productPrice[],int &productCount){
    
    cout<<"Enter Product Name: ";
    cin.ignore();
    getline(cin,productName[productCount]);
    cout<<"Enter Product Quantity: ";
    cin>>productQuantity[productCount];
    cout<<"Enter Product Price: ";
    cin>>productPrice[productCount];

    productCount++;
}
void addBillingDetail(int productQuantity[],int productPrice[],int &productCount){
    int grandTotal = 0;
    for(int i= 0;i<productCount;i++){
    int total=productQuantity[i]*productPrice[i];
    grandTotal = total + grandTotal;
    }
    // total bill and loyalty points
    cout<<"Total Bill: "<<grandTotal<<endl;
    int loyaltyPoints =(grandTotal/500)*100;
    cout<<"loyalty points you get: "<<loyaltyPoints<<endl;
    separation();
    // if user want to redeem his points
    cout<<"Do you want to redeem your points?"<<endl;
    string redeemChoice;
    cin>>redeemChoice;
    
    // if points are less then 500 or starndard points
    if(redeemChoice == "yes" || redeemChoice == "Yes" ){
        if( loyaltyPoints < 500 ){
            cout<<"you don't have enough loyalty points for getting discount!!"<<endl;
            cout<<"your total points are "<<loyaltyPoints<<endl;
            cout<<"your total bill is "<<grandTotal<<endl;
            
        }else{
        int pointsToRedeem;
        cout<<"For how much point do you want to get discount?"<<endl;
        cin>>pointsToRedeem;
        
        int discountPerct= (pointsToRedeem/100)*10;
        cout<<"you will get discount of "<<discountPerct<<"%"<<endl;
        int discountAmount =(grandTotal/100)*discountPerct;
        int afterDiscount = grandTotal - discountAmount;
        cout<<"your total bill after discount is "<<afterDiscount<<endl;
        
        int remainingPoints=loyaltyPoints - pointsToRedeem;
        cout<<"your remaining points are "<<remainingPoints<<endl;
        
        } 
        }
    }



int main() {
    // customer details
    int customerCount= 0;
    int customerID[100];
    string customerName[100];
    string phoneNumber[100];
    // product deatails
     int productCount= 0;
    string productName[100];
    int productQuantity[100];
    int productPrice[100];
    
    string choice;
    string productChoice;
do{
//   custome details
    addCustomerDetails(customerID,customerName,phoneNumber,customerCount);
    
    // for separating one part from another
    separation();
    
    // product deatails
    do{
    addProductDetails(productName,productQuantity,productPrice,productCount);
    cout<<"do you want to add another product?"<<endl;
    cin>>productChoice;
    }while(productChoice == "yes" || productChoice == "Yes");
    
// for separating one part from another
    separation();
    addBillingDetail(productQuantity,productPrice,productCount);
    
    cout<<"Do you want to add another customer and product details?"<<endl;
    cin>>choice;
}while(choice == "yes" || choice == "Yes");

   cout<<"Thanks for your shopping!!!"<<endl;
    return 0;
}