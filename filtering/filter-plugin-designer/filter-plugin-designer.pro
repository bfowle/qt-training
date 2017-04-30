QT          += widgets uiplugin
CONFIG      += plugin
CONFIG      += c++14

TEMPLATE    = lib
DEFINES     += FILTERPLUGINDESIGNER_LIBRARY
TARGET      = $$qtLibraryTarget($$TARGET)
INSTALLS    += target

windows {
    target.path = $$(QTDIR)/../../Tools/QtCreator/bin/plugins/designer

    debug:target_lib.files = $$OUT_PWD/debug/$${TARGET}.lib
    release:target_lib.files = $$OUT_PWD/release/$${TARGET}.lib
    target_lib.path = $$(QTDIR)/../../Tools/QtCreator/bin/plugins/designer

    INSTALLS += target_lib

    INCLUDEPATH += $$(OPENCV_HOME)/../../include

    LIBS += -L$$(OPENCV_HOME)/lib \
        -lopencv_core2413 \
        -lopencv_imgproc2413
}

linux {
    target.path = $$(QTDIR)/../../Tools/QtCreator/lib/Qt/plugins/designer/

    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}

macx {
    target.path = "$$(QTDIR)/../../QtCreator.app/Contents/PlugIns/designer/"
    target_lib.files = $$OUT_PWD/lib$${TARGET}.dylib
    target_lib.path = "$$(QTDIR)/../../QtCreator.app/Contents/PlugIns/designer/"

    INSTALLS += target_lib

    INCLUDEPATH += /usr/local/Cellar/opencv/2.4.13.2/include/

    LIBS += -L/usr/local/lib \
        -lopencv_core \
        -lopencv_imgproc
}

HEADERS += \
    Filter.h \
    FilterOriginal.h \
    FilterGreyscale.h \
    FilterBlur.h \
    FilterWidget.h \
    filter-plugin-designer_global.h \
    FilterPluginDesigner.h

SOURCES += \
    Filter.cpp \
    FilterOriginal.cpp \
    FilterGreyscale.cpp \
    FilterBlur.cpp \
    FilterWidget.cpp \
    FilterPluginDesigner.cpp

FORMS += \
    FilterWidget.ui

RESOURCES += \
    filter-plugin-designer.qrc
