# IOS CISCO

# Connexion sous Linux :
```
$ sudo apt update && sudo apt install minicom
$ dmesg | grep USB # récup du périphérique (exemple : /dev/ttyUSBO)
$ sudo minicom -s # (config port série | vitesse 9600 bauds | port série : /dev/ttyUSB0)
$ sudo minicom
```

# Connexion sous Windows :
Utiliser putty, port série, sélectionner le COM utilisé pour la console repéré dans le gestionnaire de périphérique.

## Modes :
- Mode de configuration de ligne : utilisé pour configurer l'accès par la console, par SSH, par Telnet, ou l'accès AUX.
- Mode de configuration d'interface : utilisé pour configurer l'interface réseau d'un port de commutateur ou d'un routeur.

">" => mode utilisateur.

"#" => mode privilégié.

## Commandes :

- ? : affiche les commandes
- enable : passe du mode utilisateur au mode privilégié ('>' => '#').
- disable : passe du mode privilégié au mode utilisateur ('#' => '>').
- configure terminal : global mode => Switch(config)#.
- configure vlan 1 : mode interface => Switch(config-if)#.
- line : passe au mode configuration ligne, suivie du type et du numéro de la ligne de gestion à laquelle on veut accéder.
    - console {0..+}
    - FastEthernet 0/1 
- line vty {0..+} {1..+} : limite le nombre de connection en ssh ou telnet.
- exit : passe au sous-mode plus haut.
- end ou CTRL+Z : passe d'un sous mode au mode d'éxecution normal.
- interface vlan {0..+} : mode interface sur une vlan.
- show running-config : affiche la configuration utilisé actuellement.
- show startup-config : affiche le contenu actuel de la mémoire nvram.
- hostname [nouveau_nom_hote] : change le nom d'hôte (à lancer en mode config terminal).
- line console 0 : mode config console/line.
- password [password] : permet de sécuriser le port console avec un mot de passe (login active la fonctionnalité).
- login : enregistre la config (password con)
- enable password [password] : permet de sécuriser le mode privilégié avec un mot de passe (besoin de : line console 0 ).
- enable secret [password] : permet de sécuriser le mode privilégié avec un mot de pass + mdp stocké dans le running-config de mannière hashé. 
- no enable password/secret : suppr les mdp 
- no ip domain-lookup : permet de désactiver la recherche DNS.
- banner motd [message]   : affiche un message de bannière à chaque connexion (MOTD: Message Of The Day ou message du jour).
- banner motd [message] # : on peut utiliser le "#" pour écrire sur plusieurs lignes, ensuite quand on a terminé de rentré le contenu de la bannière il suffit de terminé par "#".
- ip adresse [ip_addr] [masque_de_sous_reseaux] : attribut une adresse ip et un masque de sous-réseau (en mode interface)
- show ip interface brief : affiche la table 
- no shutdown : up une interface
