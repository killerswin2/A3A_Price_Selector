#include "priceselector.hpp"
#include <QMessageBox>
#include <QApplication>
#include <QDir>
#include <QColorSpace>
#include <iostream>

PriceSelector::PriceSelector(QJsonObject json, QDir folderPath, QWidget* parent) : jsonObj{ json }, image_folder_path{folderPath}
{
	widget = new QWidget(parent);
	widget->setWindowTitle("Price Selector!");

	QGridLayout* layout = new QGridLayout;
	button = new QPushButton("Done", this);
	connect(button, &QPushButton::clicked, this, &PriceSelector::buttonPushed);

	imageLabel = new QLabel(this);
	classnameLabel = new QLabel(this);
	edit = new QLineEdit(this);
	proBar = new QProgressBar(this);

	//progress bar
	proBar->setMinimum(0);
	proBar->setMaximum(jsonObj.size());


	layout->addWidget(imageLabel, 0, 0);
	layout->addWidget(classnameLabel, 1, 0);
	layout->addWidget(edit, 2, 0);
	layout->addWidget(button, 2, 1);
	layout->addWidget(proBar, 3, 0);

	widget->setLayout(layout);
	widget->show();

	connect(this, &PriceSelector::close, this, & PriceSelector::save_json_data);
}

bool PriceSelector::load_image(const QString& pathToImage)
{
	QImageReader reader(pathToImage);
	reader.setAutoTransform(true);
	image = reader.read();
	if (image.isNull()) {
		QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
			tr("Cannot load %1: %2")
			.arg(QDir::toNativeSeparators(pathToImage), reader.errorString()));
		return false;
	}
	set_image();
	return true;
}

void PriceSelector::buttonPushed()
{
	int value = proBar->value();
	endObj[iter.key()] =  edit->text().toInt();
	proBar->setValue(value++);
	if (iter != endIt) {
		iter++;
		classnameLabel->setText(iter.key());
		QDir imageFilePath{ image_folder_path.absolutePath().append("/").append(iter.key().append(".png")) };
		//std::cout << imageFilePath.absolutePath().toStdString() <<"\n";
		load_image(imageFilePath.absolutePath());
	}
	else {
		// done
		return;
	}
}

void PriceSelector::set_image()
{
	if (image.colorSpace().isValid())
	{
		image.convertToColorSpace(QColorSpace::SRgb);
		imageLabel->setPixmap(QPixmap::fromImage(image));
		//imageLabel->adjustSize();
	}
}

void PriceSelector::save_json_data()
{
	QFile saveFile(QFileDialog::getSaveFileName(this, tr("Save File"), QDir::currentPath(), tr("Json (*.json)")));
	if (!saveFile.open(QIODevice::WriteOnly))
	{
		qWarning("Couldn't open save file.");
	}
	saveFile.write(QJsonDocument(endObj).toJson());
	saveFile.close();
}

// start list processing
void PriceSelector::process_list()
{
	iter = jsonObj.constBegin();
	endIt = jsonObj.constEnd();

	classnameLabel->setText(iter.key());

	QDir imageFilePath{ image_folder_path.absolutePath().append("/").append(iter.key().append(".png")) };
	//std::cout << imageFilePath.absolutePath().toStdString() <<"\n";
	load_image(imageFilePath.absolutePath());

}
