#include "commandProcessing.cpp"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char* argv[])
{
	commandProcessing cmd;
	songQueue q;
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	

	//command test suite
	/*
	cmd.play("CantinaBand3.wav" , q);
	cout << q.getFirst() << " is playing \n\n";
	cmd.pause();
	cmd.resume();
	q.queueToString();
	cmd.repeatToggle(q);
	cmd.repeatToggle(q);
	q.queueToString();
	q.clear();
	q.queueToString();
	cmd.stop(q);
	help();
	*/
	return a.exec();
}
