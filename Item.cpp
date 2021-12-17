#include "Item.h"
#include <iostream>

Item::Item(std::string itemName, long id, double price, int numberInStock)
	: itemName{ itemName }, id{ id }, price{ price }, numberInStock{ numberInStock } {}

// Getters for each variable data
std::string Item::getItemName() const {
	return itemName;
}
long Item::getID() const {
	return id;
}
double Item::getPrice() const {
	return price;
}
int Item::getNumberInStock() const {
	return numberInStock;
}

// Setters for each variable
void Item::setItemName(std::string newItemName) {
	itemName = newItemName;
}
void Item::setID(long newID) {
	id = newID;
}
void Item::setPrice(double newPrice) {
	price = newPrice;
}
void Item::setNumberInStock(int newNumberInStock) {
	numberInStock = newNumberInStock;
}

// Print function to present all item data
void printItemData(const Item item) {
	std::cout << "Item name: " << item.getItemName() << "\n" <<
		"ID: " << item.getID() << "\n" <<
		"Price: " << item.getPrice() << "\n" <<
		"Number in stock: " << item.getNumberInStock() << "\n" << "\n";
}
