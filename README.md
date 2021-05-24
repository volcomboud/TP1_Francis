# TP1_Francis

CHEAT SHEET 
(aide à la correction)


**Il y a deux tableau de pointeur; suivez le tableau : 	

Machine* ptr_liste_machines[250]{ nullptr };

**Le tableau des « coûts » est fonctionnel mais pas utilisé dans cette version du programme.

Ce programme est construit de façon conventionnelle. (Conventionnelle; Conventionnelle, enfin je crois) L’action cette fois ci se déroule principalement dans le « Main». Les classes sont quand à elle créé à l’aide d’un fichier de déclaration (*.hpp) && un fichier de définitions (*.cpp).

Main() : 
	  La fonction « main() » est le chef d’orchestre du programme. Cette classe appelle les différents « menus » && détruits les objets créés dynamiquement « from the heap ».  

Fonctions && Procédures :


int menuAffichage() : Affiche les machines répertorié à l’aide de la procédure 
                      « afficherNomMachine » && retourne le numéro de la machine
                      Sélectionné par l’utilisateur. **ATTENTION la valeur retournée est
                      plus forte que l’index de « un »(+1) pour des raisons d’affichage && 
                       technique.

int menuInitial() : Équivalent au menu principal avec des options sur mesure. Sert à la 
                            première itération du programme.
		     	
int menuPrincipal() : Présente les différentes options du logiciel à l’utilisateur && retourne sa 
                     sélection.

int menuAjouter() : Affichage graphique du menu pour l’ajout des « Coûts » && retourne le 
                    choix de l’utilisateur.

void calculerCompteRendu() : Demande le nombre de jour pour les locations && affiche les 
                              résultats calculés. Le choix de la machine à analyser doit lui   être passer en paramètre. 
                              *ATTENTION le paramètre de l’index passé doit être de (n+1).
void afficherNomMachine() : Déroule && numérote les machines répertorié

void ajouterElement() : Simple « switch case” appelant les différentes fonctions basé sur le 
                       choix utilisateur. (Modification nécessaire pour l’implémentation de la
                       jadis nouvelle « class() » « Machine »)

void coutLocation() : Assistant de création pour « LOCATION »

void coutElectricity() : Assistant de création pour « ELECTRICITÉ »

void coutHydro() : Assistant de création pour « HYDRO » (eau)

void ajouterMachine() : : Assistant de création pour « MACHINE »

void auRevoir() : Affiche message de sortie de programme

void messageErreur() : Affiche message d’erreur

void continuer() : Crée une pause dans le programme. Ce résume lorsque l’utilisateur 
                  enfonce la touche « Entrée »

void cinChecked() : Efface les messages d’erreurs généré par un « cin fail » && vide le buffer.  
                                (Blindage logiciel)

*Les autres fonctions||procédures||Classes sont « self explanatory » && ne nécessite pas, selon moi, d’explications supplémentaires.
