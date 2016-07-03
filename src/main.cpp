#include <QtWidgets/QApplication>
#include <QtQml/QQmlApplicationEngine>

#include "ImageRenderItem.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<ImageRenderItem>("Ultrabot.Core", 1, 0, "ImageRender");

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
