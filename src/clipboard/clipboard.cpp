#include "clipboard.hpp"
#include <QtWidgets/QApplication>
#include <iostream>


clipboard::clipboard(QObject* parent)
{
	m_qclipboard = QApplication::clipboard();
}

void clipboard::onClipBoardChange()
{
	QString text = m_qclipboard->text();
	std::cout << text.toStdString() << "\n";
}