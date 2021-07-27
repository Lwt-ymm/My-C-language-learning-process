#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    void(QSpinBox::*spinBoxSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spinBoxSignal, ui->horizontalSlider, &QSlider::setValue);
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);

}

int SmallWidget::getval() {
    return ui->spinBox->value();
}

void SmallWidget::setval(int val) {
    ui->spinBox->setValue(val);
    return;
}

SmallWidget::~SmallWidget()
{
    delete ui;
}
