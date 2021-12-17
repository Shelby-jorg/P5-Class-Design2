#pragma once
#include <string>

class Item {
public:
	Item(std::string itemName, long id, double price, int numberInStock);

	// Getters for each variable data
	std::string getItemName() const;
	long getID() const;
	double getPrice() const;
	int getNumberInStock() const;

	// Setters for each variable
	void setItemName(std::string newItemName);
	void setID(long newID);
	void setPrice(double newPrice);
	void setNumberInStock(int newNumberInStock);

private:
	std::string itemName;
	long id;
	double price;
	int numberInStock;
};

// Print function to present all item data
void printItemData(const Item item);

