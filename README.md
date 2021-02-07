# wtImg
SFML-based in-terminal image renderer (windows 10 only).

##### Building (MinGW)
- Download SFML from https://www.sfml-dev.org/download/sfml/2.5.1/ (or any other trusted source)
- Extract it
```bash
git clone https://github.com/x-Eagle-x/wtImg.git
cd wtImg
g++ main.cpp -o wtImg.exe -L(SFML_LIB_PATH) -I(SFML_INCLUDE_PATH) -lsfml-graphics
```
- Paste "sfml-graphics-2.dll" from "SFML/bin".

![example](example.png)
