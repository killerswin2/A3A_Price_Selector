#ifndef LIST_H
#define LIST_H

#include <QListWidget>
#include <QList>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QString>
#include <filesystem>
#include <iostream>


class List
{
public:
	List(QWidget* parent = nullptr);
	List(const std::filesystem::path& pathToJson, QWidget* parent = nullptr);
	bool add_item(QListWidgetItem& item);
	bool show_widget();
	QListWidget* get_list_widget() { return m_listWidget; }
	QList<QListWidgetItem*> get_list() { return m_list; }
	QJsonObject get_json_object() { return m_JsonObj; }
	bool jsonFileChange(const std::filesystem::path& pathToJson);
	bool save_json_doc(const std::filesystem::path& pathToJson);
private:
	void create_list_widget();
	std::filesystem::path m_filePath;
	QList<QListWidgetItem*> m_list;
	QListWidget *m_listWidget;
	QFile m_JsonFile;
	QJsonDocument m_JsonDoc;
	QJsonObject m_JsonObj;
};

#endif // !LIST_H
