/************************************************************************************************
   Nom du fichier : MaFenetre.cpp
   Objet          : vérifier si un mot est un palindome ou pas
   Auteurs        : AGBAGLA Ariane, AVOKPO Yao Carlos, GASSIHOUN Sylvie, KOULETE Horris.
   Date           : 27/07/2014
 ***********************************************************************************************/

#include "MaFenetre.h"
#include <QInputDialog>
#include <QFormLayout>
#include <QGridLayout>
#include <QString>
#include <QLabel>
#include <QFont>
#include <QMessageBox>


MaFenetre::MaFenetre() : QWidget()
{
    setFixedSize(460, 240);
    //instanciation des attributs de MaFenetre
    titre = new QLabel("DETECTIVE DE PALINDROME\n");
    texteLabel = new QLabel("Texte");
    palindromeLabel = new QLabel("Palindrome----");
    texte = new QLineEdit;
    palindrome = new QLineEdit;
    quitter = new QPushButton("Quitter");
    valider  = new QPushButton("Valider");

    //layouts pour une bonne affcihage de MaFenetre
    QFormLayout *formLayout = new QFormLayout;
    QGridLayout *layout = new QGridLayout;
    QVBoxLayout *layoutPrincipal = new QVBoxLayout;

    //Format des composants de MaFenetre
    titre->setFont(QFont("Georgia", 16, QFont::Bold));
    texteLabel->setFont(QFont("Georgia", 10, QFont::Bold, true));
    palindromeLabel->setFont(QFont("Georgia", 10, QFont::Bold, true));
    texte->setFont(QFont("Georgia", 12));
    palindrome->setFont(QFont("Georgia", 12));
    valider->setFont(QFont("Georgia", 10));
    quitter->setFont(QFont("Georgia", 10));

    palindrome->setReadOnly(true);//zone de saisie en lecture seul

    //Ajout des composants dans des laayouts specifiques
    formLayout->addRow(titre);
    formLayout->addRow(texteLabel, texte);
    formLayout->addRow(palindromeLabel, palindrome);
    layout->addWidget(valider, 0, 0);
    layout->addWidget(quitter, 0, 1);

    //Ajout de layouts dans le layout principal
    layoutPrincipal->addLayout(formLayout);
    layoutPrincipal->addLayout(layout);

    //connexion de slots et de signals
    connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(valider, SIGNAL(clicked()), this, SLOT(verifierTexte()));

    this->setLayout(layoutPrincipal);//ajout du layout principal à Mafenetre
}

void MaFenetre::verifierTexte()
{
    bool test;
    QString contenu = texte->text().trimmed();

    if (contenu.isEmpty())//si zone de texte vide
    {
        QMessageBox::critical(this, "Erreur", "Veuillez entrer un texte !");
        palindrome->setText("");
    }
    else
    {
        test = estPalindrome();
        if(test)//si estPlindrome() renvoi vrai
        {
            palindrome->setText("OK");
        }
        else//dans le cas contraire
        {
            palindrome->setText("KO");
        }
    }

}

bool MaFenetre::estPalindrome()
{
    QString chaine = texte->text().trimmed();//on enlève les espaces de début et de fin
    QString s2(" ");
    int i(0), j(0);
    QMessageBox::information(this, "Ctrl", chaine);
    while((i = chaine.indexOf(' ', 0)) != '\0'){
        chaine.remove(' ', i);
    }
    QMessageBox::information(this, "Ctrl", chaine);
    while((j = chaine.indexOf(' ', i)) != '\0'){
        chaine.remove(' ', i);
        chaine[j] = chaine[j].toLower();
        i = j++;
    }

    int taille = chaine.size();
    bool estpal(true);//variable qui sera retourné après le test
    if(taille == 1)
    {
        estpal = true;
    }
    else if(taille % 2 != 0)/*parcours du tableau sans vérifier le caractère au milieu
                              car la taille est impaire*/
    {
        for(int i = 0;i<(taille-1)/2; i++)
        {
            if(chaine.at(i) != chaine.at(taille - i - 1))
            {
                estpal = false;
                break;
            }
         }
    }
    else
    {
        for(int i = 0;i<taille/2; i++)/*Paracours du tableau avec vérification de tous les caractères
                                         car la taille est paire*/
        {
            if(chaine.at(i) != chaine.at(taille - i -1))
            {
                estpal = false;
                break;
            }
         }
     }
    return estpal;
}
