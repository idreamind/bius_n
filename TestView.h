#ifndef TESTVIEW_H
#define TESTVIEW_H

#include <QWidget>

#include "Declarations.h"
#include "src/NLabel.h"

//------------------------------------------------------------------------------
class TestView : public QWidget
{
    Q_OBJECT

public: //-------------------------------- Public: -----------------------------
    TestView(QWidget *parent = 0);
    ~TestView();

private:

    NLabel *_n_label_1;
    NLabel *_n_label_2;
}; //--------------------------------------- End -------------------------------

#endif // TESTVIEW_H
