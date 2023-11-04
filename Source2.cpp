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


// Suprascrierea operatorului de atribuire
Parfum& operator=(const Parfum& other) {
    if (this != &other) {
        nume = other.nume;
        pret = other.pret;
        cantitate_ml = other.cantitate_ml;
    }
    return *this;
}

// Suprascrierea operatorului de adunare (+)
Parfum operator+(const Parfum& other) {
    Parfum result = *this;
    result.pret += other.pret;
    result.cantitate_ml += other.cantitate_ml;
    return result;
}

// Suprascrierea operatorului de scadere (-)
Parfum operator-(const Parfum& other) {
    Parfum result = *this;
    result.pret -= other.pret;
    result.cantitate_ml -= other.cantitate_ml;
    return result;
}

// Suprascrierea operatorului de înmulțire (*)
Parfum operator*(double factor) {
    Parfum result = *this;
    result.pret *= factor;
    return result;
}

// Suprascrierea operatorului de afișare (<<)
friend std::ostream& operator<<(std::ostream& out, const Parfum& parfum) {
    out << "Nume: " << parfum.nume << ", Pret: " << parfum.pret << ", Cantitate: " << parfum.cantitate_ml << " ml";
    return out;
}

// Funcție prietenă
friend double calculeazaReducere(const Parfum& parfum, double procent);
};

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

// Suprascrierea operatorului de atribuire
Oja& operator=(const Oja& other) {
    if (this != &other) {
        culoare = other.culoare;
        pret = other.pret;
        cantitate_ml = other.cantitate_ml;
    }
    return *this;
}

// Suprascrierea operatorului de adunare (+)
Oja operator+(const Oja& other) {
    Oja result = *this;
    result.pret += other.pret;
    result.cantitate_ml += other.cantitate_ml;
    return result;
}

// Suprascrierea operatorului de scadere (-)
Oja operator-(const Oja& other) {
    Oja result = *this;
    result.pret -= other.pret;
    result.cantitate_ml -= other.cantitate_ml;
    return result;
}

// Suprascrierea operatorului de înmulțire (*)
Oja operator*(double factor) {
    Oja result = *this;
    result.pret *= factor;
    return result;
}

// Suprascrierea operatorului de afișare (<<)
friend std::ostream& operator<<(std::ostream& out, const Oja& oja) {
    out << "Culoare: " << oja.culoare << ", Pret: " << oja.pret << ", Cantitate: " << oja.cantitate_ml << " ml";
    return out;
}

// Funcție prietenă
friend double calculeazaProfit(const Oja& oja);
};

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


// Suprascrierea operatorului de atribuire
Ruj& operator=(const Ruj& other) {
    if (this != &other) {
        culoare = other.culoare;
        pret = other.pret;
        cantitate_g = other.cantitate_g;
    }
    return *this;
}

// Suprascrierea operatorului de adunare (+)
Ruj operator+(const Ruj& other) {
    Ruj result = *this;
    result.pret += other.pret;
    result.cantitate_g += other.cantitate_g;
    return result;
}

// Suprascrierea operatorului de scadere (-)
Ruj operator-(const Ruj& other) {
    Ruj result = *this;
    result.pret -= other.pret;
    result.cantitate_g -= other.cantitate_g;
    return result;
}

// Suprascrierea operatorului de înmulțire (*)
Ruj operator*(double factor) {
    Ruj result = *this;
    result.pret *= factor;
    return result;
}

// Suprascrierea operatorului de afișare (<<)
friend std::ostream& operator<<(std::ostream& out, const Ruj& ruj) {
    out << "Culoare: " << ruj.culoare << ", Pret: " << ruj.pret << ", Cantitate: " << ruj.cantitate_g << " g";
    return out;
}

// Funcție prietenă
friend bool verificaDisponibilitateRuj(const Ruj& ruj);
};

double calculeazaReducere(const Parfum& parfum, double procent) {
    return parfum.pret - (parfum.pret * procent / 100);
}

double calculeazaProfit(const Oja& oja) {
    return oja.pret * oja.cantitate_ml;
}

bool verificaDisponibilitateRuj(const Ruj& ruj) {
    return ruj.cantitate_g > 0;
}

int main() {
    // Testarea operatorilor și funcțiilor
    Parfum parfum1;
    Parfum parfum2("Parfum A", 75.0, 100);
    Parfum parfum3("Parfum B", 60.0);

    Oja oja1;
    Oja oja2("Albastru", 12.0, 20);
    Oja oja3("Verde", 8.0);

    Ruj ruj1;
    Ruj ruj2("Rosu", 20.0, 10);
    Ruj ruj3("Maro", 18.0);

    // Suprascrierea operatorului de atribuire
    Parfum parfum4 = parfum2;
    Oja oja4 = oja2;
    Ruj ruj4 = ruj2;

    // Suprascrierea operatorilor matematici
    Parfum sumaParfum = parfum2 + parfum3;
    Oja diferentaOja = oja2 - oja3;
    Ruj produsRuj = ruj2 * 2.0;

    // Afișarea obiectelor folosind operatorul <<
    std::cout << "Parfum 1: " << parfum1 << std::endl;
    std::cout << "Parfum 4 (dupa atribuire): " << parfum4 << std::endl;
    std::cout << "Suma Parfum: " << sumaParfum << std::endl;
    std::cout << "Diferenta Oja: " << diferentaOja << std::endl;
    std::cout << "Produs Ruj: " << produsRuj << std::endl;

    // Folosirea funcțiilor prietene
    double discountParfum = calculeazaReducere(parfum2, 10.0);
    std::cout << "Reducere pentru Parfum 2: " << discountParfum << " lei" << std::endl;

    bool disponibilitateRuj = verificaDisponibilitateRuj(ruj3);
    if (disponibilitateRuj) {
        std.cout << "Rujul 3 este disponibil." << std::endl;
    }
    else {
        std::cout << "Rujul 3 nu este disponibil." << std::endl;
    }

    return 0;
}
