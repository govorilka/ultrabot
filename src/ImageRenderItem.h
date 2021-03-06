#pragma once

#include <QtGui/QPixmap>
#include <QtQuick/QQuickPaintedItem>

class ImageRenderItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(QSize viewportSize READ viewportSize WRITE setViewportSize NOTIFY viewportSizeChanged)

public:
    explicit ImageRenderItem(QQuickItem * parent = nullptr);

    QUrl source() const;
    void setSource(const QUrl & source);

    QSize viewportSize() const;
    void setViewportSize(const QSize & viewportSize);

public slots:
    void fitToView();

signals:
    void sourceChanged(const QUrl & source);
    void viewportSizeChanged(const QSize & viewportSize);

public: // QQuickPaintedItem
    virtual void paint(QPainter * painter) override;

private:
    void loadImage(const QString & filename);

private:
    QPixmap source_pixmap_;
    QPixmap pixmap_;

    QUrl source_;
    QSize viewport_size_;
};
