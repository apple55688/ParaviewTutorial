# MyPNG Reader
## 介紹:
我們做了一個可以讀特定檔案的reader plugin，將編譯好的plugin匯入進paraview後， 就可以打開.mypng的檔案。
## 檔案格式:
- MyPNGReader
    - CMakeLists.txt
    - Plugin
        - reader.xml
        - CMakeLists.txt
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
## 程式碼說明:
### xml:
以下是XML檔案的詳細介紹：

 * ServerManagerConfiguration：  
  這是根元素，表示這是一個伺服器管理器的配置文件。

 * ProxyGroup ：  
 這個元素定義了一個代理群組（Proxy Group），名為"sources"。在這個群組中，可以定義多個代理（Proxy）來實現不同的功能。

 * SourceProxy name="MyPNGReader" class="vtkPNGReader" label="PNG reader"：   
 這個元素定義了一個名為"MyPNGReader"的源代理（Source Proxy）。該代理使用vtkPNGReader類來實現。它的標籤（label）是"PNG reader"，表示它用於讀取PNG文件。

 * Documentation ：  
 這個元素提供了有關"MyPNGReader"的簡短和詳細說明。簡短說明（short_help）指出它可以讀取PNG文件，並將其轉換為圖像數據集。

 * StringVectorProperty：  
 這個元素定義了一個StringVector屬性，名為"FileName"，用於指定PNG讀取器的文件名。它具有多個屬性，例如animateable（是否可以動畫顯示），command（用於設置文件名的命令），number_of_elements（元素數量），panel_visibility（面板可見性）等。

 * FileListDomain name="files"：  
 這個元素定義了一個文件列表域（FileListDomain），它指定了允許選擇的文件類型，這裡是"files"。

 * Documentation：  
 這個元素提供了有關"FileName"屬性的說明，它說明了該屬性用於指定PNG讀取器的文件名。

 * Hints：  
 這個元素提供了一些提示（Hints）信息，用於配置讀取器的行為。

 * ReaderFactory extensions="mypng" file_description="My PNG Files" ：  
 這個元素指定了讀取器工廠（Reader Factory）的擴展（extensions）和文件描述（file_description）。在這裡，擴展是"mypng"，表示該讀取器可以處理擴展為".mypng"的文件。文件描述是"My PNG Files"，用於描述該類型的文件。

這個XML檔案定義了一個名為"MyPNGReader"的PNG讀取器插件，它可以讀取PNG文件並將其轉換為圖像數據集。它提供了一個屬性（FileName）來指定文件名，並且可以處理擴展為".mypng"的文件。
###  CMakeLists.txt:  
這兩個CMakeLists.txt檔案用於建立並配置"MyPNGReader"插件。

首先，內部的CMakeLists.txt檔案位於'Plugin'的資料夾內：
```bash
paraview_add_plugin(MyPNGReader
  REQUIRED_ON_CLIENT
  REQUIRED_ON_SERVER
  VERSION "1.0"
  SERVER_MANAGER_XML readers.xml)
```
這個CMakeLists.txt檔案使用了paraview_add_plugin指令，它用於向ParaView添加一個插件。它定義了一個名為"MyPNGReader"的插件。

'REQUIRED_ON_CLIENT'和'REQUIRED_ON_SERVER'選項指示這個插件在客戶端和伺服器端都是必需的。

VERSION "1.0"指定了插件的版本號。

SERVER_MANAGER_XML readers.xml指定了插件的Server Manager XML檔案，即上一個問題中提到的readers.xml。

接著是外部的Cmakelist.txt:  
```bash
cmake_minimum_required(VERSION 3.8)
project(MyPNGReader)

find_package(ParaView REQUIRED)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

include(GNUInstallDirs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")

set("_paraview_plugin_default_${PROJECT_NAME}" ON)
paraview_plugin_scan(
  PLUGIN_FILES      "${CMAKE_CURRENT_SOURCE_DIR}/Plugin/paraview.plugin"
  PROVIDES_PLUGINS  plugins
  REQUIRES_MODULES  required_modules)

foreach (module IN LISTS required_modules)
  if (NOT TARGET "${module}")
    message(#FATAL_ERROR
      "Skipping example ${PROJECT_NAME}: Missing required module: "
      "${module}")
    return ()
  endif ()
endforeach ()

paraview_plugin_build(
  RUNTIME_DESTINATION "${CMAKE_INSTALL_BINDIR}"
  LIBRARY_DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  LIBRARY_SUBDIRECTORY "${PARAVIEW_PLUGIN_SUBDIR}"
  PLUGINS ${plugins})
```
這個CMakeLists.txt檔案用於構建和配置"MyPNGReader"插件。

首先它指定了CMake的最低版本要求。

接下來通過find_package(ParaView REQUIRED)指令，它找到並確認ParaView庫的存在。

option(BUILD_SHARED_LIBS "Build shared libraries" ON)選項用於指定是否要建立共享庫（shared libraries）。

include(GNUInstallDirs)用於包含GNUInstallDirs模組，以獲取GNU安裝目錄的路徑。

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")和相似的指令用於設定執行檔（runtime）、庫（library）和存檔（archive）的輸出目錄。

paraview_plugin_scan指令用於掃描插件的描述檔，該描述檔位於Plugin/paraview.plugin路徑中。它識別了插件的提供的模組和需要的模組。

然後，通過paraview_plugin_build指令，它根據之前的配置來構建插件。它指定了插件的目的地目錄和子目錄，以及需要構建的插件。

這兩個CMakeLists.txt檔案一起工作，用於定義、配置和構建"MyPNGReader"插件，並將其添加到ParaView中。

