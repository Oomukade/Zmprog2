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
            if (tmp2 == 0) {
                cerr << "Błąd: Dzielenie przez zero!" << endl;
                return 0;
            }
            return tmp1 / tmp2;
        }
};

class Kreator {
    public:
        unique_ptr<Kalkulator> StworzKalkulator(char TypKalk) {
            switch (TypKalk) {
                case 'd': return make_unique<KalkDod>();
                case 'o': return make_unique<KalkOde>();
                case 'm': return make_unique<KalkMno>();
                case 'i': return make_unique<KalkDzi>();
                default:
                    cerr << "Zły wybór" << endl;
                    return nullptr;
            }
        }
};

int main() {
    Kreator kreator;
    char TypKalk;

    cout << "Wybór operacji: \n//d// - operacja dodawania (+)\n//o// - operacja odejmowania (-)\n//m// - operacja mnożenia (*)\n//i// - operacja dzielenia (:)\nTwój wybór: ";
    cin >> TypKalk;

    auto kalkulator = kreator.StworzKalkulator(TypKalk);
    if (kalkulator == nullptr) {
        cerr << "Brak wyboru opcji z listy - wybrano inną literę lub cyferkę" << endl;
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
        } else {
            cout << "Wybrano nie liczbę. Spróbuj ponownie: ";
        }
    }

    cout << "Liczba 2: ";
    while (true) {
        cin >> ws;
        getline(cin, input);
        stringstream ss(input);
        if (ss >> tmp2 && ss.eof()) {
            break;
        } else {
            cout << "Wybrano nie liczbę. Spróbuj ponownie: ";
        }
    }

    float wynik = kalkulator->Dzialanie(tmp1, tmp2);
    cout << "Wynik: " << wynik << endl;


    Logger::GetInstance()->ZarejestrujOperacje(to_string(tmp1) + " " + TypKalk + " " + to_string(tmp2) + " = " + to_string(wynik));
    char odpowiedz;

    cout << "Czy chcesz wykonać kolejną operację? (t/n): ";
    cin >> odpowiedz;
    while (odpowiedz == 't' || odpowiedz == 'T') {
        cout << "Wybór operacji: ";
        cin >> TypKalk;

        kalkulator = kreator.StworzKalkulator(TypKalk);
        if (kalkulator == nullptr) {
            cerr << "Brak wyboru opcji z listy - wybrano inną literę lub cyferkę" << endl;
            return 0;
        }

        cout << "Liczba 1: ";
        cin >> tmp1;
        cout << "Liczba 2: ";
        cin >> tmp2;

        wynik = kalkulator->Dzialanie(tmp1, tmp2);
        cout << "Wynik: " << wynik << endl;

        Logger::GetInstance()->ZarejestrujOperacje(to_string(tmp1) + " " + TypKalk + " " + to_string(tmp2) + " = " + to_string(wynik));

        cout << "Czy chcesz wykonać kolejną operację? (t/n): ";
        cin >> odpowiedz;
    }

    Logger::GetInstance()->WyswietlHistorie();

    return 0;
}
