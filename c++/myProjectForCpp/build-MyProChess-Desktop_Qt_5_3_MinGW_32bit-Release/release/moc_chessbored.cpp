/****************************************************************************
** Meta object code from reading C++ file 'chessbored.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyProChess/chessbored.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chessbored.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_chessBored_t {
    QByteArrayData data[8];
    char stringdata[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_chessBored_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_chessBored_t qt_meta_stringdata_chessBored = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 14),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 10),
QT_MOC_LITERAL(4, 38, 7),
QT_MOC_LITERAL(5, 46, 1),
QT_MOC_LITERAL(6, 48, 15),
QT_MOC_LITERAL(7, 64, 12)
    },
    "chessBored\0backToGameMenu\0\0chessPress\0"
    "gameEnd\0e\0backMenuClicked\0chessPressDo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chessBored[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    1,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void chessBored::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        chessBored *_t = static_cast<chessBored *>(_o);
        switch (_id) {
        case 0: _t->backToGameMenu(); break;
        case 1: _t->chessPress(); break;
        case 2: _t->gameEnd((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->backMenuClicked(); break;
        case 4: _t->chessPressDo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (chessBored::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chessBored::backToGameMenu)) {
                *result = 0;
            }
        }
        {
            typedef void (chessBored::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chessBored::chessPress)) {
                *result = 1;
            }
        }
        {
            typedef void (chessBored::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chessBored::gameEnd)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject chessBored::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_chessBored.data,
      qt_meta_data_chessBored,  qt_static_metacall, 0, 0}
};


const QMetaObject *chessBored::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chessBored::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_chessBored.stringdata))
        return static_cast<void*>(const_cast< chessBored*>(this));
    return QWidget::qt_metacast(_clname);
}

int chessBored::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void chessBored::backToGameMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void chessBored::chessPress()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void chessBored::gameEnd(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
