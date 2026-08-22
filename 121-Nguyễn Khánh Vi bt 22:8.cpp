#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Định nghĩa cấu trúc Nhân Viên
struct NhanVien {
    string ten;
    int tuoi;

    // Hàm nhập thông tin
    void nhap() {
        cout << "Nhap ten: ";
        cin.ignore(); // Xóa bộ nhớ đệm trước khi nhập chuỗi
        getline(cin, ten);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }

    // Hàm xuất thông tin
    void xuat() const {
        cout << "Ten: " << ten << " | Tuoi: " << tuoi << endl;
    }
};

int main() {
    const int SO_LUONG = 10; // Số lượng nhân viên là 10

    // =======================================================
    // CÁCH 1: SỬ DỤNG MẢNG TĨNH
    // =======================================================
    cout << "\n========== CACH 1: MANG TINH ==========" << endl;
    NhanVien dsnv1[SO_LUONG];
    
    // Nhập dữ liệu
    for (int i = 0; i < SO_LUONG; i++) {
        cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---" << endl;
        dsnv1[i].nhap();
    }
    
    // Xuất dữ liệu
    cout << "\n--- XUAT DANH SACH NHAN VIEN (MANG TINH) ---" << endl;
    for (int i = 0; i < SO_LUONG; i++) {
        dsnv1[i].xuat();
    }


    // =======================================================
    // CÁCH 2: SỬ DỤNG MẢNG ĐỘNG 
    // =======================================================
    cout << "\n\n========== CACH 2: MANG DONG ==========" << endl;
    NhanVien *dsnv2 = new NhanVien[SO_LUONG];
    
    // Nhập dữ liệu
    for (int i = 0; i < SO_LUONG; i++) {
        cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---" << endl;
        dsnv2[i].nhap();
    }
    
    // Xuất dữ liệu
    cout << "\n--- XUAT DANH SACH NHAN VIEN (MANG DONG) ---" << endl;
    for (int i = 0; i < SO_LUONG; i++) {
        dsnv2[i].xuat();
    }
    
    // Bắt buộc phải giải phóng bộ nhớ khi dùng new[]
    delete[] dsnv2;


    // =======================================================
    // CÁCH 3: SỬ DỤNG CẤU TRÚC VECTOR
    // =======================================================
    cout << "\n\n========== CACH 3: VECTOR ==========" << endl;
    vector<NhanVien> dsnv3;
    
    // Nhập dữ liệu
    for (int i = 0; i < SO_LUONG; i++) {
        cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---" << endl;
        NhanVien nv;      // Tạo 1 đối tượng nhân viên tạm
        nv.nhap();        // Gọi hàm nhập
        dsnv3.push_back(nv); // Thêm nhân viên vào cuối danh sách vector
    }
    
    // Xuất dữ liệu
    cout << "\n--- XUAT DANH SACH NHAN VIEN (VECTOR) ---" << endl;
    for (int i = 0; i < dsnv3.size(); i++) {
        dsnv3[i].xuat();
    }

    return 0;
}
