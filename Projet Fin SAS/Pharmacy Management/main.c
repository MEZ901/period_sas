#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

/*-------------structures section-------------*/

typedef struct{
    int code;
    char name[50];
    int quantity;
    float price;
}Product;

typedef struct{
    char name[50];
    float priceTTC;
    int date[3];
    int time[2];
}Book;

/*-------------global variables section-------------*/

int i;
int counter = 0;
int bookCounter = 0;
Product product[MAX];
Product temp[1];
Book book[MAX];

/*-------------functions section-------------*/

void newProduct();
void displayProducts();
void preSort();
void sortProducts();
void buyProduct();
void search();
void storage();
void deleteProduct();
void registerBook();
void salesStatistics();
float totalPrice();
float averagePrice();
float maxPrice();
float minPrice();

/*-------------the main function-------------*/

int main()
{
    int choice;
    do{

        system("color 30");
        printf("\n\n\n\n\n\n\n \t \t \t \t \t \t--------MENU--------\n");
        printf("\n \t \t \t \t \t \t1. Add new product.");
        printf("\n \t \t \t \t \t \t2. Display products.");
        printf("\n \t \t \t \t \t \t3. Buy product.");
        printf("\n \t \t \t \t \t \t4. Search.");
        printf("\n \t \t \t \t \t \t5. Storage.");
        printf("\n \t \t \t \t \t \t6. Delete.");
        printf("\n \t \t \t \t \t \t7. Register book.");
        printf("\n \t \t \t \t \t \t8. Sales Statistics.");
        printf("\n \t \t \t \t \t \t0. Exist.");
        printf("\n\n \t \t \t \t \t \t---------------------");

        printf("\n\n \t \t \t \t \t \tEnter your choice: "); scanf("%d",&choice);

        switch(choice){
            case 1:
                newProduct();
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tyour changes has been saved successfully\n\n"); sleep(2);
                system("cls");
                break;
            case 2:
                displayProducts();
                preSort();
                break;
            case 3:
                buyProduct();
                break;
            case 4:
                search();
                printf("\n\n \t \t \t \t \t \tPress any key to continue.");
                getch();
                system("cls");
                break;
            case 5:
                storage();
                printf("\n\n \t \t \t \t \t \tPress any key to continue.");
                getch();
                system("cls");
                break;
            case 6:
                deleteProduct();
                break;
            case 7:
                registerBook();
                printf("\n \t \t \t \t \t \tPress any key to continue.");
                getch();
                system("cls");
                break;
            case 8:
                salesStatistics();
                break;
            default:
                if(choice!=0) printf("\n \t \t \t \t \tSomething went wrong. Please try again\n");
                break;
        }

    }while(choice!=0);

    return 0;
}

/*-------------functions-------------*/

void newProduct(){
    system ("cls");
    int n;
    printf("\n\n\n\n\n\n\n");
    do{
        printf(" \t \t \t \t \tHow many products you want to add?\n");
        printf("-> "); scanf("%d", &n);
        if(n<1 || n>100) printf("\t \t \t \t \tSomething went wrong. Please try again\n\n");
    }while(n<1 || n>100);

    for(i=0; i<n; i++){
        printf("\t \t \t \t______________________________________________________________");
        printf("\n\n \t \t \t \tEnter the following informations of the product number %d\n\n", i+1);
        printf(" \t \t \t \tEnter the code of product: "); scanf("%d", &product[counter].code);
        printf(" \t \t \t \tEnter the name of product: "); scanf("%s", &product[counter].name);
        printf(" \t \t \t \tEnter the quantity of product: "); scanf("%d", &product[counter].quantity);
        printf(" \t \t \t \tEnter the price of product: "); scanf("%f", &product[counter].price);
        counter++;
    }
}


void displayProducts(){
    system("cls");
    printf("\n\n\n\n\n\n\t \t \t \t \t \tALL PRODUCTS  \n");
    printf("\t \t-----------------------------------------------------------------------------------\n");
    printf("\t \tSerial Number  |  Name  |  Code  |  Quantity  |    Price    |  Price including TTC \n");
    printf("\t \t-----------------------------------------------------------------------------------\n");
    for(i = 0; i<counter; i++){
    printf("\t \t      %d       |   %s   |   %d   |     %d     |    %.2f dh  |     %.2f dh\n", i+1, product[i].name, product[i].code, product[i].quantity, product[i].price, product[i].price + (product[i].price * 0.15));
    printf("\t \t====================================================================================\n");
    }
}


void preSort(){
    int q;
    printf("\n1. sort product");
    printf("\n2. back to menu\n");
    do{
        printf("-> "); scanf("%d", &q);
        if(q==1){
            sortProducts();
            printf("\n\n \t \t \t \t \t \tPress any key to continue.");
            getch();
            system("cls");
        }else if(q==2){
            system("cls");
            break;
        }else
            printf("\n \t \t \t \t \tSomething went wrong. Please try again\n");
    }while(q!=1 && q!=2);
}


void sortProducts(){
    system("cls");
    int choice;
    int s, j;

    printf("\n\n \t \t \t \t1. sort products in ascending alphabetical order of name.");
    printf("\n \t \t \t \t2. sort products in descending order of price.\n");
    do {
        printf("-> "); scanf("%d", &choice);

        if(choice == 1){
            for(i=0; i<counter; i++){
                for(j=i+1; j<counter; j++){
                    if(strcmp(product[i].name, product[j].name)>0){
                        temp[0] = product[i];
                        product[i] = product[j];
                        product[j] = temp[0];
                    }
                }
            }
            printf("\n\n\n\t \t \t \tsort products in ascending alphabetical order of name  \n");
            printf("\t \t-----------------------------------------------------------------------------------\n");
            printf("\t \tSerial Number  |  Name  |  Code  |  Quantity  |    Price    |  Price including TTC \n");
            printf("\t \t-----------------------------------------------------------------------------------\n");
            for(i = 0; i<counter; i++){
            printf("\t \t      %d       |   %s   |   %d   |     %d     |    %.2f dh  |     %.2f dh\n", i+1, product[i].name, product[i].code, product[i].quantity, product[i].price, product[i].price + (product[i].price * 0.15));
            printf("\t \t===================================================================================\n");
            }
        } else if(choice == 2){
            for(i=0; i<counter; i++){
                for(j=i+1; j<counter; j++){
                    if(product[i].price<product[j].price){
                        temp[0] = product[i];
                        product[i] = product[j];
                        product[j] = temp[0];
                    }
                }
            }
            printf("\n\n\n\t \t \t \tproducts in descending order of price  \n");
            printf("\t \t-----------------------------------------------------------------------------------\n");
            printf("\t \tSerial Number  |  Name  |  Code  |  Quantity  |    Price    |  Price including TTC \n");
            printf("\t \t-----------------------------------------------------------------------------------\n");
            for(i = 0; i<counter; i++){
            printf("\t \t      %d       |   %s   |   %d   |     %d     |    %.2f dh  |     %.2f dh\n", i+1, product[i].name, product[i].code, product[i].quantity, product[i].price, product[i].price + (product[i].price * 0.15));
            printf("\t \t===================================================================================\n");
            }
        } else printf("\t \t \t \t \tSomething went wrong. Please try again\n");
    } while(choice!=1 && choice!=2);
}


void buyProduct(){
    int c, b;
    int t=0;
    system("cls");
    printf("\n\n\n \t \t \t \t \tenter the code of product: "); scanf("%d", &c);
    for(i=0; i<counter; i++){
        if(product[i].code == c){
            printf("\n \t \t \t \tname: %s  | price including TTC: %.2f  | quantity: %d\n", product[i].name, product[i].price + (product[i].price * 0.15), product[i].quantity);
            t=1;
            break;
        }
    }
    if(t==1){
        printf("\n \t \t \t \tenter the new quantity: "); scanf("%d", &b);
        product[i].quantity = b;
        printf("\n \t \t \t \tenter the current date of selling:\n");
        printf(" \t \t \t \tthe day: "); scanf("%d", &book[bookCounter].date[0]);
        printf(" \t \t \t \tthe mounth: "); scanf("%d", &book[bookCounter].date[1]);
        printf(" \t \t \t \tthe year: "); scanf("%d", &book[bookCounter].date[2]);
        printf("\n  \t \t \t \tnow enter the current time of selling:\n");
        printf(" \t \t \t \tthe hour: "); scanf("%d", &book[bookCounter].time[0]);
        printf(" \t \t \t \tthe minute: "); scanf("%d", &book[bookCounter].time[1]);

        strcpy(book[bookCounter].name, product[i].name);
        book[bookCounter].priceTTC = product[i].price + (product[i].price * 0.15);
        bookCounter++;
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tyour changes has been saved successfully\n\n"); sleep(2);
        system("cls");
    }else{
        printf("\n \t \t \t \t \tthe code doesn't match any product.\n");
        printf("\n \t \t \t \t \t \tPress any key to continue.");
        getch();
        system("cls");

    }
}


void search(){
    system("cls");
    int w, s, t = 0;
    printf("\n\n\n\n\n\n\n\n\n\n\n \t \t \t \t \t \t1. search by code\n");
    printf(" \t \t \t \t \t \t2. search by quantity\n\n");
    do{
        printf("-> "); scanf("%d", &w);
        if(w!=1 && w!=2) printf("\t \t \t \t \tSomething went wrong. Please try again\n");
    }while(w!=1 && w!=2);

    if(w==1){
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n \t \t \t \t \t \tenter the code: "); scanf("%d", &s);
        for(i=0; i<counter; i++){
            if(s == product[i].code){
                printf("\n \t name:   %s   | code:   %d   | quantity:   %d     | price:   %.2f dh  | Price including TTC:   %.2f dh\n", product[i].name, product[i].code, product[i].quantity, product[i].price, product[i].price + (product[i].price * 0.15));
                t = 1;
            }
        }
        if(t == 0) printf("\n \t \t \t \t \tthe code doesn't match any product.");
    }else{
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n \t \t \t \t \t \tenter the quantity: "); scanf("%d", &s);
        for(i=0; i<counter; i++){
            if(s == product[i].quantity)
                printf("\n \t name:   %s   | code:   %d   | quantity:   %d     | price:   %.2f dh  | Price including TTC:   %.2f dh\n", product[i].name, product[i].code, product[i].quantity, product[i].price, product[i].price + (product[i].price * 0.15));
        }
    }
}


void storage(){
    system("cls");
    int t=0;
    for(i=0; i<counter; i++){
        if(product[i].quantity<3){
            printf("\n\n \t \t \t \t \tthe products whose quantity is less than 3:\n");
            printf("\n \t name:   %s   | code:   %d   | quantity:   %d     | price:   %.2f dh  | Price including TTC:   %.2f dh\n", product[i].name, product[i].code, product[i].quantity, product[i].price, product[i].price + (product[i].price * 0.15));
            t=1;
        }
    }
    if(t==0) printf("\n\n \t \t \t \tthere's no products that whose quantity is less than 3");
}


void deleteProduct(){
    system("cls");
    int d, j, t = 0;
    char c;
    printf("\n\n \t \t \t \tenter the code of product that you want to delete: "); scanf("%d", &d);
    for(i=0; i<counter; i++){
        if(product[i].code == d){
            printf("\n \t name:   %s   | code:   %d   | quantity:   %d     | price:   %.2f dh  | Price including TTC:   %.2f dh\n", product[i].name, product[i].code, product[i].quantity, product[i].price, product[i].price + (product[i].price * 0.15));
            printf("\t \t \t \tare you sure you want to delete this product (y/n): "); scanf("%s", &c);
            if(c == 'y' || c == 'Y'){
                for(j=i; j<counter; j++){
                    product[j] = product[j+1];
                }
                counter--;
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tyour changes has been saved successfully\n\n"); sleep(2);
                system("cls");
            } else if(c == 'n' || c == 'N'){
                printf("\n\n \t \t \t \t \t \tPress any key to continue.");
                getch();
                system("cls");
            }
            t = 1;
        }
    }
    if(t == 0){
        printf("\n \t \t \t \t \tthe code doesn't match any product\n");
        printf("\n\n \t \t \t \t \t \tPress any key to continue.");
        getch();
        system("cls");
    }
}


void registerBook(){
    system("cls");
    printf("\n\n\n\t \t \t \t \t \t product purchased  \n");
    printf("\t \t \t \t--------------------------------------------------------\n");
    printf("\t \t \t \t   Name    |  Price including TTC  |    date    |    time   \n");
    printf("\t \t \t \t--------------------------------------------------------\n");
    for(i=0; i<bookCounter; i++){
        printf("\t \t \t \t    %s    |       %.2f       |    %d/%d/%d    |    %d:%d    \n", book[i].name, book[i].priceTTC, book[i].date[0], book[i].date[1], book[i].date[2], book[i].time[0], book[i].time[1]);
        printf("\t \t \t \t========================================================\n");
    }
}


void salesStatistics(){
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n \t \t \t \tthe total prices of products sold in the current day is %.2f dh\n", totalPrice());
    printf(" \t \t \t \tthe average price of products sold on the current day is %.2f dh\n", averagePrice());
    printf(" \t \t \t \tthe Max price of products sold on the current day is %.2f dh\n", maxPrice());
    printf(" \t \t \t \tthe Min price of products sold in the current day is %.2f dh\n", minPrice());
    printf("\n\n\t \t \t \t \t \tPress any key to continue.");
    getch();
    system("cls");
}


float totalPrice(){
    float sum;
    for(i=0; i<bookCounter; i++){
        sum = sum + book[i].priceTTC;
    }
    return sum;
}


float averagePrice(){
    float av;
    av = totalPrice()/(bookCounter);
    return av;
}


float maxPrice(){
    float m = 0;
    for(i=0; i<bookCounter; i++){
        if(m<book[i].priceTTC)
            m = book[i].priceTTC;
    }
    return m;
}

float minPrice(){
    float n = 0;
    for(i=0; i<bookCounter; i++){
        if(n>book[i].priceTTC || n==0)
            n = book[i].priceTTC;
    }
    return n;
}
