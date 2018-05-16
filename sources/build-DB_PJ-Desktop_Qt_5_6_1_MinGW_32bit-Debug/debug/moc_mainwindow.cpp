/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DB_PJ/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[419];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "ReceiveRefresh"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "reset"
QT_MOC_LITERAL(4, 33, 17), // "HostButtonPressed"
QT_MOC_LITERAL(5, 51, 18), // "LoginButtonPressed"
QT_MOC_LITERAL(6, 70, 19), // "LogoutButtonPressed"
QT_MOC_LITERAL(7, 90, 23), // "SearchUserButtonPressed"
QT_MOC_LITERAL(8, 114, 27), // "ProblemsSearchButtonPressed"
QT_MOC_LITERAL(9, 142, 25), // "StatusSearchButtonPressed"
QT_MOC_LITERAL(10, 168, 28), // "AdminSearchUserButtonPressed"
QT_MOC_LITERAL(11, 197, 16), // "OrzButtonPressed"
QT_MOC_LITERAL(12, 214, 30), // "EditProfileSubmitButtonPressed"
QT_MOC_LITERAL(13, 245, 27), // "EditUserSubmitButtonPressed"
QT_MOC_LITERAL(14, 273, 30), // "EditProblemSubmitButtonPressed"
QT_MOC_LITERAL(15, 304, 20), // "RankListTabelClicked"
QT_MOC_LITERAL(16, 325, 5), // "index"
QT_MOC_LITERAL(17, 331, 20), // "ProblemsTabelClicked"
QT_MOC_LITERAL(18, 352, 18), // "StatusTabelClicked"
QT_MOC_LITERAL(19, 371, 23), // "EditProblemTabelClicked"
QT_MOC_LITERAL(20, 395, 23) // "AddProblemButtonPressed"

    },
    "MainWindow\0ReceiveRefresh\0\0reset\0"
    "HostButtonPressed\0LoginButtonPressed\0"
    "LogoutButtonPressed\0SearchUserButtonPressed\0"
    "ProblemsSearchButtonPressed\0"
    "StatusSearchButtonPressed\0"
    "AdminSearchUserButtonPressed\0"
    "OrzButtonPressed\0EditProfileSubmitButtonPressed\0"
    "EditUserSubmitButtonPressed\0"
    "EditProblemSubmitButtonPressed\0"
    "RankListTabelClicked\0index\0"
    "ProblemsTabelClicked\0StatusTabelClicked\0"
    "EditProblemTabelClicked\0AddProblemButtonPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x08 /* Private */,
       4,    0,  102,    2, 0x08 /* Private */,
       5,    0,  103,    2, 0x08 /* Private */,
       6,    0,  104,    2, 0x08 /* Private */,
       7,    0,  105,    2, 0x08 /* Private */,
       8,    0,  106,    2, 0x08 /* Private */,
       9,    0,  107,    2, 0x08 /* Private */,
      10,    0,  108,    2, 0x08 /* Private */,
      11,    0,  109,    2, 0x08 /* Private */,
      12,    0,  110,    2, 0x08 /* Private */,
      13,    0,  111,    2, 0x08 /* Private */,
      14,    0,  112,    2, 0x08 /* Private */,
      15,    1,  113,    2, 0x08 /* Private */,
      17,    1,  116,    2, 0x08 /* Private */,
      18,    1,  119,    2, 0x08 /* Private */,
      19,    1,  122,    2, 0x08 /* Private */,
      20,    0,  125,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   16,
    QMetaType::Void, QMetaType::QModelIndex,   16,
    QMetaType::Void, QMetaType::QModelIndex,   16,
    QMetaType::Void, QMetaType::QModelIndex,   16,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReceiveRefresh((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->HostButtonPressed(); break;
        case 2: _t->LoginButtonPressed(); break;
        case 3: _t->LogoutButtonPressed(); break;
        case 4: _t->SearchUserButtonPressed(); break;
        case 5: _t->ProblemsSearchButtonPressed(); break;
        case 6: _t->StatusSearchButtonPressed(); break;
        case 7: _t->AdminSearchUserButtonPressed(); break;
        case 8: _t->OrzButtonPressed(); break;
        case 9: _t->EditProfileSubmitButtonPressed(); break;
        case 10: _t->EditUserSubmitButtonPressed(); break;
        case 11: _t->EditProblemSubmitButtonPressed(); break;
        case 12: _t->RankListTabelClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 13: _t->ProblemsTabelClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 14: _t->StatusTabelClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 15: _t->EditProblemTabelClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 16: _t->AddProblemButtonPressed(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
