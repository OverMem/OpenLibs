<!-- Required extensions: pymdown.betterem, pymdown.tilde, pymdown.emoji, pymdown.tasklist, pymdown.superfences -->

<div style=text-align:center><img src=".Other/Logo.svg" title="Logo OpenLibs" alt="Logo OpenLibs"></div>

<h2 style="color:#0761b2">Description</h2>

OpenLibs est un framework intégrant des bibliothèques simples mais utiles, 
en C++.

<h2 style="color:#0761b2">Bibliothèques</h2>

Les bibliothèques composant le framework sont: 

* BinRes: Accéder et lire des ressources binaires
* MArgs: Accéder aux arguments du main() plus simplement
* StrTime: Repésenter un temps en ``` std::string ```
* Utils: Quelques fonctions utiles
* Types: Définit des types
* File: Lire et écrire dans des fichiers de logs et de config
* DataBase: Lire et écrire dans une base de données SQLite3
* OCL: Bibliothèque cryptographique

<h2 style="color:#0761b2">Description des bibliothèques</h2>
<h3 style="color: #045576">BinRes</h3>

BinRes permet de lire et de gérer des ressources au format binaire.
Elle utilise des pointeurs pour l'accés à celles-ci. Mais ce n'est pas 
nécessaire de les connaître en profondeur pour pouvoir utiliser cette lib.

<h3 style="color: #045576">MArgs</h3>

MArgs charge et permet de lire les arguments du main dans une 
``` std::string ```.

<h3 style="color: #045576">StrTime</h3>

StrTime récupère un timestamp et utilise ``` strftime() ``` pour le 
représenter dans le format français ou anglais.

<h3 style="color: #045576">Utils</h3>

Utils est une bibliothèque simple pour, par exemple, convertir un 
charactère en valeur ASCII.

<h3 style="color: #045576">Types</h3>

Types utilise des typedefs, pour créer des noms de types fixés 
(``` BYTE ``` => ``` uint8_t ```), des opérations sur les bits et des 
conversions (``` std::string ``` <=> types) afin d'utiliser au mieux les 
types de variables.

<h3 style="color: #045576">File</h3>

File accède à un fichier de config ou de logs et permet de le lire ainsi 
que d'y écrire.

<h3 style="color: #045576">DataBase</h3>

DataBase utilise SQLite3 pour envoyer des commandes à une base de données 
(Insert, Select, ...) le plus simplement possible.

<h3 style="color: #045576">OCL</h3>

OCL (OPEN Cryptographic Library) inclut ces algorithmes:

* SHA256
* Blowfish
* RSA
* CRC (Ansi, CCITT, Ethernet)
* Générateur aléatoire (Entropie => SHA256 => nombres pseudo-aléatoires 
cryptographiques de 32 bits (DWORD))


<h2 style="color:#0761b2">Philosophie de programmation</h2>

OpenLibs a été codé en respectant l'OPEN Standard Code (une philosophie de 
programmation inventée par moi) qui est décrite dans le fichier ${LIBS}/
share/OPEN/OSC.pdf, après installation.


<h2 style="color:#0761b2">Compilation et installation</h2>
<h3 style="color: #045576">Dépendances</h3>

Les dépendances d'OpenLibs sont fournies dans le dossier .Deps (à 
l'exception d'OpenScripts). Pour ceux qui les auraient peut-être déjà 
installées, les voici: <br/>


| Nom         | Version      | Nom de version | Utilité  |
|:-----------:|:------------:|:--------------:|:--------:|
| GMP         | v6.1.2       | Release        | RSA      |
| SFML        | v2.5.1       | Release        | Random   |
| SQLite      | 202002271621 | Snapshot       | DataBase |
| OpenScripts | v1.0         | Release        | Makefile |

Pour télécharger OpenScripts, c'est sur le dépôt du même nom dans [mon Github](https://github.com/RemsPrgm/).

<h3 style="color: #045576">Commandes</h3>

Pour compiler et installer OpenLibs, vous devez éxécuter ces commandes, en 
shell:


```bash
export LIBS={install-directory}
make
make install
```
Où:

* {install-directory}: Le répertoire d'installation (Ex: export LIBS=/usr)
