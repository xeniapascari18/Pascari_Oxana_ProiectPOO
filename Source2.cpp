#include <iostream>

using namespace std;

class Parfum {
private:
    string nume;
    double pret;
    int cantitate_ml;

public:
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

    // Constructor de copiere
    Parfum(const Parfum& other) {
        nume = other.nume;
        pret = other.pret;
        cantitate_ml = other.cantitate_ml;
    }

    // Destructor
    ~Parfum() {
        // Nu este nevoie s? eliber?m memorie alocat? în HEAP, deoarece nu am alocat memorie dinamic?
    }

    // Metode de acces (get-eri si set-eri)
    string getNume() const { return nume; }
    void setNume(const string& n) { nume = n; }

    double getPret() const { return pret; }
    void setPret(double p) { pret = p; }

    int getCantitateMl() const { return cantitate_ml; }
    void setCantitateMl(int cant) { cantitate_ml = cant; }

    // Functie statica pentru calcul
    static double calculareProfit(int cantitate, double pret) {
        return cantitate * pret;
    }

    friend double calculeazaReducere(const Parfum& parfum, double procent);
};

// Initializare atribut statice
int Parfum::numar_total_vandute = 0;

double calculeazaReducere(const Parfum& parfum, double procent) {
    return parfum.pret - (parfum.pret * procent / 100);
}

class Oja {
private:
    string culoare;
    double pret;
    int cantitate_ml;

public:
    // Atribute constante
    static const int cod_produs = 1002;

    // Atribute statice
    static int numar_total_vandute;

    // Constructori
    Oja() : culoare("Rosu"), pret(10.0), cantitate_ml(15) {}
    Oja(string culoare, double pret, int cantitate_ml)
        : culoare(culoare), pret(pret), cantitate_ml(cantitate_ml) {}
    Oja(string culoare, double pret)
        : culoare(culoare), pret(pret), cantitate_ml(15) {}
    Oja(string culoare)
        : culoare(culoare), pret(10.0), cantitate_ml(15) {}

    // Constructor de copiere
    Oja(const Oja& other) {
        culoare = other.culoare;
        pret = other.pret;
        cantitate_ml = other.cantitate_ml;
    }

    // Destructor
    ~Oja() {
        // Nu este nevoie s? eliber?m memorie alocat? în HEAP, deoarece nu am alocat memorie dinamic?
    }

    // Metode de acces (get-eri si set-eri)
    string getCuloare() const { return culoare; }
    void setCuloare(const string& c) { culoare = c; }

    double getPret() const { return pret; }
    void setPret(double p) { pret = p; }

    int getCantitateMl() const { return cantitate_ml; }
    void setCantitateMl(int cant) { cantitate_ml = cant; }

    // Functie statica pentru procesare
    static double calculareReducere(double pret, double procent) {
        return pret - (pret * procent / 100);
    }

    friend double calculeazaProfit(const Oja& oja);
};

// Initializare atribut statice
int Oja::numar_total_vandute = 0;

double calculeazaProfit(const Oja& oja) {
    return oja.pret * oja.cantitate_ml;
}

class Ruj {
private:
    string culoare;
    double pret;
    int cantitate_g;

public:
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

    // Constructor de copiere
    Ruj(const Ruj& other) {
        culoare = other.culoare;
        pret = other.pret;
        cantitate_g = other.cantitate_g;
    }

    // Destructor
    ~Ruj() {
        // Nu este nevoie s? eliber?m memorie alocat? în HEAP, deoarece nu am alocat memorie dinamic?
    }

    // Metode de acces (get-eri si set-eri)
    string getCuloare() const { return culoare; }
    void setCuloare(const string& c) { culoare = c; }

    double getPret() const { return pret; }
    void setPret(double p) { pret = p; }

    int getCantitateG() const { return cantitate_g; }
    void setCantitateG(int cant) { cantitate_g = cant; }

    // Functie statica pentru procesare
    static bool verificaDisponibilitate(int cantitate) {
        return cantitate > 0;
    }

    friend bool verificaDisponibilitateRuj(const Ruj& ruj);
};

// Initializare atribut statice
int Ruj::numar_total_vandute = 0;

bool verificaDisponibilitateRuj(const Ruj& ruj) {
    return ruj.cantitate_g > 0;
}

int main() {
    // Testarea constructorilor ?i metodelor
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
    std::cout << "Parfum 1: " << parfum1.getNume() << ", Pret: " << parfum1.getPret() << ", Cantitate: " << parfum1.getCantitateMl() << " ml" << std::endl;
    std::cout << "Parfum 2: " << parfum2.getNume() << ", Pret: " << parfum2.getPret() << ", Cantitate: " << parfum2.getCantitateMl() << " ml" << std::endl;
    std::cout << "Parfum 3: " << parfum3.getNume() << ", Pret: " << parfum3.getPret() << ", Cantitate: " << parfum3.getCantitateMl() << " ml" << std::endl;

    std::cout << "Oja 1: Culoare " << oja1.getCuloare() << ", Pret: " << oja1.getPret() << ", Cantitate: " << oja1.getCantitateMl() << " ml" << std::endl;
    std::cout << "Oja 2: Culoare " << oja2.getCuloare() << ", Pret: " << oja2.getPret() << ", Cantitate: " << oja2.getCantitateMl() << " ml" << std::endl;
    std::cout << "Oja 3: Culoare " << oja3.getCuloare() << ", Pret: " << oja3.getPret() << ", Cantitate: " << oja3.getCantitateMl() << " ml" << std::endl;

    std::cout << "Ruj 1: Culoare " << ruj1.getCuloare() << ", Pret: " << ruj1.getPret() << ", Cantitate: " << ruj1.getCantitateG() << " g" << std::endl;
    std::cout << "Ruj 2: Culoare " << ruj2.getCuloare() << ", Pret: " << ruj2.getPret() << ", Cantitate: " << ruj2.getCantitateG() << " g" << std::endl;
    std::cout << "Ruj 3: Culoare " << ruj3.getCuloare() << ", Pret: " << ruj3.getPret() << ", Cantitate: " << ruj3.getCantitateG() << " g" << std::endl;

    // Testarea functiilor globale prietene
    double discountParfum = calculeazaReducere(parfum2, 10.0);
    std::cout << "Reducere pentru Parfum 2: " << discountParfum << " lei" << std::endl;

    bool disponibilitateRuj = verificaDisponibilitateRuj(ruj3);
    if (disponibilitateRuj) {
        std::cout << "Rujul 3 este disponibil." << std::endl;
    }
    else {
        std::cout << "Rujul 3 nu este disponibil." << std::endl;
    }

    return 0;
}
