#pragma once
#include "Item.h"
#include <vector>

class Order {
public:
	Order(std::vector<Item> orderList);
	std::vector<Item> addToOrder(std::vector<Item> orderList, Item item);
	std::vector<Item> getOrderList() const;
	double getOrderTotal(std::vector<Item> orderList) const;

private:
	std::vector<Item> orderList;

};

void printOrder(const std::vector<Item> orderList);