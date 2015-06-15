/*
** MainWindow.cpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Mon Jun 15 11:34:52 2015 Hugo Laloge
** Last update Mon Jun 15 16:04:00 2015 Hugo Laloge
*/

#include	"MainWindow.hpp"
#include	"PokeEditWidget.hpp"

using namespace	ui;

MainWindow::MainWindow() : QMainWindow()
{
  /* Boutons de menu  */
  /* Menu File  */
  QMenu	*menuFile(menuBar()->addMenu("&File"));

  QAction *actionNew = new QAction(tr("&New"), this);
  //QObject::connect(actionOpen, SIGNAL(triggered()), this, SLOT(open_file()));
  actionNew->setShortcut(QKeySequence("Ctrl+N"));
  menuFile->addAction(actionNew);

  QAction *actionOpen = new QAction(tr("&Open"), this);
  QObject::connect(actionOpen, SIGNAL(triggered()), this, SLOT(open_file()));
  actionOpen->setShortcut(QKeySequence("Ctrl+O"));
  menuFile->addAction(actionOpen);

  QAction *actionSave = new QAction(tr("&Save"), this);
  //QObject::connect(actionOpen, SIGNAL(triggered()), this, SLOT(open_file()));
  actionSave->setShortcut(QKeySequence("Ctrl+S"));
  menuFile->addAction(actionSave);

  QAction *actionQuit = new QAction(tr("&Quit"), this);
  QObject::connect(actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
  actionQuit->setShortcut(QKeySequence("Ctrl+Q"));
  menuFile->addAction(actionQuit);

  /* Menu Edit */
  QMenu	*menuEdit(menuBar()->addMenu(tr("&Edit")));
  (void)menuEdit;

  /* Onglets */
  PokeEditWidget *pokeEdit = new PokeEditWidget;
  setCentralWidget(pokeEdit);
}

MainWindow::~MainWindow()
{

}

void	MainWindow::open_file()
{
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
						  "",
						  tr("Files (.poke)"));
}
