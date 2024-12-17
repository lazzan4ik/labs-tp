#pragma once

#include <iostream>

class TV {
protected:
    int lastChannel = 1;
public:
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void tuneChannel(int channel) { lastChannel = channel; }
    virtual ~TV() {}
};

class SamsungTV : public TV {
private:
    bool turnedOn = false;
public:
    void on() override {
        std::string sussyBaka = !turnedOn ? "SamsungTV is now turned on" : "It's already turned on";
        turnedOn = true;
        std::cout << sussyBaka << std::endl;
    }
    void off() override {
        std::string sussyBaka = turnedOn ? "SamsungTV is now off" : "It's already turned off";
        turnedOn = false;
        std::cout << sussyBaka << std::endl;
    }
    void tuneChannel(int channel) override {
        lastChannel = channel;
        std::cout << "SamsungTV tuned to channel " << channel << std::endl;
    }
};

class SonyTV : public TV {
private:
    bool turnedOn = false;
public:
    void on() override {
        std::string sussyBaka = !turnedOn ? "SonyTV is turned on" : "It's already turned on";
        turnedOn = true;
        std::cout << sussyBaka << std::endl;
    }
    void off() override {
        std::string sussyBaka = turnedOn ? "SonyTV is now off" : "It's already turned off";
        turnedOn = false;
        std::cout << sussyBaka << std::endl;
    }
    void tuneChannel(int channel) override {
        lastChannel = channel;
        std::cout << "SonyTV tuned to channel " << channel << std::endl;
    }
};

class RemoteControl {
protected:
    TV* tv;
public:
    RemoteControl(TV* tv) : tv(tv) {}
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void setChannel(int channel) = 0;
    virtual ~RemoteControl() {}
};

class BasicRemoteControl : public RemoteControl {
public:
    BasicRemoteControl(TV* tv) : RemoteControl(tv) {}
    void turnOn() override {
        tv->on();
    }
    void turnOff() override {
        tv->off();
    }
    void setChannel(int channel) {
        std::cout << "This function is not available on this pult" << std::endl;
    }
};

class AdvancedRemoteControl : public RemoteControl {
public:
    AdvancedRemoteControl(TV* tv) : RemoteControl(tv) {}
    void turnOn() override {
        tv->on();
    }
    void turnOff() override {
        tv->off();
    }
    void setChannel(int channel) override{
        tv->tuneChannel(channel);
    }
};
