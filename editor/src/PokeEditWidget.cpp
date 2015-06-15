/*
** PokeEditWidget.cpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Mon Jun 15 14:26:11 2015 Hugo Laloge
** Last update Mon Jun 15 17:34:16 2015 Hugo Laloge
*/

#include	"PokeEditWidget.hpp"

using namespace	ui;

PokeEditWidget::PokeEditWidget(QWidget *parent) : QWidget(parent)
{
  QGroupBox	*main_info_box;
  QGroupBox	*second_info_box;
  QGroupBox	*stats_info_box;

  /* Main info  */
  {
    main_info_box = new QGroupBox(tr("Main informations"));

    id = new QSpinBox;
    id->setMaximum(500);
    name = new QLineEdit;
    name->setMaxLength(30);
    species = new QLineEdit;
    species->setMaxLength(30);
    resum = new QTextEdit;
    xp = new XpWidget;

    type_label = new QLabel(tr("Types"));
    types[0] = new TypeWidget;
    types[1] = new TypeWidget;

    QHBoxLayout *type_layout = new QHBoxLayout;
    type_layout->addWidget(type_label);
    type_layout->addWidget(types[0]);
    type_layout->addWidget(types[1]);

    QFormLayout *form_layout = new QFormLayout;
    form_layout->addRow(tr("Id"), id);
    form_layout->addRow(tr("Name"), name);
    form_layout->addRow(tr("Species"), species);
    form_layout->addRow(tr("Resum"), resum);
    form_layout->addRow(tr("Xp type"), xp);
    form_layout->addRow(type_layout);

    main_info_box->setLayout(form_layout);
  }

  /* Secondary info */
  {
    second_info_box = new QGroupBox(tr("Secondary information"));

    heigth = new QDoubleSpinBox;
    heigth->setSuffix(" m");
    heigth->setDecimals(1);
    weight = new QDoubleSpinBox;
    weight->setSuffix(" kg");
    weight->setDecimals(1);
    catch_rate = new QSpinBox;
    catch_rate->setMaximum(100);
    catch_rate->setSuffix("%");
    gender_rate = new QSpinBox;
    gender_rate->setMaximum(100);
    gender_rate->setSuffix("%");

    QFormLayout *form_layout = new QFormLayout;
    form_layout->addRow(tr("Heigth"), heigth);
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

    QVBoxLayout *stat_layout = new QVBoxLayout;
    stat_layout->addLayout(hp_box);
    stat_layout->addLayout(atk_box);
    stat_layout->addLayout(def_box);
    stat_layout->addLayout(spa_box);
    stat_layout->addLayout(spd_box);
    stat_layout->addLayout(spe_box);

    stats_info_box->setLayout(stat_layout);
  }

  /* Layout principal */
  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(main_info_box);
  layout->addWidget(second_info_box);
  layout->addWidget(stats_info_box);
  this->setLayout(layout);
}

PokeEditWidget::~PokeEditWidget()
{

}
