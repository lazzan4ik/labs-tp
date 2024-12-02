// TBS_lab2.cpp: определяет точку входа для приложения.
//

#include "Archer.h"
#include "Fort.h"
#include "MobileHouse.h"
#include <iostream>

int main()
{
	Archer J;
	Archer G(2,5);
	Fort Boyard(10,6);
	MobileHouse Tesla;
	G.attack(J);
	Boyard.attack(G);
	Tesla.move(1, 2);
	Tesla.move(2, 2); // not correct tesla >3
	J.move(-3, 5); //not correct j >7
	J.move(-3, 4); 
	std::cout << "J ARCHER STATS:" << std::endl;
	std::cout << J.getHp() << std::endl;
	std::cout << J.getName() << std::endl;
	std::cout << J.getId() << std::endl;
	std::cout << J.getX() << std::endl;
	std::cout << J.getY() << std::endl;

	std::cout << "G ARCHER STATS" << std::endl;
	std::cout << G.getHp() << std::endl;
	std::cout << G.getName() << std::endl;
	std::cout << G.getId() << std::endl;
	std::cout << G.getX() << std::endl;
	std::cout << G.getY() << std::endl;
	Archer P;
	for (int i = 0; i < 10; ++i) {
		J.attack(P);
	}
	std::cout << "After 10 arch. attacks" << std::endl;
	std::cout << P.getHp() << std::endl;
	std::cout << P.isAlive() << std::endl;

	std::cout << "TESLA MOBILEHOME STATS" << std::endl;
	std::cout << Tesla.getId() << std::endl;
	std::cout << Tesla.getName() << std::endl;
	std::cout << Tesla.getX() << std::endl;
	std::cout << Tesla.getY() << std::endl;

	std::cout << "BOYARD FORT STATS" << std::endl;
	std::cout << Boyard.getId() << std::endl;
	std::cout << Boyard.getName() << std::endl;
	std::cout << Boyard.getDamage() << std::endl;
	std::cout << Boyard.getX() << std::endl;
	std::cout << Boyard.getY() << std::endl;
	
}
