#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

struct dane_uzytkownika {
    string nazwa;
    string haslo;
    string email;
};

class Zarzadanie_uzytkownikami {
public:

    void rejestracja(const string& nazwa, const string& haslo, const string& email) {
        dane_uzytkownika nowy_uzytkownik;
        nowy_uzytkownik.nazwa = nazwa;
        nowy_uzytkownik.haslo = haslo;
        nowy_uzytkownik.email = email;
        wszystkie_konta.push_back(nowy_uzytkownik);
        zapisywanie_danych();
        cout << "Sukces! Nowy zarejestrowany uzytkownik to: " << nazwa << endl;
    }

    bool logowanie(const string& nazwa, const string& haslo) {
        for (const auto& uzytkownik : wszystkie_konta) {
            if (uzytkownik.nazwa == nazwa && uzytkownik.haslo == haslo) {
                cout << "Sukces! Jesteś zalogowany jako: " << nazwa << endl;
                return true;
            }
        }
        cout << "Wprowadzono niepoprawne dane. Spróbuj jeszcze raz!" << endl;
        return false;
    }

private:
    vector<dane_uzytkownika> wszystkie_konta;

    void zapisywanie_danych() {
        ofstream file("uzytkownicy.txt");
        if (file.is_open()) {
            for (const auto& uzytkownik : wszystkie_konta) {
                file << uzytkownik.nazwa << " " << uzytkownik.haslo << " " << uzytkownik.email << endl;
            }
            file.close();
        }
    }

    void pobieranie_danych() {
        ifstream file("uzytkownicy.txt");
        if (file.is_open()) {
            dane_uzytkownika uzytkownik;
            while (file >> uzytkownik.nazwa >> uzytkownik.haslo >> uzytkownik.email) {
                wszystkie_konta.push_back(uzytkownik);
            }
            file.close();
        }
    }

public:
    Zarzadanie_uzytkownikami() {
        pobieranie_danych();
    }
};