#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#include <QObject>
#include <QDebug>
#include <QClipboard>

class clipboard : public QObject
{
	Q_OBJECT
public:
	explicit clipboard(QObject* parent = nullptr);
	QClipboard* m_qclipboard;

public slots:
	void onClipBoardChange();
};

#endif // !CLIPBOARD_H
