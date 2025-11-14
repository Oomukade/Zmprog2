#include "Logger.h"
using namespace std;
Logger* Logger::instance = nullptr;

Logger* Logger::GetInstance() {
    if (instance == nullptr) {
        instance = new Logger();
    }
    return instance;
}

void Logger::Rejestr(const string& operacja) {
    historiaOperacji.push_back(operacja);
}

void Logger::Historia() const {
    cout << "Historia operacji:\n";
    for (const auto& operacja : historiaOperacji) {
        cout << operacja <<endl;
    }
}