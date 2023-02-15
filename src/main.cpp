#include <iostream>
#include <string>
#include <QtWidgets/QApplication>
#include <QCoreApplication>
#include <QGuiApplication>
#include <QClipboard>
#include "test.hpp"
#include "clipboard/clipboard.hpp"
#include "mainwindow/mainwindow.hpp"
#include "list/list.hpp"
#include <filesystem>



int main(int argc, char *argv[])
{
	//QCoreApplication a(argc, argv);
	QApplication a(argc, argv);


	//clipboard clip;
	
	
	//QObject::connect(clip.m_qclipboard, &QClipboard::changed, &clip, &clipboard::onClipBoardChange, Qt::QueuedConnection);

	//std::filesystem::path path("E:/qt/json/test.json");
	//List test(path);
	//test.show_widget();
	MainWindow wind;
	wind.show();

	return a.exec();
}