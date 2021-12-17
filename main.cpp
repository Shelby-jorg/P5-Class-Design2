#include "ClassDesignA.h"
#include "ClassDesignB.h"
#include "Item.h"
#include "Store.h"
#include "Order.h"
#include <string>
#include <iostream>
#include <vector>

// This variable holds the input URL until it is passed into the constructor
std::string inputURL;

int main() {
	
	// Below is Section A of this assignment
	// Take in the user URL, and store it to a variable
	std::cout << "Please enter a URL: ";
	std::cin >> inputURL;

	// Test of the printURL function, that passes in the URL from the consol input
	printURL(inputURL);
	
	//This is a test from the previous assignment
	//Constructor that passes in the users entered url
	ClassDesignA designA(inputURL);

	// Print the URL in it's seperate parts
	std::cout << "The initial URL was: " + designA.getURL() + "\n";
	std::cout << "The scheme of this URL is: " + designA.getScheme() + "\n";
	std::cout << "The authority of this URL is: " + designA.getAuthority() + "\n";
	std::cout << "The path of this URL is: " + designA.getPath() + "\n";

	
	// Below is Section B of this assignment
	// Constructor used to create test image data
	ClassDesignB testB1("Image1", "PNG", "12/12/2020", 43.5, "Author01", 400, 600, 12, 300, 1000, true);
	ClassDesignB testB2("Image2", "JPG", "01/01/1990", 27.3, "Author02", 300, 400, 2, 600, 1500, false);
	ClassDesignB testB3("Image3", "GIF", "06/08/1999", 115.7, "Author03", 800, 1000, 24, 500, 2500, true);
	ClassDesignB testB4("Image4", "TXT", "07/12/2021", 215.8, "Author04", 400, 500, 16, 400, 500, false);

	printImageData(testB1);
	printImageData(testB2);
	printImageData(testB3);
	printImageData(testB4);
	
	// Below is Section C of this assignment
	// Test to create Items, then put them into a vector that will be used by the store
	Item item1("Book", 001, 9.99, 15);
	Item item2("Pen", 002, 3.99, 25);
	Item item3("Paper", 003, 0.99, 14);
	Item item4("Binder", 004, 2.99, 18);
	std::vector<Item> storeInv = { item1, item2, item3, item4 };

	// Store test, that takes in item vector, and prints them out
	Store store1(storeInv);
	printStoreInventory(storeInv);

	// Order test, to create items, place in a vector, then pass them onto the order
	Item orderItem1("Book", 001, 9.99, 1);
	Item orderItem2("Pen", 002, 3.99, 3);
	Item orderItem3("Binder", 004, 2.99, 1);
	std::vector<Item> firstOrder = { orderItem1, orderItem2, orderItem3 };
	Order order1(firstOrder);

	printOrder(firstOrder);
	std::cout << "Total: " << order1.getOrderTotal(firstOrder) << "\n";

	// This test if an item can be added to the order
	Item orderItem4("Paper", 003, 0.99, 2);
	firstOrder = order1.addToOrder(firstOrder, orderItem4);
	printOrder(firstOrder);
	std::cout << "Total: " << order1.getOrderTotal(firstOrder) << "\n";

	// This tests if process order will update the store inventory count
	storeInv = store1.processOrder(firstOrder);
	printStoreInventory(storeInv);
}
