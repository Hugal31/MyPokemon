/*
** MainWindow.cpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Mon Jun 15 11:34:52 2015 Hugo Laloge
** Last update Tue Jun 16 15:27:30 2015 Hugo Laloge
*/

#include	"MainWindow.hpp"
#include	"PokeEditWidget.hpp"

using namespace	ui;

MainWindow::MainWindow() :
  QMainWindow(),
  currentEditor(NULL)
{
  /* Boutons de menu  */
  /* Menu File  */
  QMenu	*menuFile = menuBar()->addMenu(tr("&File"));
  QMenu *menuNew = menuFile->addMenu(tr("&New"));

  QAction *actionNew = new QAction(tr("&Pokemon"), this);
  QObject::connect(actionNew, SIGNAL(triggered()), this, SLOT(new_pokemon()));
  actionNew->setShortcut(QKeySequence(tr("Ctrl+N")));
  menuNew->addAction(actionNew);

  QAction *actionOpen = new QAction(tr("&Open"), this);
  QObject::connect(actionOpen, SIGNAL(triggered()), this, SLOT(open_file()));
  actionOpen->setShortcut(QKeySequence(tr("Ctrl+O")));
  menuFile->addAction(actionOpen);

  QAction *actionSave = new QAction(tr("&Save"), this);
  QObject::connect(actionSave, SIGNAL(triggered()), this, SLOT(save_file()));
  actionSave->setShortcut(QKeySequence(tr("Ctrl+S")));
  menuFile->addAction(actionSave);

  QAction *actionQuit = new QAction(tr("&Quit"), this);
  QObject::connect(actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
  actionQuit->setShortcut(QKeySequence(tr("Ctrl+Q")));
  menuFile->addAction(actionQuit);

  /* Menu Edit */
  QMenu	*menuEdit(menuBar()->addMenu(tr("&Edit")));
  (void)menuEdit;
}

MainWindow::~MainWindow()
{

}

void	MainWindow::new_pokemon()
{
  if (currentEditor != NULL)
    {
      delete currentEditor;
      ///<TODO	Faire pop une fenetre de confirmation
    }
  currentEditor = new PokeEditWidget;
  setCentralWidget(currentEditor);
}

void	MainWindow::open_file()
{
  if (currentEditor != NULL)
    {
      delete currentEditor;
      ///<TODO	Faire pop une fenetre de confirmation
    }
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
						  "../ressources",
						  tr("MyPoke (*.poke)"));
  currentEditor = new PokeEditWidget(fileName);
  setCentralWidget(currentEditor);
}

void	MainWindow::save_file()
{
  currentEditor->save();
}
