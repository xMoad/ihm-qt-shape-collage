#ifndef TOOLS_H
#define TOOLS_H

/*!
 * \file tools.h
 * \brief Outils
 * \author Julien JUNG & Thomas WINCKELL
 * \version 1.0
 */
#include <QString>

/*! \class Tools
* \brief Classe contenant des méthodes utiles
*/
class Tools
{
public :
	/*!
    *  \brief Retourne le nom d'un fichier en fonction de son chemin complet
    *  \param path : chemin complet du fichier
    *  \return Retourne le nom du fichier
    */
    static QString getFileNameFromPath(QString path);
};

#endif // TOOLS_H
