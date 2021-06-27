/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** SandboxApp.hpp
*/

#ifndef FOX_SANDBOX_HPP_
#define FOX_SANDBOX_HPP_

#include "FoxEngine.hpp"

class SandboxApp : public fox::Application
{
    public:
        SandboxApp(int argc, char** argv);
        ~SandboxApp();
        void init() override;

    protected:
    private:
};

#endif /* !FOX_SANDBOX_HPP_ */
