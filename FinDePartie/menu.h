/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Menu.h
 * Author: pcruchet
 *
 * Created on 23 janvier 2024, 12:56
 */

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <limits>
#include <algorithm>


using namespace std;

class Menu {
public:
    Menu(const string _nomFichier);
    Menu(const string *_option, const int _nbOptions);
    int AfficherEtAttendreChoix();
    static void AttendreAppuiTouche();
    static void EffacerEcran();
    ~Menu();
private:
    string nomFichier;
    string *options;
    int nbOptions;
    size_t longueurMax;
};

#endif /* MENU_H */

