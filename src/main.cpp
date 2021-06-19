#include <QGuiApplication>
#include <QFont>
#include <application/Application.h>

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
    QGuiApplication app(argc, argv);
    QFont font;
    font.setFamily("Microsoft YaHei");
    QGuiApplication::setFont(font);
    QQmlApplicationEngine engine;
    APP->init(argc, argv);
    engine.load(QUrl("qrc:/layout/ActivityMain.qml"));
    return QGuiApplication::exec();
}
