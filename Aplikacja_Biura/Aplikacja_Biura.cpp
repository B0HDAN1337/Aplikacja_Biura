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

class po_zalogowaniu : public Zarzadanie_uzytkownikami {
public:
    dane_uzytkownika aktualny_uzytkownik;
    void funkcje(string nazwa) {
        string nazwa1 = nazwa;
        cout << "Co chcesz zrobic teraz?" << endl;
        cout << "1 - Sprawdz dostepne oferty!" << endl;
        cout << "2 - Sprawdz moj profil!" << endl;
        cout << "3 - Wyloguj sie!" << endl;

        int liczba;
        cin >> liczba;

        switch (liczba)
        {
        case 1:
            wyswietlOferty();
            break;
        case 2:
            sprawdzProfil();
            break;
        case 3:
            cout << "Wylogowano" << endl;
            break;
        default:
            cout << "Nie ma takiej opcji! Spróbuj jeszcze raz!" << endl;
            break;
        }
    }


    void wyswietlOferty() {
        int kraj;
        do {
            cout << "Wybierz kraj!" << endl;
            cout << "1 - Grecja" << endl;
            cout << "2 - Hiszpania" << endl;
            cout << "3 - Turcja" << endl;
            cout << "4 - Włochy" << endl;
            cout << "5 - Egipt" << endl;
            cout << "0 - Wyjdz z listy panstw" << endl;


            cin >> kraj;

            string kraj1;
            switch (kraj) {
            case 1:
                kraj1 = "Grecja";
                cout << "Wybrany kraj to: " << kraj1 << endl;
                break;
            case 2:
                kraj1 = "Hiszpania";
                cout << "Wybrany kraj to: " << kraj1 << endl;
                break;
            case 3:
                kraj1 = "Turcja";
                cout << "Wybrany kraj to: " << kraj1 << endl;
                break;
            case 4:
                kraj1 = "Włochy";
                cout << "Wybrany kraj to: " << kraj1 << endl;
                break;
            case 5:
                kraj1 = "Egipt";
                cout << "Wybrany kraj to: " << kraj1 << endl;
                break;
            case 0:
                break;
            default:
                cout << "Nie ma takiej opcji!" << endl;
                break;
            }

            switch (kraj) {
            case 1:
                wyswietlOfertyGrecja();
                break;
            case 2:
                wyswietlOfertyHiszpania();
                break;
            case 3:
                wyswietlOfertyTurcja();
                break;
            case 4:
                wyswietlOfertyWlochy();
                break;
            case 5:
                wyswietlOfertyEgipt();
                break;
            default:
                return;
            }
        } while (kraj != 0);
    }

    void wyswietlOfertyGrecja() {
        cout << " " << endl;
        cout << "-----------------Oferta 1----------------" << endl;
        cout << "Kraj: Grecja" << endl;
        cout << "Liczba dni: 14" << endl;
        cout << "Liczba osób: 2" << endl;
        cout << "Cena: 3200 zł" << endl;
        cout << "Data: 13.07.2024 - 27.07.2024" << endl;
        cout << "Miejscowość: Ateny" << endl;
        cout << " " << endl;
        cout << "-----------------Oferta 2----------------" << endl;
        cout << "Kraj: Grecja" << endl;
        cout << "Liczba dni: 10" << endl;
        cout << "Liczba osób: 2" << endl;
        cout << "Cena: 2900 zł" << endl;
        cout << "Data: 15.08.2024 - 25.08.2024" << endl;
        cout << "Miejscowość: Kreta" << endl;
        cout << " " << endl;
        cout << "-----------------Oferta 3----------------" << endl;
        cout << "Kraj: Grecja" << endl;
        cout << "Liczba dni: 7" << endl;
        cout << "Liczba osób: 2" << endl;
        cout << "Cena: 2300 zł" << endl;
        cout << "Data: 06.06.2024 - 13.06.2024" << endl;
        cout << "Miejscowość: Saloniki" << endl;
    }
    void wyswietlOfertyHiszpania() {
        cout << " " << endl;
        cout << "-----------------Oferta 1----------------" << endl;
        cout << "Kraj: Hiszpania" << endl;
        cout << "Liczba dni: 14" << endl;
        cout << "Liczba osób: 2" << endl;
        cout << "Cena: 3200 zł" << endl;
        cout << "Data: 13.07.2024 - 27.07.2024" << endl;
        cout << "Miejscowość: Madrid" << endl;
        cout << " " << endl;
        cout << "-----------------Oferta 2----------------" << endl;
        cout << "Kraj: Hiszpania" << endl;
        cout << "Liczba dni: 10" << endl;
        cout << "Liczba osób: 2" << endl;
        cout << "Cena: 2900 zł" << endl;
        cout << "Data: 15.08.2024 - 25.08.2024" << endl;
        cout << "Miejscowość: Barcelona" << endl;
        cout << " " << endl;
        cout << "-----------------Oferta 3----------------" << endl;
        cout << "Kraj: Hiszpania" << endl;
        cout << "Liczba dni: 7" << endl;
        cout << "Liczba osób: 2" << endl;
        cout << "Cena: 2300 zł" << endl;
        cout << "Data: 06.06.2024 - 13.06.2024" << endl;
        cout << "Miejscowość: Vigo" << endl;
    }
    void wyswietlOfertyTurcja() {
        cout << " " << endl;
        cout << "-----------------Oferta 1----------------" << endl;
        cout << "Kraj: Turcja" << endl;
        cout << "Liczba dni: 14" << endl;
        cout << "Liczba osób: 2" << endl;
        cout << "Cena: 3200 zł" << endl;
        cout << "Data: 13.07.2024 - 27.07.2024" << endl;
        cout << "Miejscowość: Istambuł" << endl;
        cout << " " << endl;
        cout << "-----------------Oferta 2----------------" << endl;
        cout << "Kraj: Turcja" << endl;
        cout << "Liczba dni: 10" << endl;
        cout << "Liczba osób: 2" << endl;
        cout << "Cena: 2900 zł" << endl;
        cout << "Data: 15.08.2024 - 25.08.2024" << endl;
        cout << "Miejscowość: Antalya" << endl;
        cout << " " << endl;
        cout << "-----------------Oferta 3----------------" << endl;
        cout << "Kraj: Turcja" << endl;
        cout << "Liczba dni: 7" << endl;
        cout << "Liczba osób: 2" << endl;
        cout << "Cena: 2300 zł" << endl;
        cout << "Data: 06.06.2024 - 13.06.2024" << endl;
        cout << "Miejscowość: Bodrum" << endl;
    }
    void wyswietlOfertyWlochy() {
        cout << " " << endl;
        cout << "-----------------Oferta 1----------------" << endl;
        cout << "Kraj: Wlochy" << endl;
        cout << "Liczba dni: 14" << endl;
        cout << "Liczba osób: 2" << endl;
        cout << "Cena: 3200 zł" << endl;
        cout << "Data: 13.07.2024 - 27.07.2024" << endl;
        cout << "Miejscowość: Rzym" << endl;
        cout << " " << endl;
        cout << "-----------------Oferta 2----------------" << endl;
        cout << "Kraj: Wlochy" << endl;
        cout << "Liczba dni: 10" << endl;
        cout << "Liczba osób: 2" << endl;
        cout << "Cena: 2900 zł" << endl;
        cout << "Data: 15.08.2024 - 25.08.2024" << endl;
        cout << "Miejscowość: Florencja" << endl;
        cout << " " << endl;
        cout << "-----------------Oferta 3----------------" << endl;
        cout << "Kraj: Wlochy" << endl;
        cout << "Liczba dni: 7" << endl;
        cout << "Liczba osób: 2" << endl;
        cout << "Cena: 2300 zł" << endl;
        cout << "Data: 06.06.2024 - 13.06.2024" << endl;
        cout << "Miejscowość: Wenecja" << endl;
    }
    void wyswietlOfertyEgipt() {
        cout << " " << endl;
        cout << "-----------------Oferta 1----------------" << endl;
        cout << "Kraj: Egipt" << endl;
        cout << "Liczba dni: 14" << endl;
        cout << "Liczba osób: 2" << endl;
        cout << "Cena: 3200 zł" << endl;
        cout << "Data: 13.07.2024 - 27.07.2024" << endl;
        cout << "Miejscowość: Kair" << endl;
        cout << " " << endl;
        cout << "-----------------Oferta 2----------------" << endl;
        cout << "Kraj: Egipt" << endl;
        cout << "Liczba dni: 10" << endl;
        cout << "Liczba osób: 2" << endl;
        cout << "Cena: 2900 zł" << endl;
        cout << "Data: 15.08.2024 - 25.08.2024" << endl;
        cout << "Miejscowość: Hurghada" << endl;
        cout << " " << endl;
        cout << "-----------------Oferta 3----------------" << endl;
        cout << "Kraj: Egipt" << endl;
        cout << "Liczba dni: 7" << endl;
        cout << "Liczba osób: 2" << endl;
        cout << "Cena: 2300 zł" << endl;
        cout << "Data: 06.06.2024 - 13.06.2024" << endl;
        cout << "Miejscowość: Luxor" << endl;
    }
    void sprawdzProfil() {

    }
};