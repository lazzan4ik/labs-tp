#ifndef ABSTRACT_H
#define ABSTRACT_H

#include <iostream>

class StringInstrument {
public:
    virtual void play() = 0;
    virtual ~StringInstrument() {}
};

class WindInstrument {
public:
    virtual void play() = 0;
    virtual ~WindInstrument() {}
};


class Guitar : public StringInstrument {
public:
    void play() override {
        std::cout << "Playing the Guitar." << std::endl;
    }
};

class Violin : public StringInstrument {
public:
    void play() override {
        std::cout << "Playing the Violin." << std::endl;
    }
};

class ElectroGuitar : public StringInstrument {
public:
    void play() override {
        std::cout << "Playing the Electroguitar" << std::endl;
    }
};


class Flute : public WindInstrument {
public:
    void play() override {
        std::cout << "Playing the Flute." << std::endl;
    }
};

class Trumpet : public WindInstrument {
public:
    void play() override {
        std::cout << "Playing the Trumpet." << std::endl;
    }
};

class ElectroHorn : public WindInstrument {
public:
    void play() override {
        std::cout << "Did not imagine. So here is electrohorn." << std::endl;
    }
};



class InstrumentFactory {
public:
    virtual StringInstrument* createStringInstrument() = 0;
    virtual WindInstrument* createWindInstrument() = 0;
    virtual ~InstrumentFactory() {}
};


class ClassicalInstrumentFactory : public InstrumentFactory {
public:
    StringInstrument* createStringInstrument() override {
        return new Violin();
    }

    WindInstrument* createWindInstrument() override {
        return new Flute();
    }
};

class ModernInstrumentFactory : public InstrumentFactory {
public:
    StringInstrument* createStringInstrument() override {
        return new Guitar();
    }

    WindInstrument* createWindInstrument() override {
        return new Trumpet();
    }
};

class ElectronicalInstrumentFactory : public InstrumentFactory {
public:
    StringInstrument* createStringInstrument() override {
        return new ElectroGuitar();
    }
    WindInstrument* createWindInstrument() override {
        return new ElectroHorn();
    }
};

#endif // !ABSTRACT_H
