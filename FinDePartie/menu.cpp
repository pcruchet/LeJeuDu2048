/* 
 * File:   Menu.cpp
 * Author: pcruchet
 * 
 * Created on 23 janvier 2024, 12:56
 */


#include "menu.h"


Menu::Menu(const string _nomFichier) :
nomFichier(_nomFichier),
longueurMax(0),
options(nullptr)
{
    ifstream fichierMenu(nomFichier);
    if (fichierMenu.fail())
    {
        cerr << "Erreur lors de l'ouverture du fichier : " << strerror(errno) << endl;
        exit errno;
    }
    else
    {
        nbOptions = static_cast<int> (count(istreambuf_iterator<char>(fichierMenu),
                                            istreambuf_iterator<char>(), '\n'));
        fichierMenu.seekg(0, ios::beg);

        size_t longueur;
        string item;

        options = new string[nbOptions];
        for (int i = 0; i < nbOptions; i++)
        {
            getline(fichierMenu, item);
            longueur = item.length();
            if (longueur > longueurMax)
                longueurMax = longueur;
            if (longueur > 0)
                options[i] = item;
            else
            {
                nbOptions--;
                i--;
            }
        }

    }
}

Menu::Menu(const string* _options, const int _nbOptions) :
nbOptions(_nbOptions),
        longueurMax(0)
{
    nomFichier.clear();
    size_t longueur;
    options = new string[nbOptions];
    for (int i = 0; i < nbOptions; i++)
    {
        options[i] = _options[i];
        longueur = options[i].length();
        if (longueur > longueurMax)
            longueurMax = longueur;
    }

}

Menu::~Menu()
{
    if (!nomFichier.empty() && options != nullptr)
        delete[] options;
}

int Menu::AfficherEtAttendreChoix()
{
    int choix = -1;

    if (nbOptions != 0 && options != nullptr)
    {
        cout << setfill('-');
        cout << "+-" << setw(4) << "-+-" << setw(longueurMax + 2) << "-+" << endl;
        cout << setfill(' ');
        for (int i = 0; i < nbOptions; i++)
        {
            cout << "| " << i + 1 << " | " << left << setw(longueurMax) << options[i] << " |" << endl;
        }
        std::cout << setfill('-') << right;
        cout << "+-" << setw(4) << "-+-" << setw(longueurMax + 2) << "-+" << endl;
        cout << setfill(' ');

        do
        {
            cout << "Votre choix : entre 1 et " << nbOptions << " : ";
            if (!(cin >> choix))
            {
                cin. clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                choix = -1;
            }
        }
        while (choix < 1 || choix > nbOptions);

    }

    return choix;
}

void Menu::AttendreAppuiTouche()
{
    string uneChaine;
    cout << endl << "Appuyer sur la touche Entrée pour continuer ...";
    getline(cin, uneChaine);
    // Vidage du tampon d'entrée
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // efface l'écran de la console
    cout << "\033[2J\033[1;1H";
}

void Menu::EffacerEcran()
{
     cout << "\033[2J\033[1;1H";
}