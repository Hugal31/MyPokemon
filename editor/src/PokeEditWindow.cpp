/*
** poke_edit_window.cpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Mon Jun 15 11:34:52 2015 Hugo Laloge
** Last update Mon Jun 15 14:06:54 2015 Hugo Laloge
*/

#include       "PokeEditWindow.hpp"

using namespace	ui;

PokeEditWindow::PokeEditWindow() : QMainWindow()
{
  /* Boutons de menu  */
  /* Menu File  */
  QMenu	*menuFile(menuBar()->addMenu("&File"));

  QAction *actionOpen = new QAction("&Open", this);
  QObject::connect(actionOpen, SIGNAL(triggered()), this, SLOT(open_file()));
  actionOpen->setShortcut(QKeySequence("Ctrl+O"));
  menuFile->addAction(actionOpen);

  QAction *actionQuit = new QAction("&Quit", this);
  QObject::connect(actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
  actionQuit->setShortcut(QKeySequence("Ctrl+Q"));
  menuFile->addAction(actionQuit);

  /* Menu Edit */
  QMenu	*menuEdit(menuBar()->addMenu("&Edit"));
  (void)menuEdit;
}

PokeEditWindow::~PokeEditWindow()
{

}

void	PokeEditWindow::open_file()
{
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
						  "",
						  tr("Files (.poke)"));
}
