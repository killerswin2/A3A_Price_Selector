#include "list.hpp"
#include <iostream>


List::List(QWidget* parent)
{
	m_listWidget = new QListWidget(parent);
}

List::List(const std::filesystem::path& pathToJson, QWidget* parent) : m_filePath{ pathToJson }, m_JsonFile{ QFile(pathToJson) }
{
	m_listWidget = new QListWidget(parent);

	//m_JsonFile.setFileName(pathToJson);

	if (!m_JsonFile.exists()) { std::cout << "bad file"; }
	m_JsonFile.open(QIODevice::ReadOnly);
	QByteArray data = m_JsonFile.readAll();
	m_JsonFile.close();

	QJsonParseError parseError;
	m_JsonDoc = QJsonDocument::fromJson(data, &parseError);
	create_list_widget();
}



bool List::add_item(QListWidgetItem& item)
{
	return false;
}

bool List::show_widget()
{
	m_listWidget->show();
	return false;
}

bool List::jsonFileChange(const std::filesystem::path& pathToJson)
{
	// free the memory in the m_list
	m_listWidget->clear();
	m_list.clear();

	m_JsonFile.setFileName(pathToJson);

	if (!m_JsonFile.exists()) { std::cout << "bad file"; }
	m_JsonFile.open(QIODevice::ReadOnly);
	QByteArray data = m_JsonFile.readAll();
	m_JsonFile.close();

	QJsonParseError parseError;
	m_JsonDoc = QJsonDocument::fromJson(data, &parseError);
	//TODO: handle pasring errors


	create_list_widget();
	return true;
}

bool List::save_json_doc(const std::filesystem::path& pathToJson)
{
	return true;
}

void List::create_list_widget()
{
	m_JsonObj = m_JsonDoc.object();

	// grab iterators for key, value
	QJsonObject::const_iterator iter = m_JsonObj.constBegin();
	QJsonObject::const_iterator endIt = m_JsonObj.constEnd();


	// create list objects
	for (iter; iter != endIt; iter++)
	{
		//std::cout << iter.key().toStdString() << "\n";
		QListWidgetItem * item = new QListWidgetItem( iter.key(), m_listWidget);
		m_list.push_back(item);
	}

}
