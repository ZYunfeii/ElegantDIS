#include "settingwidget.h"
#include "ui_settingwidget.h"

SettingWidget::SettingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingWidget),
    max_steps_(1000),
    free_simulation_(0)
{
    ui->setupUi(this);
    connect(ui->confirm_button, &QPushButton::clicked, this, &SettingWidget::handle_para);
    ui->max_total_steps->setText("1000");
    ui->free_simulation->setChecked(0);
}

void SettingWidget::handle_para() {
    max_steps_ = ui->max_total_steps->text().toInt();
    free_simulation_ = ui->free_simulation->checkState() == Qt::Checked;
    QMessageBox::information(this, "Info", "The parameters set successfully!");
}

std::size_t SettingWidget::get_max_steps() {
    return max_steps_;
}

bool SettingWidget::if_free_simulation() {
    return free_simulation_;
}

SettingWidget::~SettingWidget()
{
    delete ui;
}
