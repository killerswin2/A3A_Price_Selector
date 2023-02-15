#include "test.hpp"


Test::Test(QObject* parent)
{
	
}

void Test::dostuff()
{
	qInfo() << "Doing Stuff!";
	emit close();
}