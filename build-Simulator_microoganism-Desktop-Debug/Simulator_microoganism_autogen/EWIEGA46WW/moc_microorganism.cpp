/****************************************************************************
** Meta object code from reading C++ file 'microorganism.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Simulator_microoganism/microorganism.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'microorganism.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Microorganism_t {
    QByteArrayData data[11];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Microorganism_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Microorganism_t qt_meta_stringdata_Microorganism = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Microorganism"
QT_MOC_LITERAL(1, 14, 12), // "organismBorn"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "organismDied"
QT_MOC_LITERAL(4, 41, 10), // "sendStatus"
QT_MOC_LITERAL(5, 52, 6), // "status"
QT_MOC_LITERAL(6, 59, 8), // "finished"
QT_MOC_LITERAL(7, 68, 3), // "run"
QT_MOC_LITERAL(8, 72, 3), // "die"
QT_MOC_LITERAL(9, 76, 9), // "reproduce"
QT_MOC_LITERAL(10, 86, 15) // "applyAntibiotic"

    },
    "Microorganism\0organismBorn\0\0organismDied\0"
    "sendStatus\0status\0finished\0run\0die\0"
    "reproduce\0applyAntibiotic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Microorganism[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    1,   56,    2, 0x06 /* Public */,
       6,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   60,    2, 0x0a /* Public */,
       8,    0,   61,    2, 0x0a /* Public */,
       9,    0,   62,    2, 0x0a /* Public */,
      10,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Microorganism::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Microorganism *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->organismBorn(); break;
        case 1: _t->organismDied(); break;
        case 2: _t->sendStatus((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->finished(); break;
        case 4: _t->run(); break;
        case 5: _t->die(); break;
        case 6: _t->reproduce(); break;
        case 7: _t->applyAntibiotic(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Microorganism::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Microorganism::organismBorn)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Microorganism::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Microorganism::organismDied)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Microorganism::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Microorganism::sendStatus)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Microorganism::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Microorganism::finished)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Microorganism::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Microorganism.data,
    qt_meta_data_Microorganism,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Microorganism::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Microorganism::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Microorganism.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Microorganism::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Microorganism::organismBorn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Microorganism::organismDied()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Microorganism::sendStatus(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Microorganism::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
