#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <tools/ToolDate.h>
#include <qdebug.h>

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QString &string = ToolDate::getCurrTimeStr();
    qDebug()<<string;
    const QUrl url(QStringLiteral("qrc:/layout/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
            }, Qt::QueuedConnection);
    engine.load(url);
    return QGuiApplication::exec();
}