/****************************************************************************
** Meta object code from reading C++ file 'chessbored.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../chessbored.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chessbored.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_chessBored_t {
    const uint offsetsAndSize[16];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_chessBored_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_chessBored_t qt_meta_stringdata_chessBored = {
    {
QT_MOC_LITERAL(0, 10), // "chessBored"
QT_MOC_LITERAL(11, 14), // "backToGameMenu"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 10), // "chessPress"
QT_MOC_LITERAL(38, 7), // "gameEnd"
QT_MOC_LITERAL(46, 1), // "e"
QT_MOC_LITERAL(48, 15), // "backMenuClicked"
QT_MOC_LITERAL(64, 12) // "chessPressDo"

    },
    "chessBored\0backToGameMenu\0\0chessPress\0"
    "gameEnd\0e\0backMenuClicked\0chessPressDo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chessBored[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    0,   45,    2, 0x06,    2 /* Public */,
       4,    1,   46,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   49,    2, 0x08,    5 /* Private */,
       7,    0,   50,    2, 0x08,    6 /* Private */,

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
        auto *_t = static_cast<chessBored *>(_o);
        (void)_t;
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
        {
            using _t = void (chessBored::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chessBored::backToGameMenu)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (chessBored::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chessBored::chessPress)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (chessBored::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chessBored::gameEnd)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject chessBored::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_chessBored.offsetsAndSize,
    qt_meta_data_chessBored,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_chessBored_t
, QtPrivate::TypeAndForceComplete<chessBored, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *chessBored::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chessBored::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_chessBored.stringdata0))
        return static_cast<void*>(this);
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void chessBored::backToGameMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void chessBored::chessPress()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void chessBored::gameEnd(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
