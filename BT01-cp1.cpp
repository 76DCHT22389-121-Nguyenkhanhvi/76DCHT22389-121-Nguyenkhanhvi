#include <iostream>
#include <string>

using namespace std;

// ==========================================
// CP1: Tạo cấu trúc nhân viên
// ==========================================
struct NhanVien {
    string maNV;
    string tenNV;
    double luongCoBan;
    double heSo;
};

// ==========================================
// CP2: Hoàn thành hàm nhập và xuất
// ==========================================
void nhap(NhanVien nv[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---\n";
        cout << "Ma nhan vien: ";
        cin >> nv[i].maNV;
        
        cin.ignore(); // Xóa bộ nhớ đệm trước khi nhập chuỗi có khoảng trắng
        cout << "Ten nhan vien: ";
        getline(cin, nv[i].tenNV);
        
        cout << "Luong co ban: ";
        cin >> nv[i].luongCoBan;
        
        cout << "He so luong: ";
        cin >> nv[i].heSo;
    }
}

void xuat(const NhanVien nv[], int n) {
    cout << "\n================ DANH SACH NHAN VIEN ================\n";
    for (int i = 0; i < n; i++) {
        cout << "NV" << i + 1 << " | " 
             << "Ma: " << nv[i].maNV << " | "
             << "Ten: " << nv[i].tenNV << " | "
             << "Luong CB: " << nv[i].luongCoBan << " | "
             << "He so: " << nv[i].heSo << "\n";
    }
    cout << "=====================================================\n";
}

// ==========================================
// FINAL: Hoàn thành toàn bộ bài (Hàm main)
// ==========================================
int main() {
    int n;
    
    // Khai báo số lượng nhân viên
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    
    // Khai báo mảng nhân viên (cấp phát động để mảng linh hoạt theo n)
    NhanVien* danhSachNV = new NhanVien[n];
    
    // Gọi hàm nhập xuất
    nhap(danhSachNV, n);
    xuat(danhSachNV, n);
    
    // Giải phóng bộ nhớ
    delete[] danhSachNV;
    
    return 0;
}