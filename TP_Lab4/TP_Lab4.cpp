// TP_Lab4.cpp: определяет точку входа для приложения.
//

#include "Iterator.h"
#include "RespChain.h"
#include "Strategy.h"

using namespace std;

int main()
{
	//strategy
	Order* order = new Order(8.9, 139);
	ShippingStrategy* shipStrat1 = new SberShipping;
	order->setShippingStrategy(shipStrat1);
	std::cout << "Sber Shipping: " << order->calculateTotalCost() << std::endl;
	ShippingStrategy* shipStrat2 = new YandexShipping;
	order->setShippingStrategy(shipStrat2);
	std::cout << "Yandex Shipping: " << order->calculateTotalCost() << std::endl;
	ShippingStrategy* shipStrat3 = new MoscowShipping;
	order->setShippingStrategy(shipStrat3);
	std::cout << "Moscow Shipping: " << order->calculateTotalCost() << std::endl;
	delete order;

	//Responsibility chain
	DiscountHandler* discountChain = new AmountDiscountHandler(new RegularDiscountHandler());
	DiscountHandler* discountChain2 = new AmountDiscountHandler();

	double price1 = 1200;
	double price2 = 500;
	std::cout << "Regular Client (1200):    " << discountChain->applyDiscount(price1) << std::endl;
	std::cout << "Regular Client (500):   " << discountChain->applyDiscount(price2) << std::endl;
	std::cout << "Non-Regular Client (1200):    " << discountChain2->applyDiscount(price1) << std::endl;
	std::cout << "Non-Regular Client (500):   " << discountChain2->applyDiscount(price2) << std::endl;
	delete discountChain;
	delete discountChain2;

	//Iterator
	int* data = new int[10];
	ConcreteIterator<int>* s_data = new ConcreteIterator(data, 10);
	while (s_data->hasNext()) {
		std::cout << s_data->next() << std::endl;
	}
}
