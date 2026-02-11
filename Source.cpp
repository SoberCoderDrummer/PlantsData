#include <iostream>
#include <memory>
#include <cstring>
#include <bitset>
#include <optional>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class InfoGeneral
{
public:
    string famille;
    string Origine;
    string classification;
    string difficulte; // bitwise bitset<3> avec enum: Facile, Intermediare, Expert..
};
class Description;
class EntretienPropagation;
class DonneeComplementaire;

int main(int argc, char* argv[]);

struct PlantePrinter;

enum NIVEAU_DIFFICULTE { Facile = 1, Intermediaire = 2, Expert = 4 };
enum BESOIN_EAU { Leger = 1, Peu = Leger, Modere = 2, Abondant = 4, Genereux = Abondant};
enum HR {Faible = 1, Normal = 2, Elevee = 4};
enum SUBSTRAT {TouteUsage = 1, Humifere = 2, MousseDeSphaigne = 4, Ecorce = 8, RacineAir = 16, Epiphyte = RacineAir, Drainant = 32,};
enum BESOIN_LUMIERE {};
namespace PlanteInterieur
{

    struct PlantePrinter;
    class Plante
    {
        
    private:
        string nomLatin;
        string nomFrancais;
        string nomAnglais;

        string famille;
        string origine;
        string classification;
        bitset<3> niveauDifficulte;
        bitset<3> besoinEau;
        string port;
        string dimension;


        string strDifficulte;
        string strBesoinEau;

        // sfml data
        vector<string> images;

        void setStrDifficulte()
        {
            strDifficulte = "";

            const string difficulte[3] = { "Facile", "Intermediaire", "Expert" };

            for (size_t i = 0; i < 3; i++)
            {
                if (niveauDifficulte[i])
                {
                    strDifficulte += difficulte[i];
                }
            }
        }


        void setStrBesoinEau()
        {
            strBesoinEau = "";

            const string besoinEauStr[3] = { "Leger", "Modere", "Abondant" };

            for (size_t i = 0; i < 3; i++)
            {
                if (besoinEau[i])
                {
                    strBesoinEau += besoinEauStr[i];
                }
            }
        }

    public:
        static int nombrePlanteProduite;

        Plante(string_view nomLatin,  // string_view = On prend le contenu (non modifiable et leger) pis on le met dans les membre data.
            string_view nomFrancais,
            string_view nomAnglais,
            string_view famille,
            string_view origine,
            string_view classification,
            bitset<3> niveauDifficulte,
            string_view port,
            string_view dimension)
        {
            
            this->nomLatin = nomLatin;
            this->nomFrancais = nomFrancais;
            this->nomAnglais = nomAnglais;
            this->famille = famille;
            this->origine = origine;
            this->classification = classification;
            this->niveauDifficulte = niveauDifficulte;
            this->port = port;
            this->dimension = dimension;

            setStrDifficulte(); // set le string de difficulte a travers le bitset<3> niveauDIfficulte

            this->nombrePlanteProduite++;
            cout << "Plante: " << this->getNomLatin() << " produite(" << Plante::nombrePlanteProduite << ")" << endl;
        }

        Plante() = default;

        friend int ::main(int argc, char* argv[]);
        friend struct PlantePrinter;
        
        const string& getNomLatin() const
        {
            return this->nomLatin;
        }

        const string& getNomFrancais() const
        {
            return this->nomFrancais;
        }


        friend ostream& operator<<(ostream& out, const Plante& p)
        {
#define COULEUR_VERT [2333""]
            // Output info ici..
            // couleur code.. 
            out << "Nom latin: " << p.nomLatin << endl;

            return out;
        }
        
    };


    int Plante::nombrePlanteProduite = 0;

    unique_ptr<Plante> createPlante(string_view nomLatin,
        string_view nomFrancais,
        string_view nomAnglais,
        string_view famille,
        string_view origine,
        string_view classification,
        bitset<3> niveauDifficulte,
        string_view port,
        string_view dimension)
    {
        return make_unique<Plante>(
            nomLatin, nomFrancais, nomAnglais, famille, origine, classification, niveauDifficulte, port, dimension);
    }

    struct PlantePrinter
    {   
        static void printPlante(unique_ptr<Plante> &p)
        {
            
            cout << "Nom: " << p->nomLatin << endl;
            cout << "Nom francais: " << p->nomFrancais << endl;
            cout << "Nom anglais: " << p->nomAnglais << endl;
            cout << "Famille: " << p->famille << endl;
            cout << "Origine: " << p->origine << endl;
            cout << "Difficulte: " << p->strDifficulte << endl;

        }
    };
}

using namespace PlanteInterieur;

class Encyclopedie
{
    vector<unique_ptr<Plante>> listePlante;
    string nomEncyclopedie;
public:
    Encyclopedie()
    {
        listePlante.reserve(150);
        nomEncyclopedie = "Plantes interieurs :) ";
        // tout les plantes se produise ici.. 150 ... \: Ca sera long a taper. Mais faut le faire.
        //Alocasia
        listePlante.push_back(make_unique<Plante>("Alocasia", "Oreille d'elephant", "Kris Plant", "Araceae", "Asie Tropical, phillippine", "Feuillage", NIVEAU_DIFFICULTE::Facile, "rig", "Basse 10-30cm"));
        // ...

    }

    void writePlanteDataToFile(ifstream& inputFile)
    {
        // TODO
        // Toute transferer le contenu du vector de plante dans un fichier txt.
        inputFile.open("PlanteData.txt");
    }

    void peekPlante(int index)
    {
        /*
        
        try {
            catch ();
        }
        throw;
        if (index > listePlante.size() || index < listePlante.size())
        {
            cout << "Out of bound" << endl;
            return;
        }
        cout << listePlante.at(index) << endl;
        */
    }
};

int main(int argc, char* argv[])
{
    // TODO: Lancer le programme avec un argument de plante du gerne: main() Alocasia. Find data
    for (size_t i = 0; i < 150; i++)
    {
        // if vector[i].getName() == argv[0]. Print Data,,
    }
    // string targetPlante = argv[0];
    using namespace PlanteInterieur;

    Encyclopedie encyclo;
    //shared_ptr<PlanteInterieur::Plante> Alocasia = PlanteInterieur::createPlante("Alocasia", "Oreille d'‚l‚phant", "Kris Plant", "Araceae", "Asie tropical, phillippine", "Feuillage", 1 | 2, "rig‚", "Basse 10-30cm");

    unique_ptr<Plante> alocasia = createPlante("Alocasia", "Oreille d'‚l‚phant", "Kris Plant", "Araceae", "Asie tropical, phillippine", "Feuillage", NIVEAU_DIFFICULTE::Facile | NIVEAU_DIFFICULTE::Expert | NIVEAU_DIFFICULTE::Intermediaire, "rig‚", "Basse 10-30cm");

    pair<string, bitset<3>> difficulte;
    difficulte.first = "";

    difficulte.second = NIVEAU_DIFFICULTE::Expert | NIVEAU_DIFFICULTE::Intermediaire | NIVEAU_DIFFICULTE::Facile;
    const string diff[3] = { "Facile", "Intermediare", "Expert" };
    for (size_t i = 0; i < difficulte.second.size(); i++)
        if (difficulte.second[i])
            difficulte.first += diff[i];

    cout << difficulte.first << endl;
    return 0;
} 

/* Design de plante data:

    class Plante
    : Nom latin, optional nom francais, optional nom anglais
      Famille
      Origine
      Classification
      Niveau de difficulte
      Port
      Dimension
      ...
      Description
      flle et tige
      Fleur
      Couleur
      Floraison
      Induction et note
      Utilisation:.
      
      Entretien
      Eau:
      Lumiere
      H.R
      Substrat
      P de repos Fertilisation
      Propagation
      Insect et maladie
      Donnee complementaire*/

