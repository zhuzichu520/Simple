#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <tools/ToolDate.h>
#include <base/BaseActivity.h>
#include <frameless/WindowFramelessHelper.h>
#include <QQuickStyle>
#include <qdebug.h>

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
    QQuickStyle::setStyle("Material");
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QString &string = ToolDate::getCurrTimeStr();
    qDebug()<<string;
    const QUrl url(QStringLiteral("qrc:/base/Application.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    qmlRegisterType<WindowFramelessHelper>("QtShark.Window", 1, 0, "FramelessHelper");
    engine.load(url);
    return QGuiApplication::exec();
}
