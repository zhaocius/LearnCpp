//
// Created by zhaozi on 2021/2/5.
//

#include <fstream>

void read_file(const char* path){
    std::ifstream file;
    file.open(path,std::ios::binary);
    if(!file)
        return;
    file.seekg(0,file.end);
    size_t length = file.tellg();
    std::unique_ptr<uint8_t[]> buffer(new uint8_t[length]);
    file.seekg(0,file.beg);
    file.read(reinterpret_cast<char*>(buffer.get()),length);
}

void write_file(const char* path, const char* content,size_t length){
    std::ofstream file;
    file.open(path,std::ios::binary | std::ios::out);
    file.write(content,length);
    file.close();
}