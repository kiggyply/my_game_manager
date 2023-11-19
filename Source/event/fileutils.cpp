#include "evenmanager.h"
using namespace std;
namespace fs = std::filesystem;

bool judgeCopyByTime(const string& sourceFile, const string& destinationFile) {
    auto sourceTime = fs::last_write_time(sourceFile);
    if (!fs::exists(destinationFile)) {
        return true;
    }
    auto destinationTime = fs::last_write_time(destinationFile);

    return sourceTime > destinationTime;
}


bool PathMove(string oldPath, string newPath) {
    if (!fs::exists(oldPath) 
        || !fs::is_directory(oldPath) 
        || fs::is_empty(oldPath)){
        return true;
    }
    if (oldPath == newPath) {
            std::cerr << "源路径和目标路径相同" << std::endl;
            return true;
    }
    try {
        for (const auto& entry : fs::recursive_directory_iterator(oldPath)) {
            std::string sourceFilePath = entry.path().string();
            std::string destinationFilePath = newPath + entry.path().string().substr(oldPath.size());

            if (entry.is_directory()) {
                // 如果是目录，创建对应的目标目录
                fs::create_directories(destinationFilePath);
            } else {
                // 如果是文件，根据判断条件进行复制
                if (judgeCopyByTime(sourceFilePath, destinationFilePath)) {
                    fs::copy(sourceFilePath, destinationFilePath, fs::copy_options::overwrite_existing);
                }
            }
        }
        // 删除原目录及其所有内容
        fs::remove_all(oldPath);
    } catch (const exception e) {
        cerr << "目录移动失败：" << e.what() << endl;
    }
    return true;
}