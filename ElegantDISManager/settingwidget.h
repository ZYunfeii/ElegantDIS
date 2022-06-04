#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class SettingWidget;
}

class SettingWidget : public QWidget
{
    Q_OBJECT

public slots:
    void handle_para();

public:
    explicit SettingWidget(QWidget *parent = nullptr);
    ~SettingWidget();

public:
    std::size_t get_max_steps();
    bool if_free_simulation();

private:
    Ui::SettingWidget *ui;

    std::size_t max_steps_;
    bool free_simulation_;
};

#endif // SETTINGWIDGET_H
