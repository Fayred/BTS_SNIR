# IOS CISCO

## <u>Connexion sous Linux (via RS232) :</u>

```
$ sudo apt update && sudo apt install minicom
$ dmesg | grep USB # récup du périphérique (exemple : /dev/ttyUSBO)
$ sudo minicom -s # (config port série | vitesse 9600 bauds | port série : /dev/ttyUSB0)
$ sudo minicom
```

## <u>Connexion sous Windows (via RS232) :</u>

Utiliser putty, port série, sélectionner le COM utilisé pour la console repéré dans le gestionnaire de périphérique.

--------------------------------------------------------------------------------------------------------------------------------

## <u>Modes de commande :</u>

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

| Mode                  | Invite de commande                |
| --------------------- | --------------------------------- |
| Utilisateur           | Router >                          |
| Privilégié            | Router #                          |
| Configuration globale | Router (config) #                 |
| Interface             | Router (config-if) #              |
| Ligne                 | Router # Router (config-line) #   |
| Routage               | Router # Router (config-router) # |

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

## <u>Fichiers de configuration :</u>

- "running-config" : configuration courante présent dans la RAM.
- "startup-config" : configuration de sauvegarde présent dans la NVRAM.

## <u>Commandes :</u>

### <u>Commandes de visualisation d'états</u>

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

### <u>Mots de passe</u>

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

#### <u>Exemple pour le port console :</u>

```
Router(config)#line con 0
Router(config-line)#login
Router(config-line)#password mot-de-passe
Router(config-line)#exit
```

#### <u>Exemple pour le port vty (terminal virtuel) :</u>

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

### <u>Configuration des interfaces</u>

#### <u>Interfaces Ethernet</u>

Les interfaces de type Ethernet/IEEE 802.3 peuvent être de type :

- Ethernet (IEEE 802.3)
- Fast Ethernet (IEEE 802.3u)
- Gigabit Ethernet (IEEE 802.3ab ou IEEE 802.3z)
- 10-Gigabit Ethernet (IEEE 802.3ae)

La configuration basique de ces interfaces est très simple, et se résume à ces commandes :

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

#### <u>Interfaces Séries</u>

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

##### <u>Exemple :</u>

```
Router(config)#interface FastEthernet 0/0
Router(config-if)#ip address 192.168.1.1 255.255.255.0
Router(config-if)#no shutdown
```

### <u>Description et bannières de connexion</u>

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

### <u>Noms d'hôtes et résolution de noms</u>

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

### <u>Administrer un switch via Telnet</u>

Afin d’administrer un switch via le réseau par l'intermédiaire d'un terminal virtuel, il faut lui
associer une adresse IP :

```
#conf t
(config)#Interface Vlan 1
(config-if)#ip address adresse_ip masque_reseau
(config-if)#no shut
(config-if)#end
```

### <u>Routage Inter-Vlan</u>

#### <u>Configuration des switchs</u>

Sur les switchs, il faut créer les VLAN et affecter les ports connectés aux VLAN choisis. Il faut aussi
configurer les ports sur lesquels circulent les différents VLAN en « trunk ».



Création du VLAN portant le numéro 2 et le nom 2 :

```
Switch1(config)#vlan 2
Switch1(config-vlan)#name VLAN2
Switch1(config-vlan)#exit
Switch1(config)#
```

Affectation du VLAN portant le numéro 2 au port Fa0/2 du switch :

```
Switch(config)#interface fastEthernet 0/2
Switch(config-if)#switchport access vlan 2
Switch(config-if)#exit
Switch(config)#
```

Affectation du VLAN portant le numéro 2 aux ports Fa0/10 à Fa0/12 du switch :

```
Switch1(config)#interface range fastEthernet 0/10-12
Switch1(config-if)#switchport mode access
Switch1(config-if)#switchport access vlan 2
Switch1(config-if)#exit
Switch1(config)#
```

Configuration du port Fa0/1 du switch en « trunk » :

```
Switch(config)#interface fastEthernet 0/1
Switch(config-if)#switchport mode trunk
Switch(config-if)#switchport trunk allowed vlan 1,2
Switch(config-if)#exit
Switch(config)#
```

#### <u>Configuration des routeurs</u>

Sur le routeur (connecté à l'un des switchs), il faut créer autant de sous-interfaces qu'il y a de
VLAN sur le port connecté (fa0/0 dans l'exemple ci-dessous).



Création et configuration de 3 sous-interfaces ( fa0/0.1 , fa0/0.2 et fa0/0.3 ) associées
respectivement aux VLAN portant les numéros 1 , 2 et 3 :

```
Router(config)#interface fastethernet 0/0
Router(config-if)#no shutdown
Router(config-if)#interface fastethernet 0/0.1
Router(config-subif)#encapsulation dot1q 1
Router(config-subif)#ip address 192.168.1.1 255.255.255.0
Router(config-if)#interface fastethernet 0/0.2
Router(config-subif)#encapsulation dot1q 2
Router(config-subif)#ip address 192.168.5.1 255.255.255.0
Router(config-if)#interface fastethernet 0/0.3
Router(config-subif)#encapsulation dot1q 3
Router(config-subif)#ip address 192.168.7.1 255.255.255.0
Router(config-subif)#end
```

### <u>Routage Statique et Dynamique</u>

La commande permettant d'ajouter une route statique vers le réseau 192.168.3.0 via le routeur
10.0.0.2 est la suivante :

```
Router(config)#ip route 192.168.3.0 255.255.255.0 10.0.0.2
```

La commande permettant d'ajouter une route par défaut via le routeur 10.0.0.1 est la suivante :

```
Router(config)#ip route 0.0.0.0 0.0.0.0 10.0.0.2
```

Dans le cas d’un routage via le protocole RIP, les commandes à saisir pour un routeur R1 connecté
à trois réseaux dont les adresses sont 192.168.1.0, 10.0.0.0, 20.0.0.0 sont:

```
R1(config)#router rip
R1(config-router)#version 2
R1(config-router)#network 192.168.1.0
R1(config-router)#network 10.0.0.0
R1(config-router)#network 20.0.0.0
R1(config-router)#end
```

Dans le cas d’un routage via le protocole RIP, les commandes à saisir pour un routeur
directement connecté aux réseaux 192.168.10.0, 192.168.11.0 et 10.0.10.0 sont :

```
Router(config)#router ospf 1
Router(config-router)#network 192.168.10.0 0.0.0.255 area 0
Router(config-router)#network 192.168.11.0 0.0.0.255 area 0
Router(config-router)#network 10.0.10.0 0.0.0.255 area 0
Router(config-router)#end
```
