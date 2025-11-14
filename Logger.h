#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Logger {
public:
    static Logger* GetInstance();
    void Rejestr(const string& operacja);
    void Historia() const;

private:
    Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    static Logger* instance;
    vector<string> historiaOperacji;
};

#endif
