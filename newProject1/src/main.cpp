#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm> 
#include <Eigen/Dense>

// 函数：读取CSV文件并返回标题行和一个二维整数向量，pairstd::pair 是 C++ 标准库中的一个模板类，用于存储一对值。它定义在 <utility> 头文件中。std::pair 可以存储两个不同类型的值，并且可以方便地访问和操作这两个值。
std::pair<std::vector<std::string>, std::vector<std::vector<double>>> readCSV(const std::string& filename) {
    std::vector<std::string> headers; // 用于存储标题行
    std::vector<std::vector<double>> data; // 用于存储CSV数据的二维向量
	std::ifstream file(filename); // 打开CSV文件，ifstream和ofstream是C++标准库中的两个类，用于读取和写入文件;
    std::string line; // 用于存储每一行的字符串

    if (!file.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return { headers, data };
    }
    // 读取第一行标题
    bool isHeader = true;
    while (std::getline(file, line)) {
        if (isHeader) {
            std::stringstream ss(line);
            std::string cell;
            while (std::getline(ss, cell, ',')) {
                headers.push_back(cell); // 将标题单元格添加到标题行向量中
            }
            isHeader = false; // 标志设置为false，表示标题行已读取
            continue; // 跳过标题行
        }

        std::vector<double> row; // 用于存储每一行的数据
        std::stringstream ss(line); // 将行字符串转换为字符串流
        std::string cell; // 用于存储每个单元格的字符串

        // 逐个单元格读取
        while (std::getline(ss, cell, ',')) {
            try {
                row.push_back(std::stod(cell)); // 将单元格字符串转换为double并添加到行向量中
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "转换错误: " << cell << std::endl;
                row.push_back(0); // 如果转换失败，添加0
            }
        }
        if (!row.empty()) {
            data.push_back(row); // 将行向量添加到数据向量中
        }
    }
    //关闭文件
    file.close();
    return { headers, data }; // 返回标题行和读取的CSV数据
}
   

// 函数：将数据写入CSV文件
void writeCSV(const std::string& filename, const std::vector<std::string>& headers, const std::vector<std::vector<double>>& data) {



    std::ofstream file(filename); // 打开CSV文件以写入
    if (!file.is_open()) {
        std::cerr << "无法打开文件进行写入: " << filename << std::endl;
        return;
    }

    // 写入标题行
    for (size_t i = 0; i < headers.size(); ++i) {
        file << headers[i];
        if (i < headers.size() - 1) {
            file << ",";
        }
    }
    file << "\n";

    // 写入数据行
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1) {
                file << ",";
            }
        }
        file << "\n";
    }
}

//提取亮度函数，并写入data
void Extract_RGBY(std::vector<std::vector<double> >& data, int& x_column, int& y_column, int& lv_column) {
    //16灰阶下RGB的xy值
    double xr = 0.676661432911769,xg = 0.281694467945532, xb = 0.181908629176227, yr = 0.320054946381098, yg = 0.687526633192097, yb = 0.0976572896082167;
    double xw = 0, yw = 0, Yw = 0;


    Eigen::Matrix3d m;
    m(0, 0) = xr / yr; m(0, 1) = xg / yg; m(0, 2) = xb / yb;
    m(1, 0) = 1; m(1, 1) = 1; m(1, 2) = 1;
    m(2, 0) = (1 - xr - yr) / yr; m(2, 1) = (1 - xg - yg) / yg; m(2, 2) = (1 - xb - yb) / yb;

    Eigen::Vector3d result = Eigen::Vector3d::Zero(); // 初始化为零向量
    

    //计算data里面提取出的RGB的Y
	int i = 0;
	for (auto row : data) {
		xw = row[x_column], yw = row[y_column], Yw = row[lv_column];
        Eigen::Vector3d v;
        v(0) = xw * Yw / yw; v(1) = Yw; v(2) = (1 - xw - yw) * Yw / yw;
        Eigen::Vector3d result = m.inverse() * v;
        data[i].push_back(result(0));
        data[i].push_back(result(1));
        data[i].push_back(result(2));
        i++;

	}
	
}



int main() {
    std::string filename = "C:\\Users\\liqiangs\\Desktop\\tool\\6300\\LLC\\panel_W630042T_YDT0_1_6_V7_14PRO_240914_2_9\\solid_color_measure\\red_ColorMeasurement.csv"; // CSV文件名
    auto [headers, data] = readCSV(filename); // 读取CSV文件

    //想要数据的列
	int x_column =4;  
    int y_column = 5;
	int lv_column = 6;


    int i = 0;
    // 输出标题行
    std::cout << "标题行: ";
    std::for_each(headers.begin(), headers.end(), [](std::string value) { std::cout << value << " "; });
	std::cout << std::endl;
  
	Extract_RGBY(data, x_column, y_column, lv_column); // 提取亮度
   

    // 将计算结果写入CSV文件
    std::string outputFilename = "C:\\Users\\liqiangs\\Desktop\\tool\\6300\\LLC\\panel_W630042T_YDT0_1_6_V7_14PRO_240914_2_9\\solid_color_measure\\red_ColorMeasurement_with_extract.csv"; // 输出CSV文件名
    headers.push_back("Yr"); // 添加一个新的标题
	headers.push_back("Yg");
	headers.push_back("Yb");
    writeCSV(outputFilename, headers, data); // 写入CSV文件
 
    return 0;
}

