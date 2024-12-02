// Lab3_TP.cpp: определяет точку входа для приложения.
//

#include "Singleton.h"
#include "Factory.h"
#include "Abstract.h"
#include "Builder.h"

int main() {
    //singleton
    Configuration* config1 = Configuration::getInstance();
    std::cout << "Config 1 URL: " << config1->getURL() << std::endl;
    std::cout << "Config 1 Port: " << config1->getPort() << std::endl;
    config1->setURL("github.com");
    config1->setPort(5432);

    Configuration* config2 = Configuration::getInstance();
    std::cout << "Config 2 URL: " << config2->getURL() << std::endl; // Вывод: github.com
    std::cout << "Config 2 Port: " << config2->getPort() << std::endl;         // Вывод: 5432

    //factory
    Logistics* Trains = new TrainLgs();
    Trains->plannedTransport();
    delete Trains;

    Logistics* Trucks = new TruckLgs();
    Trucks->plannedTransport();
    delete Trucks;

    //abstract
    InstrumentFactory* Classicals = new ClassicalInstrumentFactory();
    StringInstrument* violin = Classicals->createStringInstrument();
    violin->play();
    WindInstrument* flute = Classicals->createWindInstrument();
    flute->play();

    InstrumentFactory* Modernic = new ModernInstrumentFactory();
    StringInstrument* guitar = Modernic->createStringInstrument();
    guitar->play();
    WindInstrument* trumpet = Modernic->createWindInstrument();
    trumpet->play();

    InstrumentFactory* Electro = new ElectronicalInstrumentFactory();
    StringInstrument* elguitar = Electro->createStringInstrument();
    elguitar->play();
    WindInstrument* elhorn = Electro->createWindInstrument();
    elhorn->play();

    delete flute;
    delete violin;
    delete Classicals;
    delete guitar;
    delete trumpet;
    delete Modernic;
    delete elguitar;
    delete elhorn;
    delete Electro;

    //builder
    ComputerBuilder* builder = new GamingComputerBuilder();
    Director* director = new Director(builder);
    director->constructComputer();
    Computer* gamingComputer = builder->getResult();

    gamingComputer->display();
    delete builder;
}
