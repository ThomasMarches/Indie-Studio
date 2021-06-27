/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** EntryPoint.cpp
*/

#include "FoxEngine.hpp"

extern fox::Application* CreateApp(int argc, char** argv);

int main(int argc, char**argv)
{
	fox::Application* pApp = CreateApp(argc, argv);
	pApp->run();
    delete pApp;
    return 0;
}