#include "mainwindow.hpp"
#include <filesystem>

#include <QtWidgets>
#include <QDir>
#include <QTextStream>

MainWindow::MainWindow()
{
	QWidget* widget = new QWidget;
	setCentralWidget(widget);

	QWidget* topFiller = new QWidget;
	topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	infoLabel = new QLabel(tr("<i>Choose a menu option, or right-click to "
		"invoke a context menu</i>"));
	infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
	infoLabel->setAlignment(Qt::AlignCenter);

	QWidget* bottomFiller = new QWidget;
	bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	list = new List(this);


	QVBoxLayout* layout = new QVBoxLayout;
	layout->setContentsMargins(5, 5, 5, 5);
	layout->addWidget(topFiller);
	layout->addWidget(list->get_list_widget());
	layout->addWidget(bottomFiller);
	widget->setLayout(layout);

	createActions();
	createMenus();

	QString message = tr("A context menu is available by right-clicking");
	statusBar()->showMessage(message);

	setWindowTitle(tr("Menu"));
	setMinimumSize(160, 160);
	resize(480, 320);

}

void MainWindow::open()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath(), tr("Json (*.json)"));
	QDir jsonPath(fileName);
	list->jsonFileChange(jsonPath.filesystemAbsolutePath());
}

void MainWindow::save()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QDir::currentPath(), tr("csv (*.csv)"));
	QDir savePath(fileName);
	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly))
	{
		qWarning("Couldn't open save file.");
	}

	QJsonObject jsonObj = list->get_json_object();

	QJsonObject::const_iterator iter = jsonObj.constBegin();
	QJsonObject::const_iterator endIt = jsonObj.constEnd();


	QTextStream out(&file);
	// create list objects
	for (iter; iter != endIt; iter++)
	{
		out << iter.key() << "\n";
		
	}
	
	file.close();
}

void MainWindow::print()
{
	infoLabel->setText(tr("Invoked <b>File|Print</b>"));
}

void MainWindow::genPrices()
{
	QString fileName = QFileDialog::getExistingDirectory(this, tr("Select Folder"), QDir::currentPath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	QDir folderPath(fileName);
	selectorDialog = new PriceSelector(list->get_json_object(), folderPath);
	selectorDialog->process_list();
}


void MainWindow::contextMenuEvent(QContextMenuEvent* event)
{

}

void MainWindow::createActions()
{
	// open action
	openAct = new QAction(tr("&Open"), this);
	openAct->setShortcuts(QKeySequence::Open);
	openAct->setStatusTip(tr("Open an existing file"));
	connect(openAct, &QAction::triggered, this, &MainWindow::open);

	// save action
	saveAct = new QAction(tr("&Save"), this);
	saveAct->setShortcuts(QKeySequence::Save);
	saveAct->setStatusTip(tr("Save the document to disk"));
	connect(saveAct, &QAction::triggered, this, &MainWindow::save);


	// print / generate  action
	printAct = new QAction(tr("&Print"), this);
	printAct->setShortcuts(QKeySequence::Print);
	printAct->setStatusTip(tr("Print out the code"));
	connect(printAct, &QAction::triggered, this, &MainWindow::print);
	
	//genPricesAct action
	genPricesAct = new QAction(tr("Generate prices"), this);
	genPricesAct->setStatusTip(tr("Generate prices for A3A"));
	connect(genPricesAct, &QAction::triggered, this, &MainWindow::genPrices);

	// exit action
	exitAct = new QAction(tr("E&xit"), this);
	exitAct->setShortcuts(QKeySequence::Quit);
	exitAct->setStatusTip(tr("Exit application"));
	connect(exitAct, &QAction::triggered, this, &QWidget::close);

	// about qt action
	aboutQtAct = new QAction(tr("About &Qt"), this);
	aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
	connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void MainWindow::createMenus()
{
	// file actions
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(openAct);
	fileMenu->addAction(saveAct);
	fileMenu->addSeparator();
	fileMenu->addAction(exitAct);

	// gen actions
	genMenu = menuBar()->addMenu(tr("Generate"));
	genMenu->addAction(printAct);
	genMenu->addAction(genPricesAct);

	// help actions
	helpMenu = menuBar()->addMenu(tr("Help"));
	helpMenu->addAction(aboutQtAct);

}
