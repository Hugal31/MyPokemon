/*
** mainwindow.cpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Sun Jun 14 10:01:52 2015 Hugo Laloge
** Last update Sun Jun 14 10:01:54 2015 Hugo Laloge
*/

#include	<iostream>
#include	"ui/mainwindow.hpp"
#include	"ui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void	MainWindow::on_actionQuit_clicked()
{
  std::cout << "YOLO" << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}
