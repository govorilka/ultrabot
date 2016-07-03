#include "FileCursorItem.h"

#include <QtCore/QFileInfo>
#include <QtCore/QStandardPaths>

FileCursorItem::FileCursorItem(QQuickItem * parent)
    : QQuickItem(parent)
{
    const auto path = QStandardPaths::locate(QStandardPaths::PicturesLocation, QString(), QStandardPaths::LocateDirectory);
    if (!path.isEmpty())
    {
        path_ = QUrl::fromLocalFile(path);
    }
}

QUrl FileCursorItem::source() const
{
    return source_;
}

void FileCursorItem::setSource(const QUrl & source)
{
    if (source_ != source)
    {
        source_ = source;

        const auto filename = source_.toLocalFile();

        path_ = QUrl::fromLocalFile(QFileInfo(filename).absolutePath());

        emit sourceChanged(source_);
        emit pathChanged(path_);
    }
}

QUrl FileCursorItem::path() const
{
    return path_;
}
