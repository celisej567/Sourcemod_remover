// WindowsProject1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "WindowsProject1.h"

#include <iostream>
#include <filesystem>
#include <thread>
namespace fs = std::filesystem;
using namespace std;

string Pass[] =
{
    "common",
    "downloading",
    "music",
    "shadercache",
    "temp",
    "workshop",
    "depotcache",

    "Windows",
    "windows",
    "Windows.old",
    "windows.old",

    "Arduino",
    "arduino",

    "AMD",
    "Amd",
    "amd",
};

fs::directory_options opt = fs::directory_options::skip_permission_denied;

fs::path Steampath[] =
{
    fs::path("C:\\"),
    fs::path("D:\\"),
    fs::path("E:\\"),
    fs::path("F:\\"),
    fs::path("G:\\"),
    fs::path("H:\\"),
    fs::path("I:\\"),
    fs::path("G:\\"),
    fs::path("K:\\"),
    fs::path("L:\\"),
    fs::path("M:\\"),
    fs::path("N:\\"),
    fs::path("O:\\"),
    fs::path("P:\\"),


};
fs::path ff2("sourcemod");

fs::path removeOnNextIter("");

void FindSourcemodsPath()
{
    for (auto& ff : Steampath)
    {
        if (fs::exists(ff))
        {
            for (auto dirEntry = fs::recursive_directory_iterator(ff, opt); dirEntry != fs::recursive_directory_iterator(); ++dirEntry)
            {

                //fs::remove_all(removeOnNextIter);

                bool skip = false;

                if (!dirEntry->is_directory())
                    continue;

                if (dirEntry->is_directory())
                {
                    for (string STR : Pass)
                    {

                        if (dirEntry->path().generic_string().contains(STR))
                        {
                            //cout << "SKIP: " << dirEntry->path() << endl;
                            skip = true;
                        }
                    }
                }

                if (skip)
                {
                    dirEntry.disable_recursion_pending();
                    continue;
                }

                if (dirEntry->is_directory() && dirEntry->path().native().contains(ff2.c_str()))
                {
                    //system("color 04");
                    //cout << "FOUNDED IN: " << dirEntry->path() << endl;
                    //system("color 07");
                    //dirEntry.disable_recursion_pending();
                    removeOnNextIter = dirEntry->path();
                    //fs::remove_all(dirEntry->path());
                    //fs::create_directory("C:\\ABOBA.txt");
                    //continue;
                }
                //cout << "CHECKED: " << dirEntry->path() << endl;
            }
        }
        else {
            //cout << "CANT FIND " << ff.generic_string() << endl;
        }
    }
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    FindSourcemodsPath();
    return 0;
}
