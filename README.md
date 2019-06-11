### Anime Interface is simple program that display any information you want but with somewhat interactive :octocat:
<p align="center">
	<img src="https://github.com/catzy007/AnimeInterface/raw/master/preview/imgss1.png" width="500px" height="auto">
</p>

Anime interface is bunch of little module that display message trough you guess it "anime interface" this program feature character [Maid Chan](https://sakurasounopetnakanojo.fandom.com/wiki/Maid) from anime [Sakurasou no Pet na Kanojo](https://myanimelist.net/anime/13759/Sakurasou_no_Pet_na_Kanojo)

#### Why AnimeInterface?
I used to have lenovo laptop that has built-in battery and power management so my battery will last even i plug it in wall everyday. Now i have Acer laptop that has no such feature and my battery went to 57% health in less than 6 months. Then i realize most cheap laptop dont have such feature that lenovo laptop has, so i this program was made. I add GUI and expand some feature and this is the AnimeInterface now.

#### To use Anime Interface
* install acpi, libgtk3, pkg-config, cmake, xterm and mplayer `sudo apt install acpi libgtk-3-dev pkg-config cmake xterm mplayer -y`
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

_personal and commercial use!_
_for commercial use, change the background first!_
