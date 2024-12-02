#ifndef BUILDER_H
#define BUILDER_H

#include <iostream>
#include <string>

class Computer {
public:
    void setCPU(const std::string& cpu) {
        this->cpu = cpu;
    }

    void setRAM(const std::string& ram) {
        this->ram = ram;
    }

    void setGraphicsCard(const std::string& graphicsCard) {
        this->graphicsCard = graphicsCard;
    }

    void setConfig(const std::string& config) {
        this->config = config;
    }

    void display() const {
        std::cout << "Computer Configuration: " << config << std::endl;
        std::cout << "  CPU: " << cpu << std::endl;
        std::cout << "  RAM: " << ram << std::endl;
        std::cout << "  Graphics Card: " << graphicsCard << std::endl;
    }
private:
    std::string cpu;
    std::string ram;
    std::string graphicsCard;
    std::string config;
};


class ComputerBuilder {
public:
    virtual void buildCPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildGraphicsCard() = 0;
    virtual void buildConfig() = 0;
    virtual Computer* getResult() = 0;
    virtual ~ComputerBuilder() {}
};

class GamingComputerBuilder : public ComputerBuilder {
private:
    Computer* computer;

public:
    GamingComputerBuilder() : computer(new Computer()) {}

    void buildCPU() override {
        computer->setCPU("AMD Ryzen 7 9700X");
    }

    void buildRAM() override {
        computer->setRAM("32 GB");
    }

    void buildGraphicsCard() override {
        computer->setGraphicsCard("Geforce RTX 4070 Super");
    }

    void buildConfig() override {
        computer->setConfig("Gaming");
    }

    Computer* getResult() override {
        return computer;
    }

    ~GamingComputerBuilder() {
        delete computer;
    }
};


class Director {
public:
    Director(ComputerBuilder* builder) {
        this->builder = builder;
    }

    void constructComputer() {
        builder->buildConfig();
        builder->buildCPU();
        builder->buildGraphicsCard();
        builder->buildRAM();
    }

private:
    ComputerBuilder* builder;
};

#endif // !BUILDER_H
