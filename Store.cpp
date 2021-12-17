#include "Store.h"
#include <iostream>
#include <vector>

Store::Store(std::vector<Item> storeInv)
	: storeInv{ storeInv } {}

std::vector<Item> Store::getStoreInv() const {
	return storeInv;
}

void Store::setStoreInventory(std::vector<Item> newStoreInv) {
	storeInv = newStoreInv;
}

// This function can be called to update the stores inventory by removing a processed orders items from inventory
std::vector<Item> Store::processOrder(const Order order) {
	// Nested for loops are used to check both the order vector and store vector to find any potential matchs in item names
	for (int i = 0; i < order.getOrderList().size(); i++) {
		for (int j = 0; j < storeInv.size(); j++) {
			// If the item names match, the store inventory's number in stock is updated
			if (order.getOrderList()[i].getItemName().compare(storeInv[j].getItemName()) == 0) {
				int newStockNumber = storeInv[j].getNumberInStock() - order.getOrderList()[i].getNumberInStock();
				storeInv[j].setNumberInStock(newStockNumber);
			}
		}
	}
	// This returned storeInv should now have the ordered items deducted from the total inventory
	return storeInv;
}

void printStoreInventory(const Store store) {
	int size = store.getStoreInv().size();
	std::cout << "Store: \n";
	for (int i = 0; i < size; i++) {
		std::cout << store.getStoreInv()[i].getItemName() << " X " << store.getStoreInv()[i].getNumberInStock() << "\n";
	}
}