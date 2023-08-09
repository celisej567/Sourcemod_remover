
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

    "Microsoft",
    "microsoft",

    "Android",
    "android",

    "Strawberry",
    "strawberry",

    "VS",
    "Visual",
    "Visual Studio",
    "Visual studio",

    "NVIDIA",
    "Nvidia",
    "nvidia",

    "git",
    "Git",

    "Roblox",
    "roblox",

    "Chrom",
    "chrom",

    "Yandex",
    "yandex",

    "AppData",
    "appdata",
    

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
            cout << "CHECKING: " << ff.generic_string() << "\\ " << endl;
            for (auto dirEntry = fs::recursive_directory_iterator(ff, opt); dirEntry != fs::recursive_directory_iterator(); ++dirEntry )
            {
                //fs::remove_all(removeOnNextIter);

                bool skip = false;

                if (!dirEntry->is_directory())
                    continue;

                if (dirEntry->is_directory())
                {
                    for (string STR : Pass)
                    {
                        fs::path pstr(STR);

                        if (dirEntry->path().native().contains(pstr.c_str()))
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
                    system("color 04");
                    cout << "FOUNDED IN: " << dirEntry->path() << endl;
                    system("color 07");
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
            cout << "CANT FIND " << ff.generic_string() << endl;
        }
    }   
}

void main()
{

    cout << "\n Started \n";

    //uint32_t drives = GetLogicalDrives();
    //string ss;

    //for (int i = 0; i < 32; ++i)
    //    if (drives & (0x1 << i))
    //        ss += (char)((int)'A' + i);
    //
    //cout << ss << endl;
    
    FindSourcemodsPath();
    
    //a.join();
    //FindSourcemodsPath();
}
