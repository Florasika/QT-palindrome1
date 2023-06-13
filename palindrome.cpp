/************************************************************************************************
   Nom du fichier : palindrome.cpp
   Objet          : vérifier si un mot est un palindome ou pas
   Auteurs        : AGBAGLA Ariane, AVOKPO Yao Carlos, GASSIHOUN Sylvie, KOULETE Horris.
   Date           : 27/07/2014
 ***********************************************************************************************/

#include <QApplication>
#include "MaFenetre.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MaFenetre fenetre;

    fenetre.show();//visibilté de fenetre

    return app.exec();
}

