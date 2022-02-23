# IOS CISCO

## Connexion sous Linux :
```
$ sudo apt update && sudo apt install minicom
$ dmesg | grep USB # récup du périphérique (exemple : /dev/ttyUSBO)
$ sudo minicom -s # (config port série | vitesse 9600 bauds | port série : /dev/ttyUSB0)
$ sudo minicom
```

## Connexion sous Windows :
Utiliser putty, port série, sélectionner le COM utilisé pour la console repéré dans le gestionnaire de périphérique.

--------------------------------------------------------------------------------------------------------------------------------

## Modes de commande :

- **Mode utilisateur** : Mode lecture qui permet à l'utilisateur de consulter des informations sur le
routeur, mais ne lui permet pas d'effectuer des modifications. Dans ce mode, on ne dispose que
de commandes de visualisation d’état sur le fonctionnement du routeur. C’est dans ce mode que
l’on arrive lorsque l’on se connecte au routeur.

- **Mode privilégié** : Mode lecture avec pouvoir. On dispose d’une panoplie complète de
commandes pour visualiser l’état de fonctionnement du routeur, ainsi que pour importer/exporter
et sauvegarder des fichiers de configuration et des images d’IOS.

- **Mode de configuration globale** : Ce mode permet d’utiliser toutes les commandes de
configuration ayant une portée globale à tout le routeur.

- **Modes de configuration spécifiques** : On ne dispose que dans chaque mode spécifique des
commandes ayant une portée localisée au composant du routeur spécifié par ce mode.

- **Mode SETUP** : Mode affichant un dialogue interactif, grâce auquel l'utilisateur néophyte peut
créer une configuration élémentaire initiale.

- **Mode RXBoot** : Mode de maintenance permettant notamment de récupérer des mots de passe
perdus.

| Mode                   | Invite de commande                |
|------------------------|-----------------------------------|
| Utilisateur            | Router >                          |
| Privilégié             | Router #                          |
| Configuration globale  | Router (config) #                 |
| Interface              | Router (config-if) #              |
| Ligne                  | Router # Router (config-line) #   |
| Routage                | Router # Router (config-router) # |

Les commandes à utiliser pour passer dans un mode de configuration spécifique sont les suivantes :

- ``line {type} {numéro}`` <br>
**Mode de configuration globale** <br>
Permet de passer dans le mode de configuration d’une ligne

- ``interface {type} {numéro}`` <br>
**Mode de configuration globale** <br>
Permet de passer dans le mode de configuration d’interface

- ``router {protocole} [option]`` <br>
**Mode de configuration globale** <br>
Permet de passer dans le mode de configuration du routeur

Pour les lignes et les interfaces, la numérotation commence à 0.

## Fichiers de configuration :

- "running-config" : configuration courante présent dans la RAM.
- "startup-config" : configuration de sauvegarde présent dans la NVRAM.

## Commandes :

### Commandes de visualisation d'états

- ``show running-config`` : Affiche le fichier de la configuration active.
- ``show startup-config`` : Affiche le fichier de la configuration de sauvegarde.
- ``show version`` : Affiche la configuration matérielle système, la version d’IOS, le nom et la source
de l'image IOS d'amorçage, ainsi que la valeur du registre de configuration.
- ``show processes`` : Affiche des informations sur les processus actifs.
- ``show memory`` : Affiche des statistiques sur la mémoire du routeur, y compris sur la mémoire disponible.
- ``show stacks`` : Contrôle l'utilisation de la pile par les processus et les routines.
- ``show buffers`` : Fournit des statistiques sur les mémoires tampon des interfaces du routeur.
- ``show arp`` : Affiche les entrées ARP connues.
- ``clear arp`` : Vide les entrées dynamiques de la table ARP.
- ``show hosts`` : Affiche la table de résolution de noms.
- ``show flash`` : Affiche des informations sur la mémoire Flash, telles que la quantité d’espace libre
et le nom des fichiers présents dans cette mémoire.
- ``show interfaces [{type} {numéro}]`` : Affiche les informations de configuration ainsi que des
statistiques de trafic pour chaque interface configurée sur le routeur (couches 2 et 3).
- ``show controllers [{type} {numéro}]`` : Affiche les informations de couche 1 des interfaces.
- ``show ip interface [{type} {numéro}] [brief]`` : Affiche les informations IP pour les
interfaces
- ``clear counters [{type} {numéro}]`` : Permet de mettre à zéro toutes les statistiques des
interfaces du routeur.
- ``show ip route`` : Affiche la table de routage IP.
- ``show protocols`` : Affiche le nom et l’état de tous les protocoles configurés de couche 3.
- ``show ip protocols`` : Affiche les valeurs des compteurs de routage et les informations de réseau
associées à l'ensemble du routeur. Cette commande nous indique les différents réseaux avec
lesquels le protocole de routage est configuré pour communiquer, ainsi que la distance
administrative de ce dernier.
- ``show sessions`` : Affiche la liste des sessions en cours.
- ``show users`` : Affiche la liste des utilisateurs actuellement connectés au routeur.
- ``show clock`` : Affiche la date et l’heure actuelle.
- ``show history`` : Affiche la liste des commandes en mémoire.

### Mots de passe

On peut protéger notre système à l’aide de mots de passe pour en restreindre l’accès. Une
protection par mot de passe peut être installée pour chaque ligne ainsi que sur l’accès au mode
privilégié.
Pour configurer une protection par mot de passe sur une ligne, il faut utiliser les commandes
suivantes :

- ``line {console | aux | vty} {{numéro} | {premier} {dernier}}`` <br>
**Mode de configuration globale** <br>
Permet de passer dans le mode de configuration de la ou des lignes voulues
Il est possible d’accéder à plusieurs lignes en même temps. Pour cela, il suffit de préciser non
pas le numéro mais la plage de numéros. Par exemple, pour accéder directement dans le mode
de configuration des 5 lignes VTY, il suffit d’utiliser la commande line vty 0 4

- ``password {mot de passe}`` <br>
**Mode de configuration de ligne** <br>
Permet de spécifier le mot de passe pour la ligne courante
Le mot de passe est écrit par défaut en clair dans le fichier de configuration

- ``login`` <br>
**Mode de configuration de ligne** <br>
Précise qu’aucun login ne sera demandé lors de la connexion
Cette commande ne peut être utilisée que si un mot de passe est déjà configuré sur la ligne.

#### Exemple pour le port console :

```
Router(config)#line con 0
Router(config-line)#login
Router(config-line)#password mot-de-passe
Router(config-line)#exit
```
#### Exemple pour le port vty (terminal virtuel) :

```
Router(config)#line vty 0 4
Router(config-line)#login
Router(config-line)#password mot-de-passe
Router(config-line)#exit
```

On peut aussi restreindre l’accès au mode privilégié en utilisant au moins une de ces commandes :

- ``enable password {mot de passe}`` <br>
**Mode de configuration globale**<br>
Le mot de passe est écrit en clair dans le fichier de configuration

- ``enable secret {mot de passe}`` <br>
**Mode de configuration globale**<br>
Le mot de passe est crypté dans le fichier de configuration en utilisant l’algorithme MD5.
Cette commande est prioritaire par rapport à enable password si elles sont toutes deux
configurées

Malheureusement, tous les mots de passe, à l’exception du enable secret, sont écrits en clair dans le
fichier de configuration.
Ceci implique une plausible faille de sécurité (sauvegarde d’un fichier de configuration sur un serveur
TFTP non sécurisé, etc.).
Pour y remédier, il faut utiliser la commande service password-encryption depuis le mode de
configuration globale.

### Configuration des interfaces

#### Interfaces Ethernet

Les interfaces de type Ethernet/IEEE 802.3 peuvent être de type :

- Ethernet (IEEE 802.3)
- Fast Ethernet (IEEE 802.3u)
- Gigabit Ethernet (IEEE 802.3ab ou IEEE 802.3z)
- 10-Gigabit Ethernet (IEEE 802.3ae)

- ``interface {Ethernet | FastEthernet} {numéro | slot/numéro}`` <br>
**Mode de configuration globale** <br>
Permet de passer dans le mode de configuration d’interface

- ``ip address {IP} {masque} [secondary]`` <br>
**Mode de configuration d’interface** <br>
Permet d’attribuer une adresse IP à cette interface
Le paramètre secondary précise qu’il s’agit d’une adresse IP secondaire

- ``[no] keepalive`` <br>
**Mode de configuration d’interface** <br>
Active/désactive les "keep alive" sur l’interface
Utile pour rendre une interface opérationnelle sans avoir à brancher un média

- ``[no] shutdown`` <br>
**Mode de configuration d’interface** <br>
Active/désactive administrativement l’interface

#### Interfaces Séries

Les interfaces série sont classifiées en fonction de leur mode de transmission qui peut être :

- Synchrone
- Asynchrone
- Synchrone/asynchrone (par défaut en mode synchrone)

Les commandes utilisées par ces interfaces sont les suivantes :

- ```interface {serial | async} {numéro | slot/numéro}``` <br>
**Mode de configuration globale** <br>
Permet de passer dans le mode de configuration d’interface
Le mot clé async n’est utilisable que pour les interfaces de type asynchrone

- ``clock rate {vitesse}`` <br>
**Mode de configuration d’interface** <br>
Spécifie la vitesse de fonctionnement de la liaison WAN
A faire uniquement sur une interface ETCD
Le paramètre vitesse est exprimé en bits par seconde

- ``ip address {IP} {masque} [secondary]`` <br>
**Mode de configuration d’interface** <br>
Permet d’attribuer une adresse IP à cette interface
Le paramètre secondary précise qu’il s’agit d’une adresse IP secondaire

- ``[no] shutdown`` <br>
**Mode de configuration d’interface** <br>
Active/désactive administrativement l’interface

##### Exemple :

```
Router(config)#interface FastEthernet 0/0
Router(config-if)#ip address 192.168.1.1 255.255.255.0
Router(config-if)#no shutdown
```

### Description et bannières de connexion

On peut indiquer une description pour chaque interface du routeur. Ceci est très utile pour ceux
qui seraient censés travailler sur ce routeur et qui ne connaissent pas forcément à quoi peut être
attribuée une interface.

Pour cela, il faut utiliser la commande :

- ``description {texte}`` <br>
**Mode de configuration d’interface** <br>
Le texte de description ne peut excéder 80 caractères sur les anciens modèles
(exemple : Routeur 2500) ou 240 caractères sur les modèles plus récents (exemple : Routeur
2600).
Cette description est visible en utilisant la commande show interfaces.


La bannière de connexion s’affiche lors de la connexion d’un terminal à une ligne et permet de
transmettre un message aux utilisateurs du routeur.

Pour définir cette bannière, il faut utiliser la commande :

- ``banner motd {caractère d’encapsulation} {message} {caractère d’encapsulation}`` <br>
**Mode de configuration globale** <br>
Le message doit être encapsulé entre un caractère quelconque qui ne doit pas exister dans le
message.

### Noms d'hôtes et résolution de noms

 - ``hostname {nom}`` <br> 
**Mode de configuration globale** <br>
Attribution du nom d’hôte du routeur
Ce nom est affiché par l’invite de commandes
La valeur par défaut est "Router"

- ``[no] ip domain-lookup`` <br>
**Mode de configuration globale** <br>
Active/désactive la résolution dynamique de noms (DNS)

- ``ip name-server {DNS1} [{DNS2}...]`` <br>
**Mode de configuration globale** <br>
Permet de spécifier le ou les serveurs DNS avec lesquels nous effectuerons les résolutions
d’adresses
On peut préciser jusqu’à 6 serveurs DNS différents

- ``ip domain-name {préfixe}`` <br>
**Mode de configuration globale** <br>
Précise le préfixe DNS par défaut à utiliser pour la résolution d’adresses dynamique

### Administrer un switch via Telnet

Afin d’administrer un switch via le réseau par l'intermédiaire d'un terminal virtuel, il faut lui
associer une adresse IP :

```
#conf t
(config)#Interface Vlan 1
(config-if)#ip address adresse_ip masque_reseau
(config-if)#no shut
(config-if)#end
```
