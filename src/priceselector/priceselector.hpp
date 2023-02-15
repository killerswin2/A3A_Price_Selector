#ifndef PRICE_SEL_H
#define PRICE_SEL_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QEvent>
#include <QImage>
#include <QLineEdit>
#include <QGridLayout>
#include <QImageReader>
#include <QString>
#include <QDir>
#include <QProgressBar>
#include "../list/list.hpp"
#include <QtWidgets>


class PriceSelector : public QWidget
{
    Q_OBJECT

public:
    PriceSelector(QJsonObject json, QDir folderPath, QWidget* parent = nullptr);
    void process_list();
private slots:
    void buttonPushed();
private:
    QWidget* widget;
    QPushButton* button;
    QLabel* imageLabel;
    QLabel* classnameLabel;;
    QImage image;
    QProgressBar* proBar;
    QLineEdit* edit;
    bool load_image(const QString& pathToImage);
    void set_image();
    void save_json_data();
    QJsonObject jsonObj;
    QDir image_folder_path;
    QJsonObject::const_iterator iter;
    QJsonObject::const_iterator endIt;
    QJsonObject endObj;
};



#endif // !PRICE_SEL_H
