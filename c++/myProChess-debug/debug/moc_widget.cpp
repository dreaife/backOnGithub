/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MyProChess/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    const uint offsetsAndSize[32];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 6), // "Widget"
QT_MOC_LITERAL(7, 11), // "gameTrigger"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 8), // "QString*"
QT_MOC_LITERAL(29, 1), // "e"
QT_MOC_LITERAL(31, 7), // "success"
QT_MOC_LITERAL(39, 7), // "gameEnd"
QT_MOC_LITERAL(47, 9), // "gameCheck"
QT_MOC_LITERAL(57, 8), // "gameBack"
QT_MOC_LITERAL(66, 9), // "gameStart"
QT_MOC_LITERAL(76, 7), // "gameLev"
QT_MOC_LITERAL(84, 14), // "gameTriggerOne"
QT_MOC_LITERAL(99, 14), // "gameTriggerTwo"
QT_MOC_LITERAL(114, 16), // "gameTriggerThree"
QT_MOC_LITERAL(131, 14), // "gameBackToMenu"
QT_MOC_LITERAL(146, 18) // "gamePlayerListShow"

    },
    "Widget\0gameTrigger\0\0QString*\0e\0success\0"
    "gameEnd\0gameCheck\0gameBack\0gameStart\0"
    "gameLev\0gameTriggerOne\0gameTriggerTwo\0"
    "gameTriggerThree\0gameBackToMenu\0"
    "gamePlayerListShow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   83,    2, 0x0a,    3 /* Public */,
       6,    1,   86,    2, 0x0a,    5 /* Public */,
       7,    0,   89,    2, 0x0a,    7 /* Public */,
       8,    0,   90,    2, 0x0a,    8 /* Public */,
       9,    1,   91,    2, 0x0a,    9 /* Public */,
      11,    0,   94,    2, 0x0a,   11 /* Public */,
      12,    0,   95,    2, 0x0a,   12 /* Public */,
      13,    0,   96,    2, 0x0a,   13 /* Public */,
      14,    0,   97,    2, 0x0a,   14 /* Public */,
      15,    0,   98,    2, 0x0a,   15 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->gameTrigger((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 1: _t->success((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->gameEnd((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->gameCheck(); break;
        case 4: _t->gameBack(); break;
        case 5: _t->gameStart((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 6: _t->gameTriggerOne(); break;
        case 7: _t->gameTriggerTwo(); break;
        case 8: _t->gameTriggerThree(); break;
        case 9: _t->gameBackToMenu(); break;
        case 10: _t->gamePlayerListShow(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget::*)(QString * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::gameTrigger)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.offsetsAndSize,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Widget_t
, QtPrivate::TypeAndForceComplete<Widget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Widget::gameTrigger(QString * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
