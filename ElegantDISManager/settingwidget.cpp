#include "settingwidget.h"
#include "ui_settingwidget.h"

SettingWidget::SettingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingWidget),
    max_steps_(1000)
{
    ui->setupUi(this);
    connect(ui->confirm_button, &QPushButton::clicked, this, &SettingWidget::handle_para);
    ui->max_total_steps->setText("1000");
}

void SettingWidget::handle_para() {
    max_steps_ = ui->max_total_steps->text().toInt();
    QMessageBox::information(this, "Info", "The parameters set successfully!");
}

std::size_t SettingWidget::get_max_steps() {
    return max_steps_;
}

SettingWidget::~SettingWidget()
{
    delete ui;
}
