#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//  Create Product
void createProduct(int NoOfProducts, string ilist[], int iprice[]) {
    //string ilist[50];
    //int itemprice[50];
    string itemname;
    int price;
    for (int i = 0; i < NoOfProducts; i++) {
        cout << "Enter Item name and price: ";
        cin >> itemname;
        cin >> price;
        ilist[i] = itemname;
        iprice[i] = price;
    }

}

// Preview Products in Supermarket
void PreviewProducts(string itemlist[], int itemprice[], int arraySize) {
    cout << " Here is your product list: " << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << i + 1 << "- " << itemlist[i] << "\t" << " Price: " << itemprice[i] << endl;

    }
}

// Edit Products Names
void EditProductsName(string itemlist[]) {
    int editedproduct;
    string newProduct;
    cout << "Which Product would you like to edit? ";
    cin >> editedproduct;
    cout << "Enter the new product: ";
    cin >> newProduct;
    itemlist[editedproduct - 1] = newProduct;
}

// Edit Product Prices
void EditProductPrice(int itemprice[]) {
    int editedproduct, newPrice;
    cout << "Enter the product that you will edit its price: ";
    cin >> editedproduct;
    cout << "Enter the new product price: ";
    cin >> newPrice;
    itemprice[editedproduct - 1] = newPrice;
}

// Save data to file
void save_data(string itemList[], int priceList[], int arraysize) {
    ofstream writer("Products.txt");
    for (int i = 0; i < arraysize; i++) {
        writer << itemList[i] << " " << priceList[i] << endl;
    }
    writer << "/////" << endl;
    writer.close();

}

//                                                              Customer functions

// Add Items to cart
void addtocart(string cartlist[], int cartpricelist[], int quantityofitem[], string itemList[], int  iprice[], int NoOfProductsInCart) {
    cout << "Enter the product's Number that you would like to add\n";
    for (int i = 0; i < NoOfProductsInCart; i++) {
        int wantedproduct;
        cin >> wantedproduct;
        cartlist[i] = itemList[wantedproduct - 1];
        cartpricelist[i] = iprice[wantedproduct - 1];
        cout << "Enter the quantity of " << cartlist[i] << "\t";
        cin >> quantityofitem[i];
        cout << "Enter the next Product: ";
    }
}

// Preview items in cart
void previewcart(string itemsincart[], int quantityofitem[], int NoOfProductsInCart, int cartpricelist[]) {
    cout << " Here is your products in cart:\n ";
    for (int i = 0; i < NoOfProductsInCart; i++)
    {
        cout << i + 1 << "- " << itemsincart[i] << "\t" << "Quantity = " << "  " << quantityofitem[i] << "\t" << "Price= " << cartpricelist[i] << endl;

    }
}

// Calculate Prices in cart
void calc(int cartpricelist[], int quantityofitem[], int  NoOfProductsInCart) {
    int totalprice = 0;
    for (int i = 0; i < NoOfProductsInCart; i++) {
        totalprice = totalprice + (cartpricelist[i] * quantityofitem[i]);

    }
    cout << "Total price = " << totalprice;
}

// Search for items in cart
void searchInCart(string cart[], int NoOfProductsInCart) {
    string product;
    cout << "What Product are you searching for?";
    cin >> product;
    for (int i = 0; i < NoOfProductsInCart; i++) {
        if (product == cart[i]) {
            cout << product << " is available" << endl;
        }
    }
}

// Load data from file
void load_data(string itemList[], int priceList[], int arraycapacity, int& arraySize) {
    ifstream reader("Products.txt");
    int i = 0;
    while ((!(reader.eof())) && i < arraycapacity) {
        reader >> itemList[i] >> priceList[i];
        if (itemList[i] == "/////") {
            itemList[i] = " ";
            priceList[i] = 0;
            return;
        }
        arraySize++;
        i++;
    }
}

//                                                          Main Function
int main()
{
    bool flag = true;
    const int ARRAY_SIZE = 50;
    const int CartSize = 50;
    string itemlist[ARRAY_SIZE], UserName;
    int itemprice[ARRAY_SIZE], quantityofitem[CartSize], cartpricelist[CartSize], priceList[CartSize], password, check;
    string itemname, newProduct;
    int NoOfProducts, NoOfProductsInCart, userinput, editedproduct, newPrice, price = 0;
    string cartlist[CartSize];

    cout << "\t \t \t \t \t Welcome to the Codymanga Supermarket \t \t \t \t \n";

    // Check if Owner or Customer Interface
    cout << " Enter 1 if you are an owner or Enter 2 if you are a customer: ";
    cin >> check;

    // Owner's Interface
    if (check == 1) {
        cout << " Enter username and password\n";
        cin >> UserName >> password;
        while ((UserName != " Admin " && password != 12345678)) {

            cout << " Try again\n";
            cout << " Enter username and password\n";
            cin >> UserName >> password;
        }
        while (flag) {
            cout << "\n What would you like to do?" << endl << " 1. Create List of Products \n 2. Edit List of Products \n 3. Edit Products Prices \n 4. Preview List of Products \n 5. Switch To User \n 0. Exit Program \n";
            cin >> userinput;
            // Creating Products
            if (userinput == 1) {
                cout << "Please enter the number of products: ";
                cin >> NoOfProducts;
                createProduct(NoOfProducts, itemlist, itemprice);
            }
            // Editing Products
            else if (userinput == 2) {
                PreviewProducts(itemlist, itemprice, NoOfProducts);
                EditProductsName(itemlist);
            }
            // Editing Prices
            else if (userinput == 3) {
                PreviewProducts(itemlist, itemprice, NoOfProducts);
                EditProductPrice(itemprice);
            }
            // Previewing Products
            else if (userinput == 4) {
                PreviewProducts(itemlist, itemprice, NoOfProducts);
            }

            // Customer's interface (switching from owner to customer)
            else if (userinput == 5) {
                char customerchoice;
                cout << "Enter A to add to cart\n";
                cout << "Enter B to preview the cart\n";
                cout << "Enter C to view all products\n";
                cout << "Enter D to calculate total price\n";
                cout << "Enter E to Search for a product\n";
                cout << "Enter N to exit the program\n";
                cin >> customerchoice;
                if (customerchoice == 'A' || customerchoice == 'a') {
                    cout << "Enter number of product you would like to add \n";
                    cin >> NoOfProductsInCart;
                    cout << "These are the items available:\n";
                    PreviewProducts(itemlist, itemprice, NoOfProducts);
                    addtocart(cartlist, cartpricelist, quantityofitem, itemlist, itemprice, NoOfProductsInCart);
                }
                else if (customerchoice == 'B' || customerchoice == 'b') {
                    previewcart(itemlist, quantityofitem, NoOfProductsInCart, cartpricelist);
                }
                else if (customerchoice == 'C' || customerchoice == 'c') {
                    PreviewProducts(itemlist, itemprice, NoOfProducts);
                }
                else if (customerchoice == 'D' || customerchoice == 'd') {
                    calc(cartpricelist, quantityofitem, NoOfProductsInCart);
                }
                else if (customerchoice == 'E' || customerchoice == 'e') {
                    searchInCart(cartlist, NoOfProductsInCart);
                }
                else if (customerchoice == 'N') {
                    flag = false;
                }

            }
            else if (userinput == 0) {
                flag = false;
            }
            else
                cout << "Please enter a valid number: ";
        }
        save_data(itemlist, itemprice, ARRAY_SIZE);
    }
    else if (check == 2) {
        while (check == 2) {
            char customerchoice;
            cout << "Enter A to add to cart\n";
            cout << "Enter B to preview the cart\n";
            cout << "Enter C to view all products\n";
            cout << "Enter D to calculate total price\n";
            cout << "Enter E to Search for a product\n";
            cout << "Enter N to exit the program\n";
            cin >> customerchoice;
            if (customerchoice == 'A' || customerchoice == 'a') {
                cout << "Enter number of product you would like to add \n";
                cin >> NoOfProductsInCart;
                cout << "These are the items available:\n";
                PreviewProducts(itemlist, itemprice, NoOfProducts);
                addtocart(cartlist, cartpricelist, quantityofitem, itemlist, itemprice, NoOfProductsInCart);
            }
            else if (customerchoice == 'B' || customerchoice == 'b') {
                previewcart(itemlist, quantityofitem, NoOfProductsInCart, cartpricelist);
            }
            else if (customerchoice == 'C' || customerchoice == 'c') {
                PreviewProducts(itemlist, itemprice, NoOfProducts);
            }
            else if (customerchoice == 'D' || customerchoice == 'd') {
                calc(cartpricelist, quantityofitem, NoOfProductsInCart);
            }
            else if (customerchoice == 'E' || customerchoice == 'e') {
                searchInCart(cartlist, NoOfProductsInCart);
            }
            else if (customerchoice == 'N') {
                flag = false;
            }
        }
    }
}