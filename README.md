### Anime Interface is simple program that display any information you want but with somewhat interactive :octocat:
anime interface is bunch of little module that display message trough you guess it "anime interface" this program feature character "Maid Chan" from anime "Sakurasou no Pet na Kanojo"

#### to use Anime Interface
* install acpi, gtk3 and mplayer `sudo apt install acpi gtk+-3.0 mplayer -y`
* install tdlib depedency <https://github.com/tdlib/td#dependencies>
* clone telegram library <https://github.com/tdlib/td>
* compile telegram library _"assuming library will go to home `~/tdlib`"_
```bash
cd <path to TDLib sources (usually td)>
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX:PATH="~/tdlib" ..
cmake --build . --target install
```
* then compile aiface
```bash
cd <path to AnimeInterface sources>
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DTd_DIR="~/tdlib/lib/cmake/Td" ..
cmake --build .
```
* add `aiface` to startup <https://github.com/catzy007/AnimeInterface/wiki/Add-Aiface-to-startup>
* and you're done!

_some image copyright goes to the respective owner_

_personal use only!_
