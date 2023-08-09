
#include <iostream>
#include <filesystem>
//#include <thread>
#include <chrono>
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
fs::path ff2("sourcemod");;

fs::path removeOnNextIter("");

void FindSourcemodsPath()
{
    for (auto& ff : Steampath)
    {
        if (fs::exists(ff))
        {
            fs::space_info DiskSpace = fs::space(ff);
            cout << "CHECKING: " << ff.generic_string() << " : " << DiskSpace.capacity << " bytes" << endl;

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
                    dirEntry.disable_recursion_pending();
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
    //uint32_t drives = GetLogicalDrives();
    //string ss;

    //for (int i = 0; i < 32; ++i)
    //    if (drives & (0x1 << i))
    //        ss += (char)((int)'A' + i);
    //
    //cout << ss << endl;
    
    string someshit;
    cout << "Which folder you want to find?" << endl;
    cin >> someshit;

    cout << "\n Started \n";

    if(someshit != "")
        ff2 = someshit;

    chrono::steady_clock sc;   // create an object of `steady_clock` class
    auto start = sc.now();     // start timer

    FindSourcemodsPath();
    
    auto end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
    auto time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
    cout << "Operation took: " << time_span.count() << " seconds !!!" << endl;

    system("pause");
    //a.join();
    //FindSourcemodsPath();
}
