/****************************************************************************
** Meta object code from reading C++ file 'mainwindow_menu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow_menu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow_menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_menu_t {
    QByteArrayData data[19];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_menu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_menu_t qt_meta_stringdata_MainWindow_menu = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MainWindow_menu"
QT_MOC_LITERAL(1, 16, 10), // "recUsrname"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "name"
QT_MOC_LITERAL(4, 33, 7), // "display"
QT_MOC_LITERAL(5, 41, 21), // "on_ButtonSure_clicked"
QT_MOC_LITERAL(6, 63, 23), // "on_ButtonCancel_clicked"
QT_MOC_LITERAL(7, 87, 9), // "qtimeSlot"
QT_MOC_LITERAL(8, 97, 6), // "figure"
QT_MOC_LITERAL(9, 104, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(10, 136, 4), // "arg1"
QT_MOC_LITERAL(11, 141, 25), // "on_ButtonTerminal_clicked"
QT_MOC_LITERAL(12, 167, 4), // "init"
QT_MOC_LITERAL(13, 172, 12), // "SendTerminal"
QT_MOC_LITERAL(14, 185, 9), // "SendStart"
QT_MOC_LITERAL(15, 195, 22), // "on_ButtonStart_clicked"
QT_MOC_LITERAL(16, 218, 20), // "on_ButtonYes_clicked"
QT_MOC_LITERAL(17, 239, 24), // "on_ButtonDisplay_clicked"
QT_MOC_LITERAL(18, 264, 16) // "on_timer_timeout"

    },
    "MainWindow_menu\0recUsrname\0\0name\0"
    "display\0on_ButtonSure_clicked\0"
    "on_ButtonCancel_clicked\0qtimeSlot\0"
    "figure\0on_comboBox_currentIndexChanged\0"
    "arg1\0on_ButtonTerminal_clicked\0init\0"
    "SendTerminal\0SendStart\0on_ButtonStart_clicked\0"
    "on_ButtonYes_clicked\0on_ButtonDisplay_clicked\0"
    "on_timer_timeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow_menu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x08 /* Private */,
       4,    0,   92,    2, 0x08 /* Private */,
       5,    0,   93,    2, 0x08 /* Private */,
       6,    0,   94,    2, 0x08 /* Private */,
       7,    0,   95,    2, 0x08 /* Private */,
       8,    0,   96,    2, 0x08 /* Private */,
       9,    1,   97,    2, 0x08 /* Private */,
      11,    0,  100,    2, 0x08 /* Private */,
      12,    0,  101,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    0,  103,    2, 0x08 /* Private */,
      15,    0,  104,    2, 0x08 /* Private */,
      16,    0,  105,    2, 0x08 /* Private */,
      17,    0,  106,    2, 0x08 /* Private */,
      18,    0,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow_menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow_menu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recUsrname((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->display(); break;
        case 2: _t->on_ButtonSure_clicked(); break;
        case 3: _t->on_ButtonCancel_clicked(); break;
        case 4: _t->qtimeSlot(); break;
        case 5: _t->figure(); break;
        case 6: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_ButtonTerminal_clicked(); break;
        case 8: _t->init(); break;
        case 9: _t->SendTerminal(); break;
        case 10: _t->SendStart(); break;
        case 11: _t->on_ButtonStart_clicked(); break;
        case 12: _t->on_ButtonYes_clicked(); break;
        case 13: _t->on_ButtonDisplay_clicked(); break;
        case 14: _t->on_timer_timeout(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow_menu::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow_menu.data,
    qt_meta_data_MainWindow_menu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow_menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow_menu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow_menu.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow_menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
