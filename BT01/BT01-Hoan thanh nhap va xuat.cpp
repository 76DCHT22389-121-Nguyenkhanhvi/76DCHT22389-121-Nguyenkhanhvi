#include <iostream>
#include <string>

using namespace std;

struct NhanVien {
    string maNV;
    string tenNV;
    double luongCoBan;
    double heSo;
};

// CP2: Hoàn thành hàm nhap() và xuat()
void nhap(NhanVien nv[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap ma nv, ten nv, luong co ban, he so: ";
        cin >> nv[i].maNV >> ws;
        getline(cin, nv[i].tenNV);
        cin >> nv[i].luongCoBan >> nv[i].heSo;
    }
}

void xuat(NhanVien nv[], int n) {
    for (int i = 0; i < n; i++) {
        cout << nv[i].maNV << " - " << nv[i].tenNV << " - " << nv[i].luongCoBan << " - " << nv[i].heSo << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    NhanVien danhSachNV[100];
    
    // Bạn có thể để trống hoặc gọi thử hàm ở đây
    return 0;
}