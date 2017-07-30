# fuArchiver 
Simple programme d'archivation de la même façon que ZIP, RAR, ou TAR.

Attention il n'y a pas de compression des données ! (la taille de l'archive est égale à la somme de la taille des fichiers)

# Utilisation
Avant de pouvoir l'utiliser ouvrez un terminal et tapez la commande **make** pour compiler les sources.

Basiquement le programme marche comme TAR pour la compression comme pour la décompression, voici comment l'utiliser:

**Compression**
./archiver [Nom de l'archive] [fichier ou dossier] [autre fichier ou autre dossier] [...]

Attention à ne pas tenter de compresser le dossier dans lequel vous vous trouvez sinon le logiciel va tenter de copier l'archive en la remplissant résultat boucleinf et le logiciel plante :)

![exemple du logiciel en fonctionnement](https://image.prntscr.com/image/us70p62JSXuP_tPmvryt_g.png)
