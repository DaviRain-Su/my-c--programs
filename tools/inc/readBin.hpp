/*=====================================
 *
 * 文件名：readBin.hpp
 * 
 * 文件描述：
 *
 * 创建人：　Copyright 2020 Snow-lake, Inc 
 *           suyinrong, 2020年3月13日
 *
 * email: davirain.yin@gmail.com
 * 
 * 版本: 1.0
 *
 * 修改记录：
 *
 * =================================*/

#include <vector>
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

#ifndef __READBIN_HPP__
#define __READBIN_HPP__

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::streampos;

template <typename T>
void readBin(const string filename, const uint64_t readSize, vector<T>& vec) {
    ifstream file(filename, ios::binary);
    file.unsetf(ios::skipws);//在具体输入前跳过前导空白
    streampos fileSize;
    file.seekg(0, ios::end);
    fileSize = file.tellg();
    file.seekg(0, ios::beg);
    if(readSize > 0 && fileSize != readSize) {
        std::cout << "WARNNING: file " << filename << " size " << fileSize << " doesn't match required size " << readSize 
            << std::endl;
    }

    assert(fileSize >= readSize);

    const uint64_t vecSize = fileSize / sizeof(T);
    vec.resize(vecSize);

    file.read(reinterpret_cast<char*>(vec.data()), fileSize);
    file.close();
}

template <typename  T>
void writeBin(const string filename, const uint64_t writeSize, vector<T>& vec){
    uint64_t fileSize = vec.size() * sizeof(T);
    if( writeSize > 0 && fileSize != writeSize ) {
        std::cout << "WARNNING: vector size " << fileSize << " doesn't match required size " << writeSize << endl;
    }
    assert(fileSize >= writeSize);
    
    ofstream file(filename, ios::binary);
    file.write(reinterpret_cast<char*>(vec.data()), writeSize);
    file.close();
}

#endif
