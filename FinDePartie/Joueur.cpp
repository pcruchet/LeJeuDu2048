/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Joueur.cpp
 * Author: philippe
 * 
 * Created on 3 février 2024, 14:26
 */

#include "Joueur.h"


Joueur::Joueur(const string _pseudo,const int _nouveauScore,const int _duree):
pseudo(_pseudo),
score(_nouveauScore),
cumulTemps(_duree)
{
}

Joueur::Joueur()
{
    pseudo.clear();
    score = 0;
    cumulTemps = 0;
}

void Joueur::Actualiser(const int _nouveauScore, const int _duree)
{
    if(_nouveauScore > score)
        score = _nouveauScore;
    cumulTemps += _duree;
}

void Joueur::ObtenirInfo(string & _pseudo, int & _score, int & _cumulTemps)
{
    _pseudo = pseudo;
    _score = score;
    _cumulTemps = cumulTemps;   
}

bool Joueur::operator > (const Joueur& _autre) const
{
    return score < _autre.score ;
}

bool Joueur::operator != (const string& _pseudo) const
{
    return pseudo != _pseudo ;
}

ostream& operator << (ostream &flux, const Joueur &unJoueur) {
    flux << unJoueur.pseudo << " " << unJoueur.score << " " << unJoueur.cumulTemps << endl;
    return flux;
}

istream& operator >> (istream &flux, Joueur &unJoueur) {
    flux >> unJoueur.pseudo >>  unJoueur.score >> unJoueur.cumulTemps;
    return flux;
}