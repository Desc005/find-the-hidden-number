/*
 * Gioco il cui scopo è indovinare il numero generato casualmente dal computer
*/

#include <iostream>
#include <ctime>

#define max 100
using namespace std;

int menu();

string changeName();

int random();

void hint(int num);

void play(string name);

int main() {
    int scelta;
    string name;
    name = changeName();
    do {
        srand((unsigned) time(nullptr));
        scelta = menu();
        switch (scelta) {
            case 1:
                play(name);
                break;
            case 2:
                name = changeName();
                break;
            default:
                if (scelta != 0) {
                    cout << "Questa non è una scelta, riprovare\n";
                }
        }
    } while (scelta != 0);
    cout << "\nHai scelta di uscire\n";
    cout << "Grazie per aver giocato \"find the hidden number\" by Desc005\n";
    system("Pause");
    return 0;
}

/**
 * Funzione per mostrare all'utente tutte le possibili scelte da effettuare
 *
 * @return scelta
 */
int menu() {
    int scelta;
    cout << "*****************************************************\n"
            "*               Find the hidden number              *\n"
            "*****************************************************\n"
            "\n"
            "*****************************************************\n"
            "*                      1) Gioca                     *\n"
            "*                      2) Cambia nome               *\n"
            "*                      0) ======> Esci              *\n"
            "*****************************************************\n"
            "\n"
            "Inserisci una scelta <1, 2 o 0>\t:";
    cin >> scelta;
    return scelta;
}

/**
 * Funzione per inserire in input un numero che verrà confrontato con quello da trovare
 *
 * @param name
 */
void play(string name) {
    int num = random(), insert, tryy = 10;
    bool found = false;
    do {
        if (tryy > 5) {
            cout << "Hai " << tryy << " tentativi, tra " << tryy - 5 << " tentativi puoi chiedere l'aiuto\n\n";
        } else {
            cout << "Hai " << tryy << " tentativi\n\n";
        }
        if (tryy <= 5) {
            cout << "Inserisci un numero <lo 0 ti fornisce un piccolo aiuto>\t:";
            cin >> insert;
            if (insert == 0) {
                cout << "Ecco l'aiuto...\t:";
                hint(num);
            } else {
                tryy--;
            }
        } else {
            cout << "Inserisci un numero\t:";
            cin >> insert;
            tryy--;
        }
        if (insert != 0) {
            if (insert != num) {
                cout << "No, numero sbagliato\n\n";
            } else {
                found = true;
            }
        }
    } while (!found && tryy > 0);
    if (tryy > 0 || found) {
        cout << "Complimenti \"" << name << "\" hai trovato il numero nascosto con " << 10 - tryy << " tentativi\n\n";
    } else {
        cout << "Mi dispiace \"" << name << "\" non hai indovinato il numero nascosto, il numero era \"" << num
             << "\"\n\n";
    }
}

/**
 * Funzione per generare casualmente un numero
 *
 * @return num
 */
int random() {
    int num;
    num = (rand() % max) + 1;
    return num;
}

/**
 * Funzione per fornire un indizio con l'intervallo tra cui si trova il numero generato casualmente
 *
 * @param num
 */
void hint(int num) {
    if (num >= 1 && num <= 10) {
        cout << "Il numero da trova si trova tra 1 e 10\n\n";
    } else if (num >= 11 && num <= 20) {
        cout << "il numero da trovare si trova tra 11 e 20\n\n";
    } else if (num >= 21 && num <= 30) {
        cout << "Il numero da trovare si trova tra 21 e 30\n\n";
    } else if (num >= 31 && num <= 40) {
        cout << "Il numero da trovare si trova tra 31 e 40\n\n";
    } else if (num >= 41 && num <= 50) {
        cout << "Il numero da trovare si trova tra 41 e 50\n\n";
    } else if (num >= 51 && num <= 60) {
        cout << "Il numero da trovare si trova tra 51 e 60\n\n";
    } else if (num >= 61 && num <= 70) {
        cout << "Il numero da trovare si trova tra 61 e 70\n";
    } else if (num >= 71 && num <= 80) {
        cout << "Il numero da trovare si trova tra 71 e 80\n\n";
    } else if (num >= 81 && num <= 90) {
        cout << "Il numero da trovare si trova tra 81 e 90\n\n";
    } else if (num >= 91 && num <= 100) {
        cout << "Il numero da trovare si trova tra 91 e 100\n\n";
    }
}

/**
 * Funzione per permettere all'utente di inserire il proprio nome, contenente anche degli spazi
 *
 * @return name
 */
string changeName() {
    string name;
    cout << "Inserisci il tuo nome\t:";
    fflush(stdin);
    getline(cin, name);
    return name;
}