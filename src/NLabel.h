#ifndef NLABEL_H
#define NLABEL_H

#include <QList>
#include <QFont>
#include <QTimer>
#include <QLabel>
#include <QString>
#include <QWidget>
#include <QStringList>

#include "../Declarations.h"

#if DEBUG_LEVEL > 0
#include <QDebug>
#endif

//------------------------------------------------------------------------------
class NLabel : public QWidget
{
    Q_OBJECT
signals: //------------------------------ Signals: -----------------------------

public: //-------------------------------- Public: -----------------------------
    NLabel(double value, QWidget *parent = 0);

public slots: //----------------------- Public slots: --------------------------
    void    c_setValue(const double value);
    void    c_setValue(int value)                       { this->c_setValue((double)value); }
    void    c_setStyle(const QString &style);
    void    c_setSuffix(const QString &suffix)          { $.suffix = suffix; }
    void    c_setDecimalCount(int count);
    void    c_setSize(int label_width, int label_height);
    void    c_setPos(int x, int y)                      { this->setGeometry(x, y, this->size().width(), this->size().height()); }
    void    c_setAlignment(Qt::Alignment alignment);
    void    c_setFontSize(int font_size);
    void    c_restoreDefaultStyle()                     { this->c_setStyle($.style_prew); }
    void    c_renewValue();
    void    c_setAutoUpdate(bool auto_updare = true);
    bool    c_getAutoUpdateMode()                       { return $.auto_update; }

    QString c_getText()         const                   { return $.text; }
    QString c_getStyle()        const                   { return $.style; }
    int     c_getDecimalCount() const                   { return $.decimal_count; }
    int     c_getFontSize()     const                   { return $.font_size; }
    Qt::Alignment c_getAlignment() const                { return $.alignment; }

private slots: //---------------------- Private slots: -------------------------
    void    p_setText();
    QString p_valuesToText();

private: //------------------------------- Private: ----------------------------

    // Data Types:
    struct _ {
        double          value_sum     = 0.0;
        QString         text          = QString("NLabel");
        QString         suffix        = QString(" °");
        QString         style;
        QString         style_prew;
        int             decimal_count = 5;
        int             font_size     = 16;
        int             interval      = 1000;
        int             value_counter = 0;
        bool            auto_update   = true;
        Qt::Alignment   alignment     = Qt::AlignCenter;
    } $;

    QLabel *_label;

    QTimer *_timer;

}; //--------------------------------------- End -------------------------------

#endif // NLABEL_H
