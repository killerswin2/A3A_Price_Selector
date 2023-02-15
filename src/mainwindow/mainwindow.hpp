#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QActionGroup>
#include <QAction>
#include <QLabel>
#include <QVBoxLayout>
#include <QStatusBar>
#include "../list/list.hpp"
#include "../priceselector/priceselector.hpp"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
protected:
#ifndef QT_NO_CONTEXTMENU
	void contextMenuEvent(QContextMenuEvent* event) override;
#endif // QT_NO_CONTEXTMENU
private slots:
    void open();
    void save();
    void print();
    void genPrices();
private:
    void createActions();
    void createMenus();
    QMenu* fileMenu;
    QMenu* genMenu;
    QMenu* helpMenu;
    QAction* openAct;
    QAction* saveAct;
    QAction* printAct;
    QAction* genPricesAct;
    QAction* exitAct;
    QAction* aboutQtAct;
    QLabel* infoLabel;
    List* list;
    PriceSelector* selectorDialog;
};

#endif // !MAIN_WINDOW_H