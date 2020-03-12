---
title: CMakeLists.txt编写基础知识
date: 2018-11-23 00:20:51
categories: 编程工具学习与应用
tags: [cmake]
description: Focus on how to use cmake to compile scripts and library and hide source files.
password: 
---
# 参考文献
[cmake 背景知识](http://www.cnblogs.com/52php/p/5681745.html)
[cmake 基础2](http://www.cnblogs.com/52php/p/5681751.html)
[cmake  共享库文件，外部链接](http://www.cnblogs.com/52php/p/5681755.html)

# 应用实例
**说明**
采用c++的类来写hello world，然后编写教程。
- bin  二进制文档
- build 链接文档
- doc README、COPYRIGHT等的说明文档
- inc 头文件文档  hello.hh
- src 源文件文档  hello.cc
main.cc 为主文件

**附录**

- main.cc
```
#include "hello.hh"

int main()
{
  
  HelloFunc hi;
  hi.Hello();
  return 0;
}
```
- hello.hh
```
#ifndef HELLO_hh
#define HELLO_hh 1

class HelloFunc
{
 public:
  HelloFunc();
  virtual ~HelloFunc();  
  
  void Hello();
 private:

};

#endif
```
- hello.cc
```
#include "hello.hh"
#include "iostream"
using namespace std;

HelloFunc::HelloFunc()
{

}

HelloFunc::~HelloFunc()
{}

void HelloFunc::Hello()
{
  cout<<"Hello World"<<endl;
}
```
-CMakeList.txt 编译文件
```
##
##  cmake module authored by Hubery Lee(李会)
##  2018年11月22日 
##

cmake_minimum_required(VERSION 2.6 FATAL_ERROR) #
set(PROJ_NAME hello)
project(${PROJ_NAME})

#project(${PROJ_NAME} C CXX Fortran)
#enable_language(Fortran) ##允许使用语言类型
#set(CMAKE_BUILD_TYPE release) ##release or debug
#set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}") ##

#------------------------------------
# Include directory for this project
#
include_directories(${PROJECT_SOURCE_DIR}/inc)

#------------------------------------
# Locate sources and headers for this project
#
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/inc/*.hh)

#------------------------------------
# Add the executable and link it to the libraries
#

add_executable(${PROJ_NAME} main.cc ${sources} ${headers})

#target_link_libraries(${PROJ_NAME} -L${PROJECT_SOURE_DIR}/lib hello.so) ##链接库文件

#-------------------------------------
# Install the executable or files to 'bin' directory
# under CMAKE_INSTALL_PREFIX
#
install(TARGETS ${PROJ_NAME} DESTINATION bin)
```
# 问题描述 
## 如何外部编译 ？
```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/lib
cd build
cmake -DCMAKE_INSTALL_PREFIX=../ ../
make -j4
make install
cd ../bin
```
  ## 设置二进制文件存放地址
```
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
```
  ## 如何生成动态库或静态库？
 [参考文献](https://blog.csdn.net/weixin_42111770/article/details/80595633)
```
1.add_library(name SHARED source1, source2, ..., sourceN)
2.add_library(name_static STATIC source1, source2, ... , sourceN)
3.set_target_properties(name_static PROPERTIES OUTPUT_NAME "name")
4.set_target_properties(name_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
5.set_target_properties(name PROPERTIES CLEAN_DIRECT_OUTPUT 1)
6.set_target_properties(name PROPERTIES VERSION 1.2 SOVERSION 1)
7.install(TARGETS name name_static 
          LIBRARY DESTINATION lib
          ARCHIVE DESTINATION lib)
8.install(DIRECTORY ${titile_H} DESTINATION include/tH)
```
第一条	指令是生成动态库（扩展名为.so），类型关键字是SHARED，并不需要写全libname.so，只需要填写name即可，cmake系统会自动生成libname.so。

第二条	指令是在支持动态库的基础上为工程添加一个静态库，因为静态库和动态库同名时，构建静态库的指令是无效的，所以把上面的name修改为name_static，就可以构建一个libname_static的静态库；然而我们需要的是名字相同的静态库和动态库，因为target的唯一性，所以就不能通过add_library指令实现，所以用到第三条指令

第三条	指令是为了能够同时得到libname.so/libname.a两个库文件，但是因为cmake在构建一个新的target时，会尝试清理掉具有相同命名的库文件，所以，在构建libname.a的时候会将libname.so库文件清理掉，因此需要再次使用set_target_properties定义的CLEAN_DIRECT_OUTPUT属性，如第四条和第五条指令所示，至此，我们再次进行构建，就会发现在目录中同时生成libname.so动态库文件和libname.a静态库文件

第六条	指令是因为按照规则，动态库是应当包含一个版本号的， 为了实现动态库版本号，仍然需要使用SET_TARGET_PROPERTIES指令，其中VERSON指代动态库版本，SOVERSION指代API版本。

第七条	指令是将动态库和静态库文件安装到系统目录，才能够真正地让其他人开发使用，我们将库文件安装到<prefix>/lib目录下

第八条	指令是将头文件安装到<prefix>/include/tH目录中。

## 外部引用动态库和静态库
```
1.INCLUDE_DIRECTORIES(头文件在系统中的位置)
2.ADD_EXECUTABLE(main source/main.cpp)
3.TARGET_LINK_LIBRARIES(main libfaceDetection.a)
```
因为编译安装将动态库安装到/usr/local/lib，/usr/bin目录下，对于动态库的外部引用有些麻烦；

# 库文件的编译和封装

- 新建`build`文件夹，将要编译成库文件的`inc`和`src`拷贝到`build`文件夹下，然后在此编写CMakeLists.txt 文件,在将头文件和源文件安装成库，CMakeLists的编写如下：
```
#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
set(PROJ_NAME hello)
project($PROJ_NAME)

#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
# Setup include directory for this project
#
include_directories(${PROJECT_SOURCE_DIR}/inc)

#----------------------------------------------------------------------------
# Locate sources and headers for this project
# NB: headers are included so they will show up in IDEs
#
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/inc/*.hh)

#-------------------------------------------
# Create static and dynamic library
#
add_library(${PROJ_NAME} SHARED ${sources} ${headers})
set_target_properties(${PROJ_NAME} PROPERTIES VERSION 1.2 SOVERSION 1)

#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
#install(TARGETS ${PROJ_NAME}  DESTINATION lib)
#install(FILES ${headers} DESTINATION inc)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}../../../lib)
```
**注意** 
- 将可执行二进制文件安装到文件夹时，采用`install(TARGETS )`方式存在一定问题，生存的二进制文件在`usr/bin`，同理，头文件安装在`usr/local/inc`下。
- ` SET(LIBRARY_OUTPUT_PATH )`可以设置库文件安装位置。
- 在`main()`的编译链接中，CMakeLists.txt将会存在以下问题，头文件必须包含生成库文件所用的全部头文件，链接生成的所有动态库文件；如，在上述的
```
    set_target_properties(${PROJ_NAME} PROPERTIES VERSION 1.2 SOVERSION 1) 
```
其将，生成三个库文件，分别如下：
```
    libhello.so
    libhello.so.1
    libhello.so.1.2
```
在链接库文件时，则需要将三个库文件均包含

- API (Application Programming Interface,应用程序编程接口）是一些预先定义的函数，目的是提供应用程序与开发人员基于某软件或硬件得以访问一组例程的能力，而又无需访问源码，或理解内部工作机制的细节。[百度百科](https://baike.baidu.com/item/api/10154)

# 外部引用库的优势

- 隐藏源码
- 不依赖机器的性能和配置差异
- 二进制库文件位置明确，脱离源码可移植性高
 
 


