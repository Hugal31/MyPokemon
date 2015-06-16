cmake_minimum_required(VERSION 2.8.4)
project(editor)

add_custom_target(editor COMMAND qmake COMMAND make)