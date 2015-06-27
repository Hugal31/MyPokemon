/*
** SkillEditWidget.cpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Sat Jun 27 14:18:42 2015 Hugo Laloge
** Last update Sat Jun 27 16:22:45 2015 Hugo Laloge
*/

#include	"SkillEditWidget.hpp"

using namespace	ui;

SkillEditWidget::SkillEditWidget(QWidget *parent, Qt::WindowFlags f) :
  EditWidget(parent, f)
{
  init_layout();
}

SkillEditWidget::SkillEditWidget(const QString &filename,
				 QWidget *parent, Qt::WindowFlags f) :
  SkillEditWidget(parent, f)
{
  open_skill(filename);
}

SkillEditWidget::~SkillEditWidget()
{

}

void	SkillEditWidget::open_skill(const QString &filename)
{

}

void	SkillEditWidget::load_skill(const game::Skill &skill)
{

}

void	SkillEditWidget::save()
{
  QString path = QFileDialog::getExistingDirectory(this,
						   tr("Save directory"),
						   "../ressources/skill");
}

void	SkillEditWidget::init_layout()
{
  id = new QSpinBox;
  name = new QLineEdit;
  type = new TypeWidget;
  power = new QSpinBox;
  precision = new QSpinBox;
  pp = new QSpinBox;
  skill_type = new QComboBox;
  skill_type->addItem(tr("PHYSICAL"));
  skill_type->addItem(tr("SPECIAL"));

  QFormLayout	*form_layout = new QFormLayout;
  form_layout->addRow(tr("Id"), id);
  form_layout->addRow(tr("Name"), name);
  form_layout->addRow(tr("Type"), type);
  form_layout->addRow(tr("Power"), power);
  form_layout->addRow(tr("Precision"), precision);
  form_layout->addRow(tr("PP"), pp);
  form_layout->addRow(tr("Skill type"), skill_type);

  this->setLayout(form_layout);
}
