/*
** MainWindow.cpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Mon Jun 15 11:34:52 2015 Hugo Laloge
** Last update Sat Jun 27 16:21:28 2015 Hugo Laloge
*/

#include	<iostream>
#include	"MainWindow.hpp"
#include	"SkillEditWidget.hpp"
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

  QAction *actionNewPokemon = new QAction(tr("&Pokemon"), this);
  QObject::connect(actionNewPokemon, SIGNAL(triggered()), this, SLOT(new_pokemon()));
  actionNewPokemon->setShortcut(QKeySequence(tr("Ctrl+N")));
  menuNew->addAction(actionNewPokemon);

  QAction *actionNewSkill = new QAction(tr("&Skill"), this);
  QObject::connect(actionNewSkill, SIGNAL(triggered()), this, SLOT(new_skill()));
  menuNew->addAction(actionNewSkill);

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

void	MainWindow::new_skill()
{
  if (currentEditor != NULL)
    {
      delete currentEditor;
      ///<TODO	Faire pop une fenetre de confirmation
    }
  currentEditor = new SkillEditWidget;
  setCentralWidget(currentEditor);
}

namespace
{
  enum	e_file_type
    {
      FILE_UNKNONWED,
      FILE_POKEMON,
      FILE_SKILL
    };

    e_file_type		get_file_type(const QString &fileName)
    {
      e_file_type	type;

      if (fileName == QString("*.poke"))
	type = FILE_POKEMON;
      else if (fileName == QString("*.skill"))
	type = FILE_SKILL;
      else
	type = FILE_UNKNONWED;
      return (type);
    }
}

void	MainWindow::open_file()
{
  if (currentEditor != NULL)
    {
      delete currentEditor;
      ///<TODO	Faire pop une fenetre de confirmation
    }
  //On determine le type de fichier ouvert
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
						  "../ressources",
						  tr("MyPoke (*.poke, *.skill)"));
  switch (get_file_type(fileName))
    {
    case FILE_POKEMON:
      currentEditor = new PokeEditWidget(fileName);
      setCentralWidget(currentEditor);
      break;
    case FILE_SKILL:
      currentEditor = new SkillEditWidget(fileName);
      setCentralWidget(currentEditor);
      break;
    default:
      std::cerr << "Unknoned file format" << std::endl;
      break;
    }
}

void	MainWindow::save_file()
{
  currentEditor->save();
}
