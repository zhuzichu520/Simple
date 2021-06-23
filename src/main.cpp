#include <QGuiApplication>
#include <application/Application.h>
#include <QFont>
#include <QIcon>

int main(int argc, char *argv[]) {

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
    QGuiApplication app(argc, argv);
//    QGuiApplication::setFont(QFont("Microsoft YaHei"));
    QGuiApplication::setWindowIcon(QIcon("://favicon.ico"));
    QQmlApplicationEngine engine;
    APP->init(argc, argv);
    engine.load(QUrl("qrc:/layout/ActivityMain.qml"));
    return QGuiApplication::exec();
}
