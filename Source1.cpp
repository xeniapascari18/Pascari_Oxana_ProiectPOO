#include <iostream>
using namespace std;

class Parfum {
public:
    // Atribute normale
    string nume;
    double pret;
    int cantitate_ml;

    // Atribute constante
    static const int cod_produs = 1001;

    // Atribute statice
    static int numar_total_vandute;

    // Constructori
    Parfum() : nume("Necunoscut"), pret(0.0), cantitate_ml(0) {}
    Parfum(string nume, double pret, int cantitate_ml)
        : nume(nume), pret(pret), cantitate_ml(cantitate_ml) {}
    Parfum(string nume, double pret)
        : nume(nume), pret(pret), cantitate_ml(50) {}
    Parfum(string nume)
        : nume(nume), pret(50.0), cantitate_ml(50) {}

    // Functie statica pentru calcul
    static double calculareProfit(int cantitate, double pret) {
        return cantitate * pret;
    }
};

// Initializare atribut statice
int Parfum::numar_total_vandute = 0;

class Oja {
public:
    // Atribute normale
    string culoare;
    double pret;
    int cantitate_ml;

    // Atribute constante
    static const int cod_produs = 1002;

    // Atribute statice
    static int numar_total_vandute;

    // Constructori
    Oja() : culoare("Rosu"), pret(10.0), cantitate_ml(15) {}
    Oja(string culoare, double pret, int cantitate_ml)
        : culoare(culoare), pret(pret), cantitate_ml(cantitate_ml) {}
    Oja(tring culoare, double pret)
        : culoare(culoare), pret(pret), cantitate_ml(15) {}
    Oja(string culoare)
        : culoare(culoare), pret(10.0), cantitate_ml(15) {}

    // Functie statica pentru procesare
    static double calculareReducere(double pret, double procent) {
        return pret - (pret * procent / 100);
    }
};

// Initializare atribut static
int Oja::numar_total_vandute = 0;

class Ruj {
public:
    // Atribute normale
    string culoare;
    double pret;
    int cantitate_g;

    // Atribute constante
    static const int cod_produs = 1003;

    // Atribute statice
    static int numar_total_vandute;

    // Constructori
    Ruj() : culoare("Roz"), pret(15.0), cantitate_g(5) {}
    Ruj(string culoare, double pret, int cantitate_g)
        : culoare(culoare), pret(pret), cantitate_g(cantitate_g) {}
    Ruj(string culoare, double pret)
        : culoare(culoare), pret(pret), cantitate_g(5) {}
    Ruj(string culoare)
        : culoare(culoare), pret(15.0), cantitate_g(5) {}

    // Functie statica pentru procesare
    static bool verificaDisponibilitate(int cantitate) {
        return cantitate > 0;
    }
};

// Initializare atribut statice
int Ruj::numar_total_vandute = 0;

int main() {
    // Testarea constructorilor
    Parfum parfum1;
    Parfum parfum2("Parfum A", 75.0, 100);
    Parfum parfum3("Parfum B", 60.0);
    Parfum parfum4("Parfum C");

    Oja oja1;
    Oja oja2("Albastru", 12.0, 20);
    Oja oja3("Verde", 8.0);
    Oja oja4("Negru");

    Ruj ruj1;
    Ruj ruj2("Rosu", 20.0, 10);
    Ruj ruj3("Maro", 18.0);
    Ruj ruj4("Roz");

    // Afisare atributele obiectelor create
    std::cout << "Parfum 1: " << parfum1.nume << ", Pret: " << parfum1.pret << ", Cantitate: " << parfum1.cantitate_ml << " ml" << std::endl;
    std::cout << "Parfum 2: " << parfum2.nume << ", Pret: " << parfum2.pret << ", Cantitate: " << parfum2.cantitate_ml << " ml" << std::endl;
    std::cout << "Parfum 3: " << parfum3.nume << ", Pret: " << parfum3.pret << ", Cantitate: " << parfum3.cantitate_ml << " ml" << std::endl;

    std::cout << "Oja 1: Culoare " << oja1.culoare << ", Pret: " << oja1.pret << ", Cantitate: " << oja1.cantitate_ml << " ml" << std::endl;
    std::cout << "Oja 2: Culoare " << oja2.culoare << ", Pret: " << oja2.pret << ", Cantitate: " << oja2.cantitate_ml << " ml" << std::endl;
    std::cout << "Oja 3: Culoare " << oja3.culoare << ", Pret: " << oja3.pret << ", Cantitate: " << oja3.cantitate_ml << " ml" << std::endl;

    std::cout << "Ruj 1: Culoare " << ruj1.culoare << ", Pret: " << ruj1.pret << ", Cantitate: " << ruj1.cantitate_g << " g" << std::endl;
    std::cout << "Ruj 2: Culoare " << ruj2.culoare << ", Pret: " << ruj2.pret << ", Cantitate: " << ruj2.cantitate_g << " g" << std::endl;
    std::cout << "Ruj 3: Culoare " << ruj3.culoare << ", Pret: " << ruj3.pret << ", Cantitate: " << ruj3.cantitate_g << " g" << std::endl;
}
