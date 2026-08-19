#include <iostream>
#include <string>

using namespace std;

struct NhanVien {
    string maNV;
    string tenNV;
    double luongCoBan;
    double heSo;
};

void nhap(NhanVien nv[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin nhan vien " << i + 1 << ":\n";
        cout << "Ma: "; cin >> nv[i].maNV; cin.ignore();
        cout << "Ten: "; getline(cin, nv[i].tenNV);
        cout << "Luong CB: "; cin >> nv[i].luongCoBan;
        cout << "He so: "; cin >> nv[i].heSo;
    }
}

void xuat(NhanVien nv[], int n) {
    cout << "\nDANH SACH NHAN VIEN:\n";
    for (int i = 0; i < n; i++) {
        cout << nv[i].maNV << "\t" << nv[i].tenNV << "\t" << nv[i].luongCoBan << "\t" << nv[i].heSo << endl;
    }
}

// FINAL: Hoàn thành toàn bộ bài
int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    
    NhanVien* ds = new NhanVien[n]; // Cấp phát động
    
    nhap(ds, n);
    xuat(ds, n);
    
    delete[] ds; // Giải phóng bộ nhớ
    return 0;
}