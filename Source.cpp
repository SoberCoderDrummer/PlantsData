#include <iostream>
#include <memory>
#include <cstring>
#include <bitset>
#include <optional>
#include <vector>
#include <string>
using namespace std;


int main();

enum NIVEAU_DIFFICULTE { Facile = 1, Intermediaire = 2, Expert = 4 };
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
        string port;
        string dimension;


        string strDifficulte;

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

    public:
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

            setStrDifficulte();
        }

        Plante() = default;

        friend int ::main();
        friend struct PlantePrinter;

        const string& getNomLatin() const
        {
            return this->nomLatin;
        }
        
    };

    shared_ptr<Plante> createPlante(string_view nomLatin,
        string_view nomFrancais,
        string_view nomAnglais,
        string_view famille,
        string_view origine,
        string_view classification,
        bitset<3> niveauDifficulte,
        string_view port,
        string_view dimension)
    {
        return make_shared<Plante>(nomLatin, nomFrancais, nomAnglais, famille, origine, classification, niveauDifficulte, port, dimension);
    }

    struct PlantePrinter
    {   
        static void printPlante(const Plante& p)
        {
            
            cout << "Nom: " << p.nomLatin << endl;
            cout << "Nom francais: " << p.nomFrancais << endl;
            cout << "Nom anglais: " << p.nomAnglais << endl;
            cout << "Famille: " << p.famille << endl;
            cout << "Origine: " << p.origine << endl;
            cout << "Difficulte: " << p.strDifficulte << endl;

        }
    };
}

int main()
{
    using namespace PlanteInterieur;
    //shared_ptr<PlanteInterieur::Plante> Alocasia = PlanteInterieur::createPlante("Alocasia", "Oreille d'‚l‚phant", "Kris Plant", "Araceae", "Asie tropical, phillippine", "Feuillage", 1 | 2, "rig‚", "Basse 10-30cm");

    shared_ptr<Plante> alocasia = createPlante("Alocasia", "Oreille d'‚l‚phant", "Kris Plant", "Araceae", "Asie tropical, phillippine", "Feuillage", NIVEAU_DIFFICULTE::Facile | NIVEAU_DIFFICULTE::Expert | NIVEAU_DIFFICULTE::Intermediaire, "rig‚", "Basse 10-30cm");

    PlantePrinter::printPlante(*alocasia.get());
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
