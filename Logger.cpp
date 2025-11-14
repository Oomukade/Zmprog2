#include "Logger.h"

Logger* Logger::instance = nullptr;

Logger* Logger::GetInstance() {
    if (instance == nullptr) {
        instance = new Logger();
    }
    return instance;
}

void Logger::ZarejestrujOperacje(const std::string& operacja) {
    historiaOperacji.push_back(operacja);
}

void Logger::WyswietlHistorie() const {
    std::cout << "Historia operacji:\n";
    for (const auto& operacja : historiaOperacji) {
        std::cout << operacja << std::endl;
    }
}
