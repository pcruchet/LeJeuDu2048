/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Joueur.h
 * Author: philippe
 *
 * Created on 3 février 2024, 14:26
 */

#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <fstream>

using namespace std;

class Joueur {
public:
    Joueur(const string _pseudo,const int _nouveauScore=0,const int _duree=0);
    Joueur();
    void Actualiser(const int _nouveauScore,const int _duree);
    void ObtenirInfo(string &_pseudo, int & _score, int &cumulTemps);
    bool operator > (const Joueur &_autre) const;
    bool operator != (const string& _pseudo) const;
    friend ostream& operator << (ostream &flux, const Joueur &unJoueur);
    friend istream& operator >> (istream &flux, Joueur &unJoueur);
private:
    string pseudo ;
    int score;
    int cumulTemps;
};

#endif /* JOUEUR_H */

