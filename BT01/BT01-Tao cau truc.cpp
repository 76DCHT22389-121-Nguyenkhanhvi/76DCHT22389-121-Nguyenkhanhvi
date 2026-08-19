#include <iostream>
#include <string>

using namespace std;

// CP1: Tạo cấu trúc nhaanvien
struct NhanVien {
    string maNV;
    string tenNV;
    double luongCoBan;
    double heSo;
};

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    // Khai báo mảng nhân viên
    NhanVien danhSachNV[100]; 

    return 0;
}