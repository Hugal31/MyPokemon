/*
** SkillEditWidget.cpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Sat Jun 27 14:18:42 2015 Hugo Laloge
** Last update Sun Jun 28 22:02:58 2015 Hugo Laloge
*/

#include	<fstream>
#include	<string>
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
  open_file(filename);
}

SkillEditWidget::~SkillEditWidget()
{

}

void	SkillEditWidget::open_file(const QString &filename)
{
  std::ifstream	file(filename.toStdString());
  game::Skill	skill;

  if (file)
    {
      boost::archive::text_iarchive	ia(file);
      ia >> skill;
      load_skill(skill);
    }
  ///< TODO	Erreur
}

void	SkillEditWidget::load_skill(const game::Skill &skill)
{
  id->setValue(skill.get_id());
  name->setText(skill.get_name().c_str());
  type->setCurrentIndex(skill.get_type().get_value());
  power->setValue(skill.get_power());
  precision->setValue(skill.get_precision());
  pp->setValue(skill.get_pp());
  skill_type->setCurrentIndex(skill.get_skill_type());
}

void	SkillEditWidget::save()
{
  QString path = QFileDialog::getExistingDirectory(this,
						   tr("Save directory"),
						   "../ressources/skill");
  game::Skill	skill;

  save_skill(skill);
  {
    std::ofstream file(path.toStdString() + "/" + std::to_string(id->value()) + ".skill");
    if (file)
      {
	boost::archive::text_oarchive oa(file);
	oa << skill;
      }
    //ERROR
  }
}

void	SkillEditWidget::save_skill(game::Skill &skill)
{
  skill.set_id(static_cast<unsigned int>(id->value()));
  skill.set_name(name->text().toStdString());
  skill.set_type(game::Type(type->currentText().toStdString()));
  skill.set_power(static_cast<unsigned int>(power->value()));
  skill.set_precision(static_cast<unsigned int>(precision->value()));
  skill.set_pp(static_cast<unsigned int>(pp->value()));
  skill.set_skill_type(static_cast<game::e_skill_type>(skill_type->currentIndex()));
}

void	SkillEditWidget::init_layout()
{
  id = new QSpinBox;
  name = new QLineEdit;
  type = new TypeWidget;	//<TODO supprimer le type NONE
  power = new QSpinBox;
  power->setMaximum(255);
  precision = new QSpinBox;
  precision->setMaximum(255);
  pp = new QSpinBox;
  pp.setMaximum(255);
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
