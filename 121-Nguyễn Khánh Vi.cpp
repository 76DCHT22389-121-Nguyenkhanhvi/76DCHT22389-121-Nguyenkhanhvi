// Khai báo thư viện
#include <iostream>
#include <string>

// Khai báo không gian tên
using namespace std;

// Khai báo lớp
class NhanVien {
public: // Cần có public để main() có thể truy cập trực tiếp vào các thuộc tính
    string hoten;
    string manv;
    string ngaysinh;
    string diachi;
};

int main() {
    // Khai báo 1 đối tượng là Minh thuộc lớp NhanVien
    NhanVien Minh;

    // Nhập thông tin cho Minh
    cout << "--- NHAP THONG TIN NHAN VIEN ---" << endl;
    cout << "Nhap ho va ten: ";
    getline(cin, Minh.hoten);

    cout << "Nhap ma nhan vien: ";
    getline(cin, Minh.manv);

    cout << "Nhap ngay sinh: ";
    getline(cin, Minh.ngaysinh);

    cout << "Nhap dia chi: ";
    getline(cin, Minh.diachi);

    // Xuất thông tin của Minh
    cout << "\n--- THONG TIN NHAN VIEN VUA NHAP ---" << endl;
    cout << "Ho va ten     : " << Minh.hoten << endl;
    cout << "Ma nhan vien  : " << Minh.manv << endl;
    cout << "Ngay sinh     : " << Minh.ngaysinh << endl;
    cout << "Dia chi       : " << Minh.diachi << endl;

    return 0;
}
