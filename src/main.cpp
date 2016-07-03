#include <QtWidgets/QApplication>
#include <QtQml/QQmlApplicationEngine>

#include "FileCursorItem.h"
#include "ImageRenderItem.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<FileCursorItem>("Ultrabot.Core", 1, 0, "FileCursor");
    qmlRegisterType<ImageRenderItem>("Ultrabot.Core", 1, 0, "ImageRender");

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
