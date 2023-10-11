/****************************************************************************
** Meta object code from reading C++ file 'MyColorWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MyColorWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyColorWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyColorWidget_t {
    QByteArrayData data[17];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyColorWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyColorWidget_t qt_meta_stringdata_MyColorWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MyColorWidget"
QT_MOC_LITERAL(1, 14, 15), // "ShowTheBestTemp"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 1), // "i"
QT_MOC_LITERAL(4, 33, 11), // "OutPutImage"
QT_MOC_LITERAL(5, 45, 1), // "I"
QT_MOC_LITERAL(6, 47, 10), // "PutBarBack"
QT_MOC_LITERAL(7, 58, 11), // "ShowTempImg"
QT_MOC_LITERAL(8, 70, 11), // "ShowOrigImg"
QT_MOC_LITERAL(9, 82, 5), // "Reset"
QT_MOC_LITERAL(10, 88, 15), // "InitCalculation"
QT_MOC_LITERAL(11, 104, 19), // "ShiftImageWithTempX"
QT_MOC_LITERAL(12, 124, 1), // "x"
QT_MOC_LITERAL(13, 126, 19), // "ShiftImageWithAngle"
QT_MOC_LITERAL(14, 146, 1), // "a"
QT_MOC_LITERAL(15, 148, 18), // "ImplementTmpScheme"
QT_MOC_LITERAL(16, 167, 11) // "OutPutExcel"

    },
    "MyColorWidget\0ShowTheBestTemp\0\0i\0"
    "OutPutImage\0I\0PutBarBack\0ShowTempImg\0"
    "ShowOrigImg\0Reset\0InitCalculation\0"
    "ShiftImageWithTempX\0x\0ShiftImageWithAngle\0"
    "a\0ImplementTmpScheme\0OutPutExcel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyColorWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       6,    1,   75,    2, 0x06 /* Public */,
       7,    1,   78,    2, 0x06 /* Public */,
       8,    1,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   84,    2, 0x0a /* Public */,
      10,    0,   85,    2, 0x0a /* Public */,
      11,    1,   86,    2, 0x0a /* Public */,
      13,    1,   89,    2, 0x0a /* Public */,
      15,    0,   92,    2, 0x0a /* Public */,
      16,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QImage,    5,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QImage,    5,
    QMetaType::Void, QMetaType::QImage,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyColorWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyColorWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowTheBestTemp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->OutPutImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->PutBarBack((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ShowTempImg((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 4: _t->ShowOrigImg((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 5: _t->Reset(); break;
        case 6: _t->InitCalculation(); break;
        case 7: _t->ShiftImageWithTempX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->ShiftImageWithAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->ImplementTmpScheme(); break;
        case 10: _t->OutPutExcel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyColorWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyColorWidget::ShowTheBestTemp)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyColorWidget::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyColorWidget::OutPutImage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyColorWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyColorWidget::PutBarBack)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyColorWidget::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyColorWidget::ShowTempImg)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyColorWidget::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyColorWidget::ShowOrigImg)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyColorWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MyColorWidget.data,
    qt_meta_data_MyColorWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyColorWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyColorWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyColorWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MyColorWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MyColorWidget::ShowTheBestTemp(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyColorWidget::OutPutImage(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyColorWidget::PutBarBack(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyColorWidget::ShowTempImg(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyColorWidget::ShowOrigImg(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
