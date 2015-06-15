/*
** PokeEditWidget.cpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Mon Jun 15 14:26:11 2015 Hugo Laloge
** Last update Mon Jun 15 16:00:25 2015 Hugo Laloge
*/

#include	"game/Type.hpp"
#include	"PokeEditWidget.hpp"

using namespace	ui;

namespace
{
  class	TypeWidget : public QComboBox
  {
  public:
    TypeWidget(QWidget *parent = NULL) : QComboBox(parent)
      {
	for (unsigned int i(game::TYPE_NONE); i < game::TYPE_END; i++)
	  addItem(QString(game::Type::names[i].c_str()));
      }
  };
}

PokeEditWidget::PokeEditWidget(QWidget *parent) : QWidget(parent)
{
  /* Main info  */
  QGroupBox *main_info_box = new QGroupBox(tr("Main informations"));

  QLineEdit *name = new QLineEdit;
  QLineEdit *species = new QLineEdit;
  QTextEdit *resum = new QTextEdit;

  QFormLayout *main_form_layout = new QFormLayout;
  main_form_layout->addRow(tr("Name"), name);
  main_form_layout->addRow(tr("Species"), species);
  main_form_layout->addRow(tr("Resum"), resum);

  QLabel *type_label = new QLabel(tr("Types"));
  TypeWidget *type_1 = new TypeWidget;
  TypeWidget *type_2 = new TypeWidget;

  QHBoxLayout *type_layout = new QHBoxLayout;
  type_layout->addWidget(type_label);
  type_layout->addWidget(type_1);
  type_layout->addWidget(type_2);

  QVBoxLayout *main_layout = new QVBoxLayout;
  main_layout->addLayout(main_form_layout);
  main_layout->addLayout(type_layout);

  main_info_box->setLayout(main_layout);

  /* Layout principal */
  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(main_info_box);
  this->setLayout(layout);
}

PokeEditWidget::~PokeEditWidget()
{

}
