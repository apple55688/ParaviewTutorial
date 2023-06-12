# MyPNG Reader
## 介紹:
我們做了一個可以讀特定檔案的reader plugin，將編譯好的plugin匯入進paraview後， 就可以打開.mypng的檔案。
## 檔案格式:
- MyPNGReader
    - CMakeLists.txt
    - Plugin
        - CMakeLists.txt
        - MyPNGReaderPlugin.cxx
        - MyPNGReader.h
        - MyPNGReader_qch.h

## 編譯步驟
因為這個code是已經編譯好的，如果要重新編譯，可以先把build資料夾刪除，然後依照下面步驟  
1.打開terminal，進入這個資料夾  
2.創建一個資料夾叫做'build'  
```bash
mkdir build
```
3.進入'build'資料夾
```bash
cd build
```
4.在'build'資料夾中執行cmake指令
```bash
cmake -GNinja -DParaview_DIR=C:\pvdebug\pvb\bin ../
```
DParaview_DIR指向Paraview所在的位址  
5.執行ninja
```bash
ninja
```
編譯完成後就會出現在'build'資料夾中
## 成果
![Alt text](image.png)