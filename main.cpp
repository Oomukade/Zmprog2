// Grupa: WEL24MX1S4  
// Imie nazwisko: Jakub Witek
// Data wykonania: 14. Listopada. 2025
// Program napisano w Visual Studio Coe
// Adres IP: 10.202.131.82

#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include "Logger.h"

using namespace std;

class Kalkulator {
public:
    virtual  float Dzialanie(float tmp1, float tmp2) = 0;
    virtual ~Kalkulator() = default;
};

class KalkDod : public Kalkulator {
public:
    float Dzialanie(float tmp1, float tmp2) override {
        return tmp1 + tmp2;
    }
};

class KalkOde : public Kalkulator {
public:
    float Dzialanie(float tmp1, float tmp2) override {
        return tmp1 - tmp2;
    }
};

class KalkMno : public Kalkulator {
public:
    float Dzialanie(float tmp1, float tmp2) override {
        return tmp1 * tmp2;
    }
};

class KalkDzi : public Kalkulator {
public:
    float Dzialanie(float tmp1, float tmp2) override {
        int tmp3;
        if (tmp1 == 0 || tmp2 == 0) {
            cerr << "Zly wybor - podano wartosc 0" << endl;
            return tmp3 = 0;
        }
        return tmp1 / tmp2;
    }
};

class Kreator {
public:
    unique_ptr<Kalkulator> StworzKalkulator(char TypKalk) {
        switch (TypKalk) {
        case 'd': return make_unique<KalkDod>();
        case 'D': return make_unique<KalkDod>();
        case 'o': return make_unique<KalkOde>();
        case 'O': return make_unique<KalkOde>();
        case 'm': return make_unique<KalkMno>();
        case 'M': return make_unique<KalkMno>();
        case 'i': return make_unique<KalkDzi>();
        case 'I': return make_unique<KalkDzi>();
        default:
            cerr << "Zly wybor" << endl;
            return nullptr;
        }
    }
};

int main() {
    Kreator kreator;
    char TypKalk;

    cout << "Wybor operacji: \n//d// - operacja dodawania (+)\n//o// - operacja odejmowania (-)\n//m// - operacja mnozenia (*)\n//i// - operacja dzielenia (:)\nTwoj wybor: ";
    cin >> TypKalk;

    auto kalkulator = kreator.StworzKalkulator(TypKalk);
    if (kalkulator == nullptr) {
        cerr << "Brak wyboru opcji z listy - wybrano inna litere lub cyfre lub inny znak";
        return 0;
    }

    float tmp1, tmp2;
    string input;

    cout << "Liczba 1: ";
    while (true) {
        cin >> ws;
        getline(cin, input);
        stringstream ss(input);
        if (ss >> tmp1 && ss.eof()) {
            break;
        }
        else {
            cout << "Wybrano nie liczbe. Sprobuj ponownie: ";
        }
    }

    cout << "Liczba 2: ";
    while (true) {
        cin >> ws;
        getline(cin, input);
        stringstream ss(input);
        if (ss >> tmp2 && ss.eof()) {
            break;
        }
        else {
            cout << "Wybrano nie liczbe. Sprobuj ponownie: ";
        }
    }

    float wynik = kalkulator->Dzialanie(tmp1, tmp2);
    cout << "Wynik: " << wynik << endl;

    // #########################################################################################
    // Zapetlenie zadania -> Mozna zrobic po break case albo petla okreslona ilosc razy i ctrl C
    // #########################################################################################
    // While odpowiedz == Y czyli wpisanie czegokolwiek innego niż Y przelamie petle
    // #########################################################################################

    double skala = 0.01;

    Logger::GetInstance()->Rejestr(to_string(tmp1*skala/skala) + " " + TypKalk + " " + to_string(tmp2*skala/skala) + " = " + to_string(wynik));
    
    char odpowiedz;
    cout << "Zapytanie o kontynuacje (Wybory: //Y// - Potwierdzenie): ";
    cin >> odpowiedz;
    while (odpowiedz == 'Y' || odpowiedz == 'y') {
        cout << "Wybor operacji: ";
        cin >> TypKalk;

        kalkulator = kreator.StworzKalkulator(TypKalk);
        if (kalkulator == nullptr) {
            cerr << "Brak wyboru opcji z listy - wybrano inna litere lub cyfre lub inny znak" << endl;
            return 0;
        }

        cout << "Liczba 1: ";
        cin >> tmp1;
        cout << "Liczba 2: ";
        cin >> tmp2;

        wynik = kalkulator->Dzialanie(tmp1, tmp2);
        cout << "Wynik: " << wynik << endl;

        Logger::GetInstance()->Rejestr(to_string(tmp1*skala/skala) + " " + TypKalk + " " + to_string(tmp2*skala/skala) + " = " + to_string(wynik));

        cout << "Zapytanie o kontynuacje (Wybory: //Y// - Potwierdzenie): ";
        cin >> odpowiedz;
    }

    Logger::GetInstance()->Historia();

    return 0;
}
