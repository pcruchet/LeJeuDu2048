#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#define NB_MAX_JOUEURS 20

#include "menu.h"
#include "Joueur.h"

using namespace std;

enum MENU
{
    AJOUTER = 1,
    VISUALISER,
    CHARGER,
    SAUVEGARDER,
    QUITTER
};

void TrierTableau(Joueur * _tab, const int _nb)
{
    Joueur aux;
    for (int indice1 = 0; indice1 < _nb - 1; indice1++)
        for (int indice2 = 0; indice2 < _nb - indice1 - 1; indice2++)
        {
            if (_tab[indice2] > _tab[indice2 + 1])
            {
                aux = _tab[indice2];
                _tab[indice2] = _tab[indice2 + 1];
                _tab[indice2 + 1] = aux;
            }
        }
}

int RechercherJoueur(Joueur * _tab, const int _nb, const string _pseudo)
{
    int indice = 0;
    while (_tab[indice] != _pseudo && indice < _nb)
        indice++;
    if (indice == _nb)
        indice = -1;
    return indice;
}

int main(int argc, char** argv)
{
    Menu leMenu("Menu.txt");
    int choix;
    Joueur tabJoueurs[NB_MAX_JOUEURS];
    string pseudo;
    int score;
    int duree;  

    int nbJoueurs = 0;

    do
    {
        choix = leMenu.AfficherEtAttendreChoix();
        switch (choix)
        {
        case AJOUTER:
        {
            int pos;
            cout << "Pseudo score durée :";
            cin >> pseudo >> score >> duree;

            if (nbJoueurs > 0)
            {
                pos = RechercherJoueur(tabJoueurs, nbJoueurs, pseudo);
                if (pos > 0)
                    tabJoueurs[pos].Actualiser(score, duree);
                else
                    tabJoueurs[nbJoueurs++] = Joueur(pseudo, score, duree);

                TrierTableau(tabJoueurs, nbJoueurs);
            }
            else
                tabJoueurs[nbJoueurs++] = Joueur(pseudo, score, duree);

            Menu::EffacerEcran();
            break;
        }
        case VISUALISER:
            Menu::EffacerEcran();
            cout << "+" << setw(13) << setfill('-') << "+" << setw(8) << "+" << setw(8) << "+" << setfill(' ') << endl;
            for (int i = 0; i < nbJoueurs; i++)
            {
                tabJoueurs[i].ObtenirInfo(pseudo, score, duree);
                cout << "| " << left << setw(10) << pseudo << " | " << right << setw(5) << score << " | " << setw(5) << duree << " |" << endl;
            }
            cout << "+" << setw(13) << setfill('-') << "+" << setw(8) << "+" << setw(8) << "+" << setfill(' ') << endl;
            Menu::AttendreAppuiTouche();
            break;

        case CHARGER:
        {
            ifstream fichier("joueurs.txt");
            if (!fichier.is_open())
            {
                nbJoueurs = 0;
            }
            else
            {
                fichier >> nbJoueurs;
                for (int i = 0; i < nbJoueurs; i++)
                {
                    fichier >> tabJoueurs[i];
                }
                fichier.close();
            }
            Menu::EffacerEcran();
            break;
        }
        case SAUVEGARDER:
        {
            ofstream fichier("joueurs.txt");
            if (!fichier.is_open())
            {
                cout << "Erreur lors de l'ouverture du fichier en écriture ";
            }
            else
            {
                fichier << nbJoueurs << endl;
                for (int i = 0; i < nbJoueurs; i++)
                {
                    fichier << tabJoueurs[i];
                }
                fichier.close();
            }
            Menu::EffacerEcran();
            break;
        }
        }
    }
    while (choix != QUITTER);

    return 0;
}
