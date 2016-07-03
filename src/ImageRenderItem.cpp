#include "ImageRenderItem.h"

#include <QtGui/QPainter>

#include <QtCore/QProcess>
#include <QtCore/QDebug>
#include <QtCore/QFileInfo>

ImageRenderItem::ImageRenderItem(QQuickItem * parent)
    : QQuickPaintedItem(parent)
{
}

void ImageRenderItem::paint(QPainter * painter)
{
    painter->drawPixmap(0, 0, pixmap_);
}

QUrl ImageRenderItem::source() const
{
    return source_;
}

void ImageRenderItem::setSource(const QUrl & source)
{
    if (source_ == source)
    {
        return;
    }

    source_ = source;

    const auto filename = source_.toLocalFile();

    path_ = QUrl::fromLocalFile(QFileInfo(filename).absolutePath());

    loadImage(filename);

    emit sourceChanged(source_);
    emit pathChanged(path_);
}

QUrl ImageRenderItem::path() const
{
    return path_;
}

QSize ImageRenderItem::viewportSize() const
{
    return viewport_size_;
}

void ImageRenderItem::setViewportSize(const QSize & viewportSize)
{
    if (viewport_size_ == viewportSize)
    {
        return;
    }

    viewport_size_ = viewportSize;
    emit viewportSizeChanged(viewport_size_);

    fitToView();
}

void ImageRenderItem::fitToView()
{
    if (source_pixmap_.isNull())
    {
        return;
    }

    if (source_pixmap_.width() > source_pixmap_.height())
    {
        pixmap_ = source_pixmap_.scaledToWidth(viewport_size_.width());
    }
    else
    {
        pixmap_ = source_pixmap_.scaledToHeight(viewport_size_.height());
    }

    setWidth(pixmap_.width());
    setHeight(pixmap_.height());
}

void ImageRenderItem::loadImage(const QString & filename)
{
    QByteArray buffer;

    QStringList arguments ;
    arguments << "-c" << "-h" << filename;

    QProcess dcProcess;
    dcProcess.setProgram("dcraw");
    dcProcess.setArguments(arguments);
    QObject::connect(&dcProcess, &QProcess::readyReadStandardOutput, [&dcProcess, &buffer]{

        buffer += dcProcess.readAllStandardOutput();
    });

    dcProcess.start();
    if (dcProcess.waitForFinished())
    {
        source_pixmap_.loadFromData(buffer);
    }

    fitToView();
}
