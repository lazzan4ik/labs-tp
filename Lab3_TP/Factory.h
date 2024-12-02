#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>

class Transport {
public:
	virtual void TransportType() = 0;
	~Transport() = default;
};

class Truck : public Transport {
public:
	void TransportType() override {
		std::cout << "Truck" << std::endl;
	}
};

class Train : public Transport {
public:
	void TransportType() override {
		std::cout << "Train" << std::endl;
	}
};

class Logistics {
public:
	virtual Transport* createTransport() = 0;
	virtual ~Logistics() {};

	void plannedTransport() {
		Transport* transport = createTransport();
		transport->TransportType();
	}
};

class TruckLgs : public Logistics {
public:
	Transport* createTransport() override { 
		return new Truck(); 
	}
};

class TrainLgs : public Logistics {
public:
	Transport* createTransport() override { 
		return new Train(); 
	}
};

#endif // !FACTORY_H
