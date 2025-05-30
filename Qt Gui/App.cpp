#include "App.h"

App::App(int &argc, char **argv)
    : QApplication(argc, argv)
{
}

bool App::InitInstance()
{
    return true; // Return true to indicate successful initialization
}
