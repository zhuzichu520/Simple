#include <QGuiApplication>
#include <application/Application.h>

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    APP->init();
    engine.load(QUrl("qrc:/base/Application.qml"));
    return QGuiApplication::exec();
}
