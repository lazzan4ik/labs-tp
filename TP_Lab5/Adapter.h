#pragma once

#include <iostream>

class OldLogger {
public:
    void logMessage(const std::string& message) {
        std::cout << "[OLD] " << message << std::endl;
    }
};


class Logger {
public:
    virtual void log(const std::string& message) = 0;
    virtual ~Logger() {}
};


class NewLogger : public Logger {
public:
    void log(const std::string& message) override {
        std::cout << "[NEW] " << message << std::endl;
    }
};


class OldLoggerAdapter : public Logger {
private:
    OldLogger* oldLogger;
public:
    OldLoggerAdapter(OldLogger* oldLogger) : oldLogger(oldLogger) {}

    void log(const std::string& message) override {
        oldLogger->logMessage(message);
    }
};