#include "qtquick2controlsapplicationviewer.h"
#include "downloader.h"


#include <QQmlEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QQmlError>
#include <QQuickItem>
#include <QQmlComponent>
#include <QDateTime>
#include <QFile>


int main(int argc, char *argv[])
{
    Application app(argc, argv);
    /*
    QQmlEngine engine;
    engine.rootContext()->setContextProperty("d", &d);
    QQmlComponent component(&engine, QUrl::fromLocalFile("/Users/tmaniaci/Documents/qt-progs/wroom3/qml/wroom3/main.qml"));
    component.create();
    */

    Downloader d;
    d.doDownload();

    /*
    QQuickView view;
    view.rootContext()->setContextProperty("currentDateTime", QDateTime::currentDateTime());
    view.setSource(QUrl::fromLocalFile("/Users/tmaniaci/Documents/qt-progs/wroom3/qml/wroom3/main.qml"));
    view.show();
    */

    QtQuick2ControlsApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/wroom3/main.qml"));
    viewer.show();

    return app.exec();
}
