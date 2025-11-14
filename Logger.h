#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
#include <iostream>

class Logger {
public:
    static Logger* GetInstance();
    void ZarejestrujOperacje(const std::string& operacja);
    void WyswietlHistorie() const;

private:
    Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    static Logger* instance;
    std::vector<std::string> historiaOperacji;
};

#endif
