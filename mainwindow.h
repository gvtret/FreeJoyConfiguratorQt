#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QEvent>
#include <QScrollBar>
#include <QSettings>

#include "deviceconfig.h"
#include "hiddevice.h"
#include "reportconverter.h"

// widgets  удалить лишнее
#include "widgets/encoders.h"
#include "widgets/encodersconfig.h"
#include "widgets/buttonconfig.h"
#include "widgets/buttonlogical.h"
#include "widgets/pincombobox.h"    // widgets  удалить лишнее
#include "widgets/pinconfig.h"
#include "widgets/advancedsettings.h"
#include "widgets/axesconfig.h"
#include "widgets/axescurves.h"
#include "widgets/axescurvesconfig.h"
#include "widgets/axestobuttons.h"
#include "widgets/axestobuttonsconfig.h"
#include "widgets/led.h"
#include "widgets/ledconfig.h"
#include "widgets/shiftregisters.h"
#include "widgets/shiftregistersconfig.h"

/* Defining */
//#define ORGANIZATION_NAME "FreeJoy"
//#define ORGANIZATION_DOMAIN "https://github.com/FreeJoy-Team"
//#define APPLICATION_NAME "FreeJoy QtConfigurator"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ReportConverter report_convert;     // nah?

//private:
    //QScopedPointer<QThread> thread;
    //QScopedPointer<HidDevice> worker;
    QThread* thread;
    HidDevice* hid_device_worker;

    PinConfig* pin_config;
    ButtonConfig* button_config;
    LedConfig* led_config;
    EncodersConfig* encoder_config;
    ShiftRegistersConfig* shift_reg_config;
    AxesConfig* axes_config;
    AxesCurvesConfig* axes_curves_config;
    AxesToButtonsConfig* a2b_config;

signals:
    void getConfigDone(bool success);
    void sendConfigDone(bool success);


private slots:
    void showConnectDeviceInfo();
    void hideConnectDeviceInfo();
    void getGamepadPacket(uint8_t *);
//    void getConfigPacket(uint8_t *);
//    void sendConfigPacket(uint8_t *);

    void configReceived(bool success);
    void configSent(bool success);

    void hidDeviceList(QStringList* device_list);
    void hidDeviceListChanged(int index);

    void languageChanged(QString language);

    void interfaceStyleChanged(bool is_dark);

    void on_pushButton_11_clicked();
    void addvalues(int);

    void on_pushButton_ResetAllPins_clicked();

    void on_pushButton_ReadConfig_clicked();
    void on_pushButton_WriteConfig_clicked();

private:
    Ui::MainWindow *ui;
    QTranslator translator;
    QString button_default_style_;  // мб статик в функции?

    QThread* thread_getSend_config;

    void LoadAppConfig();
    void SaveAppConfig();

    void LoadDeviceConfigFromFile();
    void SaveDeviceConfigToFile();

    void resizeEvent(QResizeEvent*);
};
#endif // MAINWINDOW_H
