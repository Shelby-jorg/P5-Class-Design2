#include "Order.h"
#include <vector>
#include <iostream>

Order::Order(std::vector<Item> orderList)
	: orderList{ orderList } {}

std::vector<Item> Order::addToOrder(std::vector<Item> orderList, Item item) {
	orderList.push_back(item);
	return orderList;
}

std::vector<Item> Order::getOrderList() const {
	return orderList;
}

double Order::getOrderTotal(std::vector<Item> orderList) const {
	double orderTotal = 0.0;
	for (int i = 0; i < orderList.size(); i++) {
		orderTotal += (orderList[i].getPrice() * orderList[i].getNumberInStock());
	}
	return orderTotal;
}

void printOrder(const std::vector<Item> orderList) {
	for (int i = 0; i < orderList.size(); i++) {
		std::cout << orderList[i].getNumberInStock() << "  " << orderList[i].getItemName() << "  " << orderList[i].getPrice() << "\n";
	}
}