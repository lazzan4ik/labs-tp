#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <string>
#include <vector>

// Singleton

class Configuration {
private:
    static Configuration* instance;
    std::string URL;
    int port;

    Configuration() : URL("default_url.com"), port(1111) {} // Приватный конструктор

public:
    static Configuration* getInstance() {
        if (!instance) {
            instance = new Configuration();
        }
        return instance;
    }

    void setURL(const std::string& url) {
        URL = url;
    }

    std::string getURL() const {
        return URL;
    }

    void setPort(int p) {
        port = p;
    }

    int getPort() const {
        return port;
    }
};

Configuration* Configuration::instance = nullptr; // Инициализация статического члена

#endif // !SINGLETON_H
