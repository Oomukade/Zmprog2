// Grupa: WEL24MX1S4  
// Imie nazwisko: Jakub Witek
// Data wykonania: 14. Listopada. 2025
// Program napisano w Visual Studio Coe
// Adres IP: 10.202.131.82

#include <iostream>
#include <memory>
#include <string>
#include <sstream>

using namespace std;

// ##########################
// Wzorzec z Refactoring Guru
// ##########################

// class Product {
//     public:
//      virtual ~Product() {}
//      virtual std::string Operation() const = 0;
//    };       

class Kalkulator {
    public:
    virtual  float Dzialanie(float tmp1, float tmp2) = 0;
    virtual ~Kalkulator() = default;
};

class KalkDod : public Kalkulator {
    public:
        float Dzialanie(float tmp1, float tmp2) override{
            return tmp1 + tmp2;
        }
};

class KalkOde : public Kalkulator {
    public:
        float Dzialanie(float tmp1, float tmp2) override{
            return tmp1 - tmp2;
        }
};

class KalkMno : public Kalkulator {
    public:
        float Dzialanie(float tmp1, float tmp2) override{
            return tmp1 * tmp2;
        }
};

class KalkDzi : public Kalkulator {
    public:
        float Dzialanie(float tmp1, float tmp2) override{
            int tmp3;
            if(tmp1==0||tmp2==0){
                return tmp3=0;
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
                    cerr << "ZlyWybor";
                    return nullptr;
        }
        // #################################################################################################################
        // Obejscie - wykorzystuje unikalne_ptr i make_unique w celu braku potrzeby usuwania kreatora wybranego kalkulatora 
        // #################################################################################################################
    }
};

int main() {
    Kreator kreator;
    char TypKalk;
    cout << "Wybor operacji: \n//d// - operacja dodawania (+)\n//o// - operacja odejmowania (-)\n//m// - operacja mnozenia (*)\n//i// - operacja dzielenia (:)\nTwoj wybor: ";
    cin >> TypKalk;

    auto kalkulator = kreator.StworzKalkulator(TypKalk);
    if (kalkulator == nullptr) {
        cerr<<"Brak wyboru opcji z listy - wybrano inna litere lub cyfre lub inny znak";
        return 0;
    }

    float tmp1, tmp2;
    string input;

   cout << "Liczba 1 : ";
   while (true) {
       cin >> ws; 
       getline(cin, input);
       stringstream ss(input);
       if (ss >> tmp1 && ss.eof()) {
           break;
       } else {
           cout << "Wybrano nie liczbe. Sprobuj ponownie: ";
       }
   }

   cout << "Liczba 2 : ";
   while (true) {
       cin >> ws;
       getline(cin, input);
       stringstream ss(input);
       if (ss >> tmp2 && ss.eof()) {
           break;
       } else {
           cout << "Wybrano nie liczbe. Sprobuj ponownie: ";
       }
   }

    float wynik = kalkulator->Dzialanie(tmp1, tmp2);
    cout << "Wynik: " << wynik <<endl;
    return 0;
}