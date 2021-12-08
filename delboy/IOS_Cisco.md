# IOS CISCO
## Modes :
- Mode de configuration de ligne : utilisé pour configurer l'accès par la console, par SSH, par Telnet, ou l'accès AUX.
- Mode de configuration d'interface : utilisé pour configurer l'interface réseau d'un port de commutateur ou d'un routeur.

">" => mode utilisateur

"#" => mode privilégié

## Commandes :

- ? : affiche les commandes
- enable : passe du mode utilisateur au mode privilégié ('>' => '#')
- disable : passe du mode privilégié au mode utilisateur ('#' => '>')
- configure terminal : global mode => Switch(config)#
- configure vlan 1 : mode interface => Switch(config-if)#
- line : passe au mode configuration ligne, suivie du type et du numéro de la ligne de gestion à laquelle on veut accéder
    - console {0..+}
    - FastEthernet 0/1 
- exit ou CTRL+Z : passe au sous-mode plus haut.
- line vty {0..+} {1..+} : limite le nombre de connection en ssh ou telnet
- end ou CTRL+z : passe d'un sous mode au mode d'éxecution normal
- show running-config : affiche la configuration utilisé actuellement
- show startup-config : affiche le contenu actuel de la mémoire nvram
- hostname [nouveau_nom_hote] : change le nom d'hôte (à lancer en mode config terminal).
- password [password] : permet de sécurité le port console avec un mot de passe pour le mode privilégié (login active la fonctionnalité).
