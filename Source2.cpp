#include <iostream>
using namespace std;

class Parfum {
private:
    string marca;
    int anLansare;
    const string categorie = "parfum";
    static int numarParfumuri;
    int* pointer;

public:
    Parfum(string marca, int anLansare) {
        //constructor
        this->marca = marca;
        this->anLansare = anLansare;
        numarParfumuri++;
        pointer = new int;
    }

    Parfum(string marca) {
        this->marca = marca;
        this->anLansare = 2021;
        numarParfumuri++;
        pointer = new int;
    }

    Parfum() {
        this->marca = "Necunoscut";
        this->anLansare = 2021;
        numarParfumuri++;
        pointer = new int;
    }

    Parfum(const Parfum& other) {
        marca = other.marca;
        anLansare = other.anLansare;
        pointer = new int(*other.pointer);
    }

    ~Parfum() {
         pointer;
    }

    string getMarca() const { return marca; }
    int getAnLansare() const { return anLansare; }
    void setMarca(string newMarca) { marca = newMarca; }
    void setAnLansare(int newAnLansare) { anLansare = newAnLansare; }

    static int getNumarParfumuri() { return numarParfumuri; }

    static void procesareParfum() {
        cout << "Procesare parfum" << endl;
    }

//operatori
 Parfum& operator=(const Parfum& other) {
        if (this != &other) {
            delete pointer;
            marca = other.marca;
            anLansare = other.anLansare;
            pointer = new int(*other.pointer);
        }
        return *this;
    }

    Parfum operator+(int value) const {
        Parfum result = *this;
        result.anLansare += value;
        return result;
    }

    Parfum operator-(int value) const {
        Parfum result = *this;
        result.anLansare -= value;
        return result;
    }

    Parfum operator*(int value) const {
        Parfum result = *this;
        result.anLansare *= value;
        return result;
    }

    friend ostream& operator<<(ostream& os, const Parfum& p);
};

int Parfum::numarParfumuri = 0;

ostream& operator<<(ostream& os, const Parfum& p) {
    os << "Marca: " << p.marca << ", Anul Lansarii: " << p.anLansare;
    return os;
}

 friend istream& operator>>(istream& is, Parfum& p);
};

int Parfum::numarParfumuri = 0;

istream& operator>>(istream& is, Parfum& p) {
    cout << "Introduceti marca parfumului: ";
    is >> p.marca;
    cout << "Introduceti anul lansarii parfumului: ";
    is >> p.anLansare;
    return is;
}

// Metoda pentru scrierea informatiilor in fisier text
    void scrieInFisierText(const string& numeFisier) const {
        ofstream fout(numeFisier);
        if (fout.is_open()) {
            fout << "Marca: " << marca << "\n";
            fout << "Anul Lansarii: " << anLansare << "\n";
            fout.close();
            cout << "Datele au fost scrise in fisierul text.\n";
        } else {
            cerr << "Eroare la deschiderea fisierului text.\n";
        }
    }

    // Metoda pentru citirea informatiilor din fisier text
    void citesteDinFisierText(const string& numeFisier) {
        ifstream fin(numeFisier);
        if (fin.is_open()) {
            fin >> marca >> anLansare;
            fin.close();
            cout << "Datele au fost citite din fisierul text.\n";
        } else {
            cerr << "Eroare la deschiderea fisierului text.\n";
        }
    }
};

class SetCosmetic {
private:
    string numeSet;
    vector<Parfum> parfumuri;  // Relatie de has-a cu clasa Parfum
    int pretTotal;

public:
    SetCosmetic(string numeSet) {
        // Constructor
        this->numeSet = numeSet;
        pretTotal = 0;
    }

    // Getteri si setteri pentru atributele clasei
    string getNumeSet() const { return numeSet; }
    int getPretTotal() const { return pretTotal; }

    void setNumeSet(string nume) { numeSet = nume; }
    void setPretTotal(int pret) { pretTotal = pret; }

    // Metoda pentru adaugarea unui parfum in set
    void adaugaParfum(const Parfum& parfum) {
        parfumuri.push_back(parfum);
        pretTotal += parfum.getAnLansare();  // Exemplu de calcul al pretului total
    }

    // Metoda pentru afisarea informatiilor despre set
    void afiseazaSet() const {
        cout << "Nume set: " << numeSet << endl;
        cout << "Parfumuri in set:\n";
        for (const auto& parfum : parfumuri) {
            cout << "  - " << parfum.getMarca() << " (An lansare: " << parfum.getAnLansare() << ")\n";
        }
        cout << "Pret total: " << pretTotal << endl;
    }

    // Operatori la alegere
    bool operator==(const SetCosmetic& other) const {
        return (numeSet == other.numeSet) && (pretTotal == other.pretTotal);
    }

    SetCosmetic operator+(const SetCosmetic& other) const {
        SetCosmetic result = *this;
        result.pretTotal += other.pretTotal;
        return result;
    }

    SetCosmetic& operator+=(const Parfum& parfum) {
        adaugaParfum(parfum);
        return *this;
    }

// Metoda pentru scrierea informatiilor in fisier binar
    void scrieInFisierBinar(const string& numeFisier) const {
        ofstream fout(numeFisier, ios::binary);
        if (fout.is_open()) {
            fout.write(reinterpret_cast<const char*>(&numeSet), sizeof(numeSet));
            fout.write(reinterpret_cast<const char*>(&pretTotal), sizeof(pretTotal));
            size_t numarParfumuri = parfumuri.size();
            fout.write(reinterpret_cast<const char*>(&numarParfumuri), sizeof(numarParfumuri));
            for (const Parfum& parfum : parfumuri) {
                fout.write(reinterpret_cast<const char*>(&parfum), sizeof(parfum));
            }
            fout.close();
            cout << "Datele au fost scrise in fisierul binar.\n";
        } else {
            cerr << "Eroare la deschiderea fisierului binar.\n";
        }
    }

    // Metoda pentru citirea informatiilor din fisier binar
    void citesteDinFisierBinar(const string& numeFisier) {
        ifstream fin(numeFisier, ios::binary);
        if (fin.is_open()) {
            fin.read(reinterpret_cast<char*>(&numeSet), sizeof(numeSet));
            fin.read(reinterpret_cast<char*>(&pretTotal), sizeof(pretTotal));
            size_t numarParfumuri;
            fin.read(reinterpret_cast<char*>(&numarParfumuri), sizeof(numarParfumuri));
            parfumuri.resize(numarParfumuri);
            for (Parfum& parfum : parfumuri) {
                fin.read(reinterpret_cast<char*>(&parfum), sizeof(parfum));
            }
            fin.close();
            cout << "Datele au fost citite din fisierul binar.\n";
        } else {
            cerr << "Eroare la deschiderea fisierului binar.\n";
        }
    }
};

class Oja {
private:
    string marca;
    int pret;
    const string categorie = "oja";
    static int numarOje;
    int* pointer;

public:
    Oja(string marca, int pret) {
        this->marca = marca;
        this->pret = pret;
        numarOje++;
        pointer = new int;
    }

    Oja(string marca) {
        this->marca = marca;
        this->pret = 0;
        numarOje++;
        pointer = new int;
    }

    Oja() {
        this->marca = "Necunoscut";
        this->pret = 0;
        numarOje++;
        pointer = new int;
    }

    Oja(const Oja& other) {
        marca = other.marca;
        pret = other.pret;
        pointer = new int(*other.pointer);
    }

    ~Oja() {
         pointer;
    }

    string getMarca() const { return marca; }
    int getPret() const { return pret; }
    void setMarca(string newMarca) { marca = newMarca; }
    void setPret(int newPret) { pret = newPret; }

    static int getNumarOje() { return numarOje; }

    static void procesareOja() {
        cout << "Procesare oja" << endl;
    }
};

//operatori
Oja& operator=(const Oja& other) {
        if (this != &other) {
            delete pointer;
            marca = other.marca;
            pret = other.pret;
            pointer = new int(*other.pointer);
        }
        return *this;
    }

    Oja operator+(int value) const {
        Oja result = *this;
        result.pret += value;
        return result;
    }

    Oja operator-(int value) const {
        Oja result = *this;
        result.pret -= value;
        return result;
    }

    Oja operator*(int value) const {
        Oja result = *this;
        result.pret *= value;
        return result;
    }

    friend ostream& operator<<(ostream& os, const Oja& o);
};

int Oja::numarOje = 0;

ostream& operator<<(ostream& os, const Oja& o) {
    os << "Marca: " << o.marca << ", Pret: " << o.pret;
    return os;
}
    
  friend istream& operator>>(istream& is, Oja& o);
};

int Oja::numarOje = 0;

istream& operator>>(istream& is, Oja& o) {
    cout << "Introduceti marca ojei: ";
    is >> o.marca;
    cout << "Introduceti pretul ojei: ";
    is >> o.pret;
    return is;
}

class LacUnghii : public Oja {
private:
    string tipLac; // Nou atribut specific
public:
    // Constructor specific pentru LacUnghii
    LacUnghii(string marca, int pret, string tipLac) : Oja{marca, pret}, tipLac{tipLac} {}

    // Metoda specifica pentru LacUnghii
    void aplicaLacUnghii() {
        cout << "Lacul de unghii " << getMarca() << " a fost aplicat. Tip: " << tipLac << "\n";
    }
};

class Ruj {
private:
    string marca;
    int cantitate;
    const string categorie = "ruj";
    static int numarRuje;
    int* pointer;

public:
    Ruj(string marca, int cantitate) {
        this->marca = marca;
        this->cantitate = cantitate;
        numarRuje++;
        pointer = new int;
    }

    Ruj(string marca) {
        this->marca = marca;
        this->cantitate = 0;
        numarRuje++;
        pointer = new int;
    }

    Ruj() {
        this->marca = "Necunoscut";
        this->cantitate = 0;
        numarRuje++;
        pointer = new int;
    }

    Ruj(const Ruj& other) {
        marca = other.marca;
        cantitate = other.cantitate;
        pointer = new int(*other.pointer);
    }

    ~Ruj() {
         pointer;
    }

    string getMarca() const { return marca; }
    int getCantitate() const { return cantitate; }
    void setMarca(string newMarca) { marca = newMarca; }
    void setCantitate(int newCantitate) { cantitate = newCantitate; }

    static int getNumarRuje() { return numarRuje; }

    static void procesareRuj() {
        cout << "Procesare ruj" << endl;
    }

//operatori
Ruj& operator=(const Ruj& other) {
        if (this != &other) {
            delete pointer;
            marca = other.marca;
            cantitate = other.cantitate;
            pointer = new int(*other.pointer);
        }
        return *this;
    }

    Ruj operator+(int value) const {
        Ruj result = *this;
        result.cantitate += value;
        return result;
    }

    Ruj operator-(int value) const {
        Ruj result = *this;
        result.cantitate -= value;
        return result;
    }

    Ruj operator*(int value) const {
        Ruj result = *this;
        result.cantitate *= value;
        return result;
    }

    friend ostream& operator<<(ostream& os, const Ruj& r);
};

int Ruj::numarRuje = 0;

    ostream& operator<<(ostream& os, const Ruj& r) {
    os << "Marca: " << r.marca << ", Cantitate: " << r.cantitate;
    return os;
}

friend istream& operator>>(istream& is, Ruj& r);
};

int Ruj::numarRuje = 0;

istream& operator>>(istream& is, Ruj& r) {
    cout << "Introduceti marca rujului: ";
    is >> r.marca;
    cout << "Introduceti cantitatea rujului: ";
    is >> r.cantitate;
    return is;
}

class BalsamBuze : public Ruj {
private:
    bool areAroma; // Nou atribut specific
public:
    // Constructor specific pentru BalsamBuze
    BalsamBuze(string marca, int cantitate, bool areAroma) : Ruj{marca, cantitate}, areAroma{areAroma} {}

    // Metoda specifica pentru BalsamBuze
    void aplicaBalsamBuze() {
        cout << "Balsamul de buze " << getMarca() << " a fost aplicat. Aroma: " << (areAroma ? "da" : "nu") << "\n";
    }
};

// Clasa abstracta pentru cosmetic
class CosmeticAbstract {
public:
    virtual void aplicare() const = 0; // Metoda pur virtuala
    virtual ~CosmeticAbstract() {} // Destructor virtual
};

// Clasa abstracta pentru makeup
class MakeupAbstract : public CosmeticAbstract {
public:
    virtual void folosire() const = 0; // Metoda pur virtuala
    virtual ~MakeupAbstract() {} // Destructor virtual
};


void functie1(const Parfum& p) {
    cout << "Functie 1: Marca parfum: " << p.getMarca() << endl;
}

void functie2(const Oja& o) {
    cout << "Functie 2: Pret oja: " << o.getPret() << endl;
}

int main() {
    // Testare constructori și metode

    Parfum parfum1("Dolce&Gabbana", 2019);
    Parfum parfum2("Chanel");
    Parfum parfum3;

    cout << "Numar parfumuri: " << Parfum::getNumarParfumuri() << endl;

    cout << "Marca parfum 1: " << parfum1.getMarca() << endl;
    cout << "Anul lansarii parfum 2: " << parfum2.getAnLansare() << endl;

    parfum3.setMarca("Paco Rabanne");
    parfum3.setAnLansare(2020);

    cout << "Marca parfum 3: " << parfum3.getMarca() << endl;
    cout << "Anul lansarii parfum 3: " << parfum3.getAnLansare() << endl;

    Oja oja1("Essie", 30);
    Oja oja2("OPI");
    Oja oja3;

    cout << "Numar oje: " << Oja::getNumarOje() << endl;

    cout << "Marca oja 1: " << oja1.getMarca() << endl;
    cout << "Pret oja 2: " << oja2.getPret() << endl;

    oja3.setMarca("Sephora");
    oja3.setPret(20);

    cout << "Marca oja 3: " << oja3.getMarca() << endl;
    cout << "Pret oja 3: " << oja3.getPret() << endl;

    Ruj ruj1("MAC", 5);
    Ruj ruj2("NYX");
    Ruj ruj3;

    cout << "Numar rujuri: " << Ruj::getNumarRuje() << endl;

    cout << "Marca ruj 1: " << ruj1.getMarca() << endl;
    cout << "Cantitate ruj 2: " << ruj2.getCantitate() << endl;

    ruj3.setMarca("Maybelline");
    ruj3.setCantitate(10);

    cout << "Marca ruj 3: " << ruj3.getMarca() << endl;
    cout << "Cantitate ruj 3: " << ruj3.getCantitate() << endl;

    // Testare funcții globale prietene

    functie1(parfum1);
    functie2(oja2);

    // Testare operatori si functii prietene
    Parfum parfum4 = parfum1 + 2;
    Oja oja4 = oja2 - 5;
    Ruj ruj4 = ruj3 * 3;

    cout << "Parfum 4: " << parfum4 << endl;
    cout << "Oja 4: " << oja4 << endl;
    cout << "Ruj 4: " << ruj4 << endl;

    // Vectori de obiecte
    vector<Parfum> vectorParfumuri(3);
    vector<Oja> vectorOje(3);
    vector<Ruj> vectorRuje(3);

    // Citire obiecte pentru fiecare vector
    for (int i = 0; i < 3; ++i) {
        cout << "Introduceti date pentru obiectul " << i + 1 << " din vectorParfumuri:\n";
        cin >> vectorParfumuri[i];
        cout << "Introduceti date pentru obiectul " << i + 1 << " din vectorOje:\n";
        cin >> vectorOje[i];
        cout << "Introduceti date pentru obiectul " << i + 1 << " din vectorRuje:\n";
        cin >> vectorRuje[i];
    }

    // Afisare obiecte pentru fiecare vector
    cout << "Obiecte din vectorParfumuri:\n";
    for (const auto& parfum : vectorParfumuri) {
        cout << parfum << endl;
    }

    cout << "Obiecte din vectorOje:\n";
    for (const auto& oja : vectorOje) {
        cout << oja << endl;
    }

    cout << "Obiecte din vectorRuje:\n";
    for (const auto& ruj : vectorRuje) {
        cout << ruj << endl;
    }

    // Matrice de obiecte
    const int rows = 2;
    const int cols = 2;
    Parfum matriceParfumuri[rows][cols];

    // Citire obiecte pentru matrice
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Introduceti date pentru obiectul [" << i << "][" << j << "] din matriceParfumuri:\n";
            cin >> matriceParfumuri[i][j];
        }
    }

    // Afisare obiecte pentru matrice
    cout << "Obiecte din matriceParfumuri:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matriceParfumuri[i][j] << endl;
        }
    }

// Utilizarea a noii clase
    Parfum parfum1("Dolce&Gabbana", 2019);
    Parfum parfum2("Chanel", 2020);

    SetCosmetic set1("Set Lux");
    set1.adaugaParfum(parfum1);

    SetCosmetic set2("Set Elegance");
    set2 += parfum2;

    SetCosmetic set3 = set1 + set2;

    cout << "Informatii despre Set1:\n";
    set1.afiseazaSet();

    cout << "\nInformatii despre Set2:\n";
    set2.afiseazaSet();

    cout << "\nInformatii despre Set3 (combinație de Set1 și Set2):\n";
    set3.afiseazaSet();

    // Exemplu de utilizare a metodelor pentru Parfum
    Parfum parfum;
    parfum.scrieInFisierText("parfum.txt");
    parfum.citesteDinFisierText("parfum.txt");

    // Exemplu de utilizare a metodelor pentru SetCosmetic
    SetCosmetic set("Set Lux");
    set.scrieInFisierBinar("set.bin");
    set.citesteDinFisierBinar("set.bin");

    // Creare obiecte de tipul claselor extinse
    LacUnghii lac("Essie", 25, "Mat");
    BalsamBuze balsam("Labello", 10, true);

    // Apelarea metodelor specifice noilor clase
    lac.aplicaLacUnghii();
    balsam.aplicaBalsamBuze();

    // Upcasting - Transformarea unui obiect de tip derivat in obiect de tip de baza
    Oja* ptrOja = &lac;
    Ruj* ptrRuj = &balsam;

    // Apelarea metodelor specifice clasei de baza
    ptrOja->aplicareOja();
    ptrRuj->folosireRuj();

    // Vector de pointeri la tipul abstract
    vector<CosmeticAbstract*> cosmetice;

    // Adaugare obiecte in vector
    cosmetice.push_back(new Parfum("Dolce&Gabbana", 2019));
    cosmetice.push_back(new Oja("Essie", 30));

    // Apelarea metodelor folosind late-binding
    for (const auto& cosmetic : cosmetice) {
        cosmetic->aplicare();
        MakeupAbstract* ptrMakeup = dynamic_cast<MakeupAbstract*>(cosmetic);
        if (ptrMakeup) {
            ptrMakeup->folosire();
        }
    }

    // Eliberarea memoriei
    for (const auto& cosmetic : cosmetice) {
        delete cosmetic;
    }
    
    return 0;
}

