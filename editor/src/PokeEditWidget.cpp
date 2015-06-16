/*
** PokeEditWidget.cpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Mon Jun 15 14:26:11 2015 Hugo Laloge
** Last update Tue Jun 16 16:13:57 2015 Hugo Laloge
*/

#include	<fstream>
#include	<string>
#include	"game/PokemonModel.hpp"
#include	"PokeEditWidget.hpp"

using namespace	ui;

PokeEditWidget::PokeEditWidget(QWidget *parent, Qt::WindowFlags f) :
  EditWidget(parent, f)
{
  init_layout();
}

PokeEditWidget::PokeEditWidget(const QString &filename,
			       QWidget *parent, Qt::WindowFlags f) :
  PokeEditWidget(parent, f)
{
  open_poke(filename);
}

PokeEditWidget::~PokeEditWidget()
{

}

void	PokeEditWidget::open_poke(const QString &filename)
{
  std::ifstream	file(filename.toStdString());
  game::PokemonModel	poke;

  if (file)
    {
      boost::archive::text_iarchive	ia(file);
      ia >> poke;
      load_poke(poke);
    }
  ///< TODO	Erreur
}

void	PokeEditWidget::load_poke(const game::PokemonModel &poke)
{
  id->setValue(poke.get_id());
  name->setText(poke.get_name().c_str());
  species->setText(poke.get_species().c_str());
  resum->setText(poke.get_resum().c_str());
  xp->set_value(poke.get_xp_type());
  types[0]->setCurrentText(poke.get_types()[0].get_name().c_str());
  types[1]->setCurrentText(poke.get_types()[1].get_name().c_str());
  height->setValue(static_cast<double>(poke.get_heigth()) / 10);
  weight->setValue(static_cast<double>(poke.get_weight()) / 10);
  catch_rate->setValue(poke.get_catch_rate());
  gender_rate->setValue(poke.get_gender_rate());
  hp_base->setValue(poke.get_hp().get_stat_base());
  hp_ev->setValue(poke.get_hp().get_give_ev());
  atk_base->setValue(poke.get_atk().get_stat_base());
  atk_ev->setValue(poke.get_atk().get_give_ev());
  def_base->setValue(poke.get_def().get_stat_base());
  def_ev->setValue(poke.get_def().get_give_ev());
  spa_base->setValue(poke.get_spa().get_stat_base());
  spa_ev->setValue(poke.get_spa().get_give_ev());
  spd_base->setValue(poke.get_spd().get_stat_base());
  spd_ev->setValue(poke.get_spd().get_give_ev());
  spe_base->setValue(poke.get_spe().get_stat_base());
  spe_ev->setValue(poke.get_spe().get_give_ev());
  xp_base->setValue(poke.get_xp_base());
}

/**
** @param	path	Chemin vers le dossier de sauvegarde
**			Le nom du fichier est deviné tout seul
*/
void	PokeEditWidget::save()
{
  QString path = QFileDialog::getExistingDirectory(this,
						   tr("Save directory"),
						   "../ressources/pokemon");
  game::PokemonModel	poke;

  save_poke(poke);
  {
    std::ofstream file(path.toStdString() + "/" + std::to_string(id->value()) + ".poke");
    if (file)
      {
	boost::archive::text_oarchive oa(file);
	oa << poke;
      }
  }
}

void	PokeEditWidget::save_poke(game::PokemonModel &poke)
{
  poke._id = static_cast<unsigned int>(id->value());
  poke.set_name(name->text().toStdString());
  poke.set_species(species->text().toStdString());
  poke.set_resum(resum->toPlainText().toStdString());
  poke.set_xp_type(xp->get_value());
  poke.set_types(types[0]->currentText().toStdString(), types[1]->currentText().toStdString());
  poke.set_heigth(static_cast<unsigned short int>(height->value() * 10));
  poke.set_weight(static_cast<unsigned short int>(weight->value() * 10));
  poke.set_catch_rate(static_cast<unsigned short int>(catch_rate->value()));
  poke.set_gender_rate(static_cast<unsigned short int>(gender_rate->value()));
  poke._hp.set_stat_base(static_cast<unsigned short int>(hp_base->value()));
  poke._hp.set_give_ev(static_cast<unsigned short int>(hp_ev->value()));
  poke._atk.set_stat_base(static_cast<unsigned short int>(atk_base->value()));
  poke._atk.set_give_ev(static_cast<unsigned short int>(atk_ev->value()));
  poke._def.set_stat_base(static_cast<unsigned short int>(def_base->value()));
  poke._def.set_give_ev(static_cast<unsigned short int>(def_ev->value()));
  poke._spa.set_stat_base(static_cast<unsigned short int>(spa_base->value()));
  poke._spa.set_give_ev(static_cast<unsigned short int>(spa_ev->value()));
  poke._spd.set_stat_base(static_cast<unsigned short int>(spd_base->value()));
  poke._spd.set_give_ev(static_cast<unsigned short int>(spd_ev->value()));
  poke._spe.set_stat_base(static_cast<unsigned short int>(spe_base->value()));
  poke._spe.set_give_ev(static_cast<unsigned short int>(spe_ev->value()));
  poke.set_xp_base(static_cast<unsigned short int>(xp_base->value()));
}

void	PokeEditWidget::init_layout()
{
  QGroupBox	*main_info_box;
  QGroupBox	*second_info_box;
  QGroupBox	*stats_info_box;

  /* Main info  */
  {
    main_info_box = new QGroupBox(tr("Main informtions"));

    id = new QSpinBox;
    id->setMinimum(1);
    id->setMaximum(500);
    name = new QLineEdit;
    name->setMaxLength(30);
    species = new QLineEdit;
    species->setMaxLength(30);
    resum = new QTextEdit;
    xp = new XpWidget;

    types[0] = new TypeWidget;
    types[1] = new TypeWidget;

    QHBoxLayout *type_layout = new QHBoxLayout;
    type_layout->addWidget(types[0]);
    type_layout->addWidget(types[1]);

    QFormLayout *form_layout = new QFormLayout;
    form_layout->addRow(tr("Id"), id);
    form_layout->addRow(tr("Name"), name);
    form_layout->addRow(tr("Species"), species);
    form_layout->addRow(tr("Resum"), resum);
    form_layout->addRow(tr("Types"), type_layout);
    form_layout->addRow(tr("Xp type"), xp);

    main_info_box->setLayout(form_layout);
  }

  /* Secondary info */
  {
    second_info_box = new QGroupBox(tr("Secondary information"));

    height = new QDoubleSpinBox;
    height->setSuffix(" m");
    height->setDecimals(1);
    height->setMaximum(100.0);
    height->setValue(0.5);
    weight = new QDoubleSpinBox;
    weight->setSuffix(" kg");
    weight->setDecimals(1);
    weight->setMaximum(2000.0);
    weight->setValue(10.0);
    catch_rate = new QSpinBox;
    catch_rate->setMaximum(100);
    catch_rate->setSuffix("%");
    catch_rate->setValue(50);
    gender_rate = new QSpinBox;
    gender_rate->setMaximum(100);
    gender_rate->setSuffix("%");
    gender_rate->setValue(50);

    QFormLayout *form_layout = new QFormLayout;
    form_layout->addRow(tr("Height"), height);
    form_layout->addRow(tr("Weight"), weight);
    form_layout->addRow(tr("Catch rate"), catch_rate);
    form_layout->addRow(tr("Gender rate"), gender_rate);

    second_info_box->setLayout(form_layout);
  }

  /* Stats info */
  {
    QHBoxLayout *hp_box;
    QHBoxLayout *atk_box;
    QHBoxLayout *def_box;
    QHBoxLayout *spa_box;
    QHBoxLayout *spd_box;
    QHBoxLayout *spe_box;
    QHBoxLayout *xp_box;

    stats_info_box = new QGroupBox(tr("Stats"));

    {
      hp_box = new QHBoxLayout;

      QLabel *hp_label = new QLabel(tr("<b>Hp</b>"));
      hp_base = new QSpinBox;
      hp_base->setMaximum(255);
      hp_ev = new QSpinBox;
      hp_ev->setMaximum(3);

      hp_box->addWidget(hp_label);
      hp_box->addWidget(new QLabel(tr("Base")));
      hp_box->addWidget(hp_base);
      hp_box->addWidget(new QLabel(tr("Gived ev")));
      hp_box->addWidget(hp_ev);
    }

    {
      atk_box = new QHBoxLayout;

      QLabel *atk_label = new QLabel(tr("<b>Atk</b>"));
      atk_base = new QSpinBox;
      atk_base->setMaximum(255);
      atk_ev = new QSpinBox;
      atk_ev->setMaximum(3);

      atk_box->addWidget(atk_label);
      atk_box->addWidget(new QLabel(tr("Base")));
      atk_box->addWidget(atk_base);
      atk_box->addWidget(new QLabel(tr("Gived ev")));
      atk_box->addWidget(atk_ev);
    }

    {
      def_box = new QHBoxLayout;

      QLabel *def_label = new QLabel(tr("<b>Def</b>"));
      def_base = new QSpinBox;
      def_base->setMaximum(255);
      def_ev = new QSpinBox;
      def_ev->setMaximum(3);

      def_box->addWidget(def_label);
      def_box->addWidget(new QLabel(tr("Base")));
      def_box->addWidget(def_base);
      def_box->addWidget(new QLabel(tr("Gived ev")));
      def_box->addWidget(def_ev);
    }

    {
      spa_box = new QHBoxLayout;

      QLabel *spa_label = new QLabel(tr("<b>Spa</b>"));
      spa_base = new QSpinBox;
      spa_base->setMaximum(255);
      spa_ev = new QSpinBox;
      spa_ev->setMaximum(3);

      spa_box->addWidget(spa_label);
      spa_box->addWidget(new QLabel(tr("Base")));
      spa_box->addWidget(spa_base);
      spa_box->addWidget(new QLabel(tr("Gived ev")));
      spa_box->addWidget(spa_ev);
    }

    {
      spd_box = new QHBoxLayout;

      QLabel *spd_label = new QLabel(tr("<b>Spd</b>"));
      spd_base = new QSpinBox;
      spd_base->setMaximum(255);
      spd_ev = new QSpinBox;
      spd_ev->setMaximum(3);

      spd_box->addWidget(spd_label);
      spd_box->addWidget(new QLabel(tr("Base")));
      spd_box->addWidget(spd_base);
      spd_box->addWidget(new QLabel(tr("Gived ev")));
      spd_box->addWidget(spd_ev);
    }

    {
      spe_box = new QHBoxLayout;

      QLabel *spe_label = new QLabel(tr("<b>Spe</b>"));
      spe_base = new QSpinBox;
      spe_base->setMaximum(255);
      spe_ev = new QSpinBox;
      spe_ev->setMaximum(3);

      spe_box->addWidget(spe_label);
      spe_box->addWidget(new QLabel(tr("Base")));
      spe_box->addWidget(spe_base);
      spe_box->addWidget(new QLabel(tr("Gived ev")));
      spe_box->addWidget(spe_ev);
    }

    {
      xp_box = new QHBoxLayout;

      QLabel *xp_label = new QLabel(tr("<b>Xp</b>"));
      xp_base = new QSpinBox;
      xp_base->setMaximum(255);

      xp_box->addWidget(xp_label);
      xp_box->addWidget(new QLabel(tr("Base")));
      xp_box->addWidget(xp_base);
    }

    QVBoxLayout *stat_layout = new QVBoxLayout;
    stat_layout->addLayout(hp_box);
    stat_layout->addLayout(atk_box);
    stat_layout->addLayout(def_box);
    stat_layout->addLayout(spa_box);
    stat_layout->addLayout(spd_box);
    stat_layout->addLayout(spe_box);
    stat_layout->addLayout(xp_box);

    stats_info_box->setLayout(stat_layout);
  }

  /* Layout principal */
  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(main_info_box);
  layout->addWidget(second_info_box);
  layout->addWidget(stats_info_box);
  this->setLayout(layout);
}
