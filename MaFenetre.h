/************************************************************************************************
   Nom du fichier : Mafenetre.h
   Objet          : vérifier si un mot est un palindome ou pas
   Auteurs        : AGBAGLA Ariane, AVOKPO Yao Carlos, GASSIHOUN Sylvie, KOULETE Horris.
   Date           : 27/07/2014
 ***********************************************************************************************/

#ifndef DEF_MAFENETRE
#define DEF_MAFENETRE
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>


class MaFenetre : public QWidget
{
    Q_OBJECT
    private:
        QLabel *titre;
        QLabel *texteLabel;
        QLabel *palindromeLabel;
        QLineEdit *texte;
        QLineEdit *palindrome;
        QPushButton *valider;
        QPushButton *quitter;

    public:
        MaFenetre();//constructeur
        bool estPalindrome();//methode renvoyant vrai si c'est un palindome et faut si non

    private slots:
        void verifierTexte();//slot qui affiche si c'est un palindome ou non grâce à "est palindrome()"
};
#endif
