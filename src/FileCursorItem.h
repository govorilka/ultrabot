#pragma once

#include <QtQuick/QQuickItem>

class FileCursorItem : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(QUrl path READ path NOTIFY pathChanged)

public:
    FileCursorItem(QQuickItem * parent = nullptr);

    QUrl source() const;
    void setSource(const QUrl & source);

    QUrl path() const;

signals:
    void sourceChanged(const QUrl & source);
    void pathChanged(const QUrl & path);

private:
    QUrl source_;
    QUrl path_;
};
