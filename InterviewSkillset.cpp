// InterviewSkillset.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <memory>
#include "Header.h"

using namespace std;
using namespace conteneur;

int main()
{
    std::cout << "Hello Interview!\n";

    auto shared_cont = make_unique<SharedConteneur<long long int>>(20);

    try {
        for (int i = 0; i < 30; ++i) {
            shared_cont->Add("lg", 20000000000);
        }
    }
    catch (exception& e) {
        cout << "Exception size " << e.what() <<  endl;
    }
    shared_cont->Display();

    vector<weak_ptr<ItemSet<long long int>>> weak_conteneur = shared_cont->GetAllWeakReference();
    for (int i = 0; i < 20; ++i) {
        cout << weak_conteneur[i].use_count() << endl;
        if (shared_ptr<ItemSet<long long int>> spt = weak_conteneur[i].lock()) {
            cout << spt->GetName() << " " << spt->GetValue() << endl;

        }


    }

}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
