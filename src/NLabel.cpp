#include "NLabel.h"

//------------------------------------------------------------------------------
NLabel::NLabel(double value, QWidget *parent) : QWidget(parent)
{
    _label = new QLabel(this);
    _timer = new QTimer(this);
    connect( _timer,
             &QTimer::timeout,
             this,
             &NLabel::p_setText );

    this->c_setValue(value);
    this->c_setStyle(QString("color:#FFF;background-color:#64dd17;padding:0 10px;border-radius:20px;"));
    this->c_setFontSize(16);
    $.style_prew = $.style;
}
//------------------------------------------------------------------------------
void NLabel::c_setValue(const double value)
{
    $.value_sum += value;
    $.value_counter++;
    this->c_setAutoUpdate($.auto_update);
}
//------------------------------------------------------------------------------
void NLabel::c_setStyle(const QString &style)
{
    $.style = style;
    _label->setStyleSheet($.style);
    _label->setAlignment($.alignment);
}
//------------------------------------------------------------------------------
void NLabel::c_setDecimalCount(int count)
{
    $.decimal_count = count;
    this->p_setText();
}
//------------------------------------------------------------------------------
void NLabel::c_setAlignment(Qt::Alignment alignment)
{
    $.alignment = alignment;
    this->p_setText();
}
//------------------------------------------------------------------------------
void NLabel::c_setFontSize(int font_size)
{
    $.font_size = font_size;
    QFont font;
    font.setBold(true);
    font.setPointSize($.font_size);
    _label->setFont(font);
}
//------------------------------------------------------------------------------
void NLabel::c_setSize(int label_width, int label_height)
{
    this->setGeometry(this->pos().x(), this->pos().y(), label_width, label_height);
    _label->setGeometry(0, 0, label_width, label_height);
}
//------------------------------------------------------------------------------
void NLabel::p_setText()
{
    $.text = this->p_valuesToText();
    if ($.text.length() < $.decimal_count + 3) {
        $.text.prepend('0');
    }
    _label->setAlignment($.alignment);
    _label->setStyleSheet($.style);
    _label->setText( $.text + $.suffix );
}
//------------------------------------------------------------------------------
QString NLabel::p_valuesToText()
{
    double val = $.value_sum/((double)$.value_counter);
    $.value_sum = val;
    $.value_counter = 1;
    qDebug() << val;
    return QString::number(val, 'f', $.decimal_count);
}
//------------------------------------------------------------------------------
void NLabel::c_renewValue()
{
    this->p_setText();
}
//------------------------------------------------------------------------------
void NLabel::c_setAutoUpdate(bool auto_updare)
{
    $.auto_update = auto_updare;
    if ($.auto_update && !_timer->isActive()) {
        _timer->start($.interval);
        this->p_setText();
    }
}
//------------------------------------------------------------------------------

