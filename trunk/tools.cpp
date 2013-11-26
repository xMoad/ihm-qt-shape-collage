#include "tools.h"

QString Tools::getFileNameFromPath(QString path)
{
    return path.right(path.count() - path.lastIndexOf("/") - 1);
}
