#pragma once
#include "Item.h"
#include "Order.h"
#include <vector>

class Store {
public:
	Store(std::vector<Item> storeInv);
	std::vector<Item> getStoreInv() const;
	void setStoreInventory(std::vector<Item> newStoreInv);
	std::vector<Item> processOrder(const Order order);
private:
	std::vector<Item> storeInv;
};

void printStoreInventory(const Store store);